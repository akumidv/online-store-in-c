#if !defined __SETBASE_H
#define __SETBASE_H

/*#define   SQL_MENU_S_VID_TOV  "SELECT vid_tov FROM cat GROUP BY vid_tov;"*/
#define   SQL_MENU_S_VID_TOV_LNK_IMG  "SELECT lnk_img FROM harakt;"

void SelectTable(void)
{
  printf("<center><b>Сменить таблицу</b></center>\n");
  printf("<FORM METHOD=POST ACTION=\"%s\">\n",CGI_PATH);
  printf("<select name=HT_TABLE_SEL>\n");
  printf("<option value=%d SELECTED>База товаров</option>\n",TB_CAT);
  printf("<option value=%d>База заказчиков</option>\n",TB_USERS);
  printf("<option value=%d>База заказов</option>\n",TB_ORDERS);
  printf("<option value=%d>База характеристик</option>\n",TB_HARAKT);
  printf("<option value=%d>База корзины</option>\n",TB_BASKET);
  printf("</select><br>\n");
  printf("<input type=submit checked value=\"Выбрать\">\n</form>\n");
}



/* Vyvod formy HTML voda dly tablicy */
void FstSelect(uint iTbNum)
{
  uint i;

  printf("<center><b>Поиск данных в таблице</b></center>\n");
  printf("<FORM METHOD=POST ACTION=\"%s\">\n",CGI_PATH);
  printf("<input type=hidden name=HT_TABLE_SEL value=%d>\n",iTbNum);
  printf("<input type=hidden name=%s value=0>\n", HT_CUR_REC);
  printf(HT_IN_START);
  if(iTbNum!=TB_CAT){
    for (i=0; i<Tb[iTbNum].iQntFld; i++){
      if(Tb[iTbNum].Prm[i].iFldLen>50)
        printf(HT_INPUT_BIG,Tb[iTbNum].Prm[i].szFldName,Tb[iTbNum].Prm[i].szHTFldName,50,(abs(Tb[iTbNum].Prm[i].iFldLen/50)+1),"");
      else
        printf(HT_INPUT,Tb[iTbNum].Prm[i].szFldName,Tb[iTbNum].Prm[i].szHTFldName,"",Tb[iTbNum].Prm[i].iFldLen);
    }
  }
  else {
    for (i=0;i<TBQNTFLD_CAT;i++){
      switch (i) {
        case HT_NUM_VID_TOV:
          printf(HT_SB_TB_HD_w1p,Tb[TB_CAT].Prm[HT_NUM_VID_TOV].szFldName);
          printf(HT_SB_TB_MD_w0p);
          printf(HT_INP_SLCT_EXT_HD_w1p,Tb[TB_CAT].Prm[HT_NUM_VID_TOV].szHTFldName);
          printf(HT_INP_SLCT_EXT_DEF_w2p,HT_VL_USE_CPY,HT_VL_USE_CPY);
          if (mysql_query(&mysql,SQL_CAT_VID_TOV_SB)!=0) mysql_err(3);
          if (!(res = mysql_store_result(&mysql))) mysql_err(4);
          while((row = mysql_fetch_row(res))){
            if(row[0]!=NULL)
              printf(HT_INP_SLCT_w2p,row[0],row[0]);
          }
          if (!mysql_eof(res)) mysql_err(5);
          mysql_free_result(res);
          printf(HT_SB_TB_MD_w0p);
          printf(HT_INP_SLCT_EXT_w3p,Tb[TB_CAT].Prm[HT_NUM_VID_TOV].szHTFldName,"",Tb[TB_CAT].Prm[HT_NUM_VID_TOV].iFldLen);
          printf(HT_INP_SLCT_FT_w0p);
	  break;
        case HT_NUM_SUB_VID:
          printf(HT_SB_TB_HD_w1p,Tb[TB_CAT].Prm[HT_NUM_SUB_VID].szFldName);
          printf(HT_SB_TB_MD_w0p);
          printf(HT_INP_SLCT_EXT_HD_w1p,Tb[TB_CAT].Prm[HT_NUM_SUB_VID].szHTFldName);
          printf(HT_INP_SLCT_EXT_DEF_w2p,HT_VL_USE_CPY,HT_VL_USE_CPY);
          if (mysql_query(&mysql,SQL_CAT_SUB_TOV_SB)!=0) mysql_err(3);
          if (!(res = mysql_store_result(&mysql))) mysql_err(4);
          while((row = mysql_fetch_row(res))){
            if(row[0]!=NULL)
              printf(HT_INP_SLCT_w2p,row[0],row[0]);
          }
          if (!mysql_eof(res)) mysql_err(5);
          mysql_free_result(res);
          printf(HT_SB_TB_MD_w0p);
          printf(HT_INP_SLCT_EXT_w3p,Tb[TB_CAT].Prm[HT_NUM_SUB_VID].szHTFldName,"",Tb[TB_CAT].Prm[HT_NUM_SUB_VID].iFldLen);	  
          printf(HT_INP_SLCT_FT_w0p);
	  break;
        case HT_NUM_TIP:
          printf(HT_SB_TB_HD_w1p,Tb[TB_CAT].Prm[i].szFldName);
          printf(HT_SB_TB_MD_w0p);
          printf(HT_INP_SLCT_EXT_HD_w1p,Tb[TB_CAT].Prm[i].szHTFldName);
          printf(HT_INP_SLCT_EXT_DEF_w2p,HT_VL_USE_CPY,HT_VL_USE_CPY);
          if (mysql_query(&mysql,SQL_CAT_TIP_SB)!=0) mysql_err(3);
          if (!(res = mysql_store_result(&mysql))) mysql_err(4);
          while((row = mysql_fetch_row(res))){
            if(row[0]!=NULL)
              printf(HT_INP_SLCT_w2p,row[0],row[0]);
          }
          if (!mysql_eof(res)) mysql_err(5);
          mysql_free_result(res);
          printf(HT_SB_TB_MD_w0p);
          printf(HT_INP_SLCT_EXT_w3p,Tb[TB_CAT].Prm[i].szHTFldName,"",Tb[TB_CAT].Prm[i].iFldLen);
          printf(HT_INP_SLCT_FT_w0p);
	  break;
        case HT_NUM_HARAKT0:
          printf(HT_SB_TB_HD_w1p,Tb[TB_CAT].Prm[i].szFldName);
          printf(HT_SB_TB_MD_w0p);
          printf(HT_INP_SLCT_EXT_HD_w1p,Tb[TB_CAT].Prm[i].szHTFldName);
          printf(HT_INP_SLCT_EXT_DEF_w2p,HT_VL_USE_CPY,HT_VL_USE_CPY);
          if (mysql_query(&mysql,SQL_CAT_HRKT0_SB)!=0) mysql_err(3);
          if (!(res = mysql_store_result(&mysql))) mysql_err(4);
          while((row = mysql_fetch_row(res))){
            if(row[0]!=NULL)
              printf(HT_INP_SLCT_w2p,row[0],row[0]);
          }
          if (!mysql_eof(res)) mysql_err(5);
          mysql_free_result(res);
          printf(HT_SB_TB_MD_w0p);
          printf(HT_INP_SLCT_EXT_w3p,Tb[TB_CAT].Prm[i].szHTFldName,"",Tb[TB_CAT].Prm[i].iFldLen);
          printf(HT_INP_SLCT_FT_w0p);
	  break;
        case HT_NUM_VIDIM:
          printf(HT_SB_TB_HD_w1p,Tb[TB_CAT].Prm[HT_NUM_VIDIM].szFldName);
          printf(HT_SB_TB_MD_w0p);
          printf(HT_INP_SLCT_EXT_HD_w1p,Tb[TB_CAT].Prm[HT_NUM_VIDIM].szHTFldName);
          printf(HT_INP_SLCT_EXT_DEF_w2p,HT_VL_USE_CPY,HT_VL_USE_CPY);
          printf(HT_INP_SLCT_w2p,"0","Видимый");
          printf(HT_INP_SLCT_w2p,"1","Невидимый");
          printf(HT_SB_TB_MD_w0p);
          printf(HT_INP_HDN_EXT_w2p,Tb[TB_CAT].Prm[HT_NUM_VIDIM].szHTFldName,"");
          printf(HT_INP_SLCT_FT_w0p);
	  break;
        default:
          if(Tb[TB_CAT].Prm[i].iFldLen>50)
            printf(HT_INPUT_BIG,Tb[TB_CAT].Prm[i].szFldName,Tb[TB_CAT].Prm[i].szHTFldName,50,(abs(Tb[TB_CAT].Prm[i].iFldLen/50)+1),"");
          else
            printf(HT_INPUT,Tb[TB_CAT].Prm[i].szFldName,Tb[TB_CAT].Prm[i].szHTFldName,"",Tb[TB_CAT].Prm[i].iFldLen);
	  break;
      }
    }   
  }
  printf(HT_IN_END);
  printf("<input type=radio name=HT_OPER value=%d CHECKED>SELECT\n",TBOP_SELECT);
  printf("<input type=radio name=HT_OPER value=%d>INSERT<br>\n",TBOP_INSERT);
  printf("<input type=submit checked value=\"Выполнить\">\n</form>\n");
  printf("<hr>\n");
  SelectTable();
}

