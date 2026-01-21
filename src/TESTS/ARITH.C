#include <assert.h>

#define check(actual, expected, msg) \
	if(((actual)) != ((expected))) { puts(msg); failures++; }

int f1() {
	unsigned char i, j, k;
	int failures = 0;

	i = 2; j = 3; k = i + j;
	check(k, 5, "add failed: u8 + u8 -> u8");

	i = 253; j = 3; k = i + j;
	check(k, 0, "add failed: u8 + u8 -> u8");

	i = 5; j = 3; k = i - j;
	check(k, 2, "subtract failed: u8 - u8 -> u8");

	i = 0; j = 3; k = i - j;
	check(k, 253, "subtract failed: u8 - u8 -> u8");

	return failures;
}

int f2() {
	unsigned char i, j;
	int k;
	int failures = 0;

	i = 2; j = 3; k = i + j;
	check(k, 5, "add failed: u8 + u8 -> int");

	// Desmet-ism, not standard C89
	i = 253; j = 3; k = i + j;
	check(k, 0, "add failed: u8 + u8 -> int");

	i = 5; j = 3; k = i - j;
	check(k, 2, "subtract failed: u8 - u8 -> int");

	// Desmet-ism, not standard C89
	i = 0; j = 3; k = i - j;
	check(k, 253, "subtract failed: u8 - u8 -> int");

	return failures;
}

int f3() {
	signed char i, j, k;
	int failures = 0;

	i = 2; j = -3; k = i + j;
	check(k, -1, "add failed: i8 + i8 -> i8");

	i = 125; j = 3; k = i + j;
	check(k, -128, "add failed: i8 + i8 -> i8");

	i = -1; j = -3; k = i - j;
	check(k, 2, "subtract failed: i8 - i8 -> i8");

	i = -128; j = 3; k = i - j;
	check(k, 125, "subtract failed: i8 - i8 -> i8");

	return failures;
}

int f4() {
	signed char i, j;
	int k;
	int failures = 0;

	i = 2; j = -3; k = i + j;
	check(k, -1, "add failed: i8 + i8 -> int");

	// Desmet-ism, not standard C89
	i = 125; j = 3; k = i + j;
	check(k, -128, "add failed: i8 + i8 -> int");

	i = -1; j = -3; k = i - j;
	check(k, 2, "subtract failed: i8 - i8 -> int");

	// Desmet-ism, not standard C89
	i = -128; j = 3; k = i - j;
	check(k, 125, "subtract failed: i8 - i8 -> int");

	return failures;
}

int f5() {
	unsigned char i;
	signed char j;
	int k;
	int failures = 0;

	// Desmet-ism: u8-i8 math yields a u8 result that is then
	// widened to int.
	i = 2; j = -3; k = i + j;
	check(k, 255, "add failed: u8 + i8 -> int");

	i = 125; j = 3; k = i + j;
	check(k, 128, "add failed: u8 + i8 -> int");

	i = 1; j = -3; k = i - j;
	check(k, 4, "subtract failed: u8 - i8 -> int");

	i = -128; j = 3; k = i - j;
	check(k, 125, "subtract failed: u8 - i8 -> int");

	return failures;
}

int f6() {
	signed char i, j;
	long k;
	int failures = 0;

	i = 2; j = -3; k = i + j;
	check(k, -1, "add failed: i8 + i8 -> long");

	// Desmet-ism, not standard C89
	i = 125; j = 3; k = i + j;
	check(k, -128, "add failed: i8 + i8 -> long");

	i = -1; j = -3; k = i - j;
	check(k, 2, "subtract failed: i8 - i8 -> long");

	// Desmet-ism, not standard C89
	i = -128; j = 3; k = i - j;
	check(k, 125, "subtract failed: i8 - i8 -> long");

	return failures;
}

int f7() {
	signed char i;
	int j, k;
	int failures = 0;

	i = 2; j = -3; k = i + j;
	check(k, -1, "add failed: i8 + int -> int");

	i = 125; j = 3; k = i + j;
	check(k, 128, "add failed: i8 + int -> int");

	i = -1; j = -3; k = i - j;
	check(k, 2, "subtract failed: i8 - int -> int");

	i = -128; j = 3; k = i - j;
	check(k, -131, "subtract failed: i8 - int -> int");

	return failures;
}

int f8() {
	signed char i;
	unsigned int j, k;
	int failures = 0;

	i = -2; j = 3; k = i + j;
	check(k, 1, "add failed: i8 + unsigned -> unsigned");

	i = 125; j = 4; k = i + j;
	check(k, 129, "add failed: i8 + unsigned -> unsigned");

	i = 5; j = 3; k = i - j;
	check(k, 2, "subtract failed: i8 - unsigned -> unsigned");

	i = -1; j = 1; k = i - j;
	check(k, 65534, "subtract failed: i8 - unsigned -> unsigned");

	return failures;
}

int f9() {
	signed char i;
	long j, k;
	int failures = 0;

	i = 2; j = -3; k = i + j;
	check(k, -1, "add failed: i8 + long -> long");

	i = 125; j = 3; k = i + j;
	check(k, 128, "add failed: i8 + long -> long");

	i = -1; j = -3; k = i - j;
	check(k, 2, "subtract failed: i8 - long -> long");

	i = -128; j = 3; k = i - j;
	check(k, -131, "subtract failed: i8 - long -> long");

	return failures;
}

