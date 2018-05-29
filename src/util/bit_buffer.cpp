#include "bit_buffer.h"
#include <assert.h>
#include <algorithm>

namespace Math
{
	bit_buffer::bit_buffer()
	{
	}

	// ��ӵ��ұ�
	void bit_buffer::push_right(uint8_t v)
	{
		assert(v == 1 || v == 0);
		m_bytes.push_back( v);
	}

	// ��ӵ����(��λ)
	void bit_buffer::push_left(uint8_t v)
	{
		// Ч�ʵ��£�����ʹ��list queue���Ż�m_bytes�洢
		m_bytes.insert(m_bytes.begin(), v);
	}

	// �Ƴ����(��λ)
	void bit_buffer::remove_left()
	{
		if(!m_bytes.empty())
			m_bytes.erase(m_bytes.begin());
	}

	// �Ƴ��ұ�(��λ)
	void bit_buffer::remove_right()
	{
		assert(!m_bytes.empty());
		m_bytes.pop_back();
	}

	// ��λȡ��
	void bit_buffer::neg_bits(size_t size)
	{
		for (size_t i = 0; i < m_bytes.size(); i++)
		{
			m_bytes[i] = m_bytes[i] ? 0 : 1;
		}

		while (m_bytes.size() < size)
		{
			push_right(1);
		}
	}

	// ���������
	uint8_t bit_buffer::operator [] (size_t index) const
	{
		if (index < m_bytes.size())
			return m_bytes[index];

		return 0;
	}

	// �Ƴ���λ0
	void bit_buffer::remove_right_zero()
	{
		while (!m_bytes.empty() && !m_bytes.back())
		{
			m_bytes.pop_back();
		}
	}
}
