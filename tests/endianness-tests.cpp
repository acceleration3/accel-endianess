#include <accel/endianness>

#include <iostream>
#include <cassert>
#include <array>

using namespace accel;

#define opposite_swap(data, count) endianness::swap_endianness<endianness::endiannesses::host_endian, endianness::opposite_endianness<endianness::endiannesses::host_endian>::value>(data, count)

int main(int argc, char* argv[])
{
	{
		std::uint16_t test = 0xABCD;
		opposite_swap(&test, 1);
		assert(test == 0xCDAB);
	}

	{
		std::uint32_t test = 0x00ABCDEF;
		opposite_swap(&test, 1);
		assert(test == 0xEFCDAB00);
	}

	{
		std::uint64_t test = 0x0011223344556677;
		opposite_swap(&test, 1);
		assert(test == 0x7766554433221100);
	}

	{
		std::array<uint16_t, 3> test = { 0xAABB, 0xCCDD, 0xEEFF };
		opposite_swap(test.data(), test.size());
		assert(test[0] == 0xBBAA);
		assert(test[1] == 0xDDCC);
		assert(test[2] == 0xFFEE);
	}

	std::cout << "All tests completed sucessfully.";

	return 0;
}