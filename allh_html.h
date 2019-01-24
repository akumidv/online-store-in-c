#if !defined __ALLH_HTML_H
#define __ALLH_HTML_H

#define	  HT_VL_USE_CPY "Другое..."

#define   CGI_PATH_HELP  "/cgi-bin/Help.cg"
#define   CGI_PATH_FIRST "/index.html"

#define   MAIL_ADR_CAT  "root@localhost"
#define   MAIL_ADR_FROM  "root@.ru"


#define   CGI_PATH      "/cgi-bin/sec/SetBase.cg"
#define   CGI_PATH_CAT  "/cgi-bin/Cat.cg"
#define   CGI_PATH_BASK  "/cgi-bin/Basket.cg"
#define   CGI_PATH_ORDER  "/cgi-bin/Order.cg"
#define   CGI_PATH_REG  "/cgi-bin/Registration.cg"

#define   PATH_IMG_PUT_ORDER  "/image/zakaz1.gif"

#define   PATH_IMG_SEARCH  "/image/search.gif"

#define   PATH_IMG_ORDER  "/image/enter.gif"

#define   PATH_IMG_REG    "/image/registr.gif"
#define   PATH_IMG_NEW_USER  "/image/new_user.gif"
#define   PATH_IMG_UPD_BASK  "/image/refresh.gif"

#define   PATH_IMG_HD_BASK  "/image/korzina.gif"

#define   PATH_IMG_M_ORD_MDFY_USR  "/image/usr_dat.gif"
#define   PATH_IMG_M_ORD_BSK  "/image/bask.gif"
#define   PATH_IMG_ORD_UPD_USR  "/image/refresh.gif"
#define   PATH_IMG_ORD_CAT  "/image/catalog.gif"


#define   HT_CAT_KEY_CPY   "F_CAT_KEY"
#define   HT_USERS_KEY_CPY   "F_USERS_KEY"
#define   HT_ORDERS_KEY_CPY   "F_ORDERS_KEY"
#define   HT_HARAKT_KEY_CPY   "F_HARAKT_KEY"
#define   HT_BASKET_KEY_CPY   "F_BASKET_KEY"

#define   HT_IDENT      "ID"

#define   HT_IN_START   "<table  width=100%%>\n"
#define   HT_INPUT      "<tr>\n<td>%s</td>\n<td><input type=text name=\"%s\" value=\"%s\" size=\"%d\"></td></tr>"
#define   HT_SB_TB_HD_w1p   "<tr>\n<td>%s</td>\n<td>\n"
#define   HT_SB_TB_MD_w0p   "</td>\n<td>"
#define   HT_SB_TB_FT_w0p   "</td></tr>"
#define   HT_INP_SLCT_EXT_HD_w1p "<select name=\"%s\">\n"
#define   HT_INP_SLCT_EXT_DEF_w2p "<option value=\"%s\" SELECTED>%s</option>\n"
#define   HT_INP_SLCT_w2p "<option value=\"%s\">%s</option>\n"
#define   HT_INP_SLCT_FT_w0p "</select>\n"
#define   HT_INP_SLCT_EXT_w3p "<input type=text name=\"%sEXT\" value=\"%s\" size=\"%d\">\n"
#define   HT_INP_HDN_EXT_w2p  "<input type=hidden name=\"%sEXT\" value=\"%s\">\n"


#define   HT_INPUT_PSWD "<tr>\n<td>%s</td>\n<td><input type=password name=\"%s\" value=\"%s\" size=\"%d\"></td></tr>"
#define   HT_INPUT_BIG  "<tr>\n<td>%s</td>\n<td><textarea name=\"%s\" cols=\"%d\" rows=\"%d\" wrap=\"physical\">%s</textarea></td></tr>"
#define   HT_INPUT_HIDDEN      "<input type=hidden name=\"%s\" value=\"%s\">\n"
#define   HT_INPUT_HID_DG      "<input type=hidden name=\"%s\" value=\"%d\">\n"
#define   HT_IN_END     "</table>\n"

