#if !defined __ALLHEAD_H
#define __ALLHEADL_H

#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

#include "cgi.h"

/*#define DEBAG*/

#include "allh_html.h"
#include "allh_val.h"
#include "allh_err.h"
#include "allh_fld.h"
#include "allh_tbl.h"
#include "all_usr.h"

#define   SQL_MENU_S_VID_TOV  "SELECT DISTINCT cat.vid_tov, harakt.lnk_img, harakt.lnk_hd_img, harakt.vid_tov_opis \nFROM cat, harakt \nWHERE harakt.vid_tov = cat.vid_tov AND harakt.lnk_img IS NOT NULL;"

void CGICatLftMenu(void);
#if defined __ORD
  void CGIBskLftMenu(void);
#endif

char **szMenuVidTov;/*Menu - vidov tovarov*/
char **szMenuVidTov_LnkImg; /*Menu - vidov tovarov - ssilka na izobrazhenie*/
char **szMenuVidTov_LnkHdImg; /*Menu - vidov tovarov - ssilka na izobrazhenie zagolovka*/
char **szMenuVidTov_Opis; /*Menu - vidov tovarov - opisanie*/
uint iQntCellMenu=0; /*Kol. elem menu*/

char *szBasket;/*Korzina*/

char *szId;/*Identifikator*/

char blVerifyUser=0;
uint iCurRec=0;

uint iSect;

void GetMenu(void)
{
  uint i;
  uint iLen;

#ifdef DEBAG
  printf("%s<br>\n",SQL_MENU_S_VID_TOV);
#endif

  if (mysql_query(&mysql,SQL_MENU_S_VID_TOV)!=0)
    mysql_err(3);

  if (!(res = mysql_store_result(&mysql)))
    mysql_err(4);

  iQntCellMenu=mysql_num_rows(res);

  szMenuVidTov=malloc(sizeof(char *)*iQntCellMenu);
  if(szMenuVidTov==NULL)
    http_err("Error no memory for GET MENU(0)!");
  szMenuVidTov_LnkImg=malloc(sizeof(char *)*iQntCellMenu);
  if(szMenuVidTov_LnkImg==NULL)
    http_err("Error no memory for GET MENU(1)!");
  szMenuVidTov_LnkHdImg=malloc(sizeof(char *)*iQntCellMenu);
  if(szMenuVidTov_LnkHdImg==NULL)
    http_err("Error no memory for GET MENU(2)!");

  szMenuVidTov_Opis=malloc(sizeof(char *)*iQntCellMenu);
  if(szMenuVidTov_Opis==NULL)
    http_err("Error no memory for GET MENU(3)!");
  for(i=0;i<iQntCellMenu;i++)
  {
    row = mysql_fetch_row(res);
    szMenuVidTov[i]=malloc(strlen(row[0])+1);
    if(szMenuVidTov[i]!=NULL)
    {
      strcpy(szMenuVidTov[i],row[0]);

      szMenuVidTov_LnkImg[i]=malloc(strlen(row[1])+1);
      if(szMenuVidTov_LnkImg[i]!=NULL)
        strcpy(szMenuVidTov_LnkImg[i],row[1]);

      szMenuVidTov_LnkHdImg[i]=malloc(strlen(row[2])+1);
      if(szMenuVidTov_LnkHdImg[i]!=NULL)
        strcpy(szMenuVidTov_LnkHdImg[i],row[2]);

      szMenuVidTov_Opis[i]=malloc(strlen(row[3])+1);
      if(szMenuVidTov_Opis[i]!=NULL)
        strcpy(szMenuVidTov_Opis[i],row[3]);
    }
  }
  mysql_free_result(res);
}

