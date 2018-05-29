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

		// ��������� "+"
		big_int operator + (const big_int& rhs) const;

		// ��������� "-"
		big_int operator - (const big_int& rhs) const;

		// ��������� "*"
		big_int operator * (const big_int& rhs) const;

		// ��������� "/"
		big_int operator / (const big_int& rhs) const;

		// ���Ʋ���
		big_int left_shift(int bit) const;

		// ���Ʋ���
		big_int right_shift(int bit) const;

		// ��λȡ��
		big_int neg_bits(int size) const;

		// ת��Ϊ�ַ���
		string to_str() const;

	public:
		// �Ƚ����������
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
		// hex�ַ���������ַ���ӳ�亯��
		bool mapping_hex_to_binary(string& result, char orig) const;
		bool mapping_binary_to_hex(char& result, string& orig) const;

	private:
		bool			m_is_negative;		// �ݲ�֧������(��ǰ�ٶ�ȫΪ��ֵ)
		bit_buffer		m_bits;				// ���ݴ洢
	};
}