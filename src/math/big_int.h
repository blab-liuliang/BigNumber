#pragma once

#include <string>
#include "bit_buffer.h"

using namespace std;

namespace Math
{
	/**
	 * big int
	 * used for save number which is big than 8 bytes
	 */
	class big_int
	{
	public:
		big_int();
		big_int(const string& value);
		~big_int();

		// 运算符重载 "+ - * /"
		big_int operator + (const big_int& rhs) const;
		big_int operator - (const big_int& rhs) const;
		big_int operator * (const big_int& rhs) const;
		big_int operator / (const big_int& rhs) const;

		// 转换为字符串
		string to_str();

	private:
		// hex字符与二进制字符集映射函数
		bool mapping_hex_to_binary(string& result, char orig);
		bool mapping_binary_to_hex(char& result, string& orig);

	private:
		bool			m_is_negative;		// 暂不支持正负(当前假定全为正值)
		bit_buffer		m_bits;				// 数据存储
	};
}