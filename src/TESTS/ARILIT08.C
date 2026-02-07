#include <stdio.h>

int tests = 0;
int failures = 0;
#define check(actual, expected) \
    tests++; if(((actual)) != ((expected))) { printf("test failed: line %d\n", __LINE__); failures++; }

void u8_lor_lit() {
    unsigned char i;
    i = 36;
    check((-2147483647-1 || i), 1);
    check((-2147483647-1 || i) < 0, 0);
    i = 36;
    check((-41234 || i), 1);
    check((-41234 || i) < 0, 0);
    i = 36;
    check((-21 || i), 1);
    check((-21 || i) < 0, 0);
    i = 36;
    check((-1 || i), 1);
    check((-1 || i) < 0, 0);
    i = 36;
    check((0 || i), 1);
    check((0 || i) < 0, 0);
    i = 36;
    check((1 || i), 1);
    check((1 || i) < 0, 0);
    i = 36;
    check((2 || i), 1);
    check((2 || i) < 0, 0);
    i = 36;
    check((4 || i), 1);
    check((4 || i) < 0, 0);
    i = 36;
    check((47L || i), 1);
    check((47L || i) < 0, 0);
    i = 36;
    check((41235 || i), 1);
    check((41235 || i) < 0, 0);
    i = 36;
    check((2147483647 || i), 1);
    check((2147483647 || i) < 0, 0);
}
void i8_lor_lit() {
    signed char i;
    i = -21;
    check((-2147483647-1 || i), 1);
    check((-2147483647-1 || i) < 0, 0);
    i = -21;
    check((-41234 || i), 1);
    check((-41234 || i) < 0, 0);
    i = -21;
    check((-21 || i), 1);
    check((-21 || i) < 0, 0);
    i = -21;
    check((-1 || i), 1);
    check((-1 || i) < 0, 0);
    i = -21;
    check((0 || i), 1);
    check((0 || i) < 0, 0);
    i = -21;
    check((1 || i), 1);
    check((1 || i) < 0, 0);
    i = -21;
    check((2 || i), 1);
    check((2 || i) < 0, 0);
    i = -21;
    check((4 || i), 1);
    check((4 || i) < 0, 0);
    i = -21;
    check((47L || i), 1);
    check((47L || i) < 0, 0);
    i = -21;
    check((41235 || i), 1);
    check((41235 || i) < 0, 0);
    i = -21;
    check((2147483647 || i), 1);
    check((2147483647 || i) < 0, 0);
}
void u16_lor_lit() {
    unsigned int i;
    i = 36;
    check((-2147483647-1 || i), 1);
    check((-2147483647-1 || i) < 0, 0);
    i = 36;
    check((-41234 || i), 1);
    check((-41234 || i) < 0, 0);
    i = 36;
    check((-21 || i), 1);
    check((-21 || i) < 0, 0);
    i = 36;
    check((-1 || i), 1);
    check((-1 || i) < 0, 0);
    i = 36;
    check((0 || i), 1);
    check((0 || i) < 0, 0);
    i = 36;
    check((1 || i), 1);
    check((1 || i) < 0, 0);
    i = 36;
    check((2 || i), 1);
    check((2 || i) < 0, 0);
    i = 36;
    check((4 || i), 1);
    check((4 || i) < 0, 0);
    i = 36;
    check((47L || i), 1);
    check((47L || i) < 0, 0);
    i = 36;
    check((41235 || i), 1);
    check((41235 || i) < 0, 0);
    i = 36;
    check((2147483647 || i), 1);
    check((2147483647 || i) < 0, 0);
}
void i16_lor_lit() {
    int i;
    i = -113;
    check((-2147483647-1 || i), 1);
    check((-2147483647-1 || i) < 0, 0);
    i = -113;
    check((-41234 || i), 1);
    check((-41234 || i) < 0, 0);
    i = -113;
    check((-21 || i), 1);
    check((-21 || i) < 0, 0);
    i = -113;
    check((-1 || i), 1);
    check((-1 || i) < 0, 0);
    i = -113;
    check((0 || i), 1);
    check((0 || i) < 0, 0);
    i = -113;
    check((1 || i), 1);
    check((1 || i) < 0, 0);
    i = -113;
    check((2 || i), 1);
    check((2 || i) < 0, 0);
    i = -113;
    check((4 || i), 1);
    check((4 || i) < 0, 0);
    i = -113;
    check((47L || i), 1);
    check((47L || i) < 0, 0);
    i = -113;
    check((41235 || i), 1);
    check((41235 || i) < 0, 0);
    i = -113;
    check((2147483647 || i), 1);
    check((2147483647 || i) < 0, 0);
}
void i32_lor_lit() {
    long i;
    i = -81562;
    check((-2147483647-1 || i), 1);
    check((-2147483647-1 || i) < 0, 0);
    i = -81562;
    check((-41234 || i), 1);
    check((-41234 || i) < 0, 0);
    i = -81562;
    check((-21 || i), 1);
    check((-21 || i) < 0, 0);
    i = -81562;
    check((-1 || i), 1);
    check((-1 || i) < 0, 0);
    i = -81562;
    check((0 || i), 1);
    check((0 || i) < 0, 0);
    i = -81562;
    check((1 || i), 1);
    check((1 || i) < 0, 0);
    i = -81562;
    check((2 || i), 1);
    check((2 || i) < 0, 0);
    i = -81562;
    check((4 || i), 1);
    check((4 || i) < 0, 0);
    i = -81562;
    check((47L || i), 1);
    check((47L || i) < 0, 0);
    i = -81562;
    check((41235 || i), 1);
    check((41235 || i) < 0, 0);
    i = -81562;
    check((2147483647 || i), 1);
    check((2147483647 || i) < 0, 0);
}

int main() {
    u8_lor_lit();
    i8_lor_lit();
    u16_lor_lit();
    i16_lor_lit();
    i32_lor_lit();
    printf("%s: %d tests finished, %d failures.\n",
    __FILE__, tests, failures);
}

