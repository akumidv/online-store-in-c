#Internet Catalog
#(c) Mr.Ka - mrka@.ru, http://www.100h.ru
#2001-2002 Ver. 1.1
libs=-L'/usr/local/mysql/lib/mysql' -lm -lmysqlclient -lz -lcrypt
incl=-I'/usr/local/mysql/include/mysql'
4all=cgi.o allhead.h allh_err.h allh_fld.h allh_html.h allh_tbl.h allh_val.h
path=/var/www/nbook.100h.ru/cgi-bin
path0=./html/cgi-bin

All:		order registr catalog setbase basket cgi.o
		

registr:	registr.c registr.h ${4all}
		cc  -o ${path0}/Registration.cg registr.c cgi.o ${incl} ${libs}
#		.if ${COPY} == 'true'
		    cp ${path0}/Registration.cg ${path}/Registration.cg
#		.endif

basket:		basket.c basket.h ${4all}
		cc  -o ${path0}/Basket.cg basket.c cgi.o ${incl} ${libs}
#		.if ${COPY} == 'true'
		    cp ${path0}/Basket.cg ${path}/Basket.cg
#		.endif

order:		order.c basket.h ${4all}
		cc  -o ${path0}/Order.cg order.c cgi.o ${incl} ${libs}
#		if ${DOCOPY}
		    cp ${path0}/Order.cg ${path}/Order.cg
#		endif

catalog:	cat.c cat.h allhead.h ${4all}
		gcc  -o ${path0}/Cat.cg cat.c cgi.o ${incl} ${libs}
#		if ${COPY} == 'true'
		    cp ${path0}/Cat.cg ${path}/Cat.cg
#		.enif

setbase:	setbase.c setbase.h ${4all}
		cc  -o ${path0}/SetBase.cg setbase.c cgi.o ${incl} ${libs}
#		.if ${COPY} == 'true'
		    cp ${path0}/SetBase.cg ${path}/sec/SetBase.cg
#		.endif

cgi.o:		cgi.c cgi.h cgitbl.h
		cc -c cgi.c