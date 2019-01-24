#!/bin/sh
#Первый параметр запуска пароль root для MySQL

#Настройки
blDrop="base"		#Пересоздать базу(base) или таблицы(table)
blCrtUsr="true"		#Создавать пользователей (true/false)
blShow="true"		#Выдавать информацию о созданной БД (true/false)
blDBSave="false"	#Записать данные из старых таблиц(true/false)
blDBLoad="false"	#Загрузить данные из фалов (true/false)

#Константы
mysql="/usr/local/mysql/bin/mysql"	#Путь к MySQL

NmDB="VTK"		#Имя базы
NmTBCat="cat"		#Имя таблицы каталога
NmTBUsr="users"		#Имя таблицы пользователей
NmTBOrd="orders"	#Имя таблицы заказов
NmTBHrk="harakt"	#Имя таблицы характеристик базы каталога
NmTBBsk="basket"	#Имя таблицы корзины пользователей

UsrGuest="VTK-gst_cat"	#Пользователь с правами только чтения каталога
PswGuest="123456"	#Пароль пользователя Guest
UsrBsket="VTK-bsk_add"	#Пользователь с правами добавления в карзину
PswBsket="123456"	#Пароль пользователя Bsket
UsrRegstr="VTK-usr_reg"	#Пользователь зарегистрированный в системе
PswRegstr="123456"	#Пароль пользователя Regstr
UsrAdm="VTK-admin"	#Пользователь администратор базы
PswAdm="123456"	#Пароль пользователя Adm

#Переменные
cmd=""

#Сохраняем базу
if test $blDBSave = "true"; then
    cmd="$cmd SELECT* INTO OUTFILE '$PWD/db/$NmDB-$NmTBCat.txt' FROM $NmDB.$NmTBCat;"
    cmd="$cmd SELECT* INTO OUTFILE '$PWD/db/$NmDB-$NmTBUsr.txt' FROM $NmDB.$NmTBUsr;"
    cmd="$cmd SELECT* INTO OUTFILE '$PWD/db/$NmDB-$NmTBOrd.txt' FROM $NmDB.$NmTBOrd;"
    cmd="$cmd SELECT* INTO OUTFILE '$PWD/db/$NmDB-$NmTBHrk.txt' FROM $NmDB.$NmTBHrk;"
    cmd="$cmd SELECT* INTO OUTFILE '$PWD/db/$NmDB.$NmTBBsk.txt' FROM $NmDB.$NmTBBsk;"
fi


#Создаем базу
if test $blDrop = "base"; then
    cmd="$cmd DROP DATABASE IF EXISTS $NmDB;"
    cmd="$cmd CREATE DATABASE $NmDB;"
fi

#Создаем таблицу каталога
if test $blDrop = "table"; then
    cmd="$cmd DROP TABLE IF EXISTS $NmDB.$NmTBCat;"
fi
cmd="$cmd CREATE TABLE $NmDB.$NmTBCat "
#PRIMARY KEY,"
cmd="$cmd ( kod       INTEGER UNSIGNED AUTO_INCREMENT PRIMARY KEY,"
#cmd="$cmd ( kod       CHAR(16) AUTO_INCREMENT,"
cmd="$cmd   vid_tov   CHAR(8) NOT NULL,"
cmd="$cmd   sub_vid   CHAR(32),"
cmd="$cmd   tip       CHAR(16),"
cmd="$cmd   imya_tov  CHAR(64) NOT NULL,"
cmd="$cmd   cena      DECIMAL(8,2) NOT NULL,"
cmd="$cmd   marka     CHAR(32),"
cmd="$cmd   art       CHAR(8),"
cmd="$cmd   opis_tov    VARCHAR(255),"
cmd="$cmd   harakt0   CHAR(24),"
cmd="$cmd   harakt1   CHAR(24),"
cmd="$cmd   harakt2   CHAR(24),"
cmd="$cmd   harakt3   CHAR(24),"
cmd="$cmd   slk_izobr   CHAR(64),"
cmd="$cmd   kolv      INTEGER UNSIGNED NOT NULL,"
cmd="$cmd   vidim     TINYINT UNSIGNED NOT NULL"
cmd="$cmd );"

#Создаем таблицу пользователей
if test $blDrop = "table"; then
    cmd="$cmd DROP TABLE IF EXISTS $NmDB.$NmTBUsr;"
