�������߰�װ��
# apt-get download libqt4-sql-mysql
# apt-get install libqt4-sql-mysql 

/usr/lib/i386-linux-gnu/qt4/plugins/sqldrivers/libqsqlmysql.so 

# mysql -u root -p

1:ʹ��SHOW����ҳ��ڷ������ϵ�ǰ����ʲô���ݿ⣺
mysql> SHOW DATABASES;
2:2������һ�����ݿ�MYSQLDATA
mysql> CREATE DATABASE MYSQLDATA;
3:ѡ���������������ݿ�
mysql> USE MYSQLDATA; (���س�������Database changed ʱ˵�������ɹ���)
4:�鿴���ڵ����ݿ��д���ʲô��
mysql> SHOW TABLES;
5:����һ�����ݿ��
mysql> CREATE TABLE MYTABLE (name VARCHAR(20), sex CHAR(1));
6:��ʾ��Ľṹ��
mysql> DESCRIBE MYTABLE;
7:�����м����¼
mysql> insert into MYTABLE values (��hyq��,��M��);
8:���ı���ʽ������װ�����ݿ���У�����D:/mysql.txt��
mysql> LOAD DATA LOCAL INFILE ��D:/mysql.txt�� INTO TABLE MYTABLE;
9:����.sql�ļ��������D:/mysql.sql��
mysql>use database;
mysql>source d:/mysql.sql;
10:ɾ����
mysql>drop TABLE MYTABLE;
11:��ձ�
mysql>delete from MYTABLE;
12:���±�������
mysql>update MYTABLE set sex=��f�� where name=��hyq��;


