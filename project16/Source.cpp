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
	cout << "������ ���� ������ INT - " << sizeof(int);
}
void getSizeChar() {
	cout << "������ ���� ������ CHAR - " << sizeof(char);
}
void getSizeDouble() {
	cout << "������ ���� ������ DOUBLE - " << sizeof(double);
}
void getSizeFloat() {
	cout << "������ ���� ������ FLOAT - " << sizeof(float);
}
void getSizeBool() {
	cout << "������ ���� ������ BOOL - " << sizeof(bool);
}
void showMessage() {
	cout << "������, � �������";
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
	cout << "[+] ��������� - \"�������\"\n\n";
	cout << "[1] �������� �������\n";
	cout << "[2] �������� ���� ���� �������\n";
	cout << "[3] �������� ���� ������ �������\n";
	cout << "[4] ������� ������ ���� ������ INT\n";
	cout << "[5] ������� ������ ���� ������ CHAR\n";
	cout << "[6] ������� ������ ���� ������ DOUBLE\n";
	cout << "[7] ������� ������ ���� ������ FLOAT\n";
	cout << "[8] ������� ������ ���� ������ BOOL\n";
	cout << "[9] ������� ��������� \"������, � �������\"\n";
	cout << "[10] ������� ������� 5�5\n";
	cout << "[11] �����\n\n";
	cout << "[+] �������� �����: ";
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
		cout << "[!] ������� ������ �����";
		break;
	}

	short _; cin >> _;
	return 0;
}