fi
cmd="$cmd CREATE TABLE $NmDB.$NmTBUsr "
cmd="$cmd ( email       CHAR(32) PRIMARY KEY,"
cmd="$cmd   passwd      CHAR(16) NOT NULL,"
cmd="$cmd   inn         CHAR(12),"
cmd="$cmd   naim_org    CHAR(96),"
cmd="$cmd   adres_poch  VARCHAR(255),"
cmd="$cmd   tel         CHAR(48),"
cmd="$cmd   fax         CHAR(24),"
cmd="$cmd   fio         CHAR(48) NOT NULL"
cmd="$cmd );"

#Создаем таблицу заказов
if test $blDrop = "table"; then
    cmd="$cmd DROP TABLE IF EXISTS $NmDB.$NmTBOrd;"
fi
cmd="$cmd CREATE TABLE $NmDB.$NmTBOrd "
cmd="$cmd ( order_num   INTEGER UNSIGNED NOT NULL,"
cmd="$cmd   email       CHAR(32) NOT NULL,"
cmd="$cmd   kod         CHAR(16) NOT NULL,"
cmd="$cmd   kolv        INTEGER UNSIGNED,"
cmd="$cmd   date_reg    DATE,"
cmd="$cmd   date_isp    DATE,"
cmd="$cmd   status      CHAR(1),"
cmd="$cmd   PRIMARY KEY (order_num, email, kod)"
cmd="$cmd );"

#Создаем таблицу характеристик каталога
if test $blDrop = "table"; then
    cmd="$cmd DROP TABLE IF EXISTS $NmDB.$NmTBHrk;"
fi
cmd="$cmd CREATE TABLE $NmDB.$NmTBHrk "
cmd="$cmd ( vid_tov   CHAR(8) PRIMARY KEY,"
cmd="$cmd   harakt0   CHAR(24),"
cmd="$cmd   harakt1   CHAR(24),"
cmd="$cmd   harakt2   CHAR(24),"
cmd="$cmd   harakt3   CHAR(24)"
cmd="$cmd );"


#Создаем таблицу корзины пользователей
if test $blDrop = "table"; then
    cmd="$cmd DROP TABLE IF EXISTS $NmDB.$NmTBBsk;"
fi
cmd="$cmd CREATE TABLE $NmDB.$NmTBBsk"
cmd="$cmd ( ip          CHAR(32) NOT NULL,"
cmd="$cmd   kod         CHAR(16) NOT NULL,"
cmd="$cmd   kolv        INTEGER UNSIGNED,"
cmd="$cmd   date_reg    DATE,"
cmd="$cmd   PRIMARY KEY(ip,kod)"
cmd="$cmd );"

#Вывод информации о созданных таблицах
if test $blShow = "true"; then
  cmd="$cmd SHOW tables FROM $NmDB;"
  cmd="$cmd SHOW COLUMNS FROM $NmDB.$NmTBCat;"
  cmd="$cmd SHOW COLUMNS FROM $NmDB.$NmTBUsr;"
  cmd="$cmd SHOW COLUMNS FROM $NmDB.$NmTBOrd;"
  cmd="$cmd SHOW COLUMNS FROM $NmDB.$NmTBHrk;"
  сmd="$cmd SHOW COLUMNS FROM $NmDB.$NmTBBsk;"
