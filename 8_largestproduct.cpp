// Find the thirteen adjacent digits in the 1000 - digit number that have the greatest product.What is the value of this product ?

#include <iostream>
#include <fstream>
#include <vector>

int main() {
	char c; // every char in file
	std::vector<int> buffer; // buffer numbers
	unsigned long long product = 1, maxProduct = 1; // the products: can be very big hence unsigned long long
	int current; // int of c
	int no = 4; // number looked for
	int zeroCounter = 0; // tracks 0s

	// define file as input
	std::ifstream fin("8_data.txt");

	// read character by character
	while (fin >> c) {
		// get int of current char
		current = c - '0';

		// insert into buffer
		buffer.insert(buffer.begin(), current);

		// wait for buffer to fill up, initialised by first three values
		if (buffer.size() == no + 1) {
			// divide by last value if non-zero
			if (buffer[no] != 0) {
				product /= buffer[no];
			}

			// remove overflow from buffer
			buffer.erase(buffer.end() - 1);
		}

		// if we detect a 0, we don't want to use the next 'no' numbers
		if (current == 0) {
			zeroCounter = no;
		}
		else if (zeroCounter != 0) {
			zeroCounter--;
		}

		// keep multiplying: very hacky, completely ignore 0s
		if (current != 0) {
			product *= current;
		}

		// update maxProduct if no zeros in current sequence
		if (product > maxProduct && zeroCounter == 0) {
			maxProduct = product;
		}
	}

	std::cout << maxProduct << std::endl;

	return 0;
}