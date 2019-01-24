#if !defined __ALLH_VAL_H
#define __ALLH_VAL_H

#define   TBQNT           5

char *szQS;

MYSQL mysql;
MYSQL_RES *res;
MYSQL_ROW row;


/*Parametry Tablici*/
typedef struct  tagTbParam
{
  char *szFldName; /*Nazvanie polya*/
  char *szTBFldName; /*Nazvanie polya v Tablice*/
  char *szHTFldName; /*Nazvanie polya v HTML */
  char *szHTFldValue; /*Dannie polya v HTML */
  char *szHTFldNameCpy; /*Nazvanie copii polya v HTML dly poiska posle DELETE */
  uint iFldLen; /*Dlina polya*/
  char blData; /*Dlya predvaritel'noy proverki - est' li dannie*/
} TBPrm;


typedef struct tagTb
{
  char *szName; /*Nazvanie Tablicy*/
  uint iQntFld;/*Kolichestvo poley v tablice*/
  char *szHTFldKeyCpy;/*Nazvanie polya copii clycha*/
  char *szVwFld;
  TBPrm *Prm;/*Parametry Tablicy*/
} TB;


TB Tb[TBQNT];

#endif