/*NEW ********************/
/*VT-код вида товара, MNIT - menu item, MNITVL - MNIT описание(value),
MNITLN - link, MNITLNIM - link image*/
#define   HT_SECT	"SCT"
/*Menu Item & Menu Item Value */
#define   MNIT_ABT 	0
#define   MNITVL_ABT 	"::О НАС::"
#define   MNITLN_ABT 	"../about.html"
#define   MNITLNIM0_ABT "/image/o_nas0.gif"
#define   MNITLNIM1_ABT "/image/o_nas2.gif"

#define   MNIT_KUH_INV 	1
#define   MNITVL_KUH_INV "::КУХОННЫЙ ИНВЕНТАРЬ::"
#define   MNITLNIM0_KUH_INV "/image/house_inv0.gif"
#define   MNITLNIM1_KUH_INV "/image/house_inv2.gif"
#define   VT_KUH_INV	"KUH_INV"

#define   MNIT_KND_INV 	2
#define   MNITVL_KND_INV "::КОНДИТЕРСКИЙ ИНВЕНТАРЬ::"
#define   MNITLNIM0_KND_INV "/image/kond_inv0.gif"
#define   MNITLNIM1_KND_INV "/image/kond_inv2.gif"
#define   VT_KND_INV 	"KND_INV"

#define   MNIT_KMP_HLD 3
#define   MNITVL_KMP_HLD "::КОМПЛЕКТУЮЩИЕ К ХОЛОДИЛЬНОМУ ОБОРУДОВНИЮ::"
#define   MNITLNIM0_KMP_HLD "/image/komp000.gif"
#define   MNITLNIM1_KMP_HLD "/image/komp002.gif"
#define   VT_KMP_HLD "KMP_HLD"

#define   MNIT_THN_OBR 4
#define   MNITVL_THN_OBR "::ТЕХНОЛОГИЧЕСКОЕ ОБОРУДОВНИЕ::"
#define   MNITLNIM0_THN_OBR "/image/tech0.gif"
#define   MNITLNIM1_THN_OBR "/image/tech2.gif"
#define   VT_THN_OBR "THN_OBR"

/*Top menu*/
#define TPMNIT_1	0
#define TPMNIT_ALT_1 "::ГЛАВНАЯ::"
#define TPMNIT_LNK_1 CGI_PATH_FIRST

#define TPMNIT_2	10
#define TPMNIT_ALT_2 "::СИСТЕМА ЗАКАЗОВ::"
#define TPMNIT_LNK_2 CGI_PATH_ORDER
#define TPMNIT_LNKIMG0_2 "/image/r0.gif"
#define TPMNIT_LNKIMG1_2 "/image/r2.gif"

#define TPMNIT_3	11
#define TPMNIT_ALT_3 	"::ПОМОЩЬ::"
#define TPMNIT_LNK_3 	"../cat_help.html" /*!!!!!!! вызывать через каталог*/
#define TPMNIT_LNKIMG0_3 "/image/help0.gif"
#define TPMNIT_LNKIMG1_3 "/image/help2.gif"

#define TPMNIT_4	12
#define TPMNIT_ALT_4 "::КОРЗИНА::"
#define TPMNIT_LNK_4 CGI_PATH_BASK
#define TPMNIT_LNKIMG0_4 "/image/korzina0.gif"
#define TPMNIT_LNKIMG1_4 "/image/korzina2.gif"

#define MN_REG		13
#define MN_ALT_REG "::РЕГИСТРАЦИЯ::"
#define MN_LNKIMG0_REG "/image/r0.gif"
#define MN_LNKIMG1_REG "/image/r2.gif"

/* Верхний заголовок html, параметр название страницы в title */
#define CGI_TopHd_w1p "<html><head>\n\
   <title>ВТК%s</title>\n\
<link href=\"/style_one.css\" rel=stylesheet type=text/css>\n\
 </head>\n\
<body topmargin=0 leftmargin=0 rightmargin=0 marginheight=0 marginwidth=0 bgcolor=#ffffff>\n"

