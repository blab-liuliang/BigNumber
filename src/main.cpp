#include "big_int.h"

using namespace Math;

int main() 
{
	// 目前仅支持十六进制字符串
	// 后期应支持十进制，二进制字符串。
	// 或者可以支持任意进制，任意字符表达 例 三进制 "xyz"
	// 并且应该支持转换为任意进制类型字符串。
	big_int left("12");
	big_int right("10");
	big_int add_result = left + right;
	big_int sub_result = left - right;
	big_int mul_result = left * right;
	big_int div_result = left / right;

	printf("0x%s + 0x%s = 0x%s\n", left.to_str().c_str(), right.to_str().c_str(), add_result.to_str().c_str());

	system("PAUSE");
}
