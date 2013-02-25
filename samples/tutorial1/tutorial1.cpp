#include "stdio.h"
#include "jitasm.h"

using namespace jitasm;

int gpr[4] = {0, 0, 0, 0};

Addr addr0 = Addr(RegID::Invalid(), (size_t)&gpr[0]);

struct tutorial1 : jitasm::function<int, tutorial1>
{
    Reg32 a[4];

	Result main()
	{
        mov(a[0], dword_ptr[addr0]);
        xor(a[0], a[0]);
		add(a[0], 5);
        mov(eax, a[0]);
        mul(a[0]);
        mov(a[0], eax);
        mov(dword_ptr[addr0], a[0]);
		return a[0];
	}
};

int main()
{
	// Make function instance
	tutorial1 f;

	// Runtime code genaration and run
	int result = f();

	printf("Result : %d\n", result);
    printf("a[0] : %d\n", gpr[0]);

	return 0;
}
