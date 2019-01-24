#if !defined __CAT_H
#define __CAT_H

#define HT_CAT_TBL_SRCH_HEAD "<center>\n\
<table cellspacing=2 cellpadding=3 bgcolor=#DADADA border=0>\n\
<tr><td align=center class=bg>Поиск в текущем разделе</td></tr>\n"

#define HT_CAT_TBL_SRCH_FLD_w3p "<tr><td class=bg>%s</td></tr>\n\
<tr><td class=bg><input type=text name=\"%s\" value=\"\" size=%d></td></tr>\n"

#define HT_CAT_TBL_SRCH_SLCT_HD_w2p "<tr><td class=bg>%s</td></tr>\n\
<tr><td class=bg><select name=\"%s\">\n"
#define HT_CAT_TBL_SRCH_SLCT_DEF_w2p "<option value=\"%s\" SELECTED>%s</option>\n"
#define HT_CAT_TBL_SRCH_SLCT_w2p "<option value=\"%s\">%s</option>\n"
#define HT_CAT_TBL_SRCH_SLCT_FT_w0p "</select></td></tr>\n"

#define HT_CAT_TBL_SRCH_FOOT_w0p "<tr><td align=right height=9 class=bg><input type=image src=\"/image/search.gif\" border=0 alt=\"Поиск\"></td></tr>\n\
</table></center>\n"


#define HT_CAT_TBL_HEAD "\
<table cellspacing=0 cellpadding=0 border=0 width=100%%>\n\
  <tr><td width=100%% valign=top>\n\
  <table cellspacing=3 cellpadding=4 border=0 width=100%%>\n"

#define HT_CAT_TBL_TV_NAME_w1p "\
  <tr>\n\
    <td class=yacheika0>::%s::</td>\n\
  </tr>\n"

#define HT_CAT_TBL_TV_DESC_w2p "\
  <tr>\n\
   <td class=yacheika1>%s: %s</td>\n\
  </tr>\n"

#define HT_CAT_TBL_TV_COST_w2p "\
  <tr>\n\
   <td class=yacheika3>%s: %s</td>\n\
  </tr>\n"

#define HT_CAT_TBL_MDL "\
</table></td><td valign=top>\n\
<table cellspacing=0 cellpadding=0 border=0 width=155>\n"

#define HT_CAT_TBL_TV_IMG_w1p "\
 <tr>\n\
   <td width=9 heigth=96><img src=\"/image/form006.gif\" width=9 heigth=96 border=0></td>\n\
   <td width=132 heigth=96><img src=\"%s\" width=132 heigth=96 border=0></td>\n\
   <td width=14 heigth=96><img src=\"/image/form008.gif\" width=14 heigth=96 border=0></td>\n\
 </tr>\n\
 <tr>\n\
   <td width=9 heigth=8><img src=\"/image/form011.gif\" width=9 heigth=8 border=0></td>\n\
   <td width=132 heigth=8><img src=\"/image/form012.gif\" width=132 heigth=8 border=0></td>\n\
   <td width=14 heigth=8><img src=\"/image/form013.gif\" width=14 heigth=8 border=0></td>\n\
 </tr>\n"


#define HT_CAT_TBL_TV_2BASK_w3p "\
 <tr>\n\
   <td width=9 height=17><img src=\"/image/form016.gif\" width=9 height=17 border=0></td>\n\
   <td width=132 height=17>\n\
<table cellspacing=0 cellpadding=0 border=0>\n\
   <td width=42 height=17><img src=\"/image/zakaz.gif\" width=42 height=17 border=0></td>\n\
<FORM METHOD=POST ACTION=\"%s\">\n\
<td width=61 height=17>\
<input type=hidden name=\"%s\" value=\"%s\">\
<input type=image src=\"/image/zakaz1.gif\" border=0 alt=\"Заказать\"></td>\n\
</FORM>\n\
<td width=29 height=17 border=0></td>\n\
 </tr></table></td>\n\
  <td width=14 height=17><img src=\"/image/form018.gif\" width=14 height=17 border=0></td>\n\
</tr>\n"

