// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.

#include <iostream>

bool check_multiple(int a) {
	if (a % 3 == 0 || a % 5 == 0) {
		return true;
	}

	return false;
}

// brute force method
int brute_force() {
	// go from 1 to 1000 and sum multiples of 3 and 5
	int sum = 0;

	// up to but not including 1000
	for (int i = 0; i < 1000; i++) {
		if (check_multiple(i)) {
			sum += i;
		}
	}

	return sum;
}

int slightly_less() {
	// sum 1 to 333 and multiply by 3
	// add sum of 1 to 199 and multiply by 5
	// subtract sum of 1 to 66 multiplied by 15

	int sum = 0;

	for (int i = 0; i <= 333; i++) {
		if (i <= 66) {
			sum += i * 3;
			sum += i * 5;
			sum -= i * 15;
		}
		else if (i <= 199) {
			sum += i * 3;
			sum += i * 5;
		}
		else {
			sum += i * 3;
		}
	}

	return sum;
}

int using_equation() {
	// equation: s_n = n/2(2a + d(n-1))

	int sum = 0;

	int sum_threes = 333 * ((2 * 1 + 332 * 1)) * 3/2;
	int sum_fives = 199 * ((2 * 1 + 198 * 1)) * 5/2;
	int sum_fifteens = 66 * ((2 * 1 + 65 * 1)) * 15/2;

	return sum_threes + sum_fives - sum_fifteens;
}

int main() {
	std::cout << using_equation() << std::endl;
}