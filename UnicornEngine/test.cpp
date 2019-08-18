#include "unicorn/unicorn.h"
#include <Windows.h>
#include <iostream>
​
#pragma comment(lib, "unicorn_static.lib")
​
constexpr auto ADDRESS = 0x1000000;
constexpr auto CODE32 = "\x31\xc0"; // xor eax, eax
​
int main()
{
	uc_engine* uc = NULL;
	uc_err err;
​
	int eax = 0x31337;
	int r_eax = 0;
​
	std::cout << "[+] Emulating XOR EAX, EAX..." << std::endl;
	try
	{
		uc_open(UC_ARCH_X86, UC_MODE_32, &uc);
​
		uc_mem_map(uc, ADDRESS, 2 * 1024 * 1024, UC_PROT_ALL);
		uc_mem_write(uc, ADDRESS, CODE32, sizeof(CODE32) - 1);
​
		std::cout << "[+] Writing 0x31337 to eax..." << std::endl;
		uc_reg_write(uc, UC_X86_REG_EAX, &eax); // Writes 0x31337 to eax
		uc_reg_read(uc, UC_X86_REG_EAX, &r_eax); // Proves eax is 0x31337
​
		uc_emu_start(uc, ADDRESS, ADDRESS + sizeof(CODE32) - 1, 0, 0);
​
		std::cout << "[+] Done!" << std::endl;
	}
	catch (const uc_err &error)
	{
		std::cerr << "[!] " << uc_strerror(error);
	}
​
	uc_reg_read(uc, UC_X86_REG_EAX, &eax);
​
	std::cout << "[+] EAX before: " << std::hex << r_eax << std::endl;
	std::cout << "[+] EAX after: " << std::hex << eax << std::endl;
​
	uc_emu_stop(uc);
	return EXIT_SUCCESS;
}
