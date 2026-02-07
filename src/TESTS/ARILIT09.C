#include <stdio.h>

int tests = 0;
int failures = 0;
#define check(actual, expected) \
    tests++; if(((actual)) != ((expected))) { printf("test failed: line %d\n", __LINE__); failures++; }

void lit_add_lit() {
    check((1 + -2147483647-1), -2147483647);
    check((1 + -2147483647-1) < 0, 1);
    check((1 + -41234), -41233);
    check((1 + -41234) < 0, 1);
    check((1 + -21), -20);
    check((1 + -21) < 0, 1);
    check((1 + -1), 0);
    check((1 + -1) < 0, 0);
    check((1 + 0), 1);
    check((1 + 0) < 0, 0);
    check((1 + 1), 2);
    check((1 + 1) < 0, 0);
    check((1 + 2), 3);
    check((1 + 2) < 0, 0);
    check((1 + 4), 5);
    check((1 + 4) < 0, 0);
    check((1 + 47L), 48);
    check((1 + 47L) < 0, 0);
    check((1 + 41235), 41236);
    check((1 + 41235) < 0, 0);
    check((1 + 2147483647), -2147483647-1);
    check((1 + 2147483647) < 0, 1);
}
void lit_sub_lit() {
    check((1 - -2147483647-1), 2147483647);
    check((1 - -2147483647-1) < 0, 0);
    check((1 - -41234), 41235);
    check((1 - -41234) < 0, 0);
    check((1 - -21), 22);
    check((1 - -21) < 0, 0);
    check((1 - -1), 2);
    check((1 - -1) < 0, 0);
    check((1 - 0), 1);
    check((1 - 0) < 0, 0);
    check((1 - 1), 0);
    check((1 - 1) < 0, 0);
    check((1 - 2), -1);
    check((1 - 2) < 0, 1);
    check((1 - 4), -3);
    check((1 - 4) < 0, 1);
    check((1 - 47L), -46);
    check((1 - 47L) < 0, 1);
    check((1 - 41235), -41234);
    check((1 - 41235) < 0, 1);
    check((1 - 2147483647), -2147483646);
    check((1 - 2147483647) < 0, 1);
}
void lit_mul_lit() {
    check((1 * -2147483647-1), -2147483647-1);
    check((1 * -2147483647-1) < 0, 1);
    check((1 * -41234), -41234);
    check((1 * -41234) < 0, 1);
    check((1 * -21), -21);
    check((1 * -21) < 0, 1);
    check((1 * -1), -1);
    check((1 * -1) < 0, 1);
    check((1 * 0), 0);
    check((1 * 0) < 0, 0);
    check((1 * 1), 1);
    check((1 * 1) < 0, 0);
    check((1 * 2), 2);
    check((1 * 2) < 0, 0);
    check((1 * 4), 4);
    check((1 * 4) < 0, 0);
    check((1 * 47L), 47);
    check((1 * 47L) < 0, 0);
    check((1 * 41235), 41235);
    check((1 * 41235) < 0, 0);
    check((1 * 2147483647), 2147483647);
    check((1 * 2147483647) < 0, 0);
}
void lit_div_lit() {
    check((1 / -2147483647-1), -1);
    check((1 / -2147483647-1) < 0, 1);
    check((1 / -41234), 0);
    check((1 / -41234) < 0, 0);
    check((1 / -21), 0);
    check((1 / -21) < 0, 0);
    check((1 / -1), -1);
    check((1 / -1) < 0, 1);
    check((1 / 1), 1);
    check((1 / 1) < 0, 0);
    check((1 / 2), 0);
    check((1 / 2) < 0, 0);
    check((1 / 4), 0);
    check((1 / 4) < 0, 0);
    check((1 / 47L), 0);
    check((1 / 47L) < 0, 0);
    check((1 / 41235), 0);
    check((1 / 41235) < 0, 0);
    check((1 / 2147483647), 0);
    check((1 / 2147483647) < 0, 0);
}
void lit_mod_lit() {
    check((1 % -2147483647-1), 0);
    check((1 % -2147483647-1) < 0, 0);
    check((1 % -41234), 1);
    check((1 % -41234) < 0, 0);
    check((1 % -21), 1);
    check((1 % -21) < 0, 0);
    check((1 % -1), 0);
    check((1 % -1) < 0, 0);
    check((1 % 1), 0);
    check((1 % 1) < 0, 0);
    check((1 % 2), 1);
    check((1 % 2) < 0, 0);
    check((1 % 4), 1);
    check((1 % 4) < 0, 0);
    check((1 % 47L), 1);
    check((1 % 47L) < 0, 0);
    check((1 % 41235), 1);
    check((1 % 41235) < 0, 0);
    check((1 % 2147483647), 1);
    check((1 % 2147483647) < 0, 0);
}
void lit_ban_lit() {
    check((1 & -2147483647-1), 0);
    check((1 & -2147483647-1) < 0, 0);
    check((1 & -41234), 0);
    check((1 & -41234) < 0, 0);
    check((1 & -21), 1);
    check((1 & -21) < 0, 0);
    check((1 & -1), 1);
    check((1 & -1) < 0, 0);
    check((1 & 0), 0);
    check((1 & 0) < 0, 0);
    check((1 & 1), 1);
    check((1 & 1) < 0, 0);
    check((1 & 2), 0);
    check((1 & 2) < 0, 0);
    check((1 & 4), 0);
    check((1 & 4) < 0, 0);
    check((1 & 47L), 1);
    check((1 & 47L) < 0, 0);
    check((1 & 41235), 1);
    check((1 & 41235) < 0, 0);
    check((1 & 2147483647), 1);
    check((1 & 2147483647) < 0, 0);
}
void lit_bor_lit() {
    check((1 | -2147483647-1), -2147483647);
    check((1 | -2147483647-1) < 0, 1);
    check((1 | -41234), -41233);
    check((1 | -41234) < 0, 1);
    check((1 | -21), -21);
    check((1 | -21) < 0, 1);
    check((1 | -1), -1);
    check((1 | -1) < 0, 1);
    check((1 | 0), 1);
    check((1 | 0) < 0, 0);
    check((1 | 1), 1);
    check((1 | 1) < 0, 0);
    check((1 | 2), 3);
    check((1 | 2) < 0, 0);
    check((1 | 4), 5);
    check((1 | 4) < 0, 0);
    check((1 | 47L), 47);
    check((1 | 47L) < 0, 0);
    check((1 | 41235), 41235);
    check((1 | 41235) < 0, 0);
    check((1 | 2147483647), 2147483647);
    check((1 | 2147483647) < 0, 0);
}
void lit_xor_lit() {
    check((1 ^ -2147483647-1), -2147483647);
    check((1 ^ -2147483647-1) < 0, 1);
    check((1 ^ -41234), -41233);
    check((1 ^ -41234) < 0, 1);
    check((1 ^ -21), -22);
    check((1 ^ -21) < 0, 1);
    check((1 ^ -1), -2);
    check((1 ^ -1) < 0, 1);
    check((1 ^ 0), 1);
    check((1 ^ 0) < 0, 0);
    check((1 ^ 1), 0);
    check((1 ^ 1) < 0, 0);
    check((1 ^ 2), 3);
    check((1 ^ 2) < 0, 0);
    check((1 ^ 4), 5);
    check((1 ^ 4) < 0, 0);
    check((1 ^ 47L), 46);
    check((1 ^ 47L) < 0, 0);
    check((1 ^ 41235), 41234);
    check((1 ^ 41235) < 0, 0);
    check((1 ^ 2147483647), 2147483646);
    check((1 ^ 2147483647) < 0, 0);
}
void lit_lan_lit() {
    check((1 && -2147483647-1), 1);
    check((1 && -2147483647-1) < 0, 0);
    check((1 && -41234), 1);
    check((1 && -41234) < 0, 0);
    check((1 && -21), 1);
    check((1 && -21) < 0, 0);
    check((1 && -1), 1);
    check((1 && -1) < 0, 0);
    check((1 && 0), 0);
    check((1 && 0) < 0, 0);
    check((1 && 1), 1);
    check((1 && 1) < 0, 0);
    check((1 && 2), 1);
    check((1 && 2) < 0, 0);
    check((1 && 4), 1);
    check((1 && 4) < 0, 0);
    check((1 && 47L), 1);
    check((1 && 47L) < 0, 0);
    check((1 && 41235), 1);
    check((1 && 41235) < 0, 0);
    check((1 && 2147483647), 1);
    check((1 && 2147483647) < 0, 0);
}
void lit_lor_lit() {
    check((1 || -2147483647-1), 1);
    check((1 || -2147483647-1) < 0, 0);
    check((1 || -41234), 1);
    check((1 || -41234) < 0, 0);
    check((1 || -21), 1);
    check((1 || -21) < 0, 0);
    check((1 || -1), 1);
    check((1 || -1) < 0, 0);
    check((1 || 0), 1);
    check((1 || 0) < 0, 0);
    check((1 || 1), 1);
    check((1 || 1) < 0, 0);
    check((1 || 2), 1);
    check((1 || 2) < 0, 0);
    check((1 || 4), 1);
    check((1 || 4) < 0, 0);
    check((1 || 47L), 1);
    check((1 || 47L) < 0, 0);
    check((1 || 41235), 1);
    check((1 || 41235) < 0, 0);
    check((1 || 2147483647), 1);
    check((1 || 2147483647) < 0, 0);
}
void lit_lsh_lit() {
    check((1 << 1), 2);
    check((1 << 1) < 0, 0);
    check((1 << 2), 4);
    check((1 << 2) < 0, 0);
    check((1 << 3), 8);
    check((1 << 3) < 0, 0);
    check((1 << 4), 16);
    check((1 << 4) < 0, 0);
    check((1 << 5), 32);
    check((1 << 5) < 0, 0);
    check((1 << 6), 64);
    check((1 << 6) < 0, 0);
    check((1 << 7), 128);
    check((1 << 7) < 0, 0);
}
void lit_rsh_lit() {
    check((1 >> 1), 0);
    check((1 >> 1) < 0, 0);
    check((1 >> 2), 0);
    check((1 >> 2) < 0, 0);
    check((1 >> 3), 0);
    check((1 >> 3) < 0, 0);
    check((1 >> 4), 0);
    check((1 >> 4) < 0, 0);
    check((1 >> 5), 0);
    check((1 >> 5) < 0, 0);
    check((1 >> 6), 0);
    check((1 >> 6) < 0, 0);
    check((1 >> 7), 0);
    check((1 >> 7) < 0, 0);
}
int main() {
    lit_add_lit();
    lit_sub_lit();
    lit_mul_lit();
    lit_div_lit();
    lit_mod_lit();
    lit_ban_lit();
    lit_bor_lit();
    lit_xor_lit();
    lit_lan_lit();
    lit_lor_lit();
    lit_lsh_lit();
    lit_rsh_lit();
    printf("%s: %d tests finished, %d failures.\n",
    __FILE__, tests, failures);
}

