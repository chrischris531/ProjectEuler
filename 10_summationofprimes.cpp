// Find the sum of all the primes below two million.

#include <iostream>

void sieve(unsigned long long int n, char primes[]) {
	unsigned long long int i, j;
	for (i = 0; i < n; i++) {
		primes[i] = 1;
	}
	primes[0] = 0;
	primes[1] = 0;
	for (i = 2; i < sqrt(n); i++) {
		for (j = i * i; j < n; j+=i) {
			primes[j] = 0;
		}
	}
}

int main() {
	// start off with 2 since we can then discount even numbers
	unsigned long long int sum = 0, i;

	char* v	= new char[2000000];
	sieve(2000000, v);
	for (i = 0; i < 2000000; i++) {
		if (v[i]) {
			sum += i;
		}
	}

	std::cout << sum;

	free(v);

	return 0;
}