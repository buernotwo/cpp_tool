#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <io.h>
#include <stdlib.h>
#include <direct.h>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <sstream>
#include "cpptool.h"
using namespace std;

string intToStr(int num)
{
	string num_str;
	stringstream stream;
	stream << num;
	stream >> num_str;
	return num_str;
}
//����λ���㣺��& ��|  ���^ ����<< ����>>
int main(int argc, char* argv[])
{
	int num = 255;

	cout << num << "="<<transform(10, 2, intToStr(num)) << endl;

	int mod = 170;

	cout << mod << "=" << transform(10, 2, intToStr(mod)) << endl;

	int yu = num & mod;

	cout <<"����� "<< yu<<"="<<transform(10, 2, intToStr(yu)) << endl;
	
	int huo = num | mod;
	cout << "����� " << huo << "=" << transform(10, 2, intToStr(huo)) << endl;


	int fei = num ^ mod;
	cout << "������ " << huo << "=" << transform(10, 2, intToStr(fei)) << endl;

	
	 num = 42;
	cout << num << "=" << transform(10, 2, intToStr(num)) << endl;
	int zuoyi = num << 2;
	cout << zuoyi << "=" << transform(10, 2, intToStr(zuoyi)) << endl;

	int youyi = num >> 2;
	cout << youyi << "=" << transform(10, 2, intToStr(youyi)) << endl;

	return 0;
}








