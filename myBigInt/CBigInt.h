#ifndef		DOUFEI_BIGINT_HEADER
#define	DOUFEI_BIGINT_HEADER
#include <string>
#include <iostream>

class CBigInt
{
public:
	explicit CBigInt() ; 
	CBigInt(const int i) ; 
	CBigInt(const std :: string& strValues) ;
	CBigInt(const CBigInt& bigInt) ; //���ƹ��캯��
	~CBigInt() ;

public:
	bool inline isPositive() {return flag ; };
	int compareBitInt(const CBigInt& rhs)const ; //�Ƚ��������Ĵ�С
	CBigInt& operator = (const CBigInt& rhs) ; //��ֵ����������
	friend std :: ostream& operator << (std :: ostream& ou, const CBigInt& bigInt) ; //�������������
	friend std :: istream& operator >> (std :: istream& in, CBigInt& bigInt) ; //���������������
	friend const CBigInt operator + (const CBigInt& lhs, const CBigInt& rhs ) ; //�ӷ���������
	friend const CBigInt operator - (const CBigInt& lhs, const CBigInt& rhs) ; //��������������
	friend const CBigInt operator * (const CBigInt& lhs, const CBigInt& rhs) ; //�˷�����������
	friend const CBigInt operator / (const CBigInt& lhs, const CBigInt& rhs) ; //������������
	friend const CBigInt operator % (const CBigInt& lhs, const CBigInt& rhs) ; //ȡģ�������������


	void setValue(const std :: string& strValues) ; //�����ַ���������ֵ
	const CBigInt absolute()const ; //����ֵ


private:
	std :: string values ; //��������λ�ϵ�����
	bool flag ; //true��ʾ������false��ʾ������0Ĭ��Ϊ����
};

std :: ostream& operator << (std :: ostream& ou, const CBigInt& bigInt) ;
std :: istream& operator >> (std :: istream& in, CBigInt& bigInt) ;
const CBigInt operator + (const CBigInt& lhs, const CBigInt& rhs ) ; //�ӷ�����������
const CBigInt operator - (const CBigInt& lhs, const CBigInt& rhs) ; //��������������
const CBigInt operator * (const CBigInt& lhs, const CBigInt& rhs) ; //�˷�����������
const CBigInt operator / (const CBigInt& lhs, const CBigInt& rhs) ; //������������
const CBigInt operator % (const CBigInt& lhs, const CBigInt& rhs) ; //ȡģ�������������

#endif