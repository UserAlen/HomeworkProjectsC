#include <iostream>
using namespace std;

void clearConsole() {
	system("cls");
}
void changeBackgroundColor() {
	system("color C0");
}
void changeTextColor() {
	system("color 0C");
}
void getSizeInt() {
	cout << "Размер типа данных INT - " << sizeof(int);
}
void getSizeChar() {
	cout << "Размер типа данных CHAR - " << sizeof(char);
}
void getSizeDouble() {
	cout << "Размер типа данных DOUBLE - " << sizeof(double);
}
void getSizeFloat() {
	cout << "Размер типа данных FLOAT - " << sizeof(float);
}
void getSizeBool() {
	cout << "Размер типа данных BOOL - " << sizeof(bool);
}
void showMessage() {
	cout << "Привет, я функция";
}
void showSquare() {
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			cout << "# ";
		}
		cout << endl;
	}
}
int main() {
	setlocale(0, "");
	cout << "[+] Программа - \"Функции\"\n\n";
	cout << "[1] Очистить консоль\n";
	cout << "[2] Изменить цвет фона консоли\n";
	cout << "[3] Изменить цвет текста консоли\n";
	cout << "[4] Вывести размер типа данных INT\n";
	cout << "[5] Вывести размер типа данных CHAR\n";
	cout << "[6] Вывести размер типа данных DOUBLE\n";
	cout << "[7] Вывести размер типа данных FLOAT\n";
	cout << "[8] Вывести размер типа данных BOOL\n";
	cout << "[9] Вывести сообщение \"Привет, я функция\"\n";
	cout << "[10] Вывести квадрат 5х5\n";
	cout << "[11] Выйти\n\n";
	cout << "[+] Выберите пункт: ";
	short menu;
	cin >> menu;
	cout << endl << endl;
	switch (menu) {
	case 1:
		clearConsole();
		break;
	case 2:
		changeBackgroundColor();
		break;
	case 3:
		changeTextColor();
		break;
	case 4:
		getSizeInt();
		break;
	case 5:
		getSizeChar();
		break;
	case 6:
		getSizeDouble();
		break;
	case 7:
		getSizeFloat();
		break;
	case 8:
		getSizeBool();
		break;
	case 9:
		showMessage();
		break;
	case 10:
		showSquare();
		break;
	case 11:
		return 0;
		break;
	default:
		cout << "[!] Неверно введен пункт";
		break;
	}

	short _; cin >> _;
	return 0;
}