#define HT_CAT_TBL_FOOT "\
</table></td></tr></table>\n\
<table cellspacing=0 cellpadding=0 border=0 width=100%%>\n\
  <tr><td width=100%%></td>\n\
   <td width=148 height=7><img src=\"/image/line_c.gif\" width=148 height=7 border=0></td>\n\
   </tr></table>\n"

#define HT_CAT_PAGE_HD_w0p "<table cellspacing=0 cellpadding=0 border=0 width=100%%>\n\
  <tr><td align=center bgcolor=#DADADA width=100%%>"

#define HT_CAT_PAGE_FT_w0p "</td></tr></table>"

void SetHarakt(char *szVidTovara)
{
  char *szTmp;

  szTmp=malloc(150);
  if(szTmp==NULL)
    http_err("Error no memory for MySQL SELECT!");
  strcpy(szTmp,"SELECT \n");
  strcat(szTmp, "harakt0, harakt1, harakt2, harakt3");
  strcat(szTmp, "\n FROM \n");
  strcat(szTmp, TBNM_HARAKT);
  strcat(szTmp, "\n WHERE \n");
  strcat(szTmp, Tb[TB_HARAKT].Prm[0].szTBFldName);
  strcat(szTmp, " = \"");
  strcat(szTmp, szVidTovara);
  strcat(szTmp, "\";");
#ifdef DEBAG
  printf("%s<br>\n",szTmp);
#endif
  if (mysql_query(&mysql,szTmp)!=0)
    mysql_err(3);
  if (!(res = mysql_store_result(&mysql))) mysql_err(4);
  free(szTmp);
  while((row = mysql_fetch_row(res)))
  {
    if(row[0]!=NULL)
    {
      Tb[TB_CAT].Prm[HT_NUM_HARAKT0].szFldName=malloc(strlen(row[0])+1);
      strcpy(Tb[TB_CAT].Prm[HT_NUM_HARAKT0].szFldName,row[0]);
    }
    else
      Tb[TB_CAT].Prm[HT_NUM_HARAKT0].szFldName="";

    if(row[1]!=NULL)
    {
      Tb[TB_CAT].Prm[HT_NUM_HARAKT1].szFldName=malloc(strlen(row[1])+1);
      strcpy(Tb[TB_CAT].Prm[HT_NUM_HARAKT1].szFldName,row[1]);
    }
    else
      Tb[TB_CAT].Prm[HT_NUM_HARAKT1].szFldName="";
    if(row[2]!=NULL)
    {
      Tb[TB_CAT].Prm[HT_NUM_HARAKT2].szFldName=malloc(strlen(row[2])+1);
      strcpy(Tb[TB_CAT].Prm[HT_NUM_HARAKT2].szFldName,row[2]);
    }
    else
      Tb[TB_CAT].Prm[HT_NUM_HARAKT2].szFldName="";
    if(row[3]!=NULL)
    {
      Tb[TB_CAT].Prm[HT_NUM_HARAKT3].szFldName=malloc(strlen(row[3])+1);
      strcpy(Tb[TB_CAT].Prm[HT_NUM_HARAKT3].szFldName,row[3]);
    }
    else
      Tb[TB_CAT].Prm[HT_NUM_HARAKT3].szFldName="";
  }
}


