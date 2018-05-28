#include <big_int.h>
#include <assert.h>
#include <algorithm>

namespace Math
{
	// construct
	big_int::big_int()
		: m_is_negative(false)
	{

	}

	// 使用十六进制字符串执行构造初始化
	big_int::big_int(const string& value)
		: m_is_negative(false)
	{
		string hex;
		for (char c : value)
		{
			if (mapping_hex_to_binary(hex, c))
			{
				m_bits.push_right(hex[0] == '0' ? 0 : 1);
				m_bits.push_right(hex[1] == '0' ? 0 : 1);
				m_bits.push_right(hex[2] == '0' ? 0 : 1);
				m_bits.push_right(hex[3] == '0' ? 0 : 1);
			}
			else
			{
				// 无日志系统，断言
				assert(false);
			}
		}
	}

	big_int::~big_int()
	{

	}

	// 运算符重载 "+"
	big_int big_int::operator + (const big_int& rhs) const
	{
		uint8_t base = 0;
		big_int result;

		// 从低位开始遍历相加
		size_t max_size = std::max<size_t>(m_bits.size(), rhs.m_bits.size());
		for (size_t i = 0; i < max_size; i++)
		{
			int cur_value = m_bits[i] + rhs.m_bits[i] + base;
			if (cur_value == 3)
			{
				result.m_bits.push_right(1);
				base = 1;
			}
			else if (cur_value == 2)
			{
				result.m_bits.push_right(1);
				base = 0;
			}
			else if (cur_value == 1)
			{
				result.m_bits.push_right(0);
				base = 1;
			}
			else if (cur_value == 0)
			{
				// do nothing
				assert(base == 0);
			}
			else
			{
				assert(false);
			}
		}

		if (base != 0)
		{
			assert(base == 1);

			result.m_bits.push_right(1);
			base = 0;
		}

		return result;
	}

	// 运算符重载 "-"
	big_int big_int::operator - (const big_int& rhs) const
	{
		return big_int();
	}

	// 运算符重载 "*"
	big_int big_int::operator * (const big_int& rhs) const
	{
		return big_int();
	}

	// 运算符重载 "/"
	big_int big_int::operator / (const big_int& rhs) const
	{
		return big_int();
	}

	// 转换为字符串
	string big_int::to_str()
	{
		string result;
		char hex = '0';
		string binary; binary.resize(4);

		int size = static_cast<int>(ceil(m_bits.size() / 4.f));
		for (int i = 0; i < size; i++)
		{
			binary[0] = m_bits[i * 4 + 0] == 0 ? '0' : '1';
			binary[1] = m_bits[i * 4 + 1] == 0 ? '0' : '1';
			binary[2] = m_bits[i * 4 + 2] == 0 ? '0' : '1';
			binary[3] = m_bits[i * 4 + 3] == 0 ? '0' : '1';

			if (mapping_binary_to_hex(hex, binary))
				result += hex;
		}

		return result;
	}

	// 映射hex字符到二进制字符集
	bool big_int::mapping_hex_to_binary(string& result, char orig)
	{
		switch (orig)
		{
		case '0': result = "0000";	return true;
		case '1': result = "0001";	return true;
		case '2': result = "0010";	return true;
		case '3': result = "0011";	return true;
		case '4': result = "0100";	return true;
		case '5': result = "0101";	return true;
		case '6': result = "0110";	return true;
		case '7': result = "0111";	return true;
		case '8': result = "1000";	return true;
		case '9': result = "1001";	return true;
		case 'a':
		case 'A': result = "1010";	return true;
		case 'b':
		case 'B': result = "1011";	return true;
		case 'c':
		case 'C': result = "1100";	return true;
		case 'd':
		case 'D': result = "1101";	return true;
		case 'e':
		case 'E': result = "1110";	return true;
		case 'f':
		case 'F': result = "1111";	return true;
		default:					return false;
		}

		assert(false);
		return false;
	}

	bool big_int::mapping_binary_to_hex(char& result, string& orig)
	{
		if		(orig == "0000") { result = '0';	return true; }
		else if (orig == "0001") { result = '1';	return true; }
		else if (orig == "0010") { result = '2';	return true; }
		else if (orig == "0011") { result = '3';	return true; }
		else if (orig == "0100") { result = '4';	return true; }
		else if (orig == "0101") { result = '5';	return true; }
		else if (orig == "0110") { result = '6';	return true; }
		else if (orig == "0111") { result = '7';	return true; }
		else if (orig == "1000") { result = '8';	return true; }
		else if (orig == "1001") { result = '9';	return true; }
		else if (orig == "1010") { result = 'A';	return true; }
		else if (orig == "1011") { result = 'B';	return true; }
		else if (orig == "1100") { result = 'C';	return true; }
		else if (orig == "1101") { result = 'D';	return true; }
		else if (orig == "1110") { result = 'E';	return true; }
		else if (orig == "1111") { result = 'F';	return true; }

		assert(false);
		return false;
	}
}
