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

	// ���������
	uint8_t bit_buffer::operator [] (size_t index) const
	{
		if (index < m_bytes.size())
			return m_bytes[index];

		return 0;
	}
}