void Search(char *szVidTovara)
{
  uint i;
  char *szTmp;

  printf("<FORM METHOD=POST ACTION=\"%s\">\n",CGI_PATH_CAT);
  printf("<input type=hidden name=%s value=0>\n", HT_CUR_REC);
  printf(HT_INPUT_HIDDEN, HT_FLD_BASKET, szBasket);
  printf(HT_INPUT_HID_DG, HT_SECT, iSect);
  printf(HT_INPUT_HIDDEN, Tb[TB_CAT].Prm[HT_NUM_VID_TOV].szHTFldName, szVidTovara);
  printf(HT_CAT_TBL_SRCH_HEAD);
  printf(HT_CAT_TBL_SRCH_SLCT_HD_w2p,Tb[TB_CAT].Prm[HT_NUM_SUB_VID].szFldName,Tb[TB_CAT].Prm[HT_NUM_SUB_VID].szHTFldName);
  printf(HT_CAT_TBL_SRCH_SLCT_DEF_w2p,"","::Все::");
  szTmp=malloc(sizeof(SQL_CAT_SUB_VID)+sizeof("\"\";")+Tb[TB_CAT].Prm[HT_NUM_SUB_VID].iFldLen+1);
  if(szTmp!=NULL){
    strcpy(szTmp,SQL_CAT_SUB_VID);
    strcat(szTmp,"\"");
    strcat(szTmp,Tb[TB_CAT].Prm[HT_NUM_VID_TOV].szHTFldValue);
    strcat(szTmp,"\";");
#ifdef DEBAG
    printf("%s<br>\n",szTmp);
#endif
    if (mysql_query(&mysql,szTmp)!=0)
      mysql_err(3);
    if (!(res = mysql_store_result(&mysql)))
      mysql_err(4);
    while((row = mysql_fetch_row(res))){
      if(row[0]!=NULL)
        printf(HT_CAT_TBL_SRCH_SLCT_w2p,row[0],row[0]);
    }
    if (!mysql_eof(res))
      mysql_err(5);
    mysql_free_result(res);
    free(szTmp);
  }
  printf(HT_CAT_TBL_SRCH_SLCT_FT_w0p);
  
  printf(HT_CAT_TBL_SRCH_SLCT_HD_w2p,Tb[TB_CAT].Prm[HT_NUM_TIP].szFldName,Tb[TB_CAT].Prm[HT_NUM_TIP].szHTFldName);
  printf(HT_CAT_TBL_SRCH_SLCT_DEF_w2p,"","::Все::");
  szTmp=malloc(sizeof(SQL_CAT_TIP)+sizeof("\"\";")+Tb[TB_CAT].Prm[HT_NUM_TIP].iFldLen+1);
  if(szTmp!=NULL){
    strcpy(szTmp,SQL_CAT_TIP);
    strcat(szTmp,"\"");
    strcat(szTmp,Tb[TB_CAT].Prm[HT_NUM_VID_TOV].szHTFldValue);
    strcat(szTmp,"\";");
#ifdef DEBAG
    printf("%s<br>\n",szTmp);
#endif
    if (mysql_query(&mysql,szTmp)!=0)
      mysql_err(3);
    if (!(res = mysql_store_result(&mysql)))
      mysql_err(4);
    while((row = mysql_fetch_row(res))){
      if(row[0]!=NULL)
        printf(HT_CAT_TBL_SRCH_SLCT_w2p,row[0],row[0]);
    }
    if (!mysql_eof(res))
      mysql_err(5);
    mysql_free_result(res);
    free(szTmp);
  }
  printf(HT_CAT_TBL_SRCH_SLCT_FT_w0p);
  
  printf(HT_CAT_TBL_SRCH_FLD_w3p, Tb[TB_CAT].Prm[HT_NUM_IMYA_TOV].szFldName,Tb[TB_CAT].Prm[HT_NUM_IMYA_TOV].szHTFldName, Tb[TB_CAT].Prm[HT_NUM_IMYA_TOV].iFldLen);
  printf(HT_CAT_TBL_SRCH_FLD_w3p,Tb[TB_CAT].Prm[HT_NUM_MARKA].szFldName,Tb[TB_CAT].Prm[HT_NUM_MARKA].szHTFldName, Tb[TB_CAT].Prm[HT_NUM_MARKA].iFldLen);

/*  if(strlen(Tb[TB_CAT].Prm[HT_NUM_HARAKT0].szFldName)>0)
    printf(HT_CAT_TBL_SRCH_FLD_w3p,Tb[TB_CAT].Prm[HT_NUM_HARAKT0].szFldName,Tb[TB_CAT].Prm[HT_NUM_HARAKT0].szHTFldName, Tb[TB_CAT].Prm[HT_NUM_HARAKT0].iFldLen);*/
  printf(HT_CAT_TBL_SRCH_SLCT_HD_w2p,Tb[TB_CAT].Prm[HT_NUM_HARAKT0].szFldName,Tb[TB_CAT].Prm[HT_NUM_HARAKT0].szHTFldName);
  printf(HT_CAT_TBL_SRCH_SLCT_DEF_w2p,"","::Все::");
  szTmp=malloc(sizeof(SQL_CAT_HRKT0)+sizeof("\"\";")+Tb[TB_CAT].Prm[HT_NUM_HARAKT0].iFldLen+1);
  if(szTmp!=NULL){
    strcpy(szTmp,SQL_CAT_HRKT0);
    strcat(szTmp,"\"");
    strcat(szTmp,Tb[TB_CAT].Prm[HT_NUM_VID_TOV].szHTFldValue);
    strcat(szTmp,"\";");
#ifdef DEBAG
    printf("%s<br>\n",szTmp);
#endif
    if (mysql_query(&mysql,szTmp)!=0)
      mysql_err(3);
    if (!(res = mysql_store_result(&mysql)))
      mysql_err(4);
    while((row = mysql_fetch_row(res))){
      if(row[0]!=NULL)
        printf(HT_CAT_TBL_SRCH_SLCT_w2p,row[0],row[0]);
    }
    if (!mysql_eof(res))
      mysql_err(5);
    mysql_free_result(res);
    free(szTmp);
  }
  printf(HT_CAT_TBL_SRCH_SLCT_FT_w0p);

  if(strlen(Tb[TB_CAT].Prm[HT_NUM_HARAKT1].szFldName)>0)
    printf(HT_CAT_TBL_SRCH_FLD_w3p,Tb[TB_CAT].Prm[HT_NUM_HARAKT1].szFldName,Tb[TB_CAT].Prm[HT_NUM_HARAKT1].szHTFldName, Tb[TB_CAT].Prm[HT_NUM_HARAKT1].iFldLen);
  if(strlen(Tb[TB_CAT].Prm[HT_NUM_HARAKT2].szFldName)>0)
    printf(HT_CAT_TBL_SRCH_FLD_w3p,Tb[TB_CAT].Prm[HT_NUM_HARAKT2].szFldName,Tb[TB_CAT].Prm[HT_NUM_HARAKT2].szHTFldName, Tb[TB_CAT].Prm[HT_NUM_HARAKT2].iFldLen);
  if(strlen(Tb[TB_CAT].Prm[HT_NUM_HARAKT3].szFldName)>0)
    printf(HT_CAT_TBL_SRCH_FLD_w3p,Tb[TB_CAT].Prm[HT_NUM_HARAKT3].szFldName,Tb[TB_CAT].Prm[HT_NUM_HARAKT3].szHTFldName, Tb[TB_CAT].Prm[HT_NUM_HARAKT3].iFldLen);

  printf(HT_CAT_TBL_SRCH_FOOT_w0p);
  printf("</FORM>\n");
}


