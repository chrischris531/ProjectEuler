// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

#include <iostream>
#include <cmath>

int isSquare(double a) {
	double root = sqrt(a);
	return (root == floor(root)) ? (int)root : 0;
}

int main() {
	int i = 1, j = 1, root;
	while (true) {
		root = isSquare(pow(i, 2) + pow(j, 2));

		// if square
		if (root != 0) {
			if (i + j + root == 1000) {
				break;
			}
		}
		if (i == 500) {
			i = j;
			j++;
		}
		else {
			i++;
		}
	}


	std::cout << i * j * root << std::endl;

	return 0;
}