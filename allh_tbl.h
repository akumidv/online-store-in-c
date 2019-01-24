#if !defined __ALLH_TBL_H
#define __ALLH_TBL_H

#define   TB_CAT         0
#define   TB_USERS       1
#define   TB_ORDERS      2
#define   TB_HARAKT      3
#define   TB_BASKET      4

#define   TBQNTFLD_CAT    16
#define   TBQNTFLD_USERS  8
#define   TBQNTFLD_ORDERS 7
#define   TBQNTFLD_HARAKT 5
#define   TBQNTFLD_BASKET 4

#define TBNM_CAT    "cat"
#define TBNM_USERS  "users"
#define TBNM_ORDERS "orders"
#define TBNM_HARAKT "harakt"
#define TBNM_BASKET "basket"


#define   HTQNTFLD_CAT    15

#define   HT_NUM_KOD        0
#define   HT_NUM_VID_TOV    1
#define   HT_NUM_SUB_VID    2
#define   HT_NUM_TIP        3
#define   HT_NUM_IMYA_TOV   4
#define   HT_NUM_CENA       5
#define   HT_NUM_MARKA      6
#define   HT_NUM_ART        7
#define   HT_NUM_OPIS_TOV   8
#define   HT_NUM_HARAKT0    9
#define   HT_NUM_HARAKT1    10
#define   HT_NUM_HARAKT2    11
#define   HT_NUM_HARAKT3    12
#define   HT_NUM_SLK_IZOBR  13
#define   HT_NUM_KOLV       14
#define   HT_NUM_VIDIM      15


#define   HT_NUM_BASK_IMYA_TOV   0
#define   HT_NUM_BASK_CENA       1
#define   HT_NUM_BASK_SLK_OPIS   2

#define   HT_NUM_USR_EMAIL   0
#define   HT_NUM_USR_PASSWD   1
#define   HT_NUM_USR_INN   2
#define   HT_NUM_USR_FIO   7

#define   HT_NUM_ORD_ORDER_NUM   0
#define   HT_NUM_ORD_EMAIL      1/***DUBLIRUYUT FLD_ORD_EMAIL***/
#define   HT_NUM_ORD_KOD      2
#define   HT_NUM_ORD_KOLV      3
#define   HT_NUM_ORD_DATE_REG   4
#define   HT_NUM_ORD_DATE_ISP   5
#define   HT_NUM_ORD_STATUS   6

#define   HT_NUM_BSK_IP      0
#define   HT_NUM_BSK_KOD      1
#define   HT_NUM_BSK_KOLV      2
#define   HT_NUM_BSK_DATE_REG   3

#define   TBVWFLD_CAT   "kod, vid_tov, sub_vid, tip, imya_tov, cena, marka, art, opis_tov, harakt0, harakt1, harakt2, harakt3, slk_izobr, kolv, vidim"
#define   TBVWFLD_USERS   "email, passwd, inn, naim_org, adres_poch, tel, fax, fio"
#define   TBVWFLD_ORDERS   "order_num, email, kod, kolv, date_reg, date_isp, status"
#define   TBVWFLD_ORDERS_INS   "order_num, email, kod, kolv, date_reg, status"
#define   TBVWFLD_HARAKT   "vid_tov, harakt0, harakt1, harakt2, harakt3"
#define   TBVWFLD_BASK   "cat.imya_tov, cat.cena, cat.kod, basket.kolv" /*Iz bazi Cat*/
#define   TBVWFLD_BASKET   "ip, kod, kolv, date_reg"

#define   SQL_CAT_SUB_VID "SELECT DISTINCT sub_vid FROM cat WHERE vidim=\"0\" AND vid_tov="
#define   SQL_CAT_TIP "SELECT DISTINCT tip FROM cat WHERE vidim=\"0\" AND vid_tov="
#define   SQL_CAT_HRKT0 "SELECT DISTINCT harakt0 FROM cat WHERE vidim=\"0\" AND vid_tov="
#define   SQL_CAT_VID_TOV_SB "SELECT DISTINCT vid_tov FROM cat;"
#define   SQL_CAT_SUB_TOV_SB "SELECT DISTINCT sub_vid FROM cat;"
#define   SQL_CAT_TIP_SB "SELECT DISTINCT tip FROM cat;"
#define   SQL_CAT_HRKT0_SB "SELECT DISTINCT harakt0 FROM cat;"

