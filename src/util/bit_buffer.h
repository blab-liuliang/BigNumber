#pragma once

#include <vector>

namespace Math
{
	class bit_buffer
	{
	public:
		bit_buffer();

		// 添加到右边(高位)
		void push_right(uint8_t v);

		// 移除右边(高位)
		void remove_right();

		// 添加到左边(低位)
		void push_left(uint8_t v);

		// 移除左边(低位)
		void remove_left();

		// 大小
		size_t size() const { return m_bytes.size(); }

		// 运算符重载 "[]"
		uint8_t operator [] (size_t index) const;

		// 预分配内存空间
		void reserve(size_t count) { m_bytes.reserve(count); }

		// 按位取反
		void neg_bits(size_t size);

		// 移除高位0
		void remove_right_zero();

	private:
		std::vector<uint8_t> m_bytes;		// 考虑更换为类似于 boost::dynamic_bitset等实现方式，减少内存占用
	};
}