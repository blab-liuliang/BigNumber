#include "big_int.h"

using namespace Math;

int main() 
{
	// Ŀǰ��֧��ʮ�������ַ���
	// ����Ӧ֧��ʮ���ƣ��������ַ�����
	// ���߿���֧��������ƣ������ַ���� �� ������ "xyz"
	// ����Ӧ��֧��ת��Ϊ������������ַ�����
	big_int left("12");
	big_int right("10");
	big_int add_result = left + right;
	big_int sub_result = left - right;
	big_int mul_result = left * right;
	big_int div_result = left / right;

	printf("0x%s + 0x%s = 0x%s\n", left.to_str().c_str(), right.to_str().c_str(), add_result.to_str().c_str());

	system("PAUSE");
}