#define   SQL_BSK_SUM "SELECT SUM(basket.kolv*cat.cena) FROM basket,cat WHERE basket.kod=cat.kod AND basket.ip="

#define   TBFLD_KOD   "kod"
#define   TBFLD_KOD_LEN   16

#define   FLD_CAT_KOD    0
#define   FLD_CAT_VIDTOV    1
#define   FLD_CAT_SUBVID    2
#define   FLD_CAT_TIP    3

#define   FLD_USR_EMAIL  0
#define   FLD_ORD_EMAIL  1
#define   FLD_ORD_KOD    2
#define   FLD_HAR_VIDTOV    0

#define   TBOP_SELECT   1
#define   TBOP_INSERT   2
#define   TBOP_UPDATE   3
#define   TBOP_DELETE   4


/*Inicializaciya*/
void Init(void)
{
  uint iTbNum;

  iTbNum=TB_CAT;
  Tb[iTbNum].szName=TBNM_CAT;
  Tb[iTbNum].iQntFld=TBQNTFLD_CAT;
  Tb[iTbNum].szVwFld=TBVWFLD_CAT;
  Tb[iTbNum].szHTFldKeyCpy=HT_CAT_KEY_CPY;
  Tb[iTbNum].Prm=malloc(sizeof(TBPrm)*Tb[iTbNum].iQntFld);

  Tb[iTbNum].Prm[0].szFldName="Код";
  Tb[iTbNum].Prm[1].szFldName="Код вида товара";
  Tb[iTbNum].Prm[2].szFldName="Подвид товара";  
  Tb[iTbNum].Prm[3].szFldName="Тип товара";  
  Tb[iTbNum].Prm[4].szFldName="Наименование";
  Tb[iTbNum].Prm[5].szFldName="Цена (у.е.)";
  Tb[iTbNum].Prm[6].szFldName="Марка";
  Tb[iTbNum].Prm[7].szFldName="Арт.";
  Tb[iTbNum].Prm[8].szFldName="Описание";
  Tb[iTbNum].Prm[9].szFldName="Характ. 0";
  Tb[iTbNum].Prm[10].szFldName="Характ. 1";
  Tb[iTbNum].Prm[11].szFldName="Харатк. 2";
  Tb[iTbNum].Prm[12].szFldName="Характ.  3";
  Tb[iTbNum].Prm[13].szFldName="Ссылка на изображ.";
  Tb[iTbNum].Prm[14].szFldName="Кол. заказов";
  Tb[iTbNum].Prm[15].szFldName="Флаг видимости";

  Tb[iTbNum].Prm[0].szTBFldName="kod";
  Tb[iTbNum].Prm[1].szTBFldName="vid_tov";
  Tb[iTbNum].Prm[2].szTBFldName="sub_vid";
  Tb[iTbNum].Prm[3].szTBFldName="tip";
  Tb[iTbNum].Prm[4].szTBFldName="imya_tov";
  Tb[iTbNum].Prm[5].szTBFldName="cena";
  Tb[iTbNum].Prm[6].szTBFldName="marka";
  Tb[iTbNum].Prm[7].szTBFldName="art";  
  Tb[iTbNum].Prm[8].szTBFldName="opis_tov";  
  Tb[iTbNum].Prm[9].szTBFldName="harakt0";
  Tb[iTbNum].Prm[10].szTBFldName="harakt1";
  Tb[iTbNum].Prm[11].szTBFldName="harakt2";
  Tb[iTbNum].Prm[12].szTBFldName="harakt3";
  Tb[iTbNum].Prm[13].szTBFldName="slk_izobr";
  Tb[iTbNum].Prm[14].szTBFldName="kolv";
  Tb[iTbNum].Prm[15].szTBFldName="vidim";

  Tb[iTbNum].Prm[0].szHTFldName="F_KOD";
  Tb[iTbNum].Prm[1].szHTFldName="F_VID_TOV";
  Tb[iTbNum].Prm[2].szHTFldName="F_SUB_VID";
  Tb[iTbNum].Prm[3].szHTFldName="F_TIP";
  Tb[iTbNum].Prm[4].szHTFldName="F_IMYA_TOV";
  Tb[iTbNum].Prm[5].szHTFldName="F_CENA";
  Tb[iTbNum].Prm[6].szHTFldName="F_MARKA";
  Tb[iTbNum].Prm[7].szHTFldName="F_ART";  
  Tb[iTbNum].Prm[8].szHTFldName="F_OPIS_TOV";  
  Tb[iTbNum].Prm[9].szHTFldName="F_HARAKT0";
  Tb[iTbNum].Prm[10].szHTFldName="F_HARAKT1";
  Tb[iTbNum].Prm[11].szHTFldName="F_HARAKT2";
  Tb[iTbNum].Prm[12].szHTFldName="F_HARAKT3";
  Tb[iTbNum].Prm[13].szHTFldName="F_SLK_IZOBR";
  Tb[iTbNum].Prm[14].szHTFldName="F_KOL";
  Tb[iTbNum].Prm[15].szHTFldName="F_VIDIM";

  Tb[iTbNum].Prm[0].szHTFldNameCpy="F_KOD_C";
  Tb[iTbNum].Prm[1].szHTFldNameCpy="F_VID_TOV_C";
  Tb[iTbNum].Prm[2].szHTFldNameCpy="F_SUB_VID_C";
  Tb[iTbNum].Prm[3].szHTFldNameCpy="F_TIP_C";
  Tb[iTbNum].Prm[4].szHTFldNameCpy="F_IMYA_TOV_C";
  Tb[iTbNum].Prm[5].szHTFldNameCpy="F_CENA_C";
  Tb[iTbNum].Prm[6].szHTFldNameCpy="F_MARKA_C";
  Tb[iTbNum].Prm[7].szHTFldNameCpy="F_ART_C";  
  Tb[iTbNum].Prm[8].szHTFldNameCpy="F_OPIS_TOV_C";
  Tb[iTbNum].Prm[9].szHTFldNameCpy="F_HARAKT0_C";
  Tb[iTbNum].Prm[10].szHTFldNameCpy="F_HARAKT1_C";
  Tb[iTbNum].Prm[11].szHTFldNameCpy="F_HARAKT2_C";
  Tb[iTbNum].Prm[12].szHTFldNameCpy="F_HARAKT3_C";
  Tb[iTbNum].Prm[13].szHTFldNameCpy="F_SLK_IZOBR_C";
  Tb[iTbNum].Prm[14].szHTFldNameCpy="F_KOL_C";
  Tb[iTbNum].Prm[15].szHTFldNameCpy="F_VIDIM_C";

  Tb[iTbNum].Prm[0].iFldLen=16;
  Tb[iTbNum].Prm[1].iFldLen=8;
  Tb[iTbNum].Prm[2].iFldLen=32;
  Tb[iTbNum].Prm[3].iFldLen=16;
  Tb[iTbNum].Prm[4].iFldLen=64;
  Tb[iTbNum].Prm[5].iFldLen=11;
  Tb[iTbNum].Prm[6].iFldLen=32;
  Tb[iTbNum].Prm[7].iFldLen=8;  
  Tb[iTbNum].Prm[8].iFldLen=255;
  Tb[iTbNum].Prm[9].iFldLen=24;
  Tb[iTbNum].Prm[10].iFldLen=24;
  Tb[iTbNum].Prm[11].iFldLen=24;
  Tb[iTbNum].Prm[12].iFldLen=24;
  Tb[iTbNum].Prm[13].iFldLen=64;
  Tb[iTbNum].Prm[14].iFldLen=10;
  Tb[iTbNum].Prm[15].iFldLen=1;

  iTbNum=TB_USERS;
  Tb[iTbNum].szName=TBNM_USERS;
  Tb[iTbNum].iQntFld=TBQNTFLD_USERS;
  Tb[iTbNum].szVwFld=TBVWFLD_USERS;
  Tb[iTbNum].szHTFldKeyCpy=HT_USERS_KEY_CPY;
  Tb[iTbNum].Prm=malloc(sizeof(TBPrm)*Tb[iTbNum].iQntFld);

  Tb[iTbNum].Prm[0].szFldName="E-Mail";
  Tb[iTbNum].Prm[1].szFldName="Пароль";
  Tb[iTbNum].Prm[2].szFldName="ИНН";
  Tb[iTbNum].Prm[3].szFldName="Наименование организации(ЧП)";
  Tb[iTbNum].Prm[4].szFldName="Адрес";
  Tb[iTbNum].Prm[5].szFldName="Телефон";
  Tb[iTbNum].Prm[6].szFldName="Факс";
  Tb[iTbNum].Prm[7].szFldName="ФИО контактного лица";

  Tb[iTbNum].Prm[0].szTBFldName="email";
  Tb[iTbNum].Prm[1].szTBFldName="passwd";
  Tb[iTbNum].Prm[2].szTBFldName="inn";
  Tb[iTbNum].Prm[3].szTBFldName="naim_org";
  Tb[iTbNum].Prm[4].szTBFldName="adres_poch";
  Tb[iTbNum].Prm[5].szTBFldName="tel";
  Tb[iTbNum].Prm[6].szTBFldName="fax";
  Tb[iTbNum].Prm[7].szTBFldName="fio";

  Tb[iTbNum].Prm[0].szHTFldName="F_EMAIL";
  Tb[iTbNum].Prm[1].szHTFldName="F_PASSWD";
  Tb[iTbNum].Prm[2].szHTFldName="F_INN";
  Tb[iTbNum].Prm[3].szHTFldName="F_NAIM_ORG";
  Tb[iTbNum].Prm[4].szHTFldName="F_ADRES_POCH";
  Tb[iTbNum].Prm[5].szHTFldName="F_TEL";
  Tb[iTbNum].Prm[6].szHTFldName="F_FAX";
  Tb[iTbNum].Prm[7].szHTFldName="F_FIO";

  Tb[iTbNum].Prm[0].szHTFldNameCpy="F_EMAIL_C";
  Tb[iTbNum].Prm[1].szHTFldNameCpy="F_PASSWD_C";
  Tb[iTbNum].Prm[2].szHTFldNameCpy="F_INN_C";
  Tb[iTbNum].Prm[3].szHTFldNameCpy="F_NAIM_ORG_C";
  Tb[iTbNum].Prm[4].szHTFldNameCpy="F_ADRES_POCH_C";
  Tb[iTbNum].Prm[5].szHTFldNameCpy="F_TEL_C";
  Tb[iTbNum].Prm[6].szHTFldNameCpy="F_FAX_C";
  Tb[iTbNum].Prm[7].szHTFldNameCpy="F_FIO_C";

  Tb[iTbNum].Prm[0].iFldLen=32;
  Tb[iTbNum].Prm[1].iFldLen=16;
  Tb[iTbNum].Prm[2].iFldLen=12;
  Tb[iTbNum].Prm[3].iFldLen=96;
  Tb[iTbNum].Prm[4].iFldLen=255;
  Tb[iTbNum].Prm[5].iFldLen=48;
  Tb[iTbNum].Prm[6].iFldLen=24;
  Tb[iTbNum].Prm[7].iFldLen=48;


  iTbNum=TB_ORDERS;
  Tb[iTbNum].szName=TBNM_ORDERS;
  Tb[iTbNum].iQntFld=TBQNTFLD_ORDERS;
  Tb[iTbNum].szVwFld=TBVWFLD_ORDERS;
  Tb[iTbNum].szHTFldKeyCpy=HT_ORDERS_KEY_CPY;
  Tb[iTbNum].Prm=malloc(sizeof(TBPrm)*Tb[iTbNum].iQntFld);

  Tb[iTbNum].Prm[0].szFldName="Номер заказа";
  Tb[iTbNum].Prm[1].szFldName="EMail";
  Tb[iTbNum].Prm[2].szFldName="Код заказанного товара";
  Tb[iTbNum].Prm[3].szFldName="Количество";
  Tb[iTbNum].Prm[4].szFldName="Дата размещения заказа";
  Tb[iTbNum].Prm[5].szFldName="Дата исполнения заказа";
  Tb[iTbNum].Prm[6].szFldName="Статус исполнения";

  Tb[iTbNum].Prm[0].szTBFldName="order_num";
  Tb[iTbNum].Prm[1].szTBFldName="email";
  Tb[iTbNum].Prm[2].szTBFldName="kod";
  Tb[iTbNum].Prm[3].szTBFldName="kolv";
  Tb[iTbNum].Prm[4].szTBFldName="date_reg";
  Tb[iTbNum].Prm[5].szTBFldName="date_isp";
  Tb[iTbNum].Prm[6].szTBFldName="status";

  Tb[iTbNum].Prm[0].szHTFldName="F_ORDER_NUM";
  Tb[iTbNum].Prm[1].szHTFldName="F_EMAIL";
  Tb[iTbNum].Prm[2].szHTFldName="F_KOD";
  Tb[iTbNum].Prm[3].szHTFldName="F_KOL";
  Tb[iTbNum].Prm[4].szHTFldName="D_DATA_REG";
  Tb[iTbNum].Prm[5].szHTFldName="F_DATA_ISP";
  Tb[iTbNum].Prm[6].szHTFldName="F_STATUS";

  Tb[iTbNum].Prm[0].szHTFldNameCpy="F_ORDER_NUM_C";
  Tb[iTbNum].Prm[1].szHTFldNameCpy="F_EMAIL_C";
  Tb[iTbNum].Prm[2].szHTFldNameCpy="F_KOD_C";
  Tb[iTbNum].Prm[3].szHTFldNameCpy="F_KOL_C";
  Tb[iTbNum].Prm[4].szHTFldNameCpy="F_DATA_REG_C";
  Tb[iTbNum].Prm[5].szHTFldNameCpy="F_DATA_ISP_C";
  Tb[iTbNum].Prm[6].szHTFldNameCpy="F_STATUS_C";

  Tb[iTbNum].Prm[0].iFldLen=10;
  Tb[iTbNum].Prm[1].iFldLen=32;
  Tb[iTbNum].Prm[2].iFldLen=16;
  Tb[iTbNum].Prm[3].iFldLen=10;
  Tb[iTbNum].Prm[4].iFldLen=10;
  Tb[iTbNum].Prm[5].iFldLen=10;
  Tb[iTbNum].Prm[6].iFldLen=1;


  iTbNum=TB_HARAKT;
  Tb[iTbNum].szName=TBNM_HARAKT;
  Tb[iTbNum].iQntFld=TBQNTFLD_HARAKT;
  Tb[iTbNum].szVwFld=TBVWFLD_HARAKT;
  Tb[iTbNum].szHTFldKeyCpy=HT_HARAKT_KEY_CPY;
  Tb[iTbNum].Prm=malloc(sizeof(TBPrm)*Tb[iTbNum].iQntFld);

  Tb[iTbNum].Prm[0].szFldName="Код вида товара";
  Tb[iTbNum].Prm[1].szFldName="Наим. характ. 0";
  Tb[iTbNum].Prm[2].szFldName="Наим. характ. 1";
  Tb[iTbNum].Prm[3].szFldName="Наим. характ. 2";
  Tb[iTbNum].Prm[4].szFldName="Наим. характ. 3";

  Tb[iTbNum].Prm[0].szTBFldName="vid_tov";
  Tb[iTbNum].Prm[1].szTBFldName="harakt0";
  Tb[iTbNum].Prm[2].szTBFldName="harakt1";
  Tb[iTbNum].Prm[3].szTBFldName="harakt2";
  Tb[iTbNum].Prm[4].szTBFldName="harakt3";

  Tb[iTbNum].Prm[0].szHTFldName="F_VID_TOV";
  Tb[iTbNum].Prm[1].szHTFldName="F_HARAKT0";
  Tb[iTbNum].Prm[2].szHTFldName="F_HARAKT1";
  Tb[iTbNum].Prm[3].szHTFldName="F_HARAKT2";
  Tb[iTbNum].Prm[4].szHTFldName="F_HARAKT3";

  Tb[iTbNum].Prm[0].szHTFldNameCpy="F_VID_TOV_C";
  Tb[iTbNum].Prm[1].szHTFldNameCpy="F_HARAKT0_C";
  Tb[iTbNum].Prm[2].szHTFldNameCpy="F_HARAKT1_C";
  Tb[iTbNum].Prm[3].szHTFldNameCpy="F_HARAKT2_C";
  Tb[iTbNum].Prm[4].szHTFldNameCpy="F_HARAKT3_C";

  Tb[iTbNum].Prm[0].iFldLen=8;
  Tb[iTbNum].Prm[1].iFldLen=24;
  Tb[iTbNum].Prm[2].iFldLen=24;
  Tb[iTbNum].Prm[3].iFldLen=24;
  Tb[iTbNum].Prm[4].iFldLen=24;

  iTbNum=TB_BASKET;
  Tb[iTbNum].szName=TBNM_BASKET;
  Tb[iTbNum].iQntFld=TBQNTFLD_BASKET;
  Tb[iTbNum].szVwFld=TBVWFLD_BASKET;
  Tb[iTbNum].szHTFldKeyCpy=HT_BASKET_KEY_CPY;
  Tb[iTbNum].Prm=malloc(sizeof(TBPrm)*Tb[iTbNum].iQntFld);

  Tb[iTbNum].Prm[0].szFldName="Идентификатор поситителя";
  Tb[iTbNum].Prm[1].szFldName="Код товара";
  Tb[iTbNum].Prm[2].szFldName="Количество заказанного";
  Tb[iTbNum].Prm[3].szFldName="Дата";

  Tb[iTbNum].Prm[0].szTBFldName="ip";
  Tb[iTbNum].Prm[1].szTBFldName="kod";
  Tb[iTbNum].Prm[2].szTBFldName="kolv";
  Tb[iTbNum].Prm[3].szTBFldName="date_reg";

  Tb[iTbNum].Prm[0].szHTFldName="F_IP";
  Tb[iTbNum].Prm[1].szHTFldName="F_KOD";
  Tb[iTbNum].Prm[2].szHTFldName="F_KOL";
  Tb[iTbNum].Prm[3].szHTFldName="D_DATA_REG";

  Tb[iTbNum].Prm[0].szHTFldNameCpy="F_IP_C";
  Tb[iTbNum].Prm[1].szHTFldNameCpy="F_KOD_C";
  Tb[iTbNum].Prm[2].szHTFldNameCpy="F_KOL_C";
  Tb[iTbNum].Prm[3].szHTFldNameCpy="F_DATA_REG_C";

  Tb[iTbNum].Prm[0].iFldLen=32;
  Tb[iTbNum].Prm[1].iFldLen=16;
  Tb[iTbNum].Prm[2].iFldLen=10;
  Tb[iTbNum].Prm[3].iFldLen=10;

}


