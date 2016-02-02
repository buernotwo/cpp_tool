#include "ctool.h"


BOOL startsWith(const char* str, const char* token)
{
	if (str == NULL || token == NULL)return 0;
	return (strncmp(str, token, strlen(token)) == 0);

}

BOOL endWith(const char * str, const char * end)
{
	BOOL result = FALSE;
	if (str != NULL && end != NULL)
	{
		int l1 = strlen(str);
		int l2 = strlen(end);
		if (l1 >= l2) {
			if (strcmp(str + l1 - l2, end) == 0)
			{
				result = TRUE;
			}
		}
	}
	return result;
}
char* boolToStr(BOOL flag)
{
	return flag ? "true" : "false";
}

char* intToStr(int number)
{
	static char buffer[1024];
	sprintf(buffer, "%d", number);
	return buffer;
}


long my_atol(const char *nptr)
{
	int c; /* current char */
	long total; /* current total */
	int sign; /* if ''-'', then negative, otherwise positive */
	while (isspace((int)(unsigned char)*nptr))
		++nptr;

	c = (int)(unsigned char)*nptr++;
	sign = c; /* save sign indication */
	if (c == '-' || c == '+')
		c = (int)(unsigned char)*nptr++; /* skip sign */

	total = 0;

	while (isdigit(c)) {
		total = 10 * total + (c - '0'); /* accumulate digit */
		c = (int)(unsigned char)*nptr++; /* get next char */
	}

	if (sign == '-')
		return -total;
	else
		return total; /* return result, negated if necessary */
}
//�Լ�ʵ��my_atoi ��ΪatoiΪ�Ǳ�׼c����
int  my_atoi(const char *nptr)
{
	return (int)my_atol(nptr);
}

char *charToStr(char ch)
{
	//��c����û������ c++�Ϳ���
	//sprintf(*buffer, "%c", ch);
	/**
	001
	char p = 'B';
	char data[2] = {0};
	data[0] = p;
	printf("%s\n", data);	
	*/
	static	char data[2] = { 0 };
	sprintf(data, "%c", ch);
	return data;
}
int* charsToInts(char *s)
{
	int len = strlen(s);
	int *arr = (int*)malloc(sizeof(int)*len);
	for (int i = 0; i < len; i++)
	{
		arr[i] = s[i] - '0';
	}
	return arr;
}
//https://github.com/justinkadima/cosmonaut/blob/master/src/string_util.c
int str_pos(char *str, char *chr)
{
	char *p = strstr(str, chr);
	if (p) {
		return p - str;
	}
	return -1;
}

//substr��ȡ�Ӵ�
char * substr(char *dest, const char* src, unsigned int start, unsigned int len) 
{
	strncpy(dest, src + start, len);//���ߵ���ϵͳstrncpy����
	dest[len] = '\0';
	return dest;
}
/*���ַ�������߽�ȡn���ַ�*/
char * left(char *dst, char *src, int n)
{
	char *p = src;
	char *q = dst;
	int len = strlen(src);
	if (n > len) n = len;
	/*p += (len-n);*/   /*���ұߵ�n���ַ���ʼ*/
	while (n--) *(q++) = *(p++);
	*(q++) = '\0'; /*�б�Ҫ�𣿺��б�Ҫ*/
	return dst;
}

/*���ַ������м��ȡn���ַ�*/
char * mid(char *dst, char *src, int n, int m) /*nΪ���ȣ�mΪλ��*/
{
	char *p = src;
	char *q = dst;
	int len = strlen(src);
	if (n > len) n = len - m;    /*�ӵ�m�������*/
	if (m < 0) m = 0;    /*�ӵ�һ����ʼ*/
	if (m > len) return NULL;
	p += m;
	while (n--) *(q++) = *(p++);
	*(q++) = '\0'; /*�б�Ҫ�𣿺��б�Ҫ*/
	return dst;
}

/*���ַ������ұ߽�ȡn���ַ�*/
char * right(char *dst, char *src, int n)
{
	char *p = src;
	char *q = dst;
	int len = strlen(src);
	if (n > len) n = len;
	p += (len - n);   /*���ұߵ�n���ַ���ʼ*/
	while (*(q++) = *(p++));
	return dst;
}



int file_exists(char *path) {
	struct stat st;
	return stat(path, &st) == 0 && (st.st_mode & S_IFREG);
}

off_t file_size(char *path) {
	struct stat st;
	stat(path, &st);
	return st.st_size;
}


void outputMsg(const char *format, ...)
{
	static FILE *output_fp;

	if (output_fp == NULL)
		output_fp = fopen("msg.txt", "w");

	if (output_fp == NULL)
		return;
	va_list args;
	va_start(args, format);
	vfprintf(output_fp, format, args);
	fprintf(output_fp, "\n");
	va_end(args);
	fflush(output_fp);
}