/* Заголовок, без параметров */
#define CGI_Hd_w0p "<table background=\"/image/fon_head.gif\" cellspacing=0 cellpadding=0 border=0 width=100%%>\n\
<tr><td align=left>\n\
   <table cellspacing=0 cellpadding=0 border=0><tr>\n\
        <td width=49 height=89><img src=\"/image/inde000.gif\" width=49 height=89 border=0></td>\n\
        <td width=164 height=89><img src=\"/image/inde001.gif\" width=164 height=89 border=0></td>\n\
        <td width=12 height=89><img src=\"/image/inde002.gif\" width=12 height=89 border=0></td>\n\
        <td width=114 height=89><img src=\"/image/inde003.gif\" width=114 height=89 border=0></td>\n\
        <td width=9 height=89><img src=\"/image/inde004.gif\" width=9 height=89 border=0></td>\n\
	<td width=142 height=89><img src=\"/image/inde005.gif\" width=142 height=89 border=0></td>\n\
        <td width=7 height=89><img src=\"/image/inde006.gif\" width=7 height=89 border=0></td>\n\
        <td width=128 height=89><img src=\"/image/inde007.gif\" width=128 height=89 border=0></td>\n\
        <td width=8 height=89><img src=\"/image/inde008.gif\" width=8 height=89 border=0></td>\n\
        <td width=136 height=89><img src=\"/image/inde009.gif\" width=136 height=89 border=0></td>\n\
        <td width=8 height=89><img src=\"/image/inde010.gif\" width=8 height=89 border=0></td>\n\
    </tr></table>\n\
</td></tr></table>\n"



/* Верхнее меню, парметры 4х2, ссылки и поле alt для меню  */
#define CGI_TopMenu_w4x2p "<table cellspacing=0 cellpadding=0 border=0 width=100%%>\n\
<tr><td align=left>\n\
   <table cellspacing=0 cellpadding=0 border=0><tr>\n\
        <td width=49 height=24><img src=\"/image/inde011.gif\" width=49 height=24 border=0></td>\n\
        <td width=164 height=24><img src=\"/image/inde012.gif\" width=164 height=24 border=0></td>\n\
        <td width=12 height=24><img src=\"/image/inde013.gif\" width=12 height=24 border=0></td>\n\
        <td width=114 height=24><a href=\"%s\"><img src=\"/image/inde014.gif\" width=114 height=24 border=0 alt=\"%s\"></a></td>\n\
        <td width=9 height=24><img src=\"/image/inde015.gif\" width=9 height=24 border=0></td>\n\
        <td width=142 height=24><a href=\"%s\"><img src=\"/image/inde016.gif\" width=142 height=24 border=0 alt=\"%s\"></a></td>\n\
        <td width=7 height=24><img src=\"/image/inde017.gif\" width=7 height=24 border=0></td>\n\
        <td width=128 height=24><a href=\"%s\"><img src=\"/image/inde018.gif\" width=128 height=24 border=0 alt=\"%s\"></a></td>\n\
        <td width=8 height=24><img src=\"/image/inde019.gif\" width=8 height=24 border=0></td>\n\
        <td width=136 height=24><a href=\"%s\"><img src=\"/image/inde020.gif\" width=136 height=24 border=0 alt=\"%s\"></a></td>\n\
        <td width=8 height=24><img src=\"/image/inde021.gif\" width=8 height=24 border=0></td>\n\
    </tr></table>\n\
</td></tr></table>\n"

#define CGI_MnBlokSt_w0p "<table cellspacing=0 cellpadding=0 border=0 width=100%%>\n\
<tr><td>\n\
<table  cellspacing=0 cellpadding=0 border=0 width=100%% height=100%%>\n\
<tr><td background=\"/image/fon_menu.gif\" valign=top>\n"

#define CGI_MnBlokEn_w0p "</td></tr></table>\n\
</td></tr></table>"

