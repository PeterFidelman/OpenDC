#include <assert.h>

int tests = 0;
int failures = 0;

#define check(actual, expected, msg) \
	tests++; if(((actual)) != ((expected))) { puts(msg); failures++; }

void f1() {
	unsigned char i, j, k;

	i = 2; j = 3; k = i + j;
	check(k, 5, "add failed: u8 + u8 -> u8");

	i = 253; j = 3; k = i + j;
	check(k, 0, "add failed: u8 + u8 -> u8");

	i = 5; j = 3; k = i - j;
	check(k, 2, "subtract failed: u8 - u8 -> u8");

	i = 0; j = 3; k = i - j;
	check(k, 253, "subtract failed: u8 - u8 -> u8");
}

void f2() {
	unsigned char i, j;
	int k;

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
}

void f3() {
	signed char i, j, k;

	i = 2; j = -3; k = i + j;
	check(k, -1, "add failed: i8 + i8 -> i8");

	i = 125; j = 3; k = i + j;
	check(k, -128, "add failed: i8 + i8 -> i8");

	i = -1; j = -3; k = i - j;
	check(k, 2, "subtract failed: i8 - i8 -> i8");

	i = -128; j = 3; k = i - j;
	check(k, 125, "subtract failed: i8 - i8 -> i8");
}

void f4() {
	signed char i, j;
	int k;

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
}

void f5() {
	unsigned char i;
	signed char j;
	int k;

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
}

void f6() {
	signed char i, j;
	long k;

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
}

void f7() {
	signed char i;
	int j, k;

	i = 2; j = -3; k = i + j;
	check(k, -1, "add failed: i8 + int -> int");

	i = 125; j = 3; k = i + j;
	check(k, 128, "add failed: i8 + int -> int");

	i = -1; j = -3; k = i - j;
	check(k, 2, "subtract failed: i8 - int -> int");

	i = -128; j = 3; k = i - j;
	check(k, -131, "subtract failed: i8 - int -> int");
}

void f8() {
	signed char i;
	unsigned int j, k;

	i = -2; j = 3; k = i + j;
	check(k, 1, "add failed: i8 + unsigned -> unsigned");

	i = 125; j = 4; k = i + j;
	check(k, 129, "add failed: i8 + unsigned -> unsigned");

	i = 5; j = 3; k = i - j;
	check(k, 2, "subtract failed: i8 - unsigned -> unsigned");

	i = -1; j = 1; k = i - j;
	check(k, 65534, "subtract failed: i8 - unsigned -> unsigned");
}

void f9() {
	signed char i;
	long j, k;

	i = 2; j = -3; k = i + j;
	check(k, -1, "add failed: i8 + long -> long");

	i = 125; j = 3; k = i + j;
	check(k, 128, "add failed: i8 + long -> long");

	i = -1; j = -3; k = i - j;
	check(k, 2, "subtract failed: i8 - long -> long");

	i = -128; j = 3; k = i - j;
	check(k, -131, "subtract failed: i8 - long -> long");
}

void f10() {
	unsigned char i, j;
	unsigned k;

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
}

void f11() {
	signed char i, j;
	int k;

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
}

void f12() {
	signed char i;
	unsigned char j;
	int k;

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
}

void f13() {
	unsigned char i;
	signed char j;
	int k;

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
}

void f14() {
	signed char i;
	int j, k;

	i = 0; j = 1; k = i * j;
	check(k, 0, "mul failed: i8 * int -> int");

	i = -2; j = 3; k = i * j;
	check(k, -6, "mul failed: i8 * int -> int");

	i = 25; j = 16; k = i * j;
	check(k, 400, "mul failed: i8 * int -> int");

	i = 64; j = -128; k = i * j;
	check(k, -8192, "mul failed: i8 * int -> int");
}