void PageSelectCat(uint iOldCurRec, uint iAllRec){
  uint i, iLen=0,iEndPage,iStartPage;
  char *szTmp;
  char *szTmp1;
  char blIsFirst;

  iLen=((sizeof("&")+sizeof("="))*(Tb[TB_CAT].iQntFld+sizeof(HT_SECT)+8+2));/* 8-Раздел */

  for (i=0; i<Tb[TB_CAT].iQntFld; i++) {
    if(Tb[TB_CAT].Prm[i].szHTFldValue==NULL)
      iLen+=strlen(Tb[TB_CAT].Prm[i].szHTFldName);
    else
      iLen+=strlen(Tb[TB_CAT].Prm[i].szHTFldName)+strlen(Tb[TB_CAT].Prm[i].szHTFldValue);
  }
  szTmp=malloc(iLen+1);
  iLen=sizeof("&")+sizeof(HT_CUR_REC)+sizeof("=")+12+1;/*12 - vozmozhnaya dlina iCurRec*/
  szTmp1=malloc(iLen+1);
  printf(HT_CAT_PAGE_HD_w0p);
  sprintf(szTmp,"%s=%d",HT_SECT,iSect);
  for (i=0; i<Tb[TB_CAT].iQntFld; i++) {
    if(Tb[TB_CAT].Prm[i].szHTFldValue!=NULL) {
      if(strlen(Tb[TB_CAT].Prm[i].szHTFldValue)>0) {
        strcat(szTmp,"&");
        strcat(szTmp,Tb[TB_CAT].Prm[i].szHTFldName);
        strcat(szTmp,"=");
        strcat(szTmp,Tb[TB_CAT].Prm[i].szHTFldValue);
      }
    }
  }
  CodeSpace(szTmp);
  if(iOldCurRec>((QNT_VIEW_REC/2)*QNT_VIEW_REC))
    iStartPage=iOldCurRec-(4*QNT_VIEW_REC);
  else
    iStartPage=0;

  iEndPage=iAllRec/QNT_VIEW_REC;

  if((float)((float)iAllRec/(float)QNT_VIEW_REC)!=(float)((int)(iAllRec/QNT_VIEW_REC)))
    iEndPage++;

  if(iEndPage>(iStartPage/QNT_VIEW_REC+10))
    iEndPage=iStartPage/QNT_VIEW_REC+10;
  else
    iStartPage=(iEndPage-10)*QNT_VIEW_REC;

//  for(i=0;i<iEndPage;i++)
  for(i=iStartPage/QNT_VIEW_REC;i<iEndPage;i++) {
    if(i==(iOldCurRec/QNT_VIEW_REC))
      printf("[%d]\n",i+1);
    else {
      sprintf(szTmp1,"&%s=%d",HT_CUR_REC,i*QNT_VIEW_REC);
      printf("[<a href=\"%s?%s%s\">%d</a>]\n",CGI_PATH_CAT,szTmp,szTmp1,i+1);
    }
  }
  free(szTmp1);

  free(szTmp);
  printf(HT_CAT_PAGE_FT_w0p);  
}

