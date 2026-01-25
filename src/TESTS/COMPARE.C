int tests = 0;
int failures = 0;

#define check(actual, expected, msg) \
	tests++; if(((actual)) != ((expected))) { puts(msg); failures++; }

void i8_eq_i8() {
	signed char i, j;
	i = -128; j = -128; check(i == j, 1, "comparison failed: i8 == i8");
	i = -128; j = -127; check(i == j, 0, "comparison failed: i8 == i8");
	i = 0; j = 0; check(i == j, 1, "comparison failed: i8 == i8");
	i = 0; j = 1; check(i == j, 0, "comparison failed: i8 == i8");
	i = 127; j = 127; check(i == j, 1, "comparison failed: i8 == i8");
	i = 127; j = 126; check(i == j, 0, "comparison failed: i8 == i8");
}

void i8_lt_i8() {
	signed char i, j;
	i = -128; j = -127; check(i < j, 1, "comparison failed: i8 < i8");
	i = -127; j = -128; check(i < j, 0, "comparison failed: i8 < i8");
	i = -1; j = 1; check(i < j, 1, "comparison failed: i8 < i8");
	i = 1; j = -1; check(i < j, 0, "comparison failed: i8 < i8");
	i = 126; j = 127; check(i < j, 1, "comparison failed: i8 < i8");
	i = 127; j = 126; check(i < j, 0, "comparison failed: i8 < i8");
}

int main()
{
	i8_eq_i8(); i8_lt_i8();
	printf("%s: %d tests finished, %d failures.\n",
		__FILE__, tests, failures);
	return 0;
}
