#include <stdio.h>
#include <stdlib.h>
#include <vld.h>

//��ȷʹ��ָ��
void test002()
{
	int len = 25;
	//piָ�������ڴ��ָ�벻Ҫ������������λ�� ������ͷ�
	int     *pi = malloc( sizeof(int)*len);
	int     *tempPi = pi;
	int     i = 0;

	//ֻ�ƶ�tempPi����
	for (i = 0; i < len; i++) {
		*tempPi++ = i;
	}
	//ָ���ʼλ��
	tempPi = pi;
	for (i = 0; i < 25; i++) {
		printf("%d ", *tempPi++);
	}
	free(pi);
	printf("\nhello world\n");


}
int main()
{
	int *pstr, *pstr2;
	int i = 0;
	int len = 20;
	pstr = (int*)malloc(sizeof(int)*len);
	//����ԭ��ָ��λ�ã���ԭ�����ڴ�ռ�λ�á�
	pstr2 = pstr;
	for (i = 0; i < len;i++)
	{
		*pstr = i;
		pstr++;
	}
	//�ָ�ָ��
	pstr = pstr2;
	for (i = 0; i < len; i++)
	{
		int data = *pstr;
		printf("%d ", data);
		pstr++;
	}
	printf("\n");
	//ֻ���ͷ�pstr2ԭʼָ��λ�ã�������ָ��������ڴ�ռ䣬��pstr��ָ�ڴ��Ѿ�����
	free(pstr2);
	pstr2 = NULL;
	pstr = NULL;

	test002();


}
