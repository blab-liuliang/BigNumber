#pragma once

#include <vector>

namespace Math
{
	class bit_buffer
	{
	public:
		bit_buffer();

		// ��ӵ��ұ�(��λ)
		void push_right(uint8_t v);

		// �Ƴ��ұ�(��λ)
		void remove_right();

		// ��ӵ����(��λ)
		void push_left(uint8_t v);

		// �Ƴ����(��λ)
		void remove_left();

		// ��С
		size_t size() const { return m_bytes.size(); }

		// ��������� "[]"
		uint8_t operator [] (size_t index) const;

		// Ԥ�����ڴ�ռ�
		void reserve(size_t count) { m_bytes.reserve(count); }

		// ��λȡ��
		void neg_bits(size_t size);

		// �Ƴ���λ0
		void remove_right_zero();

	private:
		std::vector<uint8_t> m_bytes;		// ���Ǹ���Ϊ������ boost::dynamic_bitset��ʵ�ַ�ʽ�������ڴ�ռ��
	};
}