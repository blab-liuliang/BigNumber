#include "big_int_test.h"
#include <assert.h>

int main() 
{
	// Ŀǰ��֧��ʮ�������ַ���
	// ����Ӧ֧��ʮ���ƣ��������ַ�����
	// ���߿���֧��������ƣ������ַ���� �� ������ "xyz"
	// ����Ӧ��֧��ת��Ϊ������������ַ�����
	TEST_BIG_INT_ADD("1", "9", "A");

	TEST_BIG_INT_SUB("A", "1", "9");

	TEST_BIG_INT_MUL("2", "9", "12");

	TEST_BIG_INT_DIV("9", "3", "3");
	
	system("PAUSE");
}