void f15() {
	signed char j;
	int i, k;

	i = 0; j = 1; k = i * j;
	check(k, 0, "mul failed: int * i8 -> int");

	i = -2; j = 3; k = i * j;
	check(k, -6, "mul failed: int * i8 -> int");

	i = 25; j = 16; k = i * j;
	check(k, 400, "mul failed: int * i8 -> int");

	i = 64; j = -128; k = i * j;
	check(k, -8192, "mul failed: int * i8 -> int");
}

void f16() {
	unsigned char i, j, k;

	i = 0; j = 1; k = i / j;
	check(k, 0, "div failed: u8 / u8 -> u8");

	i = 6; j = 3; k = i / j;
	check(k, 2, "div failed: u8 / u8 -> u8");

	i = 255; j = 15; k = i / j;
	check(k, 17, "div failed: u8 / u8 -> u8");

	i = 15; j = 255; k = i / j;
	check(k, 0, "div failed: u8 / u8 -> u8");
}

void f17() {
	unsigned i;
	unsigned char j, k;

	i = 0; j = 1; k = i / j;
	check(k, 0, "div failed: unsigned / u8 -> u8");

	i = 6; j = 3; k = i / j;
	check(k, 2, "div failed: unsigned / u8 -> u8");

	i = 400; j = 16; k = i / j;
	check(k, 25, "div failed: unsigned / u8 -> u8");

	i = 64770; j = 255; k = i / j;
	check(k, 254, "div failed: unsigned / u8 -> u8");
}

void f18() {
	signed char i, j, k;

	i = 0; j = 1; k = i / j;
	check(k, 0, "div failed: i8 / i8 -> i8");

	i = -6; j = 3; k = i / j;
	check(k, -2, "div failed: i8 / i8 -> i8");

	i = 125; j = 5; k = i / j;
	check(k, 25, "div failed: i8 / i8 -> i8");

	i = 56; j = -7; k = i / j;
	check(k, -8, "div failed: i8 / i8 -> i8");

	i = -1; j = 2; k = i / j;
	check(k, 0, "div failed: i8 / i8 -> i8");
}

void f19() {
	signed int i;
	signed char j, k;

	i = 0; j = 1; k = i / j;
	check(k, 0, "div failed: int / i8 -> i8");

	i = -6; j = 3; k = i / j;
	check(k, -2, "div failed: int / i8 -> i8");

	i = 375; j = 15; k = i / j;
	check(k, 25, "div failed: int / i8 -> i8");

	i = 56; j = -7; k = i / j;
	check(k, -8, "div failed: int / i8 -> i8");

	i = -1; j = 2; k = i / j;
	check(k, 0, "div failed: int / i8 -> i8");
}

void f20() {
	signed int j;
	signed char i, k;

	i = 0; j = 1; k = i / j;
	check(k, 0, "div failed: i8 / int -> i8");

	i = -6; j = 3; k = i / j;
	check(k, -2, "div failed: i8 / int -> i8");

	i = 125; j = 5; k = i / j;
	check(k, 25, "div failed: i8 / int -> i8");

	i = 56; j = -7; k = i / j;
	check(k, -8, "div failed: i8 / int -> i8");

	i = -1; j = 2; k = i / j;
	check(k, 0, "div failed: i8 / int -> i8");
}

void f21() {
	unsigned char i;
	signed char j, k;

	i = 255; j = 13; k = i / j;
	check(k, 19, "div failed: u8 / i8 -> i8");

	i = 6; j = 3; k = i / j;
	check(k, 2, "div failed: u8 / i8 -> i8");

	i = 56; j = -7; k = i / j;
	check(k, -8, "div failed: u8 / i8 -> i8");

	i = 15; j = 25; k = i / j;
	check(k, 0, "div failed: u8 / i8 -> i8");
}

void f22() {
	unsigned char j;
	signed char i, k;

	i = 0; j = 1; k = i / j;
	check(k, 0, "div failed: i8 / u8 -> i8");

	i = 6; j = 3; k = i / j;
	check(k, 2, "div failed: i8 / u8 -> i8");

	i = -56; j = 7; k = i / j;
	check(k, -8, "div failed: i8 / u8 -> i8");

	i = 125; j = 255; k = i / j;
	check(k, 0, "div failed: i8 / u8 -> i8");
}

