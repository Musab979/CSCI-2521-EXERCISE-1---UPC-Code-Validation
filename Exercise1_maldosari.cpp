/**
 * @file Exercise1_maldosari.cpp
 * @author Musab Aldosari
 * @date 2026-10-18
 * @brief This program validates UPC-A barcodes performing the UPC-A check digit algorithim.
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Checks whether the UPC contains exactly 12 digits.
 * @param upc The UPC code entered by the user.
 * @return True if the input contains exactly 12 digits else = false.
 */

bool isInputValid(string upc) {
	bool validInput = true;

	if (upc.length() != 12) {
		validInput = false;
	}
	else {
		for (int i = 0; i < 12; i++) {
			if (upc[i] < '0' || upc[i] > '9') {
				validInput = false;
			}
		}
	}
	return validInput;
}

/**
 * @brief Calculates the check digit using the first 11 UPC digits.
 * @param upc A UPC code containing exactly 12 numeric digits.
 * @return The calculated check digit.
 */
int calculateCheckDigit(string upc) {
	int evenSum = 0;
	int oddSum = 0;

	for (int i = 0; i < 11; i = i + 2) {
		oddSum = oddSum + (upc[i] - '0');
	}

	for (int i = 1; i < 11; i = i + 2) {
		evenSum = evenSum + (upc[i] - '0');
	}

	int total = (oddSum * 3) + evenSum;
	int remainder = total % 10;
	int checkDigit = 0;

	if (remainder != 0) {
		checkDigit = 10 - remainder;
	}
	return checkDigit;
}

/**
 * @brief Compares the calculated check digit with the entered check digit.
 * @param upc A UPC code containing exactly 12 numeric digits.
 * @return True if the UPC code is valid, else = false.
 */
bool isUPCValid(string upc) {
	int checkDigit = calculateCheckDigit(upc);
	int enteredCheckDigit = upc[11] - '0';

	if (checkDigit == enteredCheckDigit) {
		return true;
	}
	else {
		return false;
	}
}

/**
 * @brief Prompts the user to enter a UPC code and validates it.
 * @return 0 when program executes successfully.
 */

int main() {
	string upc;
	int choice = 1;

	cout << "Do you want to enter a UPC code? (1 for Yes, 0 for No): ";
	cin >> choice;

	while (choice == 1) {
		cout << "Enter a 12-digit UPC code: ";
		cin >> upc;

		if (isInputValid(upc)) {
			if (isUPCValid(upc)) {
				cout << "The UPC code is valid." << endl;
			}
			else {
				cout << "The UPC code is invalid." << endl;
			}
		}
		else {
			cout << "Invalid input. Please enter exactly 12 digits." << endl;
		}
		cout << "Do you want to enter another UPC code? (1 for Yes, 0 for No): ";
		cin >> choice;
	}
	return 0;
}
		