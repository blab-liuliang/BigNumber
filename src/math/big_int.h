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

		// 运算符重载 "+"
		big_int operator + (const big_int& rhs) const;

		// 运算符重载 "-"
		big_int operator - (const big_int& rhs) const;

		// 运算符重载 "*"
		big_int operator * (const big_int& rhs) const;

		// 运算符重载 "/"
		big_int operator / (const big_int& rhs) const;

		// 左移操作
		big_int left_shift(int bit) const;

		// 右移操作
		big_int right_shift(int bit) const;

		// 按位取反
		big_int neg_bits(int size) const;

		// 转换为字符串
		string to_str() const;

	public:
		// 比较运算符重载
		friend bool operator >= (const big_int& lhs, const big_int& rhs)
		{
			if (lhs.m_bits.size() < rhs.m_bits.size())
				return false;

			if (lhs.m_bits.size() == rhs.m_bits.size())
			{
				for (int i = int(lhs.m_bits.size())-1; i >=0; i--)
				{
					if (lhs.m_bits[i] < rhs.m_bits[i])
						return false;
				}
			}

			return true;
		}

	private:
		// hex字符与二进制字符集映射函数
		bool mapping_hex_to_binary(string& result, char orig) const;
		bool mapping_binary_to_hex(char& result, string& orig) const;

	private:
		bool			m_is_negative;		// 暂不支持正负(当前假定全为正值)
		bit_buffer		m_bits;				// 数据存储
	};
}