/*#include  "getprm.h"*/
#define HT_SHORT "SHRT" /*Просмотр базы списком при 0, другое - обычно*/

#include  "allhead.h"
#include  "cat.h"

int main(void)
{
  char *szTmp, *szTmp1;
  int iTmp;
  char blIsTrue;
  uint i = 0, j;

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

  szTmp=GetQueryValue(szQS,HT_SECT);
  if(szTmp==NULL)
    http_err("Error no GetQueryValue(szQS,HT_CUR_REC)!");
  iSect=atoi(szTmp);
  Init();
  CGIHeader();

  switch(iSect){
    case TPMNIT_3:
      HTML_FlOut(TPMNIT_LNK_3);
      break;
    case MNIT_KUH_INV:
    case MNIT_KND_INV:
    case MNIT_KMP_HLD:
    case MNIT_THN_OBR:
      /*Podkluchaemsya k serveru i otkryvaem basu*/
      if (!(mysql_connect(&mysql,"localhost",USRGUEST,PSWGUEST)))
         mysql_err(1);
      if (mysql_select_db(&mysql,NMDB)) mysql_err(2);
  
      szTmp=GetQueryValue(szQS,HT_CUR_REC);
      if(szTmp==NULL)
        http_err("Error no GetQueryValue(szQS,HT_CUR_REC)!");
      iCurRec=atoi(szTmp);
    
      blIsTrue = GetQV(0, TB_CAT);
    
      if(!blIsTrue){
        switch(iSect){
          case MNIT_THN_OBR:
            Tb[TB_CAT].Prm[HT_NUM_VID_TOV].szHTFldValue=VT_THN_OBR;
            Tb[TB_CAT].Prm[HT_NUM_VID_TOV].blData=1;	  
    	    break;
          case MNIT_KND_INV:
            Tb[TB_CAT].Prm[HT_NUM_VID_TOV].szHTFldValue=VT_KND_INV;
            Tb[TB_CAT].Prm[HT_NUM_VID_TOV].blData=1;
  	    break;
          case MNIT_KUH_INV:
            Tb[TB_CAT].Prm[HT_NUM_VID_TOV].szHTFldValue=VT_KUH_INV;
            Tb[TB_CAT].Prm[HT_NUM_VID_TOV].blData=1;
  	    break;
  	  default:
            Tb[TB_CAT].Prm[HT_NUM_VID_TOV].szHTFldValue=VT_KMP_HLD;
            Tb[TB_CAT].Prm[HT_NUM_VID_TOV].blData=1;
	    break;
        }
      }
      SetHarakt(Tb[TB_CAT].Prm[HT_NUM_VID_TOV].szHTFldValue);
    
      szTmp=SetCatSelectStr();
      SelectCat(szTmp);
      free(szTmp);
      Search(Tb[TB_CAT].Prm[HT_NUM_VID_TOV].szHTFldValue);
      mysql_close(&mysql);
      break;      
    default:
      HTML_FlOut(MNITLN_ABT);
      break;

  }
  CGIFooter();
}

