#include <Windows.h>

class CMain {
public:
	CMain() {
		VirtualProtect(reinterpret_cast<LPVOID>(0x586B04), 2, PAGE_READWRITE, &oldProt);
		memset(reinterpret_cast<void*>(0x586B04), 0xEB, 0x2);
		VirtualProtect(reinterpret_cast<LPVOID>(0x586B04), 2, oldProt, &oldProt);
	};
	~CMain() {
		VirtualProtect(reinterpret_cast<LPVOID>(0x586B04), 2, PAGE_READWRITE, &oldProt);
		memcpy(reinterpret_cast<void*>(0x586B04), "\x68\xCB", 0x2); // E8 68 CB FF FF
		VirtualProtect(reinterpret_cast<LPVOID>(0x586B04), 2, oldProt, &oldProt);
	}; DWORD oldProt;
}; CMain plugin;