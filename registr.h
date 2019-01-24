#if !defined __REGISTR_H
#define __REGISTR_H

#define HT_REG_TBL_HEAD_w1p "<center>\n\
<FORM METHOD=POST ACTION=\"%s\">\n\
<table cellspacing=2 cellpadding=3 bgcolor=#DADADA border=0>\n\
<tr><td colspan=2 align=center class=bg>Поля обязательные для ввода</td></tr>\n"

#define HT_REG_TBL_MDL "<tr><td colspan=2 align=center class=bg>Поля используемые при оформлении счетов для организаций</td></tr>\n"

#define HT_REG_TBL_FOOT "</table></FORM></center>\n"

#define HT_REG_TBL_FLD_LEN_l_50_w4p "<tr><td colspan=2 align=center class=bg>%s</td>\n\
  <td class=bg><INPUT type=text name=\"%s\" value=\"%s\" size=%d></td></tr>\n"

#define HT_REG_TBL_FLD_LEN_b_50_w5p "<tr><td colspan=2 align=center class=bg>%s</td>\n\
<td colspan=2 align=center class=bg>\n\
<TEXTAREA name=\"%s\" cols=%d rows=%d wrap=physical></TEXTAREA>%s</td>\n\
</tr>\n"

#define HT_REG_TBL_PSWD_w5p "<tr><td colspan=2 align=center class=bg>%s</td>\n\
  <td class=bg><INPUT type=password name=\"%s\" value=\"\" size=%d></td></tr>\n\
  <tr><td colspan=2 align=center class=bg>Повторить</td>\n\
  <td class=bg><INPUT type=password name=\"%s\" value=\"\" size=%d></td></tr>\n"

#define HT_REG_TBL_PUT_IMG_w0p "<tr><td colspan=2 align=right class=bg height=9>\
<INPUT src=\"/image/registr.gif\" type=image border=0 alt=\"Регистрация\"></td></tr>\n"

void ShowRegForm(void)
{
  uint i;


  printf(HT_REG_TBL_HEAD_w1p,CGI_PATH_REG);

    i=HT_NUM_USR_EMAIL;
    if(Tb[TB_USERS].Prm[i].blData)
      printf(HT_REG_TBL_FLD_LEN_l_50_w4p,Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,Tb[TB_USERS].Prm[i].szHTFldValue,Tb[TB_USERS].Prm[i].iFldLen);
    else
      printf(HT_REG_TBL_FLD_LEN_l_50_w4p, Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,"",Tb[TB_USERS].Prm[i].iFldLen);
    i=HT_NUM_USR_PASSWD;
    printf(HT_REG_TBL_PSWD_w5p, Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,Tb[TB_USERS].Prm[i].iFldLen,Tb[TB_USERS].Prm[i].szHTFldNameCpy,Tb[TB_USERS].Prm[i].iFldLen);
    i=HT_NUM_USR_FIO;
    if(Tb[TB_USERS].Prm[i].blData)
      printf(HT_REG_TBL_FLD_LEN_l_50_w4p,Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,Tb[TB_USERS].Prm[i].szHTFldValue,Tb[TB_USERS].Prm[i].iFldLen);
    else
      printf(HT_REG_TBL_FLD_LEN_l_50_w4p, Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,"",Tb[TB_USERS].Prm[i].iFldLen);

    printf(HT_REG_TBL_MDL);
    for(i=HT_NUM_USR_INN;i<HT_NUM_USR_FIO;i++)
    {
      if(Tb[TB_USERS].Prm[i].blData)
      {
        if(Tb[TB_USERS].Prm[i].iFldLen<50)
          printf(HT_REG_TBL_FLD_LEN_l_50_w4p,Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,Tb[TB_USERS].Prm[i].szHTFldValue,Tb[TB_USERS].Prm[i].iFldLen);
        else
          printf(HT_REG_TBL_FLD_LEN_b_50_w5p,Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,50,(abs(Tb[TB_USERS].Prm[i].iFldLen/50)+1),Tb[TB_USERS].Prm[i].szHTFldValue);
      }
      else
      {
        if(Tb[TB_USERS].Prm[i].iFldLen<50)
          printf(HT_REG_TBL_FLD_LEN_l_50_w4p, Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,"",Tb[TB_USERS].Prm[i].iFldLen);
        else
          printf(HT_REG_TBL_FLD_LEN_b_50_w5p,Tb[TB_USERS].Prm[i].szFldName,Tb[TB_USERS].Prm[i].szHTFldName,50,(abs(Tb[TB_USERS].Prm[i].iFldLen/50)+1),"");
      }
    }

    printf(HT_REG_TBL_PUT_IMG_w0p);
    printf(HT_REG_TBL_FOOT);
}

#endif
