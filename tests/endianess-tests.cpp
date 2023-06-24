#include <accel/endianess>

#include <iostream>
#include <cassert>
#include <array>

using namespace accel;

#define opposite_swap(data) endianess::swap_endianess<endianess::endianesses::host_endian, endianess::opposite_endianess<endianess::endianesses::host_endian>::value>(data)

int main(int argc, char* argv[])
{
	{
		std::uint16_t test = 0xABCD;
		opposite_swap(test);
		assert(test == 0xCDAB);
	}

	{
		std::uint32_t test = 0x00ABCDEF;
		opposite_swap(test);
		assert(test == 0xEFCDAB00);
	}

	{
		std::uint64_t test = 0x0011223344556677;
		opposite_swap(test);
		assert(test == 0x7766554433221100);
	}

	std::cout << "All tests completed sucessfully.";

	return 0;
}