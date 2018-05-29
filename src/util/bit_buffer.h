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

		// ��ӵ����(��λ)
		void push_left(uint8_t v);

		// ��С
		size_t size() const { return m_bytes.size(); }

		// ��������� "[]"
		uint8_t operator [] (size_t index) const;

		// Ԥ�����ڴ�ռ�
		void reserve(size_t count) { m_bytes.reserve(count); }

		// �Ƴ���λ0
		void remove_right_zero();

	private:
		std::vector<uint8_t> m_bytes;		// ���Ǹ���Ϊ������ boost::dynamic_bitset��ʵ�ַ�ʽ�������ڴ�ռ��
	};
}