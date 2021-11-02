#include <iostream>
using namespace std;

int main() {
	setlocale(0, "");

	//8 arr 10 el

	const int SIZE = 10;
	int arr1[SIZE]{ 7,5,4,2,7,1,2,3,4,5 };
	short arr2[SIZE]{ 1,2,3,4,5,6,7,8,9,10 };
	long arr3[SIZE]{ 111, 222, 333, 444, 555,666,777,888,999,101010 };

	float arr4[SIZE]{ 1.1, 2.2, 3.3, 4.4, 5.5,6.6,7.7,8.8,9.9,10.1 };
	double arr5[SIZE]{ 1.11,2.22,3.33,4.44,5.55,6.66,7.77,8.88,9.99,10.11 };

	char arr6[SIZE]{ 'a','b', 'v', 'g', 'd', 'e', 'w', '!', '0', 'j' };
	bool arr7[SIZE]{ true,true,false,true,false,true,true,false,true,false };

	string arr8[SIZE]{ "Было", "Сделано", "Кабановой", "и", "Сафоновым", "8", "массивов", "с", "10", "элементами" };

	for (int i = 0; i < SIZE; i++) {
		cout << "arr1 [" << i << "] = " << arr1[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < SIZE; i++) {
		cout << "arr2 [" << i << "] = " << arr2[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < SIZE; i++) {
		cout << "arr3 [" << i << "] = " << arr3[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < SIZE; i++) {
		cout << "arr4 [" << i << "] = " << arr4[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < SIZE; i++) {
		cout << "arr5 [" << i << "] = " << arr5[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < SIZE; i++) {
		cout << "arr6 [" << i << "] = " << arr6[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < SIZE; i++) {
		cout << "arr7 [" << i << "] = " << arr7[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < SIZE; i++) {
		cout << "arr8 [" << i << "] = " << arr8[i] << endl;
	}

	int _; cin >> _;
	return 0;
}