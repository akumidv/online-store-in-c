#if !defined __BASKET_H
#define __BASKET_H

#define   HT_BSK_VAL_VER    "VERIFYBSK"
#define   HT_BSK_VAL_UPD    "UPDATEBSK"
#define   HT_BSK_VAL_PUT    "PUTBSK"

char blIsOrder=0;

char **szOrdInBask;/*Razdelennie element korziny*/
uint iQntOrd=0;/*Kol. elem korziny*/

#define HT_BSK_TBL_HEAD "\n\n\
<table cellspacing=3 cellpadding=2 border=0 width=100%%>\n\
  <tr>\n\
    <td bgcolor=#f0f0f0 width=40 class=yacheika2>N</td>\n\
    <td bgcolor=#f0f0f0 width=60%% class=yacheika2>Наименование товара/Услуги:</td>\n\
    <td bgcolor=#f0f0f0 width=90 align=\"center\" class=yacheika3>Цена:</td>\n\
    <td bgcolor=#f0f0f0 width=70 align=\"center\" class=yacheika3>Кол-во:</td>\n\
    <td bgcolor=#f0f0f0 align=\"center\" class=yacheika3>Удалить</td>\n\
  </tr>\n"

#define HT_BSK_TBL_N "\
  <tr>\n\
    <td bgcolor=#f0f0f0 width=40>%d.</td>\n"
#define HT_BSK_TBL_NAME "\
    <td bgcolor=#f0f0f0 width=60%%>%s</td>\n"
#define HT_BSK_TBL_COST "\
    <td bgcolor=#f0f0f0 width=90 align=\"center\">%s</td>\n"
#define HT_BSK_TBL_QNT "\
    <td bgcolor=#f0f0f0 align=\"center\">\n\
      <table cellspacing=0 cellpadding=1 border=0>\n\
        <tr>\n\
          <td bgcolor=#808080>\n\
            <input type=text name=\"%s\" value=\"%s\" size=3>\n\
          </td>\n\
        </tr>\n\
        </table>\n\
    </td>\n"

#define HT_BSK_TBL_DEL "\
    <td bgcolor=#f0f0f0 align=\"center\">\n\
      <input type=checkbox name=\"del%d\" value=\"%s\">\n\
    </td>\n\
  </tr>\n"

#define HT_BSK_TBL_SUM_w1p "<tr><td colspan=4 align=\"right\">Всего(у.е.):</td>\n\
<td>%s<td></tr>\n"

#define HT_BSK_TBL_PUT "\
  <tr>\n\
    <td colspan=5 align=\"right\"><input type=image src=\"%s\" border=0 alt=\"Обновить\"></td>\n\
  </tr>\n"

#define HT_BSK_TBL_FOOT "</table>\n"
/*
#define HT_BSK_TBL_HR "<hr color=#000000 width=100%%>\n\n"
*/
#define HT_ORD_STAT_SET   "1"

/*CGI_PATH_ORDER, HT_FLD_BASKET, szBasket, HT_FLD_ORDER, HT_BSK_VAL_VER, 
  Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].szHTFldName,
  Tb[TB_USERS].Prm[HT_NUM_USR_PASSWD].szHTFldName,*/

#define HT_ORD_VRF_FRM_w7p "<center><FORM action=%s method=post>\n\
<INPUT name=%s type=hidden value=%s>\n\
<INPUT name=%s type=hidden value=%s>\n\
<table cellspacing=0 cellpadding=0 width=176 border=0><tr>\
<td width=10 height=21><img src=\"/image/reg1000.gif\" width=10 height=21 border=0></td>\
<td width=12 height=21><img src=\"/image/reg1001.gif\" width=12 height=21 border=0></td>\
<td width=141 height=21 align=\"center\" class=size><b>СИСТЕМА ЗАКАЗОВ</b></td>\
<td width=13 height=21></td></tr>\
<tr><td width=10 height=24><img src=\"/image/reg1004.gif\" width=10 height=24 border=0></td>\
<td colspan=2 width=153 height=24><INPUT name=%s class=input></td>\
<td width=13 height=24></td></tr>\
<tr><td width=10 height=20><img src=\"/image/reg1008.gif\" width=10 height=20 border=0></td>\
<td width=12 height=20><img src=\"/image/reg1009.gif\" width=12 height=20 border=0></td>\
<td width=141 height=20 align=\"right\" class=size>E-Mail</td>\
<td width=13 height=20></td></tr>\
<tr><td width=10 height=24><img src=\"/image/reg1012.gif\" width=10 height=24 border=0></td>\
<td colspan=2 width=153 height=24><INPUT name=%s type=password class=input></td>\
<td width=13 height=24><img src=\"/image/reg1015.gif\" width=13 height=24 border=0></td></tr>\
<tr><td width=10 height=21><img src=\"/image/reg1016.gif\" width=10 height=21 border=0></td>\
<td width=12 height=21><img src=\"/image/reg1017.gif\" width=12 height=21 border=0></td>\
<td width=141 height=21 align=\"right\" class=size>Пароль</td>\
<td width=13 height=21><img src=\"/image/reg1019.gif\" width=13 height=21 border=0></td></tr>\
<tr><td width=10 height=21></td>\
<td colspan=3 align=\"right\" width=166>\
<table cellspacing=0 cellpadding=0 border=0><tr>\
<td width=10 height=12></td>\
<td width=130 height=12></td>\
<td width=36 height=12><img src=\"/image/vxod005.gif\" width=36 height=12 border=0></td></tr>\
<tr><td width=10 height=16></td>\
<td><INPUT src=\"/image/vxod007.gif\" type=image border=0 alt=\"Войти в систему заказов\"></td>\
<td width=36 height=16><img src=\"/image/vxod008.gif\" width=36 height=16 border=0></td></tr>\
</table></td></tr></table>\n</form></center>\n"

