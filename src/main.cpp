#include "big_int_test.h"
#include <assert.h>

int main() 
{
	// Ŀǰ��֧��ʮ�������ַ���
	// ����Ӧ֧��ʮ���ƣ��������ַ�����
	// ���߿���֧��������ƣ������ַ���� �� ������ "xyz"
	// ����Ӧ��֧��ת��Ϊ������������ַ�����
	TEST_BIG_INT_ADD("1", "9", "A");
	TEST_BIG_INT_ADD("001", "000009", "A");
	TEST_BIG_INT_ADD("F", "1", "10");
	TEST_BIG_INT_ADD("F000A", "F0001", "1E000B");
	TEST_BIG_INT_ADD("F000A", "EDC1", "FEDCB");
	TEST_BIG_INT_ADD("123456789ABCDEF", "FEDCBA9876543210", "FFFFFFFFFFFFFFFF");

	TEST_BIG_INT_SUB("A2", "1", "A1");

	TEST_BIG_INT_MUL("2", "9", "12");
	TEST_BIG_INT_MUL("8888", "9999", "51EAE148");
	TEST_BIG_INT_MUL("888888888", "2", "1111111110");
	TEST_BIG_INT_MUL("11111111111111111111", "3", "33333333333333333333");

	TEST_BIG_INT_DIV("F", "2", "7");
	TEST_BIG_INT_DIV("9", "3", "3");
	
	system("PAUSE");
}
