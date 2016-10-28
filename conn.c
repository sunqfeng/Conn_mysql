/*************************************************************************
* File Name: conn.c
* Author: sqf
* mail: 18722358342@163.com
* Created Time: Sat 17 Sep 2016 02:18:17 AM EDT
*************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <mysql.h>  
 
int mysqlcon(MYSQL *sqlconn)
{  
	MYSQL mysql;  
	char sql[100];

	memset(sql,0x00,sizeof(sql));

	MYSQL *mysql_op = NULL;
	//int t, r;  
	/*连接之前，先用mysql_init初始化MYSQL连接句柄*/  
	mysql_init(&mysql);  
	/*使用mysql_real_connect连接服务器,其参数依次为MYSQL句柄，服务器IP地址， 
	  登录mysql的用户名，密码，要连接的数据库等*/  

	mysql_op = mysql_real_connect(sqlconn, "192.168.75.128", "sqf", "123456", "test", 0, NULL, 0);
	if ( mysql_op == NULL )
	{  
		printf("Error connecting to Mysql!\n");  
		return -1;
	}else 
	{  
		printf("Connected Mysql successful!\n");  
	}  

	/*关闭连接*/  
	//	mysql_close(&mysql);  
		
	mysql_query(sqlconn, "set character set utf8");

	return 0;  /*返回零表示连接成功*/

}
