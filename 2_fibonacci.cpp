// By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
// Fibonacci sequence: 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

#include <iostream>

void fibonacci_v1(int a, int b, int * sum) {
	if (a + b > 4000000) {
		if (b % 2 == 0) {
			*sum += b;
		}
	}
	else {
		if (a % 2 == 0) {
			*sum += a;
		}
		fibonacci_v1(b, a + b, sum);
	}
}

int main() {

	int sum = 0;

	fibonacci_v1(1, 2, &sum);

	std::cout << sum << std::endl;

	return 0;
}