fi
#Создаем пользователей и права доступа к таблицам
if test $blCrtUsr = "true"; then
  cmd="$cmd DELETE FROM mysql.tables_priv WHERE db='$NmDB';"
  cmd="$cmd DELETE FROM mysql.db WHERE db='$NmDB';"
  cmd="$cmd DELETE FROM mysql.user WHERE user='$UsrGuest';"
  cmd="$cmd DELETE FROM mysql.user WHERE user='$UsrBsket';"
  cmd="$cmd DELETE FROM mysql.user WHERE user='$UsrRegstr';"
  cmd="$cmd DELETE FROM mysql.user WHERE user='$UsrAdm';"
  
  cmd="$cmd INSERT INTO mysql.user (Host,user,password) VALUES ('localhost','$UsrGuest',password('$PswGuest'));"
  cmd="$cmd INSERT INTO mysql.tables_priv (Host,db,user,Table_name,Table_priv) VALUES ('localhost','$NmDB','$UsrGuest','$NmTBCat','Select');"
  cmd="$cmd INSERT INTO mysql.tables_priv (Host,db,user,Table_name,Table_priv) VALUES ('localhost','$NmDB','$UsrGuest','$NmTBHrk','Select');"

  cmd="$cmd INSERT INTO mysql.user (Host,user,password) VALUES ('localhost','$UsrBsket',password('$PswBsket'));"
  cmd="$cmd INSERT INTO mysql.db (Host,db,user,Select_priv) VALUES ('localhost','$NmDB','$UsrBsket','Y');"
  cmd="$cmd INSERT INTO mysql.tables_priv (Host,db,user,Table_name,Table_priv) VALUES ('localhost','$NmDB','$UsrBsket','$NmTBBsk','Select,Insert,Update,Delete');"
  cmd="$cmd INSERT INTO mysql.tables_priv (Host,db,user,Table_name,Table_priv) VALUES ('localhost','$NmDB','$UsrBsket','$NmTBOrd','Insert');"

  cmd="$cmd INSERT INTO mysql.user (Host,user,password) VALUES ('localhost','$UsrRegstr',password('$PswRegstr'));"
  cmd="$cmd INSERT INTO mysql.tables_priv (Host,db,user,Table_name,Table_priv) VALUES ('localhost','$NmDB','$UsrRegstr','$NmTBUsr','Select,Insert,Update,Delete');"
  cmd="$cmd INSERT INTO mysql.tables_priv (Host,db,user,Table_name,Table_priv) VALUES ('localhost','$NmDB','$UsrRegstr','$NmTBCat','Select');"
  cmd="$cmd INSERT INTO mysql.tables_priv (Host,db,user,Table_name,Table_priv) VALUES ('localhost','$NmDB','$UsrRegstr','$NmTBHrk','Select');"

  cmd="$cmd INSERT INTO mysql.user (Host,user,password) VALUES ('localhost','$UsrAdm',password('$PswAdm'));"
  cmd="$cmd INSERT INTO mysql.db VALUES ('localhost','$NmDB','$UsrAdm','Y','Y','Y','Y','N','N','N','N','N','N');"
fi

#Вывод информации о пользователях и правах
if test $blShow = "true"; then
  cmd="$cmd SELECT User,Host,Select_priv,Insert_priv,Update_priv,Delete_priv,Create_priv,Drop_priv,Reload_priv,Shutdown_priv,Process_priv,File_priv,Grant_priv,References_priv,Index_priv,Alter_priv FROM mysql.user "
  cmd="$cmd   WHERE "
  cmd="$cmd     user='$UsrGuest' OR "
  cmd="$cmd     user='$UsrBskt' OR "
  cmd="$cmd     user='$Regstr' OR "
  cmd="$cmd     user='$UsrAdm';"

  cmd="$cmd SELECT db,user,Host,Select_priv,Insert_priv,Update_priv,Delete_priv,Create_priv,Drop_priv,Grant_priv,References_priv,Index_priv,Alter_priv FROM mysql.db "
  cmd="$cmd  WHERE db='$NmDB';"

  cmd="$cmd SELECT Table_name,db,user,Host,Table_priv,Column_priv,Grantor,Timestamp FROM mysql.tables_priv "
  cmd="$cmd   WHERE "
  cmd="$cmd     table_name='$NmDB.$NmTBCat' OR "
  cmd="$cmd     table_name='$NmDB.$NmTBBsk' OR "
  cmd="$cmd     table_name='$NmDB.$NmTBUsr' OR "
  cmd="$cmd     table_name='$NmDB.$NmTBHrk' OR "
  cmd="$cmd     table_name='$NmDB.$NmTBOrd';"
fi

#Загружаем базу
if test $blDBLoad = "true"; then
    cmd="$cmd LOAD DATA INFILE '$PWD/db/$NmDB-$NmTBCat.txt' INTO TABLE $NmDB.$NmTBCat;"
    cmd="$cmd LOAD DATA INFILE '$PWD/db/$NmDB-$NmTBUsr.txt' INTO TABLE $NmDB.$NmTBUsr;"
    cmd="$cmd LOAD DATA INFILE '$PWD/db/$NmDB-$NmTBOrd.txt' INTO TABLE $NmDB.$NmTBOrd;"
    cmd="$cmd LOAD DATA INFILE '$PWD/db/$NmDB-$NmTBHrk.txt' INTO TABLE $NmDB.$NmTBHrk;"
    cmd="$cmd LOAD DATA INFILE '$PWD/db/$NmDB.$NmTBBsk.txt' INTO TABLE $NmDB.$NmTBBsk;"
fi

#echo $cmd;

$mysql --user=root --password="$1" --host="localhost" --execute="$cmd"
