#include <iostream>
using namespace std;

int main() {
	setlocale(0, "");

	cout << "[-] Программа \"Времена года\"\n\n";
	cout << "[1] Лето\n";
	cout << "[2] Осень\n";
	cout << "[3] Зима\n";
	cout << "[4] Весна\n\n";
	cout << "[-] Введите значение: ";
	short menu;
	cin >> menu;
	if (menu == 1) {
		system("cls");
		cout << "[+] Лето\n\n";
		cout << "Сейчас лето, следует взять с собой головной убор";
	}
	else if (menu == 2) {
		system("cls");
		cout << "[+] Осень\n\n";
		cout << "Сейчас осень, следует одеться телпо и взять с собой зонт";
	}
	else if (menu == 3) {
		system("cls");
		cout << "[+] Зима\n\n";
		cout << "Сейчас зима, следует одеться как можно теплее";
	}
	else if (menu == 4) {
		system("cls");
		cout << "[+] Весна\n\n";
		cout << "Сейчас весна, теплая погода";
	}
	else {
		cout << endl;
		cout << "[!]Такого времени года нет";
	}

	short _; cin >> _; //чтобы программа не закрывалась и пользователь мог увидеть результат
	return 0;
}