#define HT_REG_NEW_w1p "<center><table cellspacing=0 cellpadding=0  width=448 border=0>\n\
 <tr><td width=35 height=14></td>\n\
  <td><IMG SRC=\"/image/in001.gif\" width=104 height=14 border=0></td>\n\
  <td width=32 height=14></td>\n\
  <td width=118 height=14></td>\n\
  <td width=113 height=14></td>\n\
  <td width=46 height=14></td></tr>\n\
 <tr><td><IMG SRC=\"/image/in006.gif\" width=35 height=50 border=0></td>\n\
  <td><IMG SRC=\"/image/in007.gif\" width=104 height=50 border=0></td>\n\
  <td><IMG SRC=\"/image/in008.gif\" width=32 height=50 border=0></td>\n\
  <td width=118 height=50></td>\n\
  <td width=113 height=50></td>\n\
  <td width=46 height=50></td></tr>\n\
 <tr><td><IMG SRC=\"/image/in012.gif\" width=35 height=35 border=0></td>\n\
  <td><IMG SRC=\"/image/in013.gif\" width=104 height=35 border=0></td>\n\
  <td><IMG SRC=\"/image/in014.gif\" width=32 height=35 border=0></td>\n\
  <td><IMG SRC=\"/image/in015.gif\" width=118 height=35 border=0></td>\n\
  <td><IMG SRC=\"/image/in016.gif\" width=113 height=35 border=0></td>\n\
  <td><IMG SRC=\"/image/in017.gif\" width=46 height=35 border=0></td></tr>\n\
 <tr><td><IMG SRC=\"/image/in018.gif\" width=35 height=13 border=0></td>\n\
  <td><IMG SRC=\"/image/in019.gif\" width=104 height=13 border=0></td>\n\
  <td><IMG SRC=\"/image/in020.gif\" width=32 height=13 border=0></td>\n\
  <td width=118 height=13></td>\n\
  <td><a href=\"%s\"><IMG SRC=\"/image/in022.gif\" width=113 height=13 border=0 alt=\"Регистрация нового пользователя\"></a></td>\n\
  <td><IMG SRC=\"/image/in023.gif\" width=46 height=13 border=0></td> </tr>\n\
 <tr><td><IMG SRC = \"/image/in024.gif\" width=35 height=45 border=0></td>\n\
  <td><IMG SRC=\"/image/in025.gif\" width=104 height=45 border=0></td>\n\
  <td><IMG SRC=\"/image/in026.gif\" width=32 height=45 border=0></td>\n\
  <td width=118 height=45></td>\n\
  <td width=113 height=45></td>\n\
  <td width=46 height=45></td></tr>\n\
 <tr><td width=35 height=14></td>\n\
  <td><IMG src=\"/image/in031.gif\" width=104 height=14 border=0></td>\n\
  <td width=32 height=14></td>\n\
  <td width=118 height=14></td>\n\
  <td width=113 height=14></td>\n\
  <td width=46 height=14></td>\n\
  </tr></table></center>\n"


void BasketInOrder(){
  char *szCpyBask;
  uint iLen;
  char blIsTrue;
  uint i,j;

  iLen=strlen(szBasket);
  if(iLen==0)
    return;
  szCpyBask=malloc(iLen+1);
  strcpy(szCpyBask,szBasket);
  for(i=0;i<iLen;i++){
    if(szCpyBask[i]==','){
      szCpyBask[i]='\0';
      iQntOrd++;
    }
  }
  iQntOrd++;
  szOrdInBask=malloc(sizeof(char *)*iQntOrd);
  j=0;
  blIsTrue=1;
  for(i=0;i<iLen;i++){
    if(blIsTrue){
      szOrdInBask[j++]=&szCpyBask[i];
      blIsTrue=0;
    }
    else{
      if(szCpyBask[i]=='\0')
        blIsTrue=1;
    }
  }
}


