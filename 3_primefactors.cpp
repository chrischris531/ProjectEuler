// finds the largest prime factor of a number: 600851475143

#include <iostream>

// function to check if numbers are divisible
bool check_divisible(long long a, int b) {
	if (a % b == 0) {
		return true;
	}

	return false;
}

// function to calculate prime factors at each stage
void calculate_pf(long long a, int b, int* lpf) {
	// only check until half of value because can't have lpf after this value
	if (b <= a / 2) {
		// check if divisible
		if (check_divisible(a, b)) {
			// set lpf
			*lpf = a / b;
			calculate_pf(a / b, b, lpf);
		}
		else {
			calculate_pf(a, b + 1, lpf);
		}


	}
}


int main() {
	// largest prime factor:
	int lpf = 1;

	calculate_pf(600851475143, 2, &lpf);

	// print lpf
	std::cout << lpf << std::endl;


	return 0;
}