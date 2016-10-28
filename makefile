
CC = gcc
OPT = -Wall -g

INC = -I/usr/include/mysql/ \
      -I/home/sqf/sqfc/inc
	
LIB = -L/usr/lib64/mysql/ -lmysqlclient  \
		  	  -lz

src=$(wildcard *.c $HOME/sqfmysql/*.c) # 找出所有该目录下的.c文件
dir=$(notdir $(src)) 		       # 把该文件下.c的文件路径去掉
obj=$(patsubst %.c,%.o,$(dir) )	       #把.c的文件替换成.o

libmysql.a:$(obj)
	ar rcs $@ $(obj)
	mv $@ ${HOME}/sqfc/lib

%.o:%.c
	$(CC) -c $(OPT) $(INC) $(LIB) $< -o $@
clear:
	rm *.o