void InsertTmpBask(void)
{
  char *szTmp;
  uint i;
  char *szTmp1, *szTmp2;

  szTmp=getIdentif();
  if(szTmp!=NULL)
  {
    Tb[TB_BASKET].Prm[HT_NUM_BSK_IP].szHTFldValue=malloc(strlen(szTmp)+1);
    if(Tb[TB_BASKET].Prm[HT_NUM_BSK_IP].szHTFldValue!=NULL)
      strcpy(Tb[TB_BASKET].Prm[HT_NUM_BSK_IP].szHTFldValue,szTmp);
  }
  else Tb[TB_BASKET].Prm[HT_NUM_BSK_IP].szHTFldValue="0";
  if (mysql_query(&mysql,"SELECT CURDATE();")!=0)
    mysql_err(3);
  if (!(res = mysql_store_result(&mysql))) mysql_err(4);
  if(row = mysql_fetch_row(res))
  {
/* Poluchit' tekuschuyu datu servera SQL*/
    Tb[TB_BASKET].Prm[HT_NUM_BSK_DATE_REG].szHTFldValue=malloc(strlen(row[0])+1);
    if(Tb[TB_BASKET].Prm[HT_NUM_BSK_DATE_REG].szHTFldValue!=NULL)
      strcpy(Tb[TB_BASKET].Prm[HT_NUM_BSK_DATE_REG].szHTFldValue,row[0]);
    else Tb[TB_BASKET].Prm[HT_NUM_BSK_DATE_REG].szHTFldValue="0000-00-00";
  }

  szTmp=malloc(100+strlen(szBasket)+strlen(TBVWFLD_BASKET)+
              Tb[TB_BASKET].Prm[HT_NUM_BSK_KOD].iFldLen+
              Tb[TB_BASKET].Prm[HT_NUM_BSK_KOLV].iFldLen+
              Tb[TB_BASKET].Prm[HT_NUM_BSK_DATE_REG].iFldLen+20+1);/*20 - vspomog simvoly SQL-zaprosa*/
  if(szTmp==NULL)
    http_err("Error no memory for MySQL InsertTmpBask!");
  strcpy(szTmp,"INSERT INTO \n");
  strcat(szTmp, Tb[TB_BASKET].szName);
  strcat(szTmp, " (");
  strcat(szTmp, TBVWFLD_BASKET);
  strcat(szTmp, ") VALUES ");
  strcat(szTmp, "(\"");
  strcat(szTmp, Tb[TB_BASKET].Prm[HT_NUM_BSK_IP].szHTFldValue);
  strcat(szTmp, "\", \"");
  szTmp1=malloc(strlen(szTmp)+1);
  if(szTmp1==NULL)
    http_err("Error no memory for MySQL InsertBask(1)!");
  strcpy(szTmp1,szTmp);

  szTmp2=malloc(Tb[TB_BASKET].Prm[HT_NUM_BSK_DATE_REG].iFldLen+10+1);
  if(szTmp2==NULL)
    http_err("Error no memory for MySQL InsertBask(2)!");
  strcpy(szTmp2, "\", \"");
  strcat(szTmp2, Tb[TB_BASKET].Prm[HT_NUM_BSK_DATE_REG].szHTFldValue);
  strcat(szTmp2, "\");");
  if (mysql_query(&mysql,"BEGIN;")!=0)
    mysql_err(3);
  if (mysql_query(&mysql,"LOCK TABLES basket WRITE;")!=0)
    mysql_err(3);
  for(i=0;i<iQntOrd;i++)
  {
    strcat(szTmp, szOrdInBask[i]);
    strcat(szTmp, "\", \"");
    strcat(szTmp, "1");
    strcat(szTmp, szTmp2);
    mysql_query(&mysql,szTmp); /*****************Sdelat otkat v sluchaee neudachnoy vstavki*/
#ifdef DEBAG
    printf("%s<br>\n",szTmp);
#endif
    strcpy(szTmp,szTmp1);
  }
  if (mysql_query(&mysql,"UNLOCK TABLES;")!=0)
      mysql_err(3);
  if (mysql_query(&mysql,"COMMIT;")!=0)
      mysql_err(3);
  free(szTmp);
  free(szTmp1);
  free(szTmp2);
  Tb[TB_ORDERS].Prm[HT_NUM_ORD_DATE_REG].szHTFldValue=Tb[TB_BASKET].Prm[HT_NUM_BSK_DATE_REG].szHTFldValue;
}

void GetBasket(void)
{
  char *szTmp;
  char blIsTrue;
  uint i,j,l;

  szTmp=malloc(100+1);
  if(szTmp==NULL)
    http_err("Error no memory for MySQL GET SELECT BASK!");

  strcpy(szTmp,"SELECT DISTINCT kod FROM basket WHERE ip = \"");
  strcat(szTmp, getIdentif());
  strcat(szTmp, "\";");
#ifdef DEBAG
  printf("%s<br>\n",szTmp);
#endif

  if (mysql_query(&mysql,szTmp)!=0)
    mysql_err(3);
  free(szTmp);

  if (!(res = mysql_store_result(&mysql)))
    mysql_err(4);

  if(szOrdInBask!=NULL) free(szOrdInBask);
  iQntOrd=mysql_num_rows(res);

  szOrdInBask=malloc(sizeof(char *)*iQntOrd);
  if(szOrdInBask==NULL)
    http_err("Error no memory for MySQL GET SELECT BASK(1)!");
  j=iQntOrd;
  l=0;
  for(i=0;i<iQntOrd;i++){
    row = mysql_fetch_row(res);
    if(row != NULL){
      szOrdInBask[i-l]=malloc(strlen(row[0])+1);
      strcpy(szOrdInBask[i-l],row[0]);
    }
    else{
      j--;
      l++;
    }
  }
  iQntOrd=j;
  mysql_free_result(res);
}


