#include <ctr/draw.h>
#include <ctr/console.h>
#include <ctr/printf.h>

int test(void);

int main(void)
{
	draw_init((draw_s*)0x23FFFE00);
	console_init(0xFFFFFF, 0, SCREEN_TOP);
	draw_clear_screen(SCREEN_TOP, 0x00);

	printf("testing...\n");

	__asm__
	(
		"LDR             R5, =0x801B01C\n"
		"LDR             R2, =0x8006800\n"
		"LDR             R0, =0x8089F00\n"
		"CMP             R5, R2\n"
		"MOVCS           R2, R5\n"
		"CMPCS           R0, R5\n"
		"LDR 	           R3, =4\n"
		//put opcodes to test here...
		"BL              test" //modify the conditional to test
		::: "r0", "r2", "r3", "r5"
	);

	return 0;
}

int test(void)
{
	printf("branched!\n");
	return 0;
}
