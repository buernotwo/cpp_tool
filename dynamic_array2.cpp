
/************************************************************************/
/*
1��ʹ��C���Է�ʽģ���ά����Ķ�̬�������ͷ�
2��ʹ��C++ ���Է�ʽģ���ά����Ķ�̬�������ͷ�
3����չ��ά����Ķ�̬�������ͷ�                                                                     */
/************************************************************************/

#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <vld.h>
#include <iostream>
using namespace std;
//Ŀ���ǳ���No memory leaks detected
#define Type int   //char int
#define ROW 3
#define COL 4

typedef Type(*Arr)[COL];//����ָ�룬����COL������

Arr _New()
{
	Arr p = new Type[ROW][COL];

	return p;
}
void _Assign(Arr p)
{
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			p[i][j] = i + j;

		}

	}
}
void _Print(Arr p)
{

	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			cout << p[i][j]<<" ";
		}
		cout <<endl;
	}
}
void _Delete(Arr p)
{
	delete[]p;//c++�ͷ�����

}

int main(int argc, char* argv[])
{
	Arr p = _New();
	_Assign(p);
	_Print(p);
	_Delete(p);
	system("pause");
	return 0;
}
