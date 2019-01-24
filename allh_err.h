#if !defined __ALLH_ERR_H
#define __ALLH_ERR_H


void mysql_err(int exitcode)
{
  fprintf(stderr, "ICataog-MySQL Err:%s\n", mysql_error(&mysql));
  printf("%s\n", mysql_error(&mysql));
  exit(exitcode);
}

void http_err(char *szStr)
{
    fprintf(stderr,"ICatalog-Http Err: %s\n", szStr);
    printf("Error! Send mail witch date&time to support@.ru. Thanks.\n");
/*    printf(szgHTMLFooter);*/
    printf("</body>\n</html>");
    exit(1);
}

#endif