void CGIHeader(void)
{
  char *szTitle;
  char *szTpMenu;
  char *szImg0, *szImg1;
  int i;

/*Занесенние данных для заголовка*/
  switch(iSect){
    case MNIT_KUH_INV:
      szTitle=MNITVL_KUH_INV;
      szImg0=MNITLNIM0_KUH_INV;
      szImg1=MNITLNIM1_KUH_INV;
      break;
    case MNIT_KND_INV:
      szTitle=MNITVL_KND_INV;
      szImg0=MNITLNIM0_KND_INV;
      szImg1=MNITLNIM1_KND_INV;
      break;
    case MNIT_KMP_HLD:
      szTitle=MNITVL_KMP_HLD;
      szImg0=MNITLNIM0_KMP_HLD;
      szImg1=MNITLNIM1_KMP_HLD;
      break;
    case MNIT_THN_OBR:
      szTitle=MNITVL_THN_OBR;
      szImg0=MNITLNIM0_THN_OBR;
      szImg1=MNITLNIM1_THN_OBR;
      break;
#if defined __ORD
    case TPMNIT_2:
      szTitle=TPMNIT_ALT_2;
      szImg0=TPMNIT_LNKIMG0_2;
      szImg1=TPMNIT_LNKIMG1_2;
      break;
#endif
    case TPMNIT_3:
      szTitle=TPMNIT_ALT_3;
      szImg0=TPMNIT_LNKIMG0_3;
      szImg1=TPMNIT_LNKIMG1_3;
      break;
#if defined __BASK
    case TPMNIT_4:
      szTitle=TPMNIT_ALT_4;
      szImg0=TPMNIT_LNKIMG0_4;
      szImg1=TPMNIT_LNKIMG1_4;
      break;
#endif
#if defined __REG
    case MN_REG:
      szTitle=MN_ALT_REG;
      szImg0=MN_LNKIMG0_REG;
      szImg1=MN_LNKIMG1_REG;
      break;
#endif
    default:
      szTitle=MNITVL_ABT;
      szImg0=MNITLNIM0_ABT;
      szImg1=MNITLNIM1_ABT;
      break;
  }
  printf(CGI_TopHd_w1p,szTitle);
/* Шапка */
  printf(CGI_Hd_w0p);
/* Верхнее меню */
/*Кол-во верхних меню 4, указано при создании szMenu */
  szTpMenu=malloc(sizeof(CGI_PATH_CAT)+sizeof("?=")+sizeof(HT_SECT)+4+1);/*4 для цифр!!!*/    
  if(szTpMenu==NULL)
    http_err("Error no memory for Create Menu!");
  sprintf(szTpMenu,"%s?%s=%d",CGI_PATH_CAT,HT_SECT,TPMNIT_3);
  printf(CGI_TopMenu_w4x2p,TPMNIT_LNK_1,TPMNIT_ALT_1,
                           TPMNIT_LNK_2,TPMNIT_ALT_2,
			   szTpMenu,TPMNIT_ALT_3,
			   TPMNIT_LNK_4,TPMNIT_ALT_4);
  free(szTpMenu);
    
/*выбор левого меню*/
  switch(iSect){
#if defined __REG
    case MN_REG:
      CGICatLftMenu();
      break;
#endif
#if defined __ORD
    case TPMNIT_2:
      if(blVerifyUser==0)
        CGICatLftMenu();      
      else
        CGIBskLftMenu();
      break;
#endif
#if defined __BASK
    case TPMNIT_4:/*Basket*/
      CGICatLftMenu();
      break;
#endif
    default:/*Catalog & files*/
      CGICatLftMenu();
      break;
  }

  printf(CGI_MnTxt_w0p);
  printf(CGI_TxtHd_w2p,szImg0,szImg1);
  printf(CGI_TxtMnSt_w0p);
}

void CGICatLftMenu(void)
{
  char *szMenu[5];
  char *szImg0,*szImg1;
  int i;

/* Основной блок начало */
  printf(CGI_MnBlokSt_w0p);
/*Кол-во меню 5, указано при создании szMenu */
  for(i=0;i<5;i++){
    szMenu[i]=malloc(sizeof(CGI_PATH_CAT)+sizeof("?=")+sizeof(HT_SECT)+4+1);/*4 для цифр!!!*/
    if(szMenu[i]==NULL)
      http_err("Error no memory for Create Menu!");
  }
  sprintf(szMenu[0],"%s?%s=%d",CGI_PATH_CAT,HT_SECT,MNIT_ABT);
  sprintf(szMenu[1],"%s?%s=%d",CGI_PATH_CAT,HT_SECT,MNIT_KMP_HLD);
  sprintf(szMenu[2],"%s?%s=%d",CGI_PATH_CAT,HT_SECT,MNIT_THN_OBR);
  sprintf(szMenu[3],"%s?%s=%d",CGI_PATH_CAT,HT_SECT,MNIT_KND_INV);
  sprintf(szMenu[4],"%s?%s=%d",CGI_PATH_CAT,HT_SECT,MNIT_KUH_INV);
  printf(CGI_LfMn_w5x2p,szMenu[0],MNITVL_ABT,
                        szMenu[1],MNITVL_KMP_HLD,
			szMenu[2],MNITVL_THN_OBR,
			szMenu[3],MNITVL_KND_INV,
			szMenu[4],MNITVL_KUH_INV);
  for(i=0;i<5;i++)
    free(szMenu[i]);
}

#if defined __ORD
void CGIBskLftMenu(void) {
  printf("<FORM METHOD=POST ACTION=\"%s\">\n",CGI_PATH_ORDER);
  printf("<tr><td valign=\"top\">");
  printf("<input type=hidden name=%s value=%s>", HT_FLD_ORDER, HT_ORD_MDFY_USR);
  printf("<input type=hidden name=%s value=%s>",
          Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].szHTFldName,
          Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].szHTFldValue);
  printf("<input type=hidden name=%s value=%s>",
          Tb[TB_USERS].Prm[HT_NUM_USR_PASSWD].szHTFldName,
          Tb[TB_USERS].Prm[HT_NUM_USR_PASSWD].szHTFldValue);
  printf("<input type=image src=\"%s\">",PATH_IMG_M_ORD_MDFY_USR);
  printf("</td></tr>\n");
  printf("</FORM>\n");
  printf("<FORM METHOD=POST ACTION=\"%s\">\n",CGI_PATH_ORDER);
  printf("<tr><td valign=\"top\">");
  printf("<input type=hidden name=%s value=%s>", HT_FLD_ORDER, HT_ORD_SHOW);
  printf("<input type=hidden name=%s value=%s>",
          Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].szHTFldName,
          Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].szHTFldValue);
  printf("<input type=hidden name=%s value=%s>",
          Tb[TB_USERS].Prm[HT_NUM_USR_PASSWD].szHTFldName,
          Tb[TB_USERS].Prm[HT_NUM_USR_PASSWD].szHTFldValue);
  printf("<input type=image src=\"%s\">",PATH_IMG_M_ORD_BSK);
  printf("</td></tr>\n");
  printf("</FORM>\n");
  printf("<FORM METHOD=POST ACTION=\"%s\">\n",CGI_PATH_CAT);
  printf("<tr><td valign=\"top\">");
  printf("<input type=image src=\"%s\">",PATH_IMG_ORD_CAT);
  printf("</td></tr>\n");
  printf("</FORM>\n");
}
#endif

