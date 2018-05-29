#include "big_int_test.h"
#include <assert.h>

int main() 
{
	// 目前仅支持十六进制字符串
	// 后期应支持十进制，二进制字符串。
	// 或者可以支持任意进制，任意字符表达 例 三进制 "xyz"
	// 并且应该支持转换为任意进制类型字符串。
	TEST_BIG_INT_ADD("1", "9", "A");

	TEST_BIG_INT_SUB("A", "1", "9");

	TEST_BIG_INT_MUL("2", "9", "12");

	TEST_BIG_INT_DIV("9", "3", "3");
	
	system("PAUSE");
}
