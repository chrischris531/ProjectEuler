// Find the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>

// function to check if number is palindrome
bool isPalindrome(int a) {
	// split into 6 digits
	int p1, p2, p3, p4, p5, p6;
	p1 = a / 100000;
	p2 = (a % 100000) / 10000;
	p3 = (a % 10000) / 1000;
	p4 = (a % 1000) / 100;
	p5 = (a % 100) / 10;
	p6 = a % 10;

	return (p1 == p6 && p2 == p5 && p3 == p4);

}

// abccba = 100000a + 10000b + 1000c + 100c + 10b + a;
// = 100001a + 10010b + 1100c
// = 11(9091a + 910b + 100c) -> one of the numbers is divisible by 11

int main() {
	int max = 1; // for getting max palindrome
	int temp; // for getting multiplied value

	// go through all pairs of 3 digit numbers
	for (int i = 110; i < 1000; i+=11) { // make one divisible by 11
		for (int j = 100; j < 1000; j++) {
			temp = i * j;
			if (isPalindrome(temp) && temp > max) {
				// if found palindrome and it's the largest one yet, set it
				max = temp;
			}
		}
	}

	std::cout << max << std::endl;
	return 0;
}