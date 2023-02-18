#include <stdint.h>

int main() 
{
	union
	{
		uint32_t i;
		uint8_t c[4];
	} test = { 0x00000001 };
	return test.c[0];
}