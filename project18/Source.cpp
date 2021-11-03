#include <iostream>
#include <windows.h> //подключение функции Sleep
using namespace std;

void clearConsole() {
	system("cls");
}
void getMenu() {
	clearConsole();
	cout << "Меню\n";
	cout << "1. Начать игру\n";
	cout << "2. Настройки\n";
	cout << "3. Правила\n";
	cout << "4. Выйти\n";
	cout << "\nВведите нужный пункт: ";
}
void getSettingsMenu() {
	clearConsole();
	cout << "Настройки\n";
	cout << "1. Цвет крестика и нолика\n";
	cout << "2. Кто первый ходит\n";
	cout << "3. Размер поля\n";
	cout << "\nВведите нужный пункт: ";
}
void getMessageError() {
	cout << "\n[ОШИБКА] Что-то пошло не так. . .\n\n";
	for (int i = 3; i > 0; i--) {
		cout << "\rВозврат в меню через " << i << ". . .";
		Sleep(1000);
	}
}
int main() {
	setlocale(0, "");

	short menu = 0;
	while (menu != 4) {
		getMenu();
		cin >> menu;
		while (menu < 1 || menu > 4) {
			getMessageError();
			getMenu();
			cin >> menu;
		}
		switch (menu) {
		case 1:
			break;
		case 2: {
			getSettingsMenu();
			short menuSettings;
			cin >> menuSettings;
			while (menuSettings < 1 || menuSettings > 3) {
				getMessageError();
				getSettingsMenu();
				cin >> menuSettings;
			}
			switch (menuSettings) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				getMessageError();
				break;
			}
			break;
		}
		case 3:
			break;
		case 4:
			return 0;
			break;
		default:
			getMessageError();
			break;
		}
	}

	short _; cin >> _;
	return 0;
}