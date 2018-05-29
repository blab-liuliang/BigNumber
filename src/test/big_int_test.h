#pragma once

#include "big_int.h"

namespace Test
{
	void big_int_test_add(const char* lv, const char* rv, const char* result, const char* filename, int line);
	void big_int_test_sub(const char* lv, const char* rv, const char* result, const char* filename, int line);
	void big_int_test_mul(const char* lv, const char* rv, const char* result, const char* filename, int line);
	void big_int_test_div(const char* lv, const char* rv, const char* result, const char* filename, int line);
}

#define TEST_BIG_INT_ADD(lv, rv, result) Test::big_int_test_add(lv, rv, result, __FILE__, __LINE__)
#define TEST_BIG_INT_SUB(lv, rv, result) Test::big_int_test_sub(lv, rv, result, __FILE__, __LINE__)
#define TEST_BIG_INT_MUL(lv, rv, result) Test::big_int_test_mul(lv, rv, result, __FILE__, __LINE__)
#define TEST_BIG_INT_DIV(lv, rv, result) Test::big_int_test_div(lv, rv, result, __FILE__, __LINE__)