char *SetCatSelectStr(void)
{
  char *szTmp;
  char blIsTrue;
  uint i;

  szTmp=malloc(strlen(szQS)+140+sizeof(Tb[TB_CAT].szVwFld)+
  sizeof(Tb[TB_CAT].Prm[HT_NUM_SUB_VID].szTBFldName)+
  sizeof(Tb[TB_CAT].Prm[HT_NUM_TIP].szTBFldName)+
  sizeof(Tb[TB_CAT].Prm[HT_NUM_IMYA_TOV].szTBFldName)+1);
  if(szTmp==NULL)
    http_err("Error no memory for MySQL Cat SELECT!");
  strcpy(szTmp,"SELECT \n");
  strcat(szTmp, Tb[TB_CAT].szVwFld);
  strcat(szTmp, "\n FROM \n");
  strcat(szTmp, Tb[TB_CAT].szName);
  strcat(szTmp, "\n WHERE vidim=\"0\"\n");
  for(i=0;i<Tb[TB_CAT].iQntFld;i++)
  {
    if(Tb[TB_CAT].Prm[i].blData)
    {
      strcat(szTmp, " AND ");
      strcat(szTmp, Tb[TB_CAT].Prm[i].szTBFldName);
      strcat(szTmp, " = \"");
      strcat(szTmp, Tb[TB_CAT].Prm[i].szHTFldValue);
      strcat(szTmp, "\"");
    }
  }
  strcat(szTmp, "\n ORDER BY \n");
  strcat(szTmp, Tb[TB_CAT].Prm[HT_NUM_SUB_VID].szTBFldName);
  strcat(szTmp, ", ");
  strcat(szTmp, Tb[TB_CAT].Prm[HT_NUM_TIP].szTBFldName);
  strcat(szTmp, ", ");
  strcat(szTmp, Tb[TB_CAT].Prm[HT_NUM_IMYA_TOV].szTBFldName);
  strcat(szTmp, ";");
#ifdef DEBAG
  printf("%s<br>\n",szTmp);
#endif
  return szTmp;
}


