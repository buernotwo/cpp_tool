#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <math.h>
#include <io.h>
#include <string.h>
#include <time.h>
#include <direct.h>
#include <ctype.h>
#include <sys/stat.h>
#define BOOL int
#define TRUE 1
#define FALSE 0
//Ŀ����ʵ�ֿ�ƽ̨�Ļ����⣬����java��apiһ��
BOOL startsWith(const char* str, const char* token);
BOOL endWith(const char * str, const char * end);
char* boolToStr(BOOL flag);
char* intToStr(int number);
long my_atol(const char *nptr);
//char*=>int
int  my_atoi(const char *nptr);
char *charToStr(char ch);
int* charsToInts(char *s);
int str_pos(char *str, char *chr);
char * substr(char *dest, const char* src, unsigned int start, unsigned int len);

/*���ַ�������߽�ȡn���ַ�*/
char * left(char *dst, char *src, int n);
/*���ַ������м��ȡn���ַ�*/
char * mid(char *dst, char *src, int n, int m);
/*���ַ������ұ߽�ȡn���ַ�*/
char * right(char *dst, char *src, int n);

//file_util
//https://github.com/justinkadima/cosmonaut/blob/master/src/string_util.c

int file_exists(char *path);
off_t file_size(char *path);
























