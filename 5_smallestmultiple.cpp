// what is the smallest number evenly divisible by all numbers from 1 to 20?

#include <iostream>
#include <map>

// function to check if a is divisible by b
bool check_divisible(int a, int b) {
	return a % b == 0;
}

// function to work out prime factors and their powers and store in map
void pf_powers(int a, std::map<int, int>& prime_powers) {
	int original = a; // save original value
	int b = 2; // starting dividing factor
	int counter = 0; // counter of powers

	// + 1 is for the final value as well
	while (b <= original + 1) {
		// if divisible, divide and continue
		if (check_divisible(a, b)) {
			a /= b;
			counter++;
		}
		else {
			// counter > 0 means that there is a prime factor
			if (counter > 0) {
				if (prime_powers.find(b) == prime_powers.end()) {
					// does not exist in map: insert
					prime_powers.insert({ b, counter }); // prime factor : power
				}
				else if (prime_powers[b] < counter) {
					// new maximum power
					prime_powers[b] = counter;
				}
			}
			b++;
			counter = 0;
		}
	}
}

int main() {
	long long a = 1; // final value
	std::map<int, int> prime_powers; // prime factor : indice map

	// calculate all prime factor powers
	for (int i = 1; i <= 20; i++) {
		pf_powers(i, prime_powers);
	}

	// go through all prime factor powers and multiply each other when non-zero
	for (int i = 1; i <= 20; i++) {
		if (prime_powers[i] != 0) {
			a *= pow(i, prime_powers[i]);
		}
	}

	// print result
	std::cout << a << std::endl;

	return 0;
}