char GetQV(char blUseCpy, uint iTbNum)
{
  char blIsTrue;
  uint i;
  char *szTmp;

  blIsTrue=0;

  for(i=0;i<Tb[iTbNum].iQntFld;i++)
  {
    if(blUseCpy)
      Tb[iTbNum].Prm[i].szHTFldValue=GetQueryValue(szQS,Tb[iTbNum].Prm[i].szHTFldNameCpy);
     else
       Tb[iTbNum].Prm[i].szHTFldValue=GetQueryValue(szQS,Tb[iTbNum].Prm[i].szHTFldName);
 
    if(strlen(Tb[iTbNum].Prm[i].szHTFldValue)>0)
    {
      blIsTrue=1;
      Tb[iTbNum].Prm[i].blData=1;
    }
    else
      Tb[iTbNum].Prm[i].blData=0;
  }
  return blIsTrue;
}

char GetQVExt(uint iTbNum)
{
  char blIsTrue;
  uint i;
  char *szTmp;

  blIsTrue=0;

  for(i=0;i<Tb[iTbNum].iQntFld;i++)
  {
     if(!strcmp(GetQueryValue(szQS,Tb[iTbNum].Prm[i].szHTFldName),HT_VL_USE_CPY)){
       szTmp=malloc(sizeof(Tb[iTbNum].Prm[i].szHTFldName)+sizeof("EXT")+1);
       if(szTmp!=NULL)
         strcpy(szTmp,Tb[iTbNum].Prm[i].szHTFldName);
	 strcat(szTmp,"EXT");
       Tb[iTbNum].Prm[i].szHTFldValue=GetQueryValue(szQS,szTmp);
       free(szTmp);
     }
     else
       Tb[iTbNum].Prm[i].szHTFldValue=GetQueryValue(szQS,Tb[iTbNum].Prm[i].szHTFldName);
 
    if(strlen(Tb[iTbNum].Prm[i].szHTFldValue)>0)
    {
      blIsTrue=1;
      Tb[iTbNum].Prm[i].blData=1;
    }
    else
      Tb[iTbNum].Prm[i].blData=0;
  }
  return blIsTrue;
}

