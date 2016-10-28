/*************************************************************************
* File Name: showdata.c
* Author: sqf
* mail: 18722358342@163.com
* Created Time: Tue 20 Sep 2016 04:37:07 PM EDT
*************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string.h>
#include<mysql.h>

void showsql(MYSQL *sqlconn)
{

	int flag ;
	int m=0,n=0;
	char sql[100];
	MYSQL_RES *res = NULL; /*mysql查询的结果存放在改变量中*/
	MYSQL_ROW row = NULL;
	MYSQL_FIELD *fields = NULL;

	memset(sql,0x00,sizeof(sql));


	strcpy(sql ,"select *from person where id=4");
	flag = mysql_real_query(sqlconn, sql, strlen(sql));
	if (flag) 
	{
		printf("query error:%d from %s\n",mysql_errno(sqlconn),mysql_error(sqlconn));
		return ;
	}

	// 将查询结果读取到内存当中，如果数据很多的情况会比较耗内存
	res = mysql_store_result( sqlconn );

	// 字段数量
	unsigned int field_count = mysql_field_count(sqlconn);
	printf("field_cout:[%d]\n",field_count);

	// 查询总数
	my_ulonglong rows = mysql_num_rows(res);
	printf("查询数据一共多少行=[%lld]\n",rows);

	// 获取所有字段
	fields = mysql_fetch_fields(res);
	for (m = 0; m < mysql_num_fields(res); m++) 
	{
		printf("%s\t", fields[m].name); //打印数据库列名
	}

	printf("\n");

	// 遍历结果集
	while((row = mysql_fetch_row(res)))
	{
		for (n = 0; n < mysql_num_fields(res); n++)
		{
			printf("%s\t",row[n]);

		}

		printf("\n");
	}

	// 释放结果集
	mysql_free_result(res);

	return ;
}
