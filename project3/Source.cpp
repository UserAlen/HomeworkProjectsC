#include <iostream>
using namespace std;
int main() {
	setlocale(0, "");
	cout << "Выберите операцию" << endl << endl;
	cout << "[+] складывать" << endl;
	cout << "[-] вычитать" << endl;
	cout << "[*] умножать" << endl;
	cout << "[/] делить" << endl;
	cout << "[%] деление от остатка" << endl;
	char menu;
	cin >> menu;
	if (menu == '+') {
		system("cls");
		cout << "Вы выбрали [+]" << endl;
		cout << "Введите первое число: ";
		short number1;
		cin >> number1;
		cout << "Введите второе число: ";
		short number2;
		cin >> number2;
		cout << "[+] Результат : " << number1 << " + " << number2 << " = " << (number1 + number2);
	}
	else if (menu == '-') {
		system("cls");
		cout << "Вы выбрали [-]" << endl;
		cout << "Введите первое число: ";
		short number1;
		cin >> number1;
		cout << "Введите второе число: ";
		short number2;
		cin >> number2;
		cout << "[-] Результат : " << number1 << " - " << number2 << " = " << (number1 - number2);
	}
	else if (menu == '*') {
		system("cls");
		cout << "Вы выбрали [*]" << endl;
		cout << "Введите первое число: ";
		short number1;
		cin >> number1;
		cout << "Введите второе число: ";
		short number2;
		cin >> number2;
		cout << "[*] Результат : " << number1 << " * " << number2 << " = " << (number1 * number2);
	}
	else if (menu == '/') {
		system("cls");
		cout << "Вы выбрали [/]" << endl;
		cout << "Введите первое число: ";
		short number1;
		cin >> number1;
		cout << "Введите второе число: ";
		short number2;
		cin >> number2;
		if (number2 == 0) {
			cout << "Делить на 0 запрещено";
		}
		else {
			cout << "[/] Результат : " << number1 << " / " << number2 << " = " << (number1 / number2);
		}
	}
	else if (menu == '%') {
		system("cls");
		cout << "Вы выбрали [%]" << endl;
		cout << "Введите первое число: ";
		short number1;
		cin >> number1;
		cout << "Введите второе число: ";
		short number2;
		cin >> number2;
		if (number2 == 0) {
			cout << "Делить на 0 запрещено";
		}
		else {
			cout << "[%] Результат : " << number1 << " % " << number2 << " = " << (number1 % number2);
		}
	}
	else {
		system("cls");
		cout << "Такой операции не существует";
	}
	int _; cin >> _;
	return 0;
}