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
	short i = 0;
	short iSize3x3 = 3;
	short iSize4x4 = 4;
	short iSize5x5 = 4;
	for (short y = 0; y < SIZE + 1; y++) {
		if ( // 
			(SIZE == 3 * 3 && (y == 3 || y == 3 * 2 || y == 3 * 3))
			||
			(SIZE == 4 * 4 && (y == 4 || y == 4 * 2 || y == 4 * 3 || y == 4 * 4))
			||
			(SIZE == 5 * 5 && (y == 5 || y == 5 * 2 || y == 5 * 3 || y == 5 * 4 || y == 5 * 5))
			) {
			cout << "\t";
			if (SIZE == 3 * 3) {
				for (; i < iSize3x3; i++) {
					cout << i + 1 << " ";
				}
				iSize3x3 += 3;
			}
			else if (SIZE == 4 * 4) {
				for (; i < iSize4x4; i++) {
					cout << i + 1 << " ";
				}
				iSize4x4 += 4;
			}
			else if (SIZE == 5 * 5) {
				for (; i < iSize5x5; i++) {
					cout << i + 1 << " ";
				}
				iSize5x5 += 5;
			}
			cout << endl;
		}
		if (y == SIZE) {
			break;
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

string getSoloGameMessage(short array[], const short SIZE, short inputPlayer) {//добавить в параметры цвета, arrayInput после настроек
	// ДОБАВИТЬ ИНФО КТО ХОДИТ
	short roundPlayer = 0;
	short roundBot = 0;

	short inputBot;
	if (inputPlayer == 1) {
		inputBot = 2;
	}
	else {
		inputBot = 1;
	}

	short placeInput = 0;
	//Если место уже помечено Х или 0, то туда больше нельзя ставить
	while (roundPlayer + roundBot != SIZE + 1) {
		clearConsole();
		showArray(array, SIZE);
		if (roundPlayer + roundBot == SIZE) {
			return "Тест\n";
		}
		else {
			cin >> placeInput; //пользователь вводит куда ставить arrayInput
			switch (placeInput) {
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				array[placeInput - 1] = inputPlayer;
				roundPlayer++;
				break;
			default:
				getErrorMessage();
				break;
			}
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
		short _; //нужно для того, чтобы сразу не закрывалось какое-либо окно в консоле

		//-- для настроек
		short inputPlayer1 = 2;
		short inputPlayer2 = 1;
		
		short arraySizeInput = 1;

		short colorO = 1;
		short colorX = 1;
		//== для настроек (перекинуть за цикл)


		switch (menu) {
		case 1: // начать игру
			getStartGameMenu();
			short menuStartGame;
			cin >> menuStartGame;
			switch (menuStartGame) {
			case 1: //Одиночная
				cout << getSoloGameMessage(array3x3, SIZE3x3, inputPlayer1);//в разработке
				cout << endl << "Введите что-нибудь для возврата в меню. . ." << endl;
				cin >> _;
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
	return 0;
}