void SelectCat(char *szTmp)
{
  uint i,j, iOldCurRec,iAllRec;
  char *szTmp1;

  if (mysql_query(&mysql,szTmp)!=0)
    mysql_err(3);
  if (!(res = mysql_store_result(&mysql)))
    mysql_err(4);

  iOldCurRec=iCurRec;
  j=0;
  iAllRec=mysql_num_rows(res);

  while((row = mysql_fetch_row(res)))
  {
    if(j++<iOldCurRec)
      continue;
    if(j>(iOldCurRec+QNT_VIEW_REC))
        break;
    iCurRec++;

    printf(HT_CAT_TBL_HEAD);
    if(row[HT_NUM_IMYA_TOV]!=NULL)
      printf(HT_CAT_TBL_TV_NAME_w1p,row[HT_NUM_IMYA_TOV]);
    else
      printf(HT_CAT_TBL_TV_NAME_w1p,"");
    if(row[HT_NUM_MARKA]!=NULL)
      printf(HT_CAT_TBL_TV_DESC_w2p,Tb[TB_CAT].Prm[HT_NUM_MARKA].szFldName,row[HT_NUM_MARKA]);
    if(row[HT_NUM_ART]!=NULL)
      printf(HT_CAT_TBL_TV_DESC_w2p,Tb[TB_CAT].Prm[HT_NUM_ART].szFldName,row[HT_NUM_ART]);
    if(row[HT_NUM_HARAKT0]!=NULL)
      printf(HT_CAT_TBL_TV_DESC_w2p,Tb[TB_CAT].Prm[HT_NUM_HARAKT0].szFldName,row[HT_NUM_HARAKT0]);
    if(row[HT_NUM_HARAKT1]!=NULL)
      printf(HT_CAT_TBL_TV_DESC_w2p,Tb[TB_CAT].Prm[HT_NUM_HARAKT1].szFldName,row[HT_NUM_HARAKT1]);
    if(row[HT_NUM_HARAKT2]!=NULL)
      printf(HT_CAT_TBL_TV_DESC_w2p,Tb[TB_CAT].Prm[HT_NUM_HARAKT2].szFldName,row[HT_NUM_HARAKT2]);
    if(row[HT_NUM_HARAKT3]!=NULL)
      printf(HT_CAT_TBL_TV_DESC_w2p,Tb[TB_CAT].Prm[HT_NUM_HARAKT3].szFldName,row[HT_NUM_HARAKT3]);
    if(row[HT_NUM_OPIS_TOV]!=NULL){
      szTmp1=malloc(sizeof(HT_CAT_TBL_TV_DESC_w2p)+sizeof(Tb[TB_CAT].Prm[HT_NUM_OPIS_TOV].szFldName)+strlen(row[HT_NUM_OPIS_TOV])+1);
      sprintf(szTmp1,HT_CAT_TBL_TV_DESC_w2p,Tb[TB_CAT].Prm[HT_NUM_OPIS_TOV].szFldName,row[HT_NUM_OPIS_TOV]);
      PrintTxtInHTML(szTmp1);
      free(szTmp1);
    }
    if(row[HT_NUM_CENA]!=NULL)
      printf(HT_CAT_TBL_TV_COST_w2p,Tb[TB_CAT].Prm[HT_NUM_CENA].szFldName,row[HT_NUM_CENA]);
    printf(HT_CAT_TBL_MDL);
    if(row[HT_NUM_SLK_IZOBR]!=NULL)
      printf(HT_CAT_TBL_TV_IMG_w1p, row[HT_NUM_SLK_IZOBR]);
    else
      printf(HT_CAT_TBL_TV_IMG_w1p, "/image/form007.gif");
    printf(HT_CAT_TBL_TV_2BASK_w3p, CGI_PATH_BASK, HT_FLD_BASKET, row[HT_NUM_KOD]);
    printf(HT_CAT_TBL_FOOT);
  }

  if (!mysql_eof(res))
    mysql_err(5);
  mysql_free_result(res);

  if(iAllRec>QNT_VIEW_REC)
    PageSelectCat(iOldCurRec,iAllRec);
}

#endif