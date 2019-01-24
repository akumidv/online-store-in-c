#!/bin/sh
#Первый параметр запуска пароль root для MySQL

#Константы
mysql="/usr/local/mysql/bin/mysql"	#Путь к MySQL

NmDB="VTK"		#Имя базы
NmTBCat="cat"		#Имя таблицы каталога
NmTBUsr="users"		#Имя таблицы пользователей
NmTBOrd="orders"	#Имя таблицы заказов
NmTBHrk="harakt"	#Имя таблицы характеристик базы каталога
NmTBBsk="basket"	#Имя таблицы корзины пользователей

#Переменные
cmd=""

    cmd="$cmd LOAD DATA INFILE '$PWD/$NmDB-$NmTBCat.txt' INTO TABLE $NmDB.$NmTBCat;"
    cmd="$cmd LOAD DATA INFILE '$PWD/$NmDB-$NmTBUsr.txt' INTO TABLE $NmDB.$NmTBUsr;"
    cmd="$cmd LOAD DATA INFILE '$PWD/$NmDB-$NmTBOrd.txt' INTO TABLE $NmDB.$NmTBOrd;"
    cmd="$cmd LOAD DATA INFILE '$PWD/$NmDB-$NmTBHrk.txt' INTO TABLE $NmDB.$NmTBHrk;"
    cmd="$cmd LOAD DATA INFILE '$PWD/$NmDB.$NmTBBsk.txt' INTO TABLE $NmDB.$NmTBBsk;"

#echo $cmd;

$mysql --user=root --password="$1" --host="localhost" --execute="$cmd"