/* Vyvod formy HTML voda dly tablicy */
void NextSelect(uint iTbNum)
{
  uint i;

  printf("<FORM METHOD=POST ACTION=\"%s\">\n",CGI_PATH);
  printf("<input type=hidden name=HT_TABLE_SEL value=%d>\n",iTbNum);
  printf("<input type=hidden name=%s value=%d>\n", HT_CUR_REC, iCurRec);
  printf("<input type=hidden name=HT_OPER value=%d>\n",TBOP_SELECT);
  for (i=0; i<Tb[iTbNum].iQntFld; i++)
  {
    if(Tb[iTbNum].Prm[i].szHTFldValue==NULL)
      printf(HT_INPUT_HIDDEN, Tb[iTbNum].Prm[i].szHTFldName, "");
    else
      printf(HT_INPUT_HIDDEN, Tb[iTbNum].Prm[i].szHTFldName, Tb[iTbNum].Prm[i].szHTFldValue);
  }
  printf("<input type=submit checked value=\"Следующая страница\">\n</form>\n");
  printf("<hr>\n");
}



void Select(char *szTmp, uint iTbNum)
{
  uint i,j,iOldCurRec;

  MYSQL_RES *resV;
  MYSQL_RES *resS;
  MYSQL_RES *resT;
  MYSQL_RES *resH;
  MYSQL_ROW rowS;

  if (mysql_query(&mysql,SQL_CAT_VID_TOV_SB)!=0) mysql_err(3);
  if (!(resV = mysql_store_result(&mysql))) mysql_err(4);
  if (mysql_query(&mysql,SQL_CAT_SUB_TOV_SB)!=0) mysql_err(3);
  if (!(resS = mysql_store_result(&mysql))) mysql_err(4);
  if (mysql_query(&mysql,SQL_CAT_TIP_SB)!=0) mysql_err(3);
  if (!(resT = mysql_store_result(&mysql))) mysql_err(4);
  if (mysql_query(&mysql,SQL_CAT_HRKT0_SB)!=0) mysql_err(3);
  if (!(resH = mysql_store_result(&mysql))) mysql_err(4);
 


  if (mysql_query(&mysql,szTmp)!=0)
    mysql_err(3);
  if (!(res = mysql_store_result(&mysql))) mysql_err(4);
  iOldCurRec=iCurRec;
  j=0;
  while((row = mysql_fetch_row(res)))
  {
    if(j++<iOldCurRec)
      continue;
    if(j>iOldCurRec+QNT_VIEW_REC)
        break;
    iCurRec++;
    printf("<form METHOD=POST ACTION=\"%s\">\n",CGI_PATH);
    printf("<input type=hidden name=HT_TABLE_SEL value=%d>\n",iTbNum);
    printf("<input type=hidden name=%s value=0>\n", HT_CUR_REC);
    /*Delayem ne izmenyaemuyu kopiyu KODa dlya DELETE, UPDATE*/
    if(row[0]==NULL)
      printf("<input type=hidden name=%s value=\"\">\n", Tb[iTbNum].szHTFldKeyCpy);
    else
      printf("<input type=hidden name=%s value=\"%s\">\n", Tb[iTbNum].szHTFldKeyCpy, row[0]);
    printf(HT_IN_START);
    for (i=0;i<mysql_num_fields(res);i++){
     if(iTbNum!=TB_CAT){
      if(row[i]==NULL)
      {
        if(Tb[iTbNum].Prm[i].iFldLen>50)
          printf(HT_INPUT_BIG,Tb[iTbNum].Prm[i].szFldName,Tb[iTbNum].Prm[i].szHTFldName,50,(abs(Tb[iTbNum].Prm[i].iFldLen/50)+1),"");
        else
          printf(HT_INPUT,Tb[iTbNum].Prm[i].szFldName,Tb[iTbNum].Prm[i].szHTFldName,"",Tb[iTbNum].Prm[i].iFldLen);
        printf(HT_INPUT_HIDDEN, Tb[iTbNum].Prm[i].szHTFldNameCpy, "");
      }
      else
      {
        if(Tb[iTbNum].Prm[i].iFldLen>50)
          printf(HT_INPUT_BIG,Tb[iTbNum].Prm[i].szFldName,Tb[iTbNum].Prm[i].szHTFldName,50,(abs(Tb[iTbNum].Prm[i].iFldLen/50)+1),row[i]);
        else
          printf(HT_INPUT,Tb[iTbNum].Prm[i].szFldName,Tb[iTbNum].Prm[i].szHTFldName,row[i],Tb[iTbNum].Prm[i].iFldLen);
        printf(HT_INPUT_HIDDEN, Tb[iTbNum].Prm[i].szHTFldNameCpy, Tb[iTbNum].Prm[i].szHTFldValue);
      }
     }
     else {
        switch (i) {
          case HT_NUM_VID_TOV:
            printf(HT_SB_TB_HD_w1p,Tb[TB_CAT].Prm[HT_NUM_VID_TOV].szFldName);
            printf(HT_SB_TB_MD_w0p);
            printf(HT_INP_SLCT_EXT_HD_w1p,Tb[TB_CAT].Prm[HT_NUM_VID_TOV].szHTFldName);
            printf(HT_INP_SLCT_EXT_DEF_w2p,HT_VL_USE_CPY,HT_VL_USE_CPY);
            while((rowS = mysql_fetch_row(resV))){
              if(rowS[0]!=NULL)
                printf(HT_INP_SLCT_w2p,rowS[0],rowS[0]);
            }
            if (!mysql_eof(resS)) mysql_err(5);
            printf(HT_SB_TB_MD_w0p);
            if(row[i]==NULL){
              printf(HT_INP_SLCT_EXT_w3p,Tb[TB_CAT].Prm[HT_NUM_VID_TOV].szHTFldName,"",Tb[TB_CAT].Prm[HT_NUM_VID_TOV].iFldLen);
	      printf(HT_INPUT_HIDDEN, Tb[iTbNum].Prm[i].szHTFldNameCpy, "");
	    }
            else {
              printf(HT_INP_SLCT_EXT_w3p,Tb[TB_CAT].Prm[HT_NUM_VID_TOV].szHTFldName,row[i],Tb[TB_CAT].Prm[HT_NUM_VID_TOV].iFldLen);
              printf(HT_INPUT_HIDDEN, Tb[iTbNum].Prm[i].szHTFldNameCpy, Tb[iTbNum].Prm[i].szHTFldValue);
	    }
            printf(HT_INP_SLCT_FT_w0p);
  	    break;
          case HT_NUM_SUB_VID:
            printf(HT_SB_TB_HD_w1p,Tb[TB_CAT].Prm[HT_NUM_SUB_VID].szFldName);
            printf(HT_SB_TB_MD_w0p);
            printf(HT_INP_SLCT_EXT_HD_w1p,Tb[TB_CAT].Prm[HT_NUM_SUB_VID].szHTFldName);
            printf(HT_INP_SLCT_EXT_DEF_w2p,HT_VL_USE_CPY,HT_VL_USE_CPY);
            while((rowS = mysql_fetch_row(resS))){
              if(rowS[0]!=NULL)
                printf(HT_INP_SLCT_w2p,rowS[0],rowS[0]);
            }
            if (!mysql_eof(resS)) mysql_err(5);
            printf(HT_SB_TB_MD_w0p);
            if(row[i]==NULL){
              printf(HT_INP_SLCT_EXT_w3p,Tb[TB_CAT].Prm[HT_NUM_SUB_VID].szHTFldName,"",Tb[TB_CAT].Prm[HT_NUM_SUB_VID].iFldLen);
	      printf(HT_INPUT_HIDDEN, Tb[iTbNum].Prm[i].szHTFldNameCpy, "");
	    }
	    else {
              printf(HT_INP_SLCT_EXT_w3p,Tb[TB_CAT].Prm[HT_NUM_SUB_VID].szHTFldName,row[i],Tb[TB_CAT].Prm[HT_NUM_SUB_VID].iFldLen);
              printf(HT_INPUT_HIDDEN, Tb[iTbNum].Prm[i].szHTFldNameCpy, Tb[iTbNum].Prm[i].szHTFldValue);
	    }
            printf(HT_INP_SLCT_FT_w0p);	    
  	  break;
          case HT_NUM_TIP:
            printf(HT_SB_TB_HD_w1p,Tb[TB_CAT].Prm[i].szFldName);
            printf(HT_SB_TB_MD_w0p);
            printf(HT_INP_SLCT_EXT_HD_w1p,Tb[TB_CAT].Prm[i].szHTFldName);
            printf(HT_INP_SLCT_EXT_DEF_w2p,HT_VL_USE_CPY,HT_VL_USE_CPY);
            while((rowS = mysql_fetch_row(resT))){
              if(rowS[0]!=NULL)
                printf(HT_INP_SLCT_w2p,rowS[0],rowS[0]);
            }
            if (!mysql_eof(resS)) mysql_err(5);
            printf(HT_SB_TB_MD_w0p);
            if(row[i]==NULL){
              printf(HT_INP_SLCT_EXT_w3p,Tb[TB_CAT].Prm[i].szHTFldName,"",Tb[TB_CAT].Prm[i].iFldLen);
	      printf(HT_INPUT_HIDDEN, Tb[iTbNum].Prm[i].szHTFldNameCpy, "");
	    }
	    else {
              printf(HT_INP_SLCT_EXT_w3p,Tb[TB_CAT].Prm[i].szHTFldName,row[i],Tb[TB_CAT].Prm[i].iFldLen);
              printf(HT_INPUT_HIDDEN, Tb[iTbNum].Prm[i].szHTFldNameCpy, Tb[iTbNum].Prm[i].szHTFldValue);
	    }
            printf(HT_INP_SLCT_FT_w0p);	    
  	  break;
          case HT_NUM_HARAKT0:
            printf(HT_SB_TB_HD_w1p,Tb[TB_CAT].Prm[i].szFldName);
            printf(HT_SB_TB_MD_w0p);
            printf(HT_INP_SLCT_EXT_HD_w1p,Tb[TB_CAT].Prm[i].szHTFldName);
            printf(HT_INP_SLCT_EXT_DEF_w2p,HT_VL_USE_CPY,HT_VL_USE_CPY);
            while((rowS = mysql_fetch_row(resH))){
              if(rowS[0]!=NULL)
                printf(HT_INP_SLCT_w2p,rowS[0],rowS[0]);
            }
            if (!mysql_eof(resS)) mysql_err(5);
            printf(HT_SB_TB_MD_w0p);
            if(row[i]==NULL){
              printf(HT_INP_SLCT_EXT_w3p,Tb[TB_CAT].Prm[i].szHTFldName,"",Tb[TB_CAT].Prm[i].iFldLen);
	      printf(HT_INPUT_HIDDEN, Tb[iTbNum].Prm[i].szHTFldNameCpy, "");
	    }
	    else {
              printf(HT_INP_SLCT_EXT_w3p,Tb[TB_CAT].Prm[i].szHTFldName,row[i],Tb[TB_CAT].Prm[i].iFldLen);
              printf(HT_INPUT_HIDDEN, Tb[iTbNum].Prm[i].szHTFldNameCpy, Tb[iTbNum].Prm[i].szHTFldValue);
	    }
            printf(HT_INP_SLCT_FT_w0p);	    
  	  break;
          case HT_NUM_VIDIM:
            printf(HT_SB_TB_HD_w1p,Tb[TB_CAT].Prm[HT_NUM_VIDIM].szFldName);
            printf(HT_SB_TB_MD_w0p);
            printf(HT_INP_SLCT_EXT_HD_w1p,Tb[TB_CAT].Prm[HT_NUM_VIDIM].szHTFldName);
            printf(HT_INP_SLCT_EXT_DEF_w2p,HT_VL_USE_CPY,HT_VL_USE_CPY);
	    if(!strcmp(row[i],"0")) {
              printf(HT_INP_SLCT_w2p,HT_VL_USE_CPY,HT_VL_USE_CPY);
	      printf(HT_INP_SLCT_EXT_DEF_w2p,"0","Видимый");
              printf(HT_INP_SLCT_w2p,"1","Невидимый");
	    }
	    else {
              printf(HT_INP_SLCT_w2p,HT_VL_USE_CPY,HT_VL_USE_CPY);
	      printf(HT_INP_SLCT_w2p,"0","Видимый");
              printf(HT_INP_SLCT_EXT_DEF_w2p,"1","Невидимый");
	    }
            printf(HT_SB_TB_MD_w0p);
            printf(HT_INP_HDN_EXT_w2p,Tb[TB_CAT].Prm[HT_NUM_VIDIM].szHTFldName,"");
            printf(HT_INPUT_HIDDEN, Tb[iTbNum].Prm[i].szHTFldNameCpy, Tb[iTbNum].Prm[i].szHTFldValue);
            printf(HT_INP_SLCT_FT_w0p);
    	  break;
          default:
            if(row[i]==NULL) {
              if(Tb[iTbNum].Prm[i].iFldLen>50)
                printf(HT_INPUT_BIG,Tb[iTbNum].Prm[i].szFldName,Tb[iTbNum].Prm[i].szHTFldName,50,(abs(Tb[iTbNum].Prm[i].iFldLen/50)+1),"");
              else
                printf(HT_INPUT,Tb[iTbNum].Prm[i].szFldName,Tb[iTbNum].Prm[i].szHTFldName,"",Tb[iTbNum].Prm[i].iFldLen);
              printf(HT_INPUT_HIDDEN, Tb[iTbNum].Prm[i].szHTFldNameCpy, "");
            }
            else {
              if(Tb[iTbNum].Prm[i].iFldLen>50)
                printf(HT_INPUT_BIG,Tb[iTbNum].Prm[i].szFldName,Tb[iTbNum].Prm[i].szHTFldName,50,(abs(Tb[iTbNum].Prm[i].iFldLen/50)+1),row[i]);
              else
                printf(HT_INPUT,Tb[iTbNum].Prm[i].szFldName,Tb[iTbNum].Prm[i].szHTFldName,row[i],Tb[iTbNum].Prm[i].iFldLen);
              printf(HT_INPUT_HIDDEN, Tb[iTbNum].Prm[i].szHTFldNameCpy, Tb[iTbNum].Prm[i].szHTFldValue);
            }
    	    break;
        }
      }   
    }
    mysql_free_result(resV);
    mysql_free_result(resS);
    mysql_free_result(resT);
    mysql_free_result(resH);
    
    printf(HT_IN_END);
    printf("<input type=radio name=HT_OPER value=%d CHECKED>SELECT\n",TBOP_SELECT);
    printf("<input type=radio name=HT_OPER value=%d>INSERT\n",TBOP_INSERT);
    printf("<input type=radio name=HT_OPER value=%d>UPDATE\n",TBOP_UPDATE);
    printf("<input type=radio name=HT_OPER value=%d>DELETE<br>\n",TBOP_DELETE);
/*    printf("<input type=image src=\"%s\">\n</form>\n",PATH_IMG_ST_BASE);*/
    printf("<input type=submit checked value=\"Выполнить\">\n</form>\n");
    switch(iTbNum)
    {
      case TB_CAT:
        printf("Соответствующая запись из Базы заказов",CGI_PATH);
        printf("<form METHOD=POST ACTION=\"%s\">\n",CGI_PATH);
        printf("<input type=hidden name=HT_TABLE_SEL value=%d>\n",TB_ORDERS);
        printf("<input type=hidden name=HT_OPER value=%d>\n",TBOP_SELECT);
        if(row[FLD_CAT_KOD]==NULL)
          printf(HT_INPUT_HIDDEN, Tb[TB_ORDERS].Prm[FLD_ORD_KOD].szHTFldName, "");
        else
          printf(HT_INPUT_HIDDEN, Tb[TB_ORDERS].Prm[FLD_ORD_KOD].szHTFldName, row[FLD_CAT_KOD]);
        printf("<input type=submit checked value=\"Получить\">\n</form><br>\n");

        printf("Соответствующая запись и базы характеристик",CGI_PATH);
        printf("<form METHOD=POST ACTION=\"%s\">\n",CGI_PATH);
        printf("<input type=hidden name=HT_TABLE_SEL value=%d>\n",TB_HARAKT);
        printf("<input type=hidden name=HT_OPER value=%d>\n",TBOP_SELECT);
        if(row[FLD_CAT_VIDTOV]==NULL)
          printf(HT_INPUT_HIDDEN, Tb[TB_HARAKT].Prm[FLD_HAR_VIDTOV].szHTFldName, "");
        else
          printf(HT_INPUT_HIDDEN, Tb[TB_HARAKT].Prm[FLD_HAR_VIDTOV].szHTFldName, row[FLD_CAT_VIDTOV]);
        printf("<input type=submit checked value=\"Получить\">\n</form><br>\n");
        break;
      case TB_USERS:
        printf("Соответствующая запись из базы заказов",CGI_PATH);
        printf("<form METHOD=POST ACTION=\"%s\">\n",CGI_PATH);
        printf("<input type=hidden name=HT_TABLE_SEL value=%d>\n",TB_ORDERS);
        printf("<input type=hidden name=HT_OPER value=%d>\n",TBOP_SELECT);

        if(row[FLD_USR_EMAIL]==NULL)
          printf(HT_INPUT_HIDDEN, Tb[TB_ORDERS].Prm[FLD_ORD_EMAIL].szHTFldName, "");
        else
          printf(HT_INPUT_HIDDEN, Tb[TB_ORDERS].Prm[FLD_ORD_EMAIL].szHTFldName, row[FLD_USR_EMAIL]);
        printf("<input type=submit checked value=\"Получить\">\n</form><br>\n");
        break;

      case TB_ORDERS:
        printf("Соответствующая запись из базы заказчиков",CGI_PATH);
        printf("<form METHOD=POST ACTION=\"%s\">\n",CGI_PATH);
        printf("<input type=hidden name=HT_TABLE_SEL value=%d>\n",TB_USERS);
        printf("<input type=hidden name=HT_OPER value=%d>\n",TBOP_SELECT);
        if(row[FLD_ORD_EMAIL]==NULL)
          printf(HT_INPUT_HIDDEN, Tb[TB_USERS].Prm[FLD_USR_EMAIL].szHTFldName, "");
        else
          printf(HT_INPUT_HIDDEN, Tb[TB_USERS].Prm[FLD_USR_EMAIL].szHTFldName, row[FLD_ORD_EMAIL]);
        printf("<input type=submit checked value=\"Получить\">\n</form><br>\n");

        printf("Соответствующая запись из базы товаров",CGI_PATH);
        printf("<form METHOD=POST ACTION=\"%s\">\n",CGI_PATH);
        printf("<input type=hidden name=HT_TABLE_SEL value=%d>\n",TB_CAT);
        printf("<input type=hidden name=HT_OPER value=%d>\n",TBOP_SELECT);
        if(row[FLD_ORD_KOD]==NULL)
          printf(HT_INPUT_HIDDEN, Tb[TB_CAT].Prm[FLD_CAT_KOD].szHTFldName, "");
        else
          printf(HT_INPUT_HIDDEN, Tb[TB_CAT].Prm[FLD_CAT_KOD].szHTFldName, row[FLD_ORD_KOD]);
        printf("<input type=submit checked value=\"Получить\">\n</form><br>\n");
        break;

      case TB_HARAKT:
        printf("Соответствующая запись из базы товаров",CGI_PATH);
        printf("<form METHOD=POST ACTION=\"%s\">\n",CGI_PATH);
        printf("<input type=hidden name=HT_TABLE_SEL value=%d>\n",TB_CAT);
        printf("<input type=hidden name=HT_OPER value=%d>\n",TBOP_SELECT);
        if(row[FLD_HAR_VIDTOV]==NULL)
          printf(HT_INPUT_HIDDEN, Tb[TB_CAT].Prm[FLD_CAT_VIDTOV].szHTFldName, "");
        else
          printf(HT_INPUT_HIDDEN, Tb[TB_CAT].Prm[FLD_CAT_VIDTOV].szHTFldName, row[FLD_HAR_VIDTOV]);
        printf("<input type=submit checked value=\"Получить\">\n</form><br>\n");
        break;
    }
    printf("<hr><br>\n");
  }
  if (!mysql_eof(res)) mysql_err(5);
  mysql_free_result(res);

  if(iCurRec>(iOldCurRec+QNT_VIEW_REC-1))
    NextSelect(iTbNum);
  FstSelect(iTbNum);
}

char *SetDeleteStr(uint iTbNum)
{
  char *szTmp;

  szTmp=malloc(100);
  if(szTmp==NULL)
    http_err("Error no memory for MySQL DELETE!");
  strcpy(szTmp,"DELETE \n");
  strcat(szTmp, "\n FROM \n");
  strcat(szTmp, Tb[iTbNum].szName);
  strcat(szTmp, "\n WHERE \n");
  strcat(szTmp, Tb[iTbNum].Prm[0].szTBFldName);
  if(strlen(GetQueryValue(szQS,Tb[iTbNum].szHTFldKeyCpy))>0)
  {
    strcat(szTmp, " = \"");
    strcat(szTmp, GetQueryValue(szQS,Tb[iTbNum].szHTFldKeyCpy));
    strcat(szTmp, "\"");
  }
  else
    strcat(szTmp, " IS NULL");
#ifdef DEBAG
  printf("%s<br>\n",szTmp);
#endif
  return szTmp;
}


#endif