void CGIFooter(void)
{
  char *szBtMenu[5];
  int i;
/* Основной блок конец */
  printf(CGI_TxtMnEn_w0p);
  printf(CGI_MnBlokEn_w0p);

/*Кол-во меню 5, указано при создании szMenu */
  for(i=0;i<5;i++){
    szBtMenu[i]=malloc(sizeof(CGI_PATH_CAT)+sizeof("?=")+sizeof(HT_SECT)+4+1);/*4 для цифр!!!*/
    if(szBtMenu[i]==NULL)
      http_err("Error no memory for Create Bt Menu!");
  }
  sprintf(szBtMenu[0],"%s?%s=%d",CGI_PATH_CAT,HT_SECT,MNIT_ABT);
  sprintf(szBtMenu[1],"%s?%s=%d",CGI_PATH_CAT,HT_SECT,MNIT_KMP_HLD);
  sprintf(szBtMenu[2],"%s?%s=%d",CGI_PATH_CAT,HT_SECT,MNIT_THN_OBR);
  sprintf(szBtMenu[3],"%s?%s=%d",CGI_PATH_CAT,HT_SECT,MNIT_KND_INV);
  sprintf(szBtMenu[4],"%s?%s=%d",CGI_PATH_CAT,HT_SECT,MNIT_KUH_INV);
  printf(CGI_BtMn_w5x2p,szBtMenu[0],MNITVL_ABT,
                        szBtMenu[1],MNITVL_KMP_HLD,
			szBtMenu[2],MNITVL_THN_OBR,
			szBtMenu[3],MNITVL_KND_INV,
			szBtMenu[4],MNITVL_KUH_INV);
  for(i=0;i<5;i++)
    free(szBtMenu[i]);
  printf(CGI_BtFt_w0p);
}

char *SetSelectStr(uint iTbNum)
{
  char *szTmp;
  char blIsTrue;
  uint i;

  szTmp=malloc(strlen(szQS)+100+sizeof(Tb[iTbNum].szVwFld));
  if(szTmp==NULL)
    http_err("Error no memory for MySQL SELECT!");
  strcpy(szTmp,"SELECT \n");
  strcat(szTmp, Tb[iTbNum].szVwFld);
  strcat(szTmp, "\n FROM \n");
  strcat(szTmp, Tb[iTbNum].szName);
  strcat(szTmp, "\n WHERE \n");
  blIsTrue=0;
  for(i=0;i<Tb[iTbNum].iQntFld;i++)
  {
    if(Tb[iTbNum].Prm[i].blData)
    {

      if(blIsTrue==0)
      blIsTrue=1;
      else
        strcat(szTmp, " AND ");
      strcat(szTmp, Tb[iTbNum].Prm[i].szTBFldName);
      strcat(szTmp, " = \"");
      strcat(szTmp, Tb[iTbNum].Prm[i].szHTFldValue);
      strcat(szTmp, "\"");
    }
  }
  strcat(szTmp, ";");
#ifdef DEBAG
  printf("%s<br>\n",szTmp);
#endif
  return szTmp;
}




int VerifyUser(void)
{
  char blIsTrue;
  char *szTmp;
  uint i;


  blIsTrue = GetQV(0, TB_USERS);
  if(Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].blData==1 && Tb[TB_USERS].Prm[HT_NUM_USR_PASSWD].blData==1)
  {
    for(i=0;i<Tb[TB_USERS].iQntFld;i++)/*Chtoby ne iskalo leshnee*/
      Tb[TB_USERS].Prm[i].blData=0;
    Tb[TB_USERS].Prm[HT_NUM_USR_EMAIL].blData=1;
    Tb[TB_USERS].Prm[HT_NUM_USR_PASSWD].blData=1;

    szTmp=SetSelectStr(TB_USERS);

    if (mysql_query(&mysql,szTmp)!=0)
      mysql_err(3);
    free(szTmp);
    if (!(res = mysql_store_result(&mysql))) mysql_err(4);
    if(mysql_num_rows(res)!=0)
    {
      mysql_free_result(res);
      return 1;
    }
    mysql_free_result(res);
  }
  return 0;
}

#endif