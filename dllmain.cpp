#include <windows.h>

struct stMain {
	stMain() {
		*reinterpret_cast<float*>(0xBA8308) = 1.0f;
		*reinterpret_cast<float*>(0xBA830C) = 0.0f;
		VirtualProtect(reinterpret_cast<LPVOID>(0x586B04), 0x2, PAGE_READWRITE, &oldProt);
		memset(reinterpret_cast<void*>(0x586B04), 0xEB, 0x2);
		VirtualProtect(reinterpret_cast<LPVOID>(0x586B04), 0x2, oldProt, &oldProt);
	};
	~stMain() {
		VirtualProtect(reinterpret_cast<LPVOID>(0x586B04), 0x2, PAGE_READWRITE, &oldProt);
		memcpy(reinterpret_cast<void*>(0x586B04), "\x68\xCB", 0x2); // E8 68 CB FF FF
		VirtualProtect(reinterpret_cast<LPVOID>(0x586B04), 0x2, oldProt, &oldProt);
	}; DWORD oldProt;
} plugin;
