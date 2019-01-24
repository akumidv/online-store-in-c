/*#include  "getprm.h"*/
#define __BASK
#include  "allhead.h"
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
  char blPutBsk=0;
  pid_t child_pid;
  FILE *fh;

/*blIsOrder=0;*/

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

/*Podkluchaemsya k serveru i otkryvaem basu*/
  if (!(mysql_connect(&mysql,"localhost",USRBSKET,PSWBSKET)))
     mysql_err(1);

  if (mysql_select_db(&mysql,NMDB)) mysql_err(2);

  iSect=TPMNIT_4;
  Init();
  CGIHeader();

  szBasket=GetQueryValue(szQS,HT_FLD_BASKET);
  if(szBasket!=NULL)
    if(strlen(szBasket)>0)
      BasketInOrder();
  szBasket="";

  if(iQntOrd!=0)
    InsertTmpBask();

  GetBasket();

  if(iQntOrd!=0)
  {
    szTmp=GetQueryValue(szQS,HT_FLD_ORDER);
    if(szTmp==NULL)
      http_err("Error no GetQueryValue(szQS,HT_FLD_ORDER)!");
    if(!strcmp(szTmp,HT_BSK_VAL_UPD))
    {
       UpdateBasket();
       GetBasket();
    }
  }
  if(iQntOrd!=0)
  {
/*    printf(HT_CAT_HEAD_w2p,PATH_IMG_HD_BASK,"");*/
    szTmp=SetBaskSelectStr();
    SelectBask(szTmp);
    free(szTmp);
  }
  else
    printf("<center><big>Ваша корзина пуста!</big></center>");


  VerifyForm();

  mysql_close(&mysql);
  CGIFooter();
}