/*Левое меню, 5х2 параметры, ссылка на раздел и поле alt для рисунка*/
#define CGI_LfMn_w5x2p "<table cellspacing=0 cellpadding=0 border=0 width=213 height=100%%>\n\
<tr><td valign=top>\n\
    <table  cellspacing=0 cellpadding=0 border=0 width=213><tr>\n\
       <td width=49 height=60><img src=\"/image/inde022.gif\" width=49 height=60 border=0></td>\n\
       <td width=164 height=60><a href=\"%s\"><img src=\"/image/inde023.gif\" width=164 height=60 border=0 alt=\"%s\"></a></td>\n\
    </tr><tr>\n\
       <td width=49 height=49><img src=\"/image/inde033.gif\" width=49 height=49 border=0></td>\n\
       <td width=164 height=49><a href=\"%s\"><img src=\"/image/inde034.gif\" width=164 height=49 border=0 alt=\"%s\"></a></td>\n\
     </tr><tr>\n\
       <td width=49 height=51><img src=\"/image/inde044.gif\" width=49 height=51 border=0></td>\n\
       <td width=164 height=51><a href=\"%s\"><img src=\"/image/inde045.gif\" width=164 height=51 border=0 alt=\"%s\"></a></td>\n\
     </tr><tr>\n\
       <td width=49 height=49><img src=\"/image/inde055.gif\" width=49 height=49 border=0></td>\n\
       <td width=164 height=49><a href=\"%s\"><img src=\"/image/inde056.gif\" width=164 height=49 border=0 alt=\"%s\"></a></td>\n\
     </tr><tr>\n\
       <td width=49 height=51><img src=\"/image/inde066.gif\" width=49 height=51 border=0></td>\n\
       <td width=164 height=51><a href=\"%s\"><img src=\"/image/inde067.gif\" width=164 height=51 border=0 alt=\"%s\"></a></td>\n\
     </tr><tr>\n\
       <td colspan=2 width=213 height=78><img src=\"/image/inde_gb.gif\" width=213 height=78 border=0></td>\n\
     </tr></table>\n\
      </td></tr>\n\
</table></td>\n"

/*Начало основного блока для текста, без параметров*/
#define CGI_MnTxt_w0p "<td valign=top width=100%%>"

/*Заголовок текстового блока, параметры ссылки на два рисунка заголовка*/
#define CGI_TxtHd_w2p "<table cellspacing=0 cellpadding=0 border=0 width=100%%><tr>\n\
   <td width=342 height=60><img src=\"%s\" width=342 height=60 border=0></td>\n\
   <td background=\"/image/line.gif\" width=100%% height=60></td>\n\
   <td width=90 height=60><img src=\"%s\" width=90 height=60 border=0></td>\n\
</tr></table>"

/*Начало текстового блока*/
#define CGI_TxtMnSt_w0p "<table cellspacing=5 cellpadding=5 border=0 width=100%% height=100%%>\n\
     <tr><td valign=top>"

#define CGI_TxtMnEn_w0p "</td></tr></table>"

/*Нижнее меню */
#define CGI_BtMn_w5x2p "<table cellspacing=0 cellpadding=0 border=0 width=100%%><tr>\n\
    <td align=left width=155 height=47><img src=\"/image/bott000.gif\" width=155 height=47 border=0></td>\n\
    <td align=left background=\"/image/bott.gif\"><img src=\"/image/bott001.gif\" width=57 height=47 border=0></td>\n\
    <td width=70 height=47><a href=\"%s\"><img src=\"/image/bott002.gif\" width=70 height=47 border=0 alt=\"%s\"></a></td>\n\
    <td width=69 height=47><a href=\"%s\"><img src=\"/image/bott003.gif\" width=69 height=47 border=0 alt=\"%s\"></a></td>\n\
    <td width=73 height=47><a href=\"%s\"><img src=\"/image/bott004.gif\" width=73 height=47 border=0 alt=\"%s\"></a></td>\n\
    <td width=68 height=47><a href=\"%s\"><img src=\"/image/bott005.gif\" width=68 height=47 border=0 alt=\"%s\"></a></td>\n\
    <td width=71 height=47><a href=\"%s\"><img src=\"/image/bott006.gif\" width=71 height=47 border=0 alt=\"%s\"></a></td>\n\
    <td align=right background=\"/image/bott2.gif\"><img src=\"/image/bott007.gif\" width=56 height=47 border=0></td>\n\
    <td align=right width=158 height=47><img src=\"/image/bott008.gif\" width=158 height=47 border=0></td>\n\
</tr></table>\n"
/*Нижний заголовок html, без параметров*/
#define CGI_BtFt_w0p "</body></html>"

void HTML_FlOut(char *szName){
  int ch;
  FILE *fh;

  fh=fopen(szName,"r");
  if(fh!=NULL) {
    do {
      ch=fgetc(fh);
      if(ch!=EOF)
        putchar(ch);
      else
        break;
    }
    while(ch!=EOF);
  }
}

#endif