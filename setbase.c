/*#include  "getprm.h"*/
#include  "allhead.h"
#include  "setbase.h"


int main(void)
{
  char *szTmp, *szTmp1;
  int iTmp;
  char blIsTrue;
  uint i = 0, j;
  uint iTbNum;

  printf(CGI_CONTENT);

/*  printf(szgHTMLHeader);*/
  printf("<html>\n<body>\n");

  szQS=GetParamStr();
  if(!szQS)
    http_err("Error no set szQS!");

  szQS=UnCode(szQS);
  if(!szQS)
    http_err("Error no UnCode(szQS)!");

/*  QSToCharSet(szQS,"ibm866");*/

/*Podkluchaemsya k serveru i otkryvaem basu*/

  if (!(mysql_connect(&mysql,"localhost",USRADM,PSWADM)))
     mysql_err(1);

  if (mysql_select_db(&mysql,NMDB)) mysql_err(2);

  Init();

  szTmp=GetQueryValue(szQS,"HT_TABLE_SEL");
  if(szTmp==NULL)
    http_err("Error no GetQueryValue(szQS,HT_TABLE_SEL)");

  iTbNum=atoi(szTmp);
  switch(iTbNum)
  {
    default:
      iTbNum=TB_CAT;

    case TB_CAT:
      printf("<center><big>База товаров</big></center><br>\n");
      break;

    case TB_USERS:
      printf("<center><big>База заказчиков</big></center><br>\n");
      break;

    case TB_ORDERS:
      printf("<center><big>База заказов</big></center><br>\n");
      break;

    case TB_HARAKT:
      printf("<center><big>База характеристик</big></center><br>\n");
      break;
    case TB_BASKET:
      printf("<center><big>База корзины</big></center><br>\n");
      break;
  }
  szTmp=GetQueryValue(szQS,HT_CUR_REC);
  if(szTmp==NULL)
    http_err("Error no GetQueryValue(szQS,HT_CUR_REC)!");
  iCurRec=atoi(szTmp);

  szTmp=GetQueryValue(szQS,"HT_OPER");
  if(szTmp==NULL)
    http_err("Error no GetQueryValue(szQS,HT_OPER)!");
  switch(atoi(szTmp))
  {
    case TBOP_INSERT:
    /*Zanosim dannie */
      blIsTrue = GetQVExt(iTbNum);
      if(blIsTrue)
      {
        szTmp=SetInsertStr(iTbNum);
        if (mysql_query(&mysql,szTmp)!=0)
          mysql_err(3);
        else
          printf("Данные успешно занесены<br>\n");
        free(szTmp);
        blIsTrue = GetQV(1, iTbNum);
        if(blIsTrue)
        {
          szTmp=SetSelectStr(iTbNum);
          Select(szTmp, iTbNum);
          free(szTmp);
        }
      }
      else
        printf("<center><b>Не введены данные</b></center><br>");
      break;

    case TBOP_SELECT:
      blIsTrue = GetQVExt(iTbNum);
      if(blIsTrue)
      {
        szTmp=SetSelectStr(iTbNum);
        Select(szTmp, iTbNum);
        free(szTmp);
        break;
      }
      else
        printf("<center><b>Не введены данные</b></center><br>");
      break;

    case TBOP_DELETE:
      szTmp=SetDeleteStr(iTbNum);
      if (mysql_query(&mysql,szTmp)!=0)
        mysql_err(3);
      free(szTmp);
      blIsTrue = GetQV(1, iTbNum);
      if(blIsTrue){
        szTmp=SetSelectStr(iTbNum);
        Select(szTmp, iTbNum);
        free(szTmp);
      }
      break;

    case TBOP_UPDATE:
      blIsTrue = GetQVExt(iTbNum);
      if(blIsTrue)
      {
        szTmp=SetUpdateStr(iTbNum);
        if (mysql_query(&mysql,szTmp)!=0)
          mysql_err(3);
        free(szTmp);
        blIsTrue = GetQV(1, iTbNum);
        if(blIsTrue)
        {
          szTmp=SetSelectStr(iTbNum);
          Select(szTmp, iTbNum);
          free(szTmp);
        }
      }
      else
        printf("<center><b>Не введены данные</b></center><br>");
      break;

    default:
      FstSelect(iTbNum);
      break;
  }
  printf("<br><hr>\n");
  mysql_close(&mysql);
  printf("</body>\n</html>");
}

