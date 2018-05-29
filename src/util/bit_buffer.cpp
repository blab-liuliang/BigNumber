#include "bit_buffer.h"
#include <assert.h>
#include <algorithm>

namespace Math
{
	bit_buffer::bit_buffer()
	{
	}

	// 添加到右边
	void bit_buffer::push_right(uint8_t v)
	{
		assert(v == 1 || v == 0);
		m_bytes.push_back( v);
	}

	// 添加到左边(低位)
	void bit_buffer::push_left(uint8_t v)
	{
		// 效率低下，考虑使用list queue等优化m_bytes存储
		m_bytes.insert(m_bytes.begin(), v);
	}

	// 运算符重载
	uint8_t bit_buffer::operator [] (size_t index) const
	{
		if (index < m_bytes.size())
			return m_bytes[index];

		return 0;
	}

	// 移除高位0
	void bit_buffer::remove_right_zero()
	{
		while (!m_bytes.empty() && !m_bytes.back())
		{
			m_bytes.pop_back();
		}
	}
}