int f10() {
	unsigned char i, j;
	unsigned k;
	int failures = 0;
	
	i = 0; j = 1; k = i * j;
	check(k, 0, "mul failed: u8 * u8 -> unsigned");

	i = 2; j = 3; k = i * j;
	check(k, 6, "mul failed: u8 * u8 -> unsigned");

	i = 25; j = 16; k = i * j;
	check(k, 400, "mul failed: u8 * u8 -> unsigned");

	i = 254; j = 255; k = i * j;
	check(k, 64770, "mul failed: u8 * u8 -> unsigned");

	assert(i*j > 0);
	check(i*j, 64770, "mul failed: u8 * u8 -> unsigned");

	return failures;
}

int f11() {
	signed char i, j;
	int k;
	int failures = 0;
	
	i = 0; j = 1; k = i * j;
	check(k, 0, "mul failed: i8 * i8 -> int");

	i = -2; j = 3; k = i * j;
	check(k, -6, "mul failed: i8 * i8 -> int");

	i = 25; j = 16; k = i * j;
	check(k, 400, "mul failed: i8 * i8 -> int");

	i = 64; j = -128; k = i * j;
	check(k, -8192, "mul failed: i8 * i8 -> int");

	assert(i*j < 0);
	check(i*j, -8192, "mul failed: i8 * i8 -> int");

	return failures;
}

int f12() {
	signed char i;
	unsigned char j;
	int k;
	int failures = 0;
	
	i = 0; j = 1; k = i * j;
	check(k, 0, "mul failed: i8 * u8 -> int");

	i = -2; j = 3; k = i * j;
	check(k, -6, "mul failed: i8 * u8 -> int");

	i = 25; j = 16; k = i * j;
	check(k, 400, "mul failed: i8 * u8 -> int");

	i = -64; j = 128; k = i * j;
	check(k, -8192, "mul failed: i8 * u8 -> int");

	assert(i*j < 0);
	check(i*j, -8192, "mul failed: i8 * u8 -> int");

	return failures;
}

int f13() {
	unsigned char i;
	signed char j;
	int k;
	int failures = 0;
	
	i = 0; j = 1; k = i * j;
	check(k, 0, "mul failed: u8 * i8 -> int");

	i = 2; j = -3; k = i * j;
	check(k, -6, "mul failed: u8 * i8 -> int");

	i = 25; j = 16; k = i * j;
	check(k, 400, "mul failed: u8 * i8 -> int");

	i = 64; j = -128; k = i * j;
	check(k, -8192, "mul failed: u8 * i8 -> int");

	assert(i*j < 0);
	check(i*j, -8192, "mul failed: u8 * i8 -> int");

	return failures;
}

int f14() {
	signed char i;
	int j, k;
	int failures = 0;
	
	i = 0; j = 1; k = i * j;
	check(k, 0, "mul failed: i8 * int -> int");

	i = -2; j = 3; k = i * j;
	check(k, -6, "mul failed: i8 * int -> int");

	i = 25; j = 16; k = i * j;
	check(k, 400, "mul failed: i8 * int -> int");

	i = 64; j = -128; k = i * j;
	check(k, -8192, "mul failed: i8 * int -> int");

	return failures;
}

int f15() {
	signed char j;
	int i, k;
	int failures = 0;
	
	i = 0; j = 1; k = i * j;
	check(k, 0, "mul failed: int * i8 -> int");

	i = -2; j = 3; k = i * j;
	check(k, -6, "mul failed: int * i8 -> int");

	i = 25; j = 16; k = i * j;
	check(k, 400, "mul failed: int * i8 -> int");

	i = 64; j = -128; k = i * j;
	check(k, -8192, "mul failed: int * i8 -> int");

	return failures;
}

int f16() {
	unsigned char i, j, k;
	int failures = 0;
	
	i = 0; j = 1; k = i / j;
	check(k, 0, "div failed: u8 / u8 -> u8");

	i = 6; j = 3; k = i / j;
	check(k, 2, "div failed: u8 / u8 -> u8");

	i = 255; j = 15; k = i / j;
	check(k, 17, "div failed: u8 / u8 -> u8");

	i = 15; j = 255; k = i / j;
	check(k, 0, "div failed: u8 / u8 -> u8");

	return failures;
}

int f17() {
	unsigned i;
	unsigned char j, k;
	int failures = 0;
	
	i = 0; j = 1; k = i / j;
	check(k, 0, "div failed: unsigned / u8 -> u8");

	i = 6; j = 3; k = i / j;
	check(k, 2, "div failed: unsigned / u8 -> u8");

	i = 400; j = 16; k = i / j;
	check(k, 25, "div failed: unsigned / u8 -> u8");

	i = 64770; j = 255; k = i / j;
	check(k, 254, "div failed: unsigned / u8 -> u8");

	return failures;
}

int f18() {
	signed char i, j, k;
	int failures = 0;
	
	i = 0; j = 1; k = i / j;
	check(k, 0, "div failed: i8 / i8 -> i8");
	printf("%d\n", (int) k);

	i = -6; j = 3; k = i / j;
	check(k, -2, "div failed: i8 / i8 -> i8");
	printf("%d\n", (int) k);

	i = 125; j = 5; k = i / j;
	check(k, 25, "div failed: i8 / i8 -> i8");
	printf("%d\n", (int) k);

	i = 56; j = -7; k = i / j;
	check(k, -8, "div failed: i8 / i8 -> i8");
	printf("%d\n", (int) k);

	i = -1; j = 2; k = i / j;
	check(k, 0, "div failed: i8 / i8 -> i8");
	printf("%d\n", (int) k);

	return failures;
}

int main()
{
	int failures = 0;
	failures += f1() + f2() + f3() + f4() + f5();
	failures += f6() + f7() + f8() + f9() + f10();
	failures += f11() + f12() + f13() + f14() + f15();
	failures += f16() + f17() + f18();
	printf("tests finished, %d failures.\n", failures);
	return 0;
}