void f23() {
	long i, k;
	signed char j;

	i = 0; j = 1; k = i / j;
	check(k, 0, "div failed: long / i8 -> long");

	i = -427014; j = 126; k = i / j;
	check(k, -3389, "div failed: long / i8 -> long");

	i = 427014; j = -126; k = i / j;
	check(k, -3389, "div failed: long / i8 -> long");

	i = 504; j = 9; k = i / j;
	check(k, 56, "div failed: long / i8 -> long");

	i = -9; j = 56; k = i / j;
	check(k, 0, "div failed: long / i8 -> long");
}

void f24() {
	unsigned char i, j, k;

	i = 0; j = 1; k = i % j;
	check(k, 0, "mod failed: u8 % u8 -> u8");

	i = 6; j = 3; k = i % j;
	check(k, 0, "mod failed: u8 % u8 -> u8");

	i = 255; j = 13; k = i % j;
	check(k, 8, "mod failed: u8 % u8 -> u8");

	i = 115; j = 255; k = i % j;
	check(k, 115, "mod failed: u8 % u8 -> u8");
}

void f25() {
	signed char i, j, k;

	i = 0; j = 1; k = i % j;
	check(k, 0, "mod failed: i8 % i8 -> i8");

	i = 6; j = 3; k = i % j;
	check(k, 0, "mod failed: i8 % i8 -> i8");

	i = 125; j = 13; k = i % j;
	check(k, 8, "mod failed: i8 % i8 -> i8");

	i = -125; j = 13; k = i % j;
	check(k, -8, "mod failed: i8 % i8 -> i8");

	i = 125; j = -13; k = i % j;
	check(k, 8, "mod failed: i8 % i8 -> i8");

	i = 115; j = 127; k = i % j;
	check(k, 115, "mod failed: i8 % i8 -> i8");
}

void f26() {
	unsigned char i;
	signed char j, k;

	i = 0; j = 1; k = i % j;
	check(k, 0, "mod failed: u8 % i8 -> i8");

	i = 6; j = 3; k = i % j;
	check(k, 0, "mod failed: u8 % i8 -> i8");

	i = 125; j = 13; k = i % j;
	check(k, 8, "mod failed: u8 % i8 -> i8");

	i = 255; j = 13; k = i % j;
	check(k, 8, "mod failed: u8 % i8 -> i8");

	i = 125; j = -13; k = i % j;
	check(k, 8, "mod failed: u8 % i8 -> i8");

	i = 115; j = 127; k = i % j;
	check(k, 115, "mod failed: u8 % i8 -> i8");
}

void f27() {
	unsigned char j;
	signed char i, k;

	i = 0; j = 1; k = i % j;
	check(k, 0, "mod failed: u8 % i8 -> i8");

	i = 6; j = 3; k = i % j;
	check(k, 0, "mod failed: u8 % i8 -> i8");

	i = 125; j = 13; k = i % j;
	check(k, 8, "mod failed: u8 % i8 -> i8");

	i = 255; j = 13; k = i % j;
	check(k, 8, "mod failed: u8 % i8 -> i8");

	i = 125; j = -13; k = i % j;
	check(k, 8, "mod failed: u8 % i8 -> i8");

	i = 115; j = 127; k = i % j;
	check(k, 115, "mod failed: u8 % i8 -> i8");
}

int main()
{
	f1(); f2(); f3(); f4(); f5();
	f6(); f7(); f8(); f9(); f10();
	f11(); f12(); f13(); f14(); f15();
	f16(); f17(); f18(); f19(); f20();
	f21(); f22(); f23(); f24(); f25();
	f26();
	printf("%d tests finished, %d failures.\n", tests, failures);
	return 0;
}
