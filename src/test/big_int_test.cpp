#include "big_int_test.h"
#include <assert.h>

using namespace Math;

namespace Test
{
	void big_int_test_add(const char* lv, const char* rv, const char* result, const char* filename, int line)
	{
		big_int left(lv);
		big_int right(rv);
		big_int add_result = left + right;
		std::string result_str = add_result.to_str();
		if (result_str != result)
		{
			printf("test failed  : [%s] line[%d]\n", filename, line);
		}
		else
		{
			printf("test succeed : 0x%s + 0x%s = 0x%s\n", lv, rv, result_str.c_str());
		}
	}

	void big_int_test_sub(const char* lv, const char* rv, const char* result, const char* filename, int line)
	{
		big_int left(lv);
		big_int right(rv);
		big_int sub_result = left - right;
		std::string result_str = sub_result.to_str();
		if (result_str != result)
		{
			printf("test failed  : [%s] line[%d]\n", filename, line);
		}
		else
		{
			printf("test succeed : 0x%s - 0x%s = 0x%s\n", lv, rv, result_str.c_str());
		}
	}

	void big_int_test_mul(const char* lv, const char* rv, const char* result, const char* filename, int line)
	{
		big_int left(lv);
		big_int right(rv);
		big_int mul_result = left * right;
		std::string result_str = mul_result.to_str();
		if (result_str != result)
		{
			printf("test failed  : [%s] line[%d]\n", filename, line);
		}
		else
		{
			printf("test succeed : 0x%s * 0x%s = 0x%s\n", lv, rv, result_str.c_str());
		}
	}

	void big_int_test_div(const char* lv, const char* rv, const char* result, const char* filename, int line)
	{
		big_int left(lv);
		big_int right(rv);
		big_int div_result = left / right;
		std::string result_str = div_result.to_str();
		if (result_str != result)
		{
			printf("test failed  : [%s] line[%d]\n", filename, line);
		}
		else
		{
			printf("test succeed : 0x%s / 0x%s = 0x%s\n", lv, rv, result_str.c_str());
		}
	}
}