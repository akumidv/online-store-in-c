/*#include  "getprm.h"*/
#define __REG
#include  "allhead.h"
#include  "registr.h"


int main(void)
{
  char *szTmp, *szTmp1;
  int iTmp;
  char blIsTrue;
  uint i = 0, j;
  uint iTbNum;
  char blPutBsk=0;

  printf(CGI_CONTENT);

  szQS=GetParamStr();
  if(!szQS)
    http_err("Error no set szQS!");

  szQS=UnCode(szQS);
  if(!szQS)
    http_err("Error no UnCode(szQS)!");
/*  QSToCharSet(szQS,"ibm866");*/

/*Podkluchaemsya k serveru i otkryvaem basu*/
  if (!(mysql_connect(&mysql,"localhost",USRREGSTR,PSWREGSTR)))
     mysql_err(1);
  if (mysql_select_db(&mysql,NMDB)) mysql_err(2);

  iSect=MN_REG;
  Init();

  CGIHeader();
#ifdef DEBAG
  printf("%s<br>\n",szQS);
#endif

  blIsTrue = GetQV(0, TB_USERS);

  if(blIsTrue)
  {
    if(Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].blData!=1)
    {
      blIsTrue=0;
      printf("Вы не ввели обязательное поле: %s<br>\n",Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].szFldName);
    }
    if(IsMailAdr(Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].szHTFldValue)!=1)
    {
      blIsTrue=0;
      printf("Введенный Вами данные как адерес Email, совсем на него не похожи.<br>\n");
    }
    if(Tb[TB_USERS].Prm[HT_NUM_USR_PASSWD].blData!=1)
    {
      blIsTrue=0;
      printf("Вы не ввели обязательное поле: %s<br>\n",Tb[TB_USERS].Prm[HT_NUM_USR_PASSWD].szFldName);
    }
    if(Tb[TB_USERS].Prm[HT_NUM_USR_FIO].blData!=1)
    {
      blIsTrue=0;
      printf("Вы не ввели обязательное поле: %s<br>\n",Tb[TB_USERS].Prm[HT_NUM_USR_FIO].szFldName);
    }
    if(blIsTrue)
    {
      if(strcmp(Tb[TB_USERS].Prm[HT_NUM_USR_PASSWD].szHTFldValue,GetQueryValue(szQS,Tb[TB_USERS].Prm[HT_NUM_USR_PASSWD].szHTFldNameCpy))==0)
      {
        szTmp=SetInsertStr(TB_USERS);
        if (mysql_query(&mysql,szTmp)!=0)
          mysql_err(3);
        else
        {
          printf("Вы зарегистрированы!<br>\n");
          printf("Теперь Вы можете оформить заказ. Для этого войдите в [<a href=\"%s\">систему</a>]\n",CGI_PATH_ORDER);
        }
        free(szTmp);
      }
      else
      {
        printf("Пароли различаются, попробуйте еще раз!<br>\n");
        blIsTrue=0;
      }
    }
  }
  if(blIsTrue==0)
  {
    ShowRegForm();
  }

  mysql_close(&mysql);
  CGIFooter();
}

