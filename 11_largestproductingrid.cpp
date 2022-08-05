// What is the greatest product of four adjacent numbers in the same direction(up, down, left, right, or diagonally) in the 20×20 grid ?

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
	std::ifstream file("11_data.txt"); // file with the grid in
	std::string line; // each number in the grid and each line in the grid
	std::vector<std::vector<int>> nums(20, std::vector<int>(20)); // a 20 x 20 vector for storing the numbers
	int i = 0, j = 0;
	int num;

	// get every line
	while (std::getline(file, line)) {
		// get every number, which is every pair of characters at 0, 3, 6 etc
		for (int idx = 0; idx < line.size(); idx += 3) {
			// get number
			nums[i][j] = stoi(line.substr(idx, 2));

			// increase x coord
			j++;

			// reset x and increase y if necessary
			if (j == 20) {
				j = 0;
				i++;
			}
		}

	}

	int rowIdx = 0, colIdx = 0; // start off at 0,0
	unsigned long long int rowProduct = 1, colProduct = 1, leftDiagProduct = 1, rightDiagProduct = 1, maxProduct = 1; // track products
	
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			// each time, find product of row and check
			for (int counter = 0; counter < 4; counter++) {
				if (j < 17) {
					rowProduct *= nums[i][j + counter];
				}
				if (i < 17) {
					colProduct *= nums[i + counter][j];
				}

				if (j < 17 && i < 17) {
					leftDiagProduct *= nums[i + counter][j + counter];
					rightDiagProduct *= nums[i + 3 - counter][j + counter];
				}
			}
			if (rowProduct > maxProduct) {
				maxProduct = rowProduct;
			}
			if (colProduct > maxProduct) {
				maxProduct = colProduct;
			}
			if (leftDiagProduct > maxProduct) {
				maxProduct = leftDiagProduct;
			}
			if (rightDiagProduct > maxProduct) {
				maxProduct = rightDiagProduct;
			}

			rowProduct = 1;
			colProduct = 1;
			leftDiagProduct = 1;
			rightDiagProduct = 1;
		}
	}

	std::cout << maxProduct;
	
}