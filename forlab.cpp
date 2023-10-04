#include <iostream>
int get_random_number(int min, int max) {
	srand(time(NULL));
	int number = min + rand() % (max - min + 1);
	return number;
}
bool get_user_input_type() {
	std::cout << "Choose the type of input: 1-automatically, 2-manually: ";
	int input_type;
	std::cin >> input_type;
	switch (input_type) {
	case 1: {
		return true;
		break;
	}
	case 2: {
		return false;
		break;
	}
	}
}
int main() {
	const int n = 10;
	int new_array[n];
	bool input_type = get_user_input_type();
	if (input_type==true) {
		std::cout << "\nEnter the boundaries for finding random numbers: ";
		int left, right;
		std::cin >> left >> right;
		if (right < left) {
			std::cout << "\nEnter the correct sequence of boundaries";
			return 1;
		}
		for (int i = 0; i < n; ++i) {
			new_array[i] = get_random_number(left, right);
			if (abs(new_array[i]) > n) {
				new_array[i] = 0;
			}
		}
	}
	else {
		for (int i = 0; i < n; ++i) {
			std::cin >> new_array[i];
			if (abs(new_array[i]) > n) {
				new_array[i] = 0;
			}
		}
	}
	std::cout << "\nThe sum of the elements of the array with odd numbers: ";
	int sum_of_elements = 0,i=1;
	for (; i < n;) {
		sum_of_elements += new_array[i];
		i += 2;
	}
	std::cout << sum_of_elements;
	int first_positive = -1, last_positive = -1;
	int q = 0;
	for (; q < n; ++q) {
		if (new_array[q] > 0) {
			if (first_positive == -1) {
				first_positive = q;
			}
			last_positive = q;
		}
	}
	if (first_positive == -1 || last_positive == -1) {
		std::cout << "\nThe necessary positive values are missing";
		return 1;
	}
	int umn = 1;
	bool over_zero;
	for (int u=first_positive; u <= last_positive; ++u) {
		over_zero = false;
		if (new_array[u] > 0) {
			over_zero = true;
		}
		if (over_zero == true) {
			umn *= new_array[u];
		}
	}
	if (umn < 0) {
		umn *= -1;
	}
	std::cout << "\nThe result of multiplication: " << umn;
	return 0;
}