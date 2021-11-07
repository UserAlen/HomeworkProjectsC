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
void getErrorMessage() {
	cout << "\n[ОШИБКА] Что-то пошло не так. . .\n\nЕсли произошло зацикливание - ALT+F4\n\n";
	for (int i = 3; i > 0; i--) {
		cout << "\rВозврат через " << i << ". . .";
		Sleep(1000);
	}
}
void getStartGameMenu() {
	clearConsole();
	cout << "Настройки\n";
	cout << "1. Одиночная\n";
	cout << "2. Два игрока\n";
	cout << "\nВведите нужный пункт: ";
}
void showArray(short array[], const short SIZE) {//доработать 12345 abcde
	//0 - пусто
	//1 - нолик
	//2 - крестик
	for (int y = 0; y < SIZE; y++) {
		if (
			(SIZE == 3 * 3 && (y == 3 || y == 3 * 2 || y == 3 * 3))
			||
			(SIZE == 4 * 4 && (y == 4 || y == 4 * 2 || y == 4 * 3 || y == 4 * 4))
			||
			(SIZE == 5 * 5 && (y == 5 || y == 5 * 2 || y == 5 * 3 || y == 5 * 4 || y == 5 * 5))
			) {
			cout << endl;
		}

		if (array[y] == 0) {
			cout << "# ";
		}
		else if (array[y] == 1) {
			cout << "О ";
		}
		else if (array[y] == 2) {
			cout << "X ";
		}
	}
	cout << endl << endl;
}

void showArrayGuide(const short SIZE) { //гайд куда ставить 
	//123 abc 
	//1. 1a
	//2. 2a
	if (SIZE == 3 * 3) { // для поля 3х3

	}
	//добавить else if 4x4 else if 5x5
}
string getSoloGameMessage(short array[], const short SIZE) {//добавить в параметры цвета, arrayInput после настроек
	// ДОБАВИТЬ ИНФО КТО ХОДИТ
	short roundPlayer = 0;
	short roundBot = 0;

	short arrayInput = 0;

	short placeInput = 0;
	//Если место уже помечено Х или 0, то туда больше нельзя ставить
	while (roundPlayer + roundBot != SIZE) {
		clearConsole();
		showArray(array, SIZE);
		cin >> arrayInput; // позже placeInput - пользователь вводит куда ставить arrayInput
		switch (arrayInput) { // тест как отрабатывает массив
		case 1:
		case 2:
			array[placeInput] = arrayInput;
			roundPlayer++;
			break;
		default:
			getErrorMessage();
			break;
		}
	}
	return "В разработке";
}
int main() {
	setlocale(0, "");

	const short SIZE3x3 = 3 * 3;
	short array3x3[SIZE3x3] = {
		0,0,0,
		0,0,0,
		0,0,0
	};

	const short SIZE4x4 = 4 * 4;
	short array4x4[SIZE4x4] = {
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0
	};

	const short SIZE5x5 = 5 * 5;
	short array5x5[SIZE5x5] = {
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	};

	short menu = 0;
	while (menu != 4) {
		getMenu();
		cin >> menu;
		
		switch (menu) {
		case 1: // начать игру
			getStartGameMenu();
			short menuStartGame;
			cin >> menuStartGame;
			switch (menuStartGame) {
			case 1: //Одиночная
				getSoloGameMessage(array3x3, SIZE3x3);//в разработке
				break;
			case 2: //Два игрока
				//в разработке
				break;
			default:
				getErrorMessage();
				break;
			}
			break;
		case 2: {//настройки
			getSettingsMenu();
			short menuSettings;
			cin >> menuSettings;
			switch (menuSettings) {
			case 1: // цвет крестика и нолика
				//в разработке
				break;
			case 2: // кто первый ходит
				//в разработке
				break;
			case 3: // размер поля
				//в разработке
				break;
			default:
				getErrorMessage();
				break;
			}
			break;
		}
		case 3: // правила
			//в разработке (добавить функцию showRules())
			break;
		case 4: // выход
			return 0;
			break;
		default:
			getErrorMessage();
			break;
		}
	}

	short _; cin >> _;
	return 0;
}