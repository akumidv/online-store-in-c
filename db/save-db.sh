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

#Сохраняем базу
    cmd="$cmd SELECT* INTO OUTFILE '$PWD/$NmDB-$NmTBCat.txt' FROM $NmDB.$NmTBCat;"
    cmd="$cmd SELECT* INTO OUTFILE '$PWD/$NmDB-$NmTBUsr.txt' FROM $NmDB.$NmTBUsr;"
    cmd="$cmd SELECT* INTO OUTFILE '$PWD/$NmDB-$NmTBOrd.txt' FROM $NmDB.$NmTBOrd;"
    cmd="$cmd SELECT* INTO OUTFILE '$PWD/$NmDB-$NmTBHrk.txt' FROM $NmDB.$NmTBHrk;"
    cmd="$cmd SELECT* INTO OUTFILE '$PWD/$NmDB.$NmTBBsk.txt' FROM $NmDB.$NmTBBsk;"

#echo $cmd

$mysql --user=root --password="$1" --host="localhost" --execute="$cmd"
