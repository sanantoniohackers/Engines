#include "keystone/keystone.h"
#include <Windows.h>
#include <iostream>

#pragma comment(lib, "keystone/keystone_static.lib")

#define CODE "INC ecx; DEC edx"

int main(int argc, char** argv)
{
	ks_engine* ks;
	ks_err err = KS_ERR_ARCH;
	size_t count;
	unsigned char* encode;
	size_t size;

	err = ks_open(KS_ARCH_X86, KS_MODE_32, &ks);
	if (err != KS_ERR_OK) {
		printf("ERROR: failed on ks_open(), quit\n");
		return -1;
	}

	if (ks_asm(ks, CODE, 0, &encode, &size, &count)) {
		printf("ERROR: failed on ks_asm() with count = %lu, error code = %u\n", count, ks_errno(ks));
	}
	else {
		size_t i;

		printf("%s = ", CODE);
		for (i = 0; i < size; i++) {
			printf("%02x ", encode[i]);
		}
		printf("\n");
		printf("Assembled: %lu bytes, %lu statements\n\n", size, count);
	}

	// NOTE: free encode after usage to avoid leaking memory
	ks_free(encode);

	// close Keystone instance when done
	ks_close(ks);

	return 0;
}