char *SetInsertStr(uint iTbNum)
{
  char *szTmp;
  char blIsTrue;
  uint i;

  szTmp=malloc(20+atol(getenv("CONTENT_LENGTH")));
  if(szTmp==NULL)
    http_err("Error no memory for MySQL INSERT!");
  strcpy(szTmp,"INSERT INTO \n");
  strcat(szTmp, Tb[iTbNum].szName);
  blIsTrue=0;
  for(i=0;i<Tb[iTbNum].iQntFld;i++)
  {
    if(i==HT_NUM_KOD && iTbNum==TB_CAT)
      continue;/*Не вставляем поле код, т.к. оно автоинкрементируется*/
    if(Tb[iTbNum].Prm[i].blData)
    {
      if(blIsTrue==0)
      {
        blIsTrue=1;
        strcat(szTmp, " (");
      }
      else
        strcat(szTmp, ", ");
      strcat(szTmp, Tb[iTbNum].Prm[i].szTBFldName);
    }
  }
  strcat(szTmp, ")\n VALUES \n");
  blIsTrue=0;
  for(i=0;i<Tb[iTbNum].iQntFld;i++)
  {
    if(i==HT_NUM_KOD && iTbNum==TB_CAT)
      continue;/*Не вставляем поле код, т.к. оно автоинкрементируется*/
    if(Tb[iTbNum].Prm[i].blData)
    {
      if(blIsTrue==0)
      {
        blIsTrue=1;
        strcat(szTmp, "(\"");
      }
      else
        strcat(szTmp, ", \"");
      strcat(szTmp, Tb[iTbNum].Prm[i].szHTFldValue);
      strcat(szTmp, "\"");
    }
  }
  strcat(szTmp, ");");
#ifdef DEBAG
  printf("%s<br>\n",szTmp);
#endif
  return szTmp;
}


char *SetUpdateStr(uint iTbNum)
{
  char *szTmp;
  char blIsTrue;
  uint i;

  szTmp=malloc(100);
  if(szTmp==NULL)
    http_err("Error no memory for MySQL UPDATE!");
  strcpy(szTmp,"UPDATE \n");
  strcat(szTmp, Tb[iTbNum].szName);
  strcat(szTmp, "\n SET \n");

  blIsTrue=0;
/*i - s edinicy, chtoby ne obnovlyali Kod tovara*/
  for(i=1;i<Tb[iTbNum].iQntFld;i++)
  {
    if(Tb[iTbNum].Prm[i].blData)
    {
      if(blIsTrue==0)
        blIsTrue=1;
      else
        strcat(szTmp, ", ");
      strcat(szTmp, Tb[iTbNum].Prm[i].szTBFldName);
      strcat(szTmp, "=\"");
      strcat(szTmp, Tb[iTbNum].Prm[i].szHTFldValue);
      strcat(szTmp, "\"");
    }
    else
    {
      if(blIsTrue==0)
        blIsTrue=1;
      else
        strcat(szTmp, ", ");
      strcat(szTmp, Tb[iTbNum].Prm[i].szTBFldName);
      strcat(szTmp, "=");
      strcat(szTmp, "NULL");
    }
  }
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