/*#include  "getprm.h"*/
#define __ORD

#define   HT_ORD_SHOW       "SHOWORD"
#define   HT_ORD_MDFY_USR    "USERMODIFY"
#define   HT_ORD_MDFY_SET_USR "USERSETDATA"

#include  "allhead.h"
#include  "registr.h"
#include  "basket.h"
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
  char *szTmp, *szTmp1;
  int iTmp;
  char blIsTrue;
  uint i = 0, j;
  uint iTbNum;
  pid_t child_pid, child_pid1;
  FILE *fh;

  blIsOrder=1;

  printf(CGI_CONTENT);

  szQS=GetParamStr();
  if(!szQS)
    http_err("Error no set szQS!");

  szQS=UnCode(szQS);
  if(!szQS)
    http_err("Error no UnCode(szQS)!");
/*  QSToCharSet(szQS,"ibm866");*/

#ifdef DEBAG
  printf("%s<br>\n",szQS);
#endif


  iSect=TPMNIT_2;
  Init();

/*Podkluchaemsya k serveru i otkryvaem basu*/
  if (!(mysql_connect(&mysql,"localhost",USRBSKET,PSWBSKET)))
     mysql_err(1);

  if (mysql_select_db(&mysql,NMDB)) mysql_err(2);

  szBasket=GetQueryValue(szQS,HT_FLD_BASKET);
  if(szBasket!=NULL)
    BasketInOrder();
  szBasket="";

  if(iQntOrd!=0)
    InsertTmpBask();

  if(VerifyUser())
    blVerifyUser=1;

  szTmp=GetQueryValue(szQS,HT_FLD_ORDER);
  if(szTmp==NULL)
    http_err("Error no GetQueryValue(szQS,HT_FLD_ORDER)!");

  CGIHeader();
  if(blVerifyUser==0){
    if(!strcmp(szTmp,HT_BSK_VAL_VER))
      printf("<center><b>Введенный Вами Email и пароль не корректны!</b></center><br>\n");
    VerifyForm();
  }
  else {
    if(!strcmp(szTmp,HT_ORD_MDFY_SET_USR))
    {
      mysql_close(&mysql);
      if (!(mysql_connect(&mysql,"localhost",USRREGSTR,PSWREGSTR)))
         mysql_err(1);
      if (mysql_select_db(&mysql,NMDB))
        mysql_err(2);

      GetQV(0, TB_USERS);
      UpdUserData();
      ShowUserData();
    }
    else {
      if(!strcmp(szTmp,HT_ORD_MDFY_USR))
        ShowUserData();
      else {
        GetBasket();
        if(!strcmp(szTmp,HT_BSK_VAL_UPD)) {
          UpdateBasket();
          GetBasket();
        }
        if(iQntOrd!=0) {
          if(!strcmp(szTmp,HT_BSK_VAL_PUT)) {
            Tb[TB_ORDERS].Prm[HT_NUM_ORD_EMAIL].szHTFldValue=Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].szHTFldValue;
            InsertBask();
            printf("Ваш заказ <b>%s</b> от <b>%s</b> оформлен<br>",Tb[TB_ORDERS].Prm[HT_NUM_ORD_ORDER_NUM].szHTFldValue, Tb[TB_ORDERS].Prm[HT_NUM_ORD_DATE_REG].szHTFldValue);
            printf("На Ваш Email: %s будет выслана вся информация по заказу.<br>\n",Tb[TB_ORDERS].Prm[HT_NUM_ORD_EMAIL].szHTFldValue);
            printf("Все вопросы направляйте по адресу %s",MAIL_ADR_CAT);
            szTmp=SendOrderMail();
            fh=fopen("./ord_mail.tmp","w");
            if(fh!=NULL) {
              fprintf(fh,szTmp);
              fclose(fh);
              child_pid=fork();

              if(child_pid==0) {
                szTmp1=malloc(sizeof("sendmail  < ./ord_mail.tmp")+sizeof(MAIL_ADR_CAT)+1);
                strcpy(szTmp1,"sendmail ");
                strcat(szTmp1,MAIL_ADR_CAT);
                strcat(szTmp1," < ./ord_mail.tmp");
                execl("/bin/sh","sh","-c",szTmp1,0);
                free(szTmp1);              
                exit(1);
              }
              child_pid1=fork();
              if(child_pid1==0) {
                szTmp1=malloc(sizeof("sendmail  < ./ord_mail.tmp")+strlen(Tb[TB_ORDERS].Prm[HT_NUM_ORD_EMAIL].szHTFldValue)+1);
                strcpy(szTmp1,"sendmail ");
                strcat(szTmp1,Tb[TB_ORDERS].Prm[HT_NUM_ORD_EMAIL].szHTFldValue);
                strcat(szTmp1," < ./ord_mail.tmp");
                execl("/bin/sh","sh","-c",szTmp1,0);
                free(szTmp1);
                exit(1);
              }
            }
            free(szTmp);
          }
          else {
            printf("<center><big>Внимательно проверьте заказ!</big></center>");
            szTmp=SetBaskSelectStr();
            SelectBask(szTmp);
            free(szTmp);
            if(blVerifyUser)
              PutOrderForm();
          }
        }
        else
          printf("<center><big>Ваша корзина пуста!</big></ceneter>");
      }
    }
  }
  mysql_close(&mysql);
  CGIFooter();
}