void UpdateBasket(void)
{
  char *szTmp;
  uint i;
  char blIsTrue;
  char *szTmp1, *szTmp2;

  szTmp=getIdentif();
  if(szTmp!=NULL)
  {
    Tb[TB_BASKET].Prm[HT_NUM_BSK_IP].szHTFldValue=malloc(strlen(szTmp));
    if(Tb[TB_BASKET].Prm[HT_NUM_BSK_IP].szHTFldValue!=NULL)
      strcpy(Tb[TB_BASKET].Prm[HT_NUM_BSK_IP].szHTFldValue,szTmp);
  }
  else Tb[TB_BASKET].Prm[HT_NUM_BSK_IP].szHTFldValue="0";

  szTmp=malloc(100+strlen(szBasket)+strlen(TBVWFLD_BASKET)+
              Tb[TB_BASKET].Prm[HT_NUM_BSK_KOD].iFldLen+
              Tb[TB_BASKET].Prm[HT_NUM_BSK_KOLV].iFldLen+20+1);/*20 - vspomog simvoly SQL-zaprosa*/
  if(szTmp==NULL)
    http_err("Error no memory for MySQL UpdateTmpBask!");
  strcpy(szTmp,"UPDATE \n");
  strcat(szTmp, Tb[TB_BASKET].szName);
  strcat(szTmp, "\n SET \n");
  strcat(szTmp, Tb[TB_BASKET].Prm[HT_NUM_BSK_KOLV].szTBFldName);
  strcat(szTmp, "=\"");
  szTmp1=malloc(strlen(szTmp)+1);
  if(szTmp1==NULL)
    http_err("Error no memory for MySQL UpdateBask(1)!");
  strcpy(szTmp1,szTmp);

  szTmp2=malloc(Tb[TB_BASKET].Prm[HT_NUM_BSK_DATE_REG].iFldLen+10+1);
  if(szTmp2==NULL)
    http_err("Error no memory for MySQL UpdateBask(2)!");
  strcpy(szTmp2, "\" WHERE kod=\"");

  if (mysql_query(&mysql,"LOCK TABLES basket WRITE;")!=0)
    mysql_err(3);
  if (mysql_query(&mysql,"BEGIN;")!=0)
    mysql_err(3);
  for(i=0;i<iQntOrd;i++)
  {
    strcat(szTmp, GetQueryValue(szQS,szOrdInBask[i]));
    strcat(szTmp, szTmp2);
    strcat(szTmp, szOrdInBask[i]);
    strcat(szTmp, "\";");
    mysql_query(&mysql,szTmp); /*****************Sdelat otkat v sluchaee neudachnoy vstavki*/

#ifdef DEBAG
    printf("%s<br>\n",szTmp);
#endif
    strcpy(szTmp,szTmp1);
  }
  free(szTmp);
  free(szTmp1);
  free(szTmp2);
  szTmp1=malloc(sizeof("del")+10+1);
  if(szTmp==NULL)
    http_err("Error no memory for MySQL UpdateBask(5)!");
  if(szTmp1==NULL)
    http_err("Error no memory for MySQL UpdateBask(3)!");
  szTmp=malloc(sizeof("DELETE FROM basket WHERE ip='' kod=SET('');")+(15+6)*iQntOrd+1);
  blIsTrue=0;
  strcpy(szTmp,"DELETE FROM basket WHERE ip='");
  strcat(szTmp,Tb[TB_BASKET].Prm[HT_NUM_BSK_IP].szHTFldValue);
  strcat(szTmp,"' AND kod=('");
  for(i=1;i<iQntOrd+1;i++)
  {
    sprintf(szTmp1,"del%d",i);
    szTmp2=GetQueryValue(szQS,szTmp1);
    if(szTmp2!=NULL)
      if(strlen(szTmp2)>0)
      {
        if(blIsTrue)
          strcat(szTmp,"' OR '");
        else
          blIsTrue=1;
        strcat(szTmp,szTmp2);
      }
  }
  strcat(szTmp,"');");
  if(blIsTrue!=0)
  {
    if (mysql_query(&mysql,szTmp)!=0)
      mysql_err(3);
#ifdef DEBAG
  printf("%s<br>\n",szTmp);
#endif
  }
  free(szTmp);
  if (mysql_query(&mysql,"COMMIT;")!=0)
      mysql_err(3);
  if (mysql_query(&mysql,"UNLOCK TABLES;")!=0)
      mysql_err(3);

}

char *SetBaskSelectStr(void)
{
  char *szTmp;
  char blIsTrue;
  uint i,j;

  szTmp=malloc(100+strlen(szBasket)+strlen(TBVWFLD_BASK)+iQntOrd*2*(TBFLD_KOD_LEN+14)+1);/*10 - vspomog simvoly SQL-zaprosa*/
  if(szTmp==NULL)
    http_err("Error no memory for MySQL SELECT BASK!");

  strcpy(szTmp,"SELECT DISTINCT\n");
  strcat(szTmp, TBVWFLD_BASK);
  strcat(szTmp, "\n FROM \n");
  strcat(szTmp, TBNM_CAT);
  strcat(szTmp, ", ");
  strcat(szTmp, TBNM_BASKET);
  strcat(szTmp, "\n WHERE \n(");
  blIsTrue=0;
  for(i=0;i<iQntOrd;i++)
  {
    if(blIsTrue==0)
      blIsTrue=1;
    else
      strcat(szTmp, ") OR (");
    strcat(szTmp, "cat.kod");
    strcat(szTmp, " = \"");
    strcat(szTmp, szOrdInBask[i]);
    strcat(szTmp, "\" AND ");
    strcat(szTmp, "basket.kod");
    strcat(szTmp, " = \"");
    strcat(szTmp, szOrdInBask[i]);
    strcat(szTmp, "\"");
  }
  strcat(szTmp, ");");
#ifdef DEBAG
  printf("%s<br>\n",szTmp);
#endif

  return szTmp;
}


void InsertBask(void)
{
  char *szTmp, *szTmpBsk, *szTmpDelBsk;
  uint i;
  char *szTmpBsk1,*szTmpDelBsk1,*szTmp1,*szTmp2;

/*  if (mysql_query(&mysql,"LOCK TABLES orders WRITE;")!=0)
      mysql_err(3);*/
    if (mysql_query(&mysql,"BEGIN;")!=0)
      mysql_err(3);

  if (mysql_query(&mysql,"SELECT (MAX(order_num)+1), CURDATE() FROM orders;")!=0)
      mysql_err(3);
  if (!(res = mysql_store_result(&mysql))) mysql_err(4);


  if(row = mysql_fetch_row(res))
  {
/* Poluchit' nomer zakaza i tekuschuyu datu servera SQL*/
    if(row[0]!=NULL){
      Tb[TB_ORDERS].Prm[HT_NUM_ORD_ORDER_NUM].szHTFldValue=malloc(strlen(row[0])+1);
      if(Tb[TB_ORDERS].Prm[HT_NUM_ORD_ORDER_NUM].szHTFldValue!=NULL)
        strcpy(Tb[TB_ORDERS].Prm[HT_NUM_ORD_ORDER_NUM].szHTFldValue,row[0]);
      else Tb[TB_ORDERS].Prm[HT_NUM_ORD_ORDER_NUM].szHTFldValue="0";
    }
    else 
      Tb[TB_ORDERS].Prm[HT_NUM_ORD_ORDER_NUM].szHTFldValue="0";
    Tb[TB_ORDERS].Prm[HT_NUM_ORD_DATE_REG].szHTFldValue=malloc(strlen(row[1])+1);
    if(Tb[TB_ORDERS].Prm[HT_NUM_ORD_DATE_REG].szHTFldValue!=NULL)
      strcpy(Tb[TB_ORDERS].Prm[HT_NUM_ORD_DATE_REG].szHTFldValue,row[1]);
    else Tb[TB_ORDERS].Prm[HT_NUM_ORD_DATE_REG].szHTFldValue="0000-00-00";
  }

  szTmpBsk=malloc(150+1);
  if(szTmpBsk==NULL)
    http_err("Error no memory for MySQL INSERT BASK0!");
  szTmpDelBsk=malloc(150+1);
  if(szTmpDelBsk==NULL)
    http_err("Error no memory for MySQL INSERT BASK2!");
  strcpy(szTmpBsk,"SELECT kolv\n FROM \n");
  strcat(szTmpBsk, TBNM_BASKET);
  strcat(szTmpBsk, "\n WHERE \n(ip=\"");
  strcat(szTmpBsk, getIdentif());
  strcat(szTmpBsk, "\" AND kod=\"");
  szTmpBsk1=malloc(strlen(szTmpBsk)+1);
  if(szTmpBsk1==NULL)
    http_err("Error no memory for MySQL InsertBask(1)!");
  strcpy(szTmpBsk1,szTmpBsk);

  strcpy(szTmpDelBsk,"DELETE FROM \n");
  strcat(szTmpDelBsk, TBNM_BASKET);
  strcat(szTmpDelBsk, "\n WHERE \n(ip=\"");
  strcat(szTmpDelBsk, getIdentif());
  strcat(szTmpDelBsk, "\" AND kod=\"");
  szTmpDelBsk1=malloc(strlen(szTmpDelBsk)+1);
  if(szTmpDelBsk1==NULL)
    http_err("Error no memory for MySQL InsertBask(1)!");
  strcpy(szTmpDelBsk1,szTmpDelBsk);

  szTmp=malloc(100+strlen(szBasket)+strlen(TBVWFLD_ORDERS_INS)+
              Tb[TB_BASKET].Prm[HT_NUM_ORD_ORDER_NUM].iFldLen+
              Tb[TB_ORDERS].Prm[HT_NUM_ORD_EMAIL].iFldLen+
              Tb[TB_ORDERS].Prm[HT_NUM_ORD_KOD].iFldLen+
              Tb[TB_ORDERS].Prm[HT_NUM_ORD_DATE_REG].iFldLen+
              Tb[TB_ORDERS].Prm[HT_NUM_ORD_STATUS].iFldLen+20+1);/*20 - vspomog simvoly SQL-zaprosa*/
  if(szTmp==NULL)
    http_err("Error no memory for MySQL InsertBask!");
  strcpy(szTmp,"INSERT INTO \n");
  strcat(szTmp, Tb[TB_ORDERS].szName);
  strcat(szTmp, " (");
  strcat(szTmp, TBVWFLD_ORDERS_INS);
  strcat(szTmp, ") VALUES ");
  strcat(szTmp, "(\"");
  strcat(szTmp, Tb[TB_ORDERS].Prm[HT_NUM_ORD_ORDER_NUM].szHTFldValue);
  strcat(szTmp, "\", \"");
  strcat(szTmp, Tb[TB_ORDERS].Prm[HT_NUM_ORD_EMAIL].szHTFldValue);
  strcat(szTmp, "\", \"");
  szTmp1=malloc(strlen(szTmp)+1);
  if(szTmp1==NULL)
    http_err("Error no memory for MySQL InsertBask(1)!");
  strcpy(szTmp1,szTmp);

  szTmp2=malloc(Tb[TB_ORDERS].Prm[HT_NUM_ORD_DATE_REG].iFldLen+strlen(HT_ORD_STAT_SET)+10+1);
  if(szTmp2==NULL)
    http_err("Error no memory for MySQL InsertBask(2)!");
  strcat(szTmp2, "\", \"");
  strcat(szTmp2, Tb[TB_ORDERS].Prm[HT_NUM_ORD_DATE_REG].szHTFldValue);
  strcat(szTmp2, "\", \"");
  strcat(szTmp2, HT_ORD_STAT_SET);
  strcat(szTmp2, "\");");
  for(i=0;i<iQntOrd;i++)
  {
    strcat(szTmpBsk, szOrdInBask[i]);
    strcat(szTmpBsk, "\");");

    strcat(szTmpDelBsk, szOrdInBask[i]);
    strcat(szTmpDelBsk, "\");");

    strcat(szTmp, szOrdInBask[i]);
    strcat(szTmp, "\", \"");
    if (mysql_query(&mysql,szTmpBsk)!=0)
      mysql_err(3);
    if (!(res = mysql_store_result(&mysql))) mysql_err(4);
    if(row = mysql_fetch_row(res))/*Kolichestvo*/
    {
      if(strcmp(row[0],"0"))
      {
        strcat(szTmp, row[0]);
        mysql_free_result(res);
        strcat(szTmp, szTmp2);
        if (mysql_query(&mysql,szTmp)!=0) /*****************Sdelat otkat v sluchaee neudachnoy vstavki*/
          mysql_err(3);
      }
    }
    if (mysql_query(&mysql,szTmpDelBsk)!=0)
      mysql_err(3);

#ifdef DEBAG
    printf("%s<br>\n",szTmpBsk);
    printf("%s<br>\n",szTmp);
    printf("%s<br>\n",szTmpDelBsk);
#endif
    strcpy(szTmpBsk,szTmpBsk1);
    strcpy(szTmpDelBsk,szTmpDelBsk1);
    strcpy(szTmp,szTmp1);
  }
  if (mysql_query(&mysql,"COMMIT;")!=0)
      mysql_err(3);
/*  if (mysql_query(&mysql,"UNLOCK TABLES;")!=0)
      mysql_err(3);*/
  free(szTmp);
  free(szTmp1);
  free(szTmp2);
  free(szTmpBsk);
  free(szTmpBsk1);
  free(szTmpDelBsk);
  free(szTmpDelBsk1);
}

void SelectBask(char *szTmp)
{
  uint i,j;
  char *szTmp1;

  if (mysql_query(&mysql,szTmp)!=0)
    mysql_err(3);
  if (!(res = mysql_store_result(&mysql))) mysql_err(4);
  j=0;
  printf(HT_BSK_TBL_HEAD);
/*  if(blIsOrder)*/
#ifdef __ORD
   printf("<FORM METHOD=POST ACTION=\"%s\">\n",CGI_PATH_ORDER);
#else
   printf("<FORM METHOD=POST ACTION=\"%s\">\n",CGI_PATH_BASK);  
#endif
  printf("<input type=hidden name=%s value=\"%s\">\n", HT_FLD_ORDER, HT_BSK_VAL_UPD);
#ifdef __ORD
  if(blVerifyUser){
    printf("<input type=hidden name=%s value=\"%s\"><br>\n", Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].szHTFldName,Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].szHTFldValue);
    printf("<input type=hidden name=%s value=\"%s\">\n", Tb[TB_USERS].Prm[HT_NUM_USR_PASSWD].szHTFldName,Tb[TB_USERS].Prm[HT_NUM_USR_PASSWD].szHTFldValue);
  }
#endif
  while((row = mysql_fetch_row(res)))
  {
    j++;
    printf(HT_BSK_TBL_N,j);
    if(row[0]!=NULL)
      printf(HT_BSK_TBL_NAME,row[0]);
    else
      printf(HT_BSK_TBL_NAME,"&nbsp;");
    if(row[1]!=NULL)
      printf(HT_BSK_TBL_COST,row[1]);
    else
      printf(HT_BSK_TBL_COST,"&nbsp;");
    if(row[3]!=NULL)
      printf(HT_BSK_TBL_QNT,row[2],row[3]);
    else
      printf(HT_BSK_TBL_QNT,row[2],"1");

    printf(HT_BSK_TBL_DEL,j,row[2]);
  }
  if (!mysql_eof(res)) mysql_err(5);
    mysql_free_result(res);

  szTmp1=malloc(sizeof(SQL_BSK_SUM)+Tb[TB_BASKET].Prm[HT_NUM_BSK_IP].iFldLen+sizeof("\"\";")+1);
  if(szTmp1==NULL)
    http_err("Error no memory for MySQL GET SELECT BASK!");

  strcpy(szTmp1, SQL_BSK_SUM);
  strcat(szTmp1, "\"");
  strcat(szTmp1, getIdentif());
  strcat(szTmp1, "\";");
#ifdef DEBAG
  printf("%s<br>\n",szTmp1);
#endif

  if (mysql_query(&mysql,szTmp1)!=0)
    mysql_err(3);
  free(szTmp1);
  if (!(res = mysql_store_result(&mysql))) mysql_err(4);
  row = mysql_fetch_row(res);
  if(row[0]!=NULL)
    printf(HT_BSK_TBL_SUM_w1p,row[0]);
  printf(HT_BSK_TBL_PUT,PATH_IMG_UPD_BASK);
  printf("</FORM>\n");
  printf(HT_BSK_TBL_FOOT);
  if (!mysql_eof(res)) mysql_err(5);
    mysql_free_result(res);
}

void PutOrderForm()
{
  printf("<table cellspacing=0 cellpadding=0 border=0 width=100%%><tr><td><img src=\"/image/line.gif\" width=100%% height=2 border=0></td></tr>");
  printf("<FORM METHOD=POST ACTION=\"%s\">",CGI_PATH_ORDER);
  printf("<tr>\n<td align=\"center\" valign=\"top\">");
  printf("<input type=hidden name=%s value=%s>", HT_FLD_BASKET, szBasket);
  printf("<input type=hidden name=%s value=\"%s\">", HT_FLD_ORDER, HT_BSK_VAL_PUT);
  printf("<input type=hidden name=%s value=\"%s\">", Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].szHTFldName,Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].szHTFldValue);
  printf("<input type=hidden name=%s value=\"%s\">", Tb[TB_USERS].Prm[HT_NUM_USR_PASSWD].szHTFldName,Tb[TB_USERS].Prm[HT_NUM_USR_PASSWD].szHTFldValue);
  printf("<input type=image src=\"%s\" border=0 alt=\"Заказать\">",PATH_IMG_PUT_ORDER);
  printf("</td></tr></FORM>");
  printf("</table>\n");
}

void VerifyForm()
{
  printf(HT_ORD_VRF_FRM_w7p, CGI_PATH_ORDER, 
                             HT_FLD_BASKET, szBasket, 
			     HT_FLD_ORDER, HT_BSK_VAL_VER, 
                             Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].szHTFldName,
                             Tb[TB_USERS].Prm[HT_NUM_USR_PASSWD].szHTFldName);
  printf(HT_REG_NEW_w1p, CGI_PATH_REG);
}



char *SendOrderMail(void)
{
  char *szTmp,*szTmp1;
  uint i;

  for(i=0;i<Tb[TB_ORDERS].iQntFld;i++)/*Chtoby ne iskalo leshnee*/
    Tb[TB_ORDERS].Prm[i].blData=0;
  Tb[TB_ORDERS].Prm[HT_NUM_ORD_ORDER_NUM].blData=1;
  Tb[TB_ORDERS].Prm[HT_NUM_ORD_EMAIL].blData=1;


  szTmp=malloc(sizeof("SELECT DISTINCT orders.kod, cat.imya_tov, cat.cena, orders.kolv FROM orders, cat WHERE cat.kod=orders.kod AND orders.order_num='';")+strlen(Tb[TB_ORDERS].Prm[HT_NUM_ORD_ORDER_NUM].szHTFldValue)+1);

  if(szTmp==NULL)
    http_err("Error no memory for SendOrderMail!");
  strcpy(szTmp,"SELECT DISTINCT orders.kod, cat.imya_tov, cat.cena, orders.kolv FROM orders, cat WHERE cat.kod=orders.kod AND orders.order_num='");
  strcat(szTmp,Tb[TB_ORDERS].Prm[HT_NUM_ORD_ORDER_NUM].szHTFldValue);
  strcat(szTmp,"';");

#ifdef DEBAG
  printf("%s<br>\n",szTmp);
#endif
  if (mysql_query(&mysql,szTmp)!=0)
    mysql_err(3);
  free(szTmp);

  if (!(res = mysql_store_result(&mysql)))
    mysql_err(4);

  szTmp1=malloc(sizeof("From: VostokTorgComplect - Internet Catalog <")+
                sizeof(MAIL_ADR_FROM)+sizeof(">\nTo: ")+
		Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].iFldLen+
                sizeof("Subject: Order N")+
		Tb[TB_ORDERS].Prm[HT_NUM_ORD_ORDER_NUM].iFldLen+
                sizeof("\n\nЗаказ N")+
		Tb[TB_ORDERS].Prm[HT_NUM_ORD_ORDER_NUM].iFldLen+
                sizeof("\nЗаказчик: ")+
		Tb[TB_ORDERS].Prm[HT_NUM_ORD_EMAIL].iFldLen+
                sizeof("\nДата заказа: ")+
		Tb[TB_ORDERS].Prm[HT_NUM_ORD_DATE_REG].iFldLen+
                mysql_num_rows(res)*(Tb[TB_CAT].Prm[HT_NUM_KOD].iFldLen+
		Tb[TB_CAT].Prm[HT_NUM_IMYA_TOV].iFldLen+
		Tb[TB_CAT].Prm[HT_NUM_CENA].iFldLen+
		Tb[TB_ORDERS].Prm[HT_NUM_ORD_KOLV].iFldLen+
		+10)+sizeof("\n.")+1);
  if(szTmp1==NULL)
    http_err("Error no memory for SendOrderMail(1)!");
  strcpy(szTmp1,"From: VostokTorgComplect-Internet Catalog <");
  strcat(szTmp1,MAIL_ADR_FROM);
  strcat(szTmp1,">\nTo: ");
  strcat(szTmp1,Tb[TB_ORDERS].Prm[HT_NUM_ORD_EMAIL].szHTFldValue);
  strcat(szTmp1,"\nSubject: Order N");
  strcat(szTmp1,Tb[TB_ORDERS].Prm[HT_NUM_ORD_ORDER_NUM].szHTFldValue);
  strcat(szTmp1,"\n\nЗаказ N");
  strcat(szTmp1,Tb[TB_ORDERS].Prm[HT_NUM_ORD_ORDER_NUM].szHTFldValue);
  strcat(szTmp1,"\nЗаказчик: ");
  strcat(szTmp1,Tb[TB_ORDERS].Prm[HT_NUM_ORD_EMAIL].szHTFldValue);
  strcat(szTmp1,"\nДата заказа: ");
  strcat(szTmp1,Tb[TB_ORDERS].Prm[HT_NUM_ORD_DATE_REG].szHTFldValue);

  while((row = mysql_fetch_row(res))){
    strcat(szTmp1,"\n");
    strcat(szTmp1,row[0]);
    strcat(szTmp1,"\t\"");
    strcat(szTmp1,row[1]);
    strcat(szTmp1,"\"\t$");
    strcat(szTmp1,row[2]);
    strcat(szTmp1,"\t- ");
    strcat(szTmp1,row[3]);
  }
  mysql_free_result(res);
  strcat(szTmp1,"\n.");

#ifdef DEBAG
  printf("<br>%s<br>\n",szTmp1);
#endif
  return szTmp1;
}

#if defined __REGISTR_H
void ShowUserData(void)
{
  uint i;
  char *szTmp;

    szTmp=SetSelectStr(TB_USERS);
    if (mysql_query(&mysql,szTmp)!=0)
      mysql_err(3);
    free(szTmp);
    if (!(res = mysql_store_result(&mysql))) mysql_err(4);

    printf(HT_REG_TBL_HEAD_w1p,CGI_PATH_ORDER);
    if((row = mysql_fetch_row(res)))
    {
/* !!! не было!!!
      i=HT_NUM_USR_EMAIL;
      if(row[i]!=NULL)
        printf(HT_REG_TBL_FLD_LEN_l_50_w4p,Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,row[i],Tb[TB_USERS].Prm[i].iFldLen);
      else
        printf(HT_REG_TBL_FLD_LEN_l_50_w4p, Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,"",Tb[TB_USERS].Prm[i].iFldLen);
/*      i=HT_NUM_USR_PASSWD;
      printf(HT_REG_TBL_PSWD_w5p, Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,Tb[TB_USERS].Prm[i].iFldLen,Tb[TB_USERS].Prm[i].szHTFldNameCpy,Tb[TB_USERS].Prm[i].iFldLen);
*/
      i=HT_NUM_USR_FIO;
      if(row[i]!=NULL)
        printf(HT_REG_TBL_FLD_LEN_l_50_w4p,Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,row[i],Tb[TB_USERS].Prm[i].iFldLen);
      else
        printf(HT_REG_TBL_FLD_LEN_l_50_w4p, Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,"",Tb[TB_USERS].Prm[i].iFldLen);

      printf(HT_REG_TBL_MDL);
      for(i=HT_NUM_USR_INN;i<HT_NUM_USR_FIO;i++)
      {
        if(row[i]!=NULL)
        {
          if(Tb[TB_USERS].Prm[i].iFldLen<50)
            printf(HT_REG_TBL_FLD_LEN_l_50_w4p,Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,row[i],Tb[TB_USERS].Prm[i].iFldLen);
          else
            printf(HT_REG_TBL_FLD_LEN_b_50_w5p,Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,50,(abs(Tb[TB_USERS].Prm[i].iFldLen/50)+1),row[i]);
        }
        else
        {
          if(Tb[TB_USERS].Prm[i].iFldLen<50)
            printf(HT_REG_TBL_FLD_LEN_l_50_w4p, Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,"",Tb[TB_USERS].Prm[i].iFldLen);
          else
            printf(HT_REG_TBL_FLD_LEN_b_50_w5p,Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,50,(abs(Tb[TB_USERS].Prm[i].iFldLen/50)+1),"");
        }
      }
      printf("<input type=hidden name=\"%s\" value=\"%s\">\n",Tb[TB_USERS].szHTFldKeyCpy,row[HT_NUM_USR_EMAIL]);
      printf("<input type=hidden name=\"%s\" value=\"%s\">\n",Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].szHTFldName,row[HT_NUM_USR_EMAIL]);
      printf("<input type=hidden name=\"%s\" value=\"%s\">\n",Tb[TB_USERS].Prm[HT_NUM_USR_PASSWD].szHTFldName,row[HT_NUM_USR_PASSWD]);
      printf("<input type=hidden name=\"%s\" value=\"%s\">\n",HT_FLD_ORDER,HT_ORD_MDFY_SET_USR);
      printf(HT_REG_TBL_PUT_IMG_w0p);
      printf(HT_REG_TBL_FOOT);
    }
    mysql_free_result(res);

}
#endif

void UpdUserData(void)
{
  char *szTmp;

  szTmp=SetUpdateStr(TB_USERS);
  if (mysql_query(&mysql,szTmp)!=0)
     mysql_err(3);
  else
    printf("<p align=center>Изменения занесены.</p>\n");
  free(szTmp);
}

#endif


