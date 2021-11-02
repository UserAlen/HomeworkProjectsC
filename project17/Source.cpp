#include <iostream>
using namespace std;
int sum(int num1, int num2, char operation) {
	if (operation == '/' && num2 == 0) return -1;

	switch (operation) {
	case '+': return num1 + num2;
	case '-': return num1 - num2;
	case '*': return num1 * num2;
	case '/': return num1 / num2;
	case '^': {
		int num = num1;
		for (int i = 1; i < num2; i++) {
			num1 *= num;
		}
		return num1;
	}
	case '%': return num1 % num2;
	case '!': {
		int result = 0;
		for (int i = 0; i <= num1; i++) {
			if (i == 0) {
				result = 1;
			}
			else {
				result *= i;
			}
		}
		return result;
	}
	case '?': {
		if (num1 < num2) {
			return num2;
		}
		else {
			return num1;
		}
	}
	default: return 0;
	}
}

int main() {
	setlocale(0, "");

	cout << "[+] Введите первое число: ";
	int num1;
	cin >> num1;

	cout << "[+] Введите второе число: ";
	int num2;
	cin >> num2;

	cout << endl << "[+] Действия:" << endl << endl;
	cout << "[+] Сложить первое число со вторым" << endl;
	cout << "[-] Вычесть из первого числа второе" << endl;
	cout << "[*] Умножить первое число со вторым" << endl;
	cout << "[/] Разделить первое число на второе" << endl;
	cout << "[^] Возвести первое число в степень второго числа" << endl;
	cout << "[%] Получить остаток при делении первого числа на второе" << endl;
	cout << "[!] Получить факториал первого числа" << endl;
	cout << "[?] Узнать какое из чисел является большим" << endl << endl;
	cout << "[+] Введите действие: ";
	char operation;
	cin >> operation;

	int result = sum(num1, num2, operation);

	cout << "[+] Результат: " << result << endl;

	cout << endl << "Для выхода нажмите любую клавишу. . .";
	int _; cin >> _;
	return 0;
}