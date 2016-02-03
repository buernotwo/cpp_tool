#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>


/********************************************************************
*  Function��  my_strstr()
*  Description: ��һ���ַ����в���һ���Ӵ�;
*  Input��      ps: Դ;      pd���Ӵ�
*  Return :    0��Դ�ַ�����û���Ӵ�; 1��Դ�ַ��������Ӵ�;
*********************************************************************/
char * my_strstr(char * ps, char *pd)
{
	char *pt = pd;
	int c = 0;
	while (*ps != '\0')
	{
		if (*ps == *pd)
		{
			while (*ps == *pd && *pd != '\0')
			{
				ps++;
				pd++;
				c++;
			}
		}
		else
		{
			ps++;
		}
		if (*pd == '\0')
		{
			return (ps - c);
		}
		c = 0;
		pd = pt;
	}
	return 0;
}

/********************************************************************
*  Function��  my_memcpy()
*  Description: ����һ���ڴ�������һ������;
*  Input��      src: Դ;
count: �����ֽ���.
*  Output��      dest: ����Ŀ�ĵ�;
*  Return :      dest;
*********************************************************************/
void * my_memcpy(void * dest, const void *src, size_t count)
{
	char *tmp = (char *)dest, *s = (char *)src;
	while (count--)
		*tmp++ = *s++;
	return dest;
}

/********************************************************************
*  Function��  str_replace()
*  Description: ��һ���ַ����в���һ���Ӵ������Ұ����з��ϵ��Ӵ���
��һ���滻�ַ����滻��
*  Input��      p_source:Ҫ���ҵ�ĸ�ַ����� p_seachҪ���ҵ����ַ���;
p_repstr���滻���ַ���;
*  Output��      p_result:��Ž��;
*  Return :      �����滻�ɹ����Ӵ�����;
*  Others:      p_resultҪ�㹻��Ŀռ��Ž�����������������Ҫ��\0����;
*********************************************************************/
int str_replace(char *p_result, char* p_source, char* p_seach, char *p_repstr)
{
	int c = 0;
	int repstr_leng = 0;
	int searchstr_leng = 0;
	char *p1;
	char *presult = p_result;
	char *psource = p_source;
	char *prep = p_repstr;
	char *pseach = p_seach;
	int nLen = 0;
	repstr_leng = strlen(prep);
	searchstr_leng = strlen(pseach);

	do {
		p1 = strstr(psource, p_seach);
		if (p1 == 0)
		{
			strcpy(presult, psource);
			return c;
		}
		c++;  //ƥ���Ӵ�������1;
		//printf("���:%s\r\n", p_result);
		//printf("Դ�ַ�:%s\r\n", p_source);
		// ������һ���滻�����һ���滻���м���ַ���
		nLen = p1 - psource;
		memcpy(presult, psource, nLen);
		// ������Ҫ�滻���ַ���
		memcpy(presult + nLen, p_repstr, repstr_leng);
		psource = p1 + searchstr_leng;
		presult = presult + nLen + repstr_leng;
	} while (p1);

	return c;
}
#define MAX 200
int main(void)
{
	int i = 0;
	char s[MAX] = { 0 };        //���Դ�ִ�
	char s1[MAX] = { 0 };        //������ִ�
	char s2[MAX] = { 0 };        //����滻�ִ�
	char result_a[2000] = { 0 };//����滻���;
	puts("Please input the string for s:");
	gets_s(s,MAX);
	puts("Please input the string for s1:");
	gets_s(s1, MAX);
	puts("Please input the string for s2:");
	gets_s(s2, MAX);
	i = str_replace(result_a, s, s1, s2);
	printf("�滻%d�����ַ���;\r\n", i);
	printf("�滻����:%s\r\n", result_a);
}