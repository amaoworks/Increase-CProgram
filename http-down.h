#ifndef http-down_h
#define http-down_h

#include <stdio.h>//printf
#include <string.h>//字符串处理
#include <sys/socket.h>//套接字
#include <arpa/inet.h>//ip地址处理
#include <fcntl.h>//open系统调用
#include <unistd.h>//write系统调用
#include <netdb.h>//查询DNS
#include <stdlib.h>//exit函数
#include <sys/stat.h>//stat系统调用获取文件大小
#include <sys/time.h>//获取下载时间

struct HTTP_RES_HEADER//保持相应头信息
{
	int status_code;//HTTP/1.1 '200' OK
	char content_type[128];//Content-Type: application/gzip
	long content_length;//Content-Length: 11683079
};

void parse_url(const char *url, char *host, int *port, char *)

#endif
