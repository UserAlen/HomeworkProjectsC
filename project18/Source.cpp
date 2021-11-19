#include <iostream>
#include <windows.h> //подключение функции Sleep
#include <ctime> //подключение функции time
using namespace std;

void clearConsole() {
	system("cls");
}
void getReturningMessage() {
	cout << endl;
	for (int i = 3; i > 0; i--) {
		cout << "\rВозврат через " << i << ". . .";
		Sleep(1000);
	}
}
void getErrorMessage() {
	cout << "\n[ОШИБКА] Что-то пошло не так. . .\n\nЕсли произошло зацикливание - ALT+F4\n\n";
	getReturningMessage();
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
void getSettingsMenu(short colorX, short colorO, short fieldSize, short firstInput) {
	clearConsole();
	char firstInputChar = 'X';
	switch (firstInput) {
	case 1:
		firstInputChar = 'O';
		break;
	case 2:
		firstInputChar = 'X';
		break;
	default:
		getErrorMessage();
		break;
	}
	cout << "Настройки\n";
	cout << "1. Цвет крестика \x1b[" << colorX << "m[X]\x1b[0m и нолика \x1b[" << colorO << "m[O]\x1b[0m\n";
	cout << "2. Кто первый ходит [" << firstInputChar << "]\n";
	cout << "3. Размер поля [" << fieldSize + 2 << "x" << fieldSize + 2 << "]\n";
	cout << "\nВведите нужный пункт: ";
}
void getStartGameMenu() {
	clearConsole();
	cout << "Выбор игры\n";
	cout << "1. Одиночная\n";
	cout << "2. Два игрока\n";
	cout << "\nВведите нужный пункт: ";
}
void showExitMessage(short number) {
	cout << "Введите число \"" << number << "\" для выхода\n\n";
}
void showArray(short array[], const short SIZE, short colorX, short colorO) {
	//0 - пусто
	//1 - нолик
	//2 - крестик
	short i = 0;
	short iSize3x3 = 3;
	short iSize4x4 = 4;
	short iSize5x5 = 5;
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
					if (i < 9) {
						cout << " ";
					}
				}
				iSize4x4 += 4;
			}
			else if (SIZE == 5 * 5) {
				for (; i < iSize5x5; i++) {
					cout << i + 1 << " ";
					if (i < 10) {
						cout << " ";
					}
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
			cout << "\x1b[" << colorO << "mО \x1b[0m";
		}
		else if (array[y] == 2) {
			cout << "\x1b[" << colorX << "mX \x1b[0m";
		}
	}
	cout << endl << endl;
}
short checkGameWin(short arrayInputs[], const short SIZE) {
	// функция:
	// возвращает 0, если еще никто не выиграл
	// возвращает 1, если выиграл нолик
	// возвращает 2, если выиграл крестик
	short shortSize = 3;
	if (SIZE == 3 * 3) { // проверка для 3x3
		shortSize = 3;
		for (short x = 0, y = 0; y < shortSize; x += shortSize, y++) {
			if (arrayInputs[x] == 2
				&&
				arrayInputs[x + 1] == 2
				&&
				arrayInputs[x + 2] == 2
				|| 
				arrayInputs[y] == 2
				&&
				arrayInputs[y + shortSize] == 2
				&&
				arrayInputs[y + shortSize * 2] == 2) {
				return 2;
			}
			else if (arrayInputs[x] == 1
				&&
				arrayInputs[x + 1] == 1
				&&
				arrayInputs[x + 2] == 1
				||
				arrayInputs[y] == 1
				&&
				arrayInputs[y + shortSize] == 1
				&&
				arrayInputs[y + shortSize * 2] == 1) {
				return 1;
			}
		}
		if (arrayInputs[0] == 2
			&&
			arrayInputs[1 + shortSize] == 2
			&&
			arrayInputs[2 + shortSize * 2] == 2
			||
			arrayInputs[shortSize - 1] == 2
			&& 
			arrayInputs[shortSize * 2 - 2] == 2
			&& 
			arrayInputs[shortSize * 2] == 2) {
			return 2;
		}
		else if (arrayInputs[0] == 1
			&&
			arrayInputs[1 + shortSize] == 1
			&&
			arrayInputs[2 + shortSize * 2] == 1
			||
			arrayInputs[shortSize - 1] == 1
			&&
			arrayInputs[shortSize * 2 - 2] == 1
			&&
			arrayInputs[shortSize * 2] == 1) {
			return 1;
		}
	}//3x3
	else if (SIZE == 4 * 4) { // проверка для 4x4
		shortSize = 4;
		for (short x = 0, y = 0; y < shortSize; x += shortSize, y++) {
			if (arrayInputs[x] == 2
				&&
				arrayInputs[x + 1] == 2
				&&
				arrayInputs[x + 2] == 2
				&&
				arrayInputs[x + 3] == 2
				||
				arrayInputs[y] == 2
				&&
				arrayInputs[y + shortSize] == 2
				&&
				arrayInputs[y + shortSize * 2] == 2
				&&
				arrayInputs[y + shortSize * 3] == 2) {
				return 2;
			}
			else if (arrayInputs[x] == 1
				&&
				arrayInputs[x + 1] == 1
				&&
				arrayInputs[x + 2] == 1
				&&
				arrayInputs[x + 3] == 1
				||
				arrayInputs[y] == 1
				&&
				arrayInputs[y + shortSize] == 1
				&&
				arrayInputs[y + shortSize * 2] == 1
				&&
				arrayInputs[y + shortSize * 3] == 1) {
				return 1;
			}
		}
		if (arrayInputs[0] == 2
			&&
			arrayInputs[1 + shortSize] == 2
			&&
			arrayInputs[2 + shortSize * 2] == 2
			&&
			arrayInputs[3 + shortSize * 3] == 2
			||
			arrayInputs[shortSize - 1] == 2
			&&
			arrayInputs[shortSize * 2 - 2] == 2
			&&
			arrayInputs[shortSize * 3 - 3] == 2
			&&
			arrayInputs[shortSize * 3] == 2) {
			return 2;
		}
		else if(arrayInputs[0] == 1
			&&
			arrayInputs[1 + shortSize] == 1
			&&
			arrayInputs[2 + shortSize * 2] == 1
			&&
			arrayInputs[3 + shortSize * 3] == 1
			||
			arrayInputs[shortSize - 1] == 1
			&&
			arrayInputs[shortSize * 2 - 2] == 1
			&&
			arrayInputs[shortSize * 3 - 3] == 1
			&&
			arrayInputs[shortSize * 3] == 1) {
			return 1;
		}
	}//4х4
	else if (SIZE == 5 * 5) {
		shortSize = 5;
		for (short x = 0, y = 0; y < shortSize; x += shortSize, y++) {
			if (arrayInputs[x] == 2
				&&
				arrayInputs[x + 1] == 2
				&&
				arrayInputs[x + 2] == 2
				&&
				arrayInputs[x + 3] == 2
				&&
				arrayInputs[x + 4] == 2
				||
				arrayInputs[y] == 2
				&&
				arrayInputs[y + shortSize] == 2
				&&
				arrayInputs[y + shortSize * 2] == 2
				&&
				arrayInputs[y + shortSize * 3] == 2
				&&
				arrayInputs[y + shortSize * 4] == 2) {
				return 2;
			}
			else if (arrayInputs[x] == 1
				&&
				arrayInputs[x + 1] == 1
				&&
				arrayInputs[x + 2] == 1
				&&
				arrayInputs[x + 3] == 1
				&&
				arrayInputs[x + 4] == 1
				||
				arrayInputs[y] == 1
				&&
				arrayInputs[y + shortSize] == 1
				&&
				arrayInputs[y + shortSize * 2] == 1
				&&
				arrayInputs[y + shortSize * 3] == 1
				&&
				arrayInputs[y + shortSize * 4] == 1) {
				return 1;
			}
		}
		if (arrayInputs[0] == 2
			&&
			arrayInputs[1 + shortSize] == 2
			&&
			arrayInputs[2 + shortSize * 2] == 2
			&&
			arrayInputs[3 + shortSize * 3] == 2
			&&
			arrayInputs[4 + shortSize * 4] == 2
			||
			arrayInputs[shortSize - 1] == 2
			&&
			arrayInputs[shortSize * 2 - 2] == 2
			&&
			arrayInputs[shortSize * 3 - 3] == 2
			&&
			arrayInputs[shortSize * 4 - 4] == 2
			&&
			arrayInputs[shortSize * 4] == 2) {
			return 2;
		}
		else if (arrayInputs[0] == 1
			&&
			arrayInputs[1 + shortSize] == 1
			&&
			arrayInputs[2 + shortSize * 2] == 1
			&&
			arrayInputs[3 + shortSize * 3] == 1
			&&
			arrayInputs[4 + shortSize * 4] == 1
			||
			arrayInputs[shortSize - 1] == 1
			&&
			arrayInputs[shortSize * 2 - 2] == 1
			&&
			arrayInputs[shortSize * 3 - 3] == 1
			&&
			arrayInputs[shortSize * 4 - 4] == 1
			&&
			arrayInputs[shortSize * 4] == 1) {
			return 1;
		}
	}
	return 0;
}
string showSoloGame(short array[], const short SIZE, short inputPlayer, short colorX, short colorO, short firstInput) {
	short round = 0;
	short numberInWhile = 1; //чтобы из цикла не выходило, пока while не обновит текущее поле
	if (inputPlayer != firstInput) {
		round = 1;
		numberInWhile = 2;
	}
	short inputBot;
	if (inputPlayer == 1) {
		inputBot = 2;
	}
	else {
		inputBot = 1;
	}

	short placeInput = 0;

	const short SIZE_FOR_ARRAY3x3 = 3 * 3;

	short arrayForSavingPlaceInputs3x3[SIZE_FOR_ARRAY3x3]{};
	for (short i = 0; i < SIZE_FOR_ARRAY3x3; i++) {
		arrayForSavingPlaceInputs3x3[i] = 0;
	}

	const short SIZE_FOR_ARRAY4x4 = 4 * 4;

	short arrayForSavingPlaceInputs4x4[SIZE_FOR_ARRAY4x4]{};
	for (short i = 0; i < SIZE_FOR_ARRAY4x4; i++) {
		arrayForSavingPlaceInputs4x4[i] = 0;
	}

	const short SIZE_FOR_ARRAY5x5 = 5 * 5;

	short arrayForSavingPlaceInputs5x5[SIZE_FOR_ARRAY5x5]{};
	for (short i = 0; i < SIZE_FOR_ARRAY5x5; i++) {
		arrayForSavingPlaceInputs5x5[i] = 0;
	}

	while (round != SIZE + numberInWhile) {
		clearConsole();
		showExitMessage(99);
		showArray(array, SIZE, colorX, colorO);
		short winGame = 0;
		if (SIZE == 3 * 3) {
			winGame = checkGameWin(arrayForSavingPlaceInputs3x3, SIZE);
			if (winGame == inputBot) {
				return "Победил [компьютер]";
			}
			else if (winGame == inputPlayer) {
				return "Победил [пользователь]";
			}
		}
		else if (SIZE == 4 * 4) {
			winGame = checkGameWin(arrayForSavingPlaceInputs4x4, SIZE);
			if (winGame == inputBot) {
				return "Победил [компьютер]";
			}
			else if (winGame == inputPlayer) {
				return "Победил [пользователь]";
			}
		}
		else if (SIZE == 5 * 5) {
			winGame = checkGameWin(arrayForSavingPlaceInputs5x5, SIZE);
			if (winGame == inputBot) {
				return "Победил [компьютер]";
			}
			else if (winGame == inputPlayer) {
				return "Победил [пользователь]";
			}
		}
		if (round == SIZE + numberInWhile - 1) {
			return "\nНичья\n";
		}
		if (round % 2 == 0) {
			cout << "\nХодит [пользователь]\n\n";
		}
		else {
			cout << "\nХодит [компьютер]\n\n";
			Sleep(1000);
		}

		if (round % 2 == 0) { // если раунд четный, то ходит пользователь
			cin >> placeInput; //пользователь вводит куда ставить inputPlayer
			if (placeInput == 99) {
				return "\nИгра закончена\n";
			}
			bool inputIsOkay = false;
			bool inputGotError = false;
			if (SIZE == 3 * 3) {
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
					if (arrayForSavingPlaceInputs3x3[placeInput - 1] != 0) {
						getErrorMessage();
						inputGotError = true;
					}
					else {
						arrayForSavingPlaceInputs3x3[placeInput - 1] = inputPlayer;
						inputIsOkay = true;
					}
					if (inputIsOkay == true && inputGotError == false) {
						array[placeInput - 1] = inputPlayer;
						round++;
					}
					break;
				default:
					getErrorMessage();
					break;
				}
			}
			else if (SIZE == 4 * 4) {
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
				case 10:
				case 11:
				case 12:
				case 13:
				case 14:
				case 15:
				case 16:
					if (arrayForSavingPlaceInputs4x4[placeInput - 1] != 0) {
						getErrorMessage();
						inputGotError = true;
					}
					else {
						arrayForSavingPlaceInputs4x4[placeInput - 1] = inputPlayer;
						inputIsOkay = true;
					}
					if (inputIsOkay == true && inputGotError == false) {
						array[placeInput - 1] = inputPlayer;
						round++;
					}
					break;
				default:
					getErrorMessage();
					break;
				}
			}
			else if (SIZE == 5 * 5) {
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
				case 10:
				case 11:
				case 12:
				case 13:
				case 14:
				case 15:
				case 16:
				case 17:
				case 18:
				case 19:
				case 20:
				case 21:
				case 22:
				case 23:
				case 24:
				case 25:
					if (arrayForSavingPlaceInputs5x5[placeInput - 1] != 0) {
						getErrorMessage();
						inputGotError = true;
					}
					else {
						arrayForSavingPlaceInputs5x5[placeInput - 1] = inputPlayer;
						inputIsOkay = true;
					}
					if (inputIsOkay == true && inputGotError == false) {
						array[placeInput - 1] = inputPlayer;
						round++;
					}
					break;
				default:
					getErrorMessage();
					break;
				}
			}
		}
		else { // если раунд нечетный, то ходит компьютер (бот)
			short placeBot;
			if (SIZE == 3 * 3) {
				placeBot = rand() % 9;
				while (arrayForSavingPlaceInputs3x3[placeBot] != 0) {
					placeBot = rand() % 9;
				}
				arrayForSavingPlaceInputs3x3[placeBot] = inputBot;
				array[placeBot] = inputBot;
				round++;
			}
			else if (SIZE == 4 * 4) {
				placeBot = rand() % 16;
				while (arrayForSavingPlaceInputs4x4[placeBot] != 0) {
					placeBot = rand() % 16;
				}
				arrayForSavingPlaceInputs4x4[placeBot] = inputBot;
				array[placeBot] = inputBot;
				round++;
			}
			else if (SIZE == 5 * 5) {
				placeBot = rand() % 25;
				while (arrayForSavingPlaceInputs5x5[placeBot] != 0) {
					placeBot = rand() % 25;
				}
				arrayForSavingPlaceInputs5x5[placeBot] = inputBot;
				array[placeBot] = inputBot;
				round++;
			}
		}
	}
	return "\nИгра закончена\n";
}
string showTwoPlayerGame(short array[], const short SIZE, short colorX, short colorO, short firstInput) {
	short round = 0;

	short placeInput = 0;

	short inputPlayer1 = firstInput;
	string colorPlayer1;
	string colorPlayer2;
	short inputPlayer2;
	if (firstInput == 1) {
		inputPlayer2 = 2;
	}
	else {
		inputPlayer2 = 1;
	}

	const short SIZE_FOR_ARRAY3x3 = 3 * 3;

	short arrayForSavingPlaceInputs3x3[SIZE_FOR_ARRAY3x3]{};
	for (short i = 0; i < SIZE_FOR_ARRAY3x3; i++) {
		arrayForSavingPlaceInputs3x3[i] = 0;
	}

	const short SIZE_FOR_ARRAY4x4 = 4 * 4;

	short arrayForSavingPlaceInputs4x4[SIZE_FOR_ARRAY4x4]{};
	for (short i = 0; i < SIZE_FOR_ARRAY4x4; i++) {
		arrayForSavingPlaceInputs4x4[i] = 0;
	}

	const short SIZE_FOR_ARRAY5x5 = 5 * 5;

	short arrayForSavingPlaceInputs5x5[SIZE_FOR_ARRAY5x5]{};
	for (short i = 0; i < SIZE_FOR_ARRAY5x5; i++) {
		arrayForSavingPlaceInputs5x5[i] = 0;
	}
	while (round != SIZE + 1) {
		clearConsole();
		showExitMessage(99);
		showArray(array, SIZE, colorX, colorO);
		short winGame = 0;
		if (SIZE == 3 * 3) {
			winGame = checkGameWin(arrayForSavingPlaceInputs3x3, SIZE);
			if (winGame == inputPlayer1) {
				return "Победил [игрок 1]";
			}
			else if (winGame == inputPlayer2) {
				return "Победил [игрок 2]";
			}
		}
		else if (SIZE == 4 * 4) {
			winGame = checkGameWin(arrayForSavingPlaceInputs4x4, SIZE);
			if (winGame == inputPlayer1) {
				return "Победил [игрок 1]";
			}
			else if (winGame == inputPlayer2) {
				return "Победил [игрок 2]";
			}
		}
		else if (SIZE == 5 * 5) {
			winGame = checkGameWin(arrayForSavingPlaceInputs5x5, SIZE);
			if (winGame == inputPlayer1) {
				return "Победил [игрок 1]";
			}
			else if (winGame == inputPlayer2) {
				return "Победил [игрок 2]";
			}
		}
		if (round == SIZE) {
			return "\nНичья\n";
		}
		if (round % 2 == 0) {
			if (firstInput == 1) {
				cout << "\nХодит [игрок 1 (\x1b[" << colorO << "mO\x1b[0m)]\n\n";
			}
			else {
				cout << "\nХодит [игрок 1 (\x1b[" << colorX << "mX\x1b[0m)]\n\n";
			}
		}
		else {
			if (firstInput == 1) {
				cout << "\nХодит [игрок 2 (\x1b[" << colorX << "mX\x1b[0m)]\n\n";
			}
			else {
				cout << "\nХодит [игрок 2 (\x1b[" << colorO << "mO\x1b[0m)]\n\n";
			}
		}
		short inputIsOkay = false;
		short inputGotError = false;
		if (round % 2 == 0) { // если раунд четный, то ходит первый игрок
			cin >> placeInput; //игрок 1 вводит, куда ставить inputPlayer1
			if (placeInput == 99) {
				return "\nИгра закончена\n";
			}
			inputIsOkay = false;
			inputGotError = false;
			if (SIZE == 3 * 3) {
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
					if (arrayForSavingPlaceInputs3x3[placeInput - 1] != 0) {
						getErrorMessage();
						inputGotError = true;
					}
					else {
						arrayForSavingPlaceInputs3x3[placeInput - 1] = inputPlayer1;
						inputIsOkay = true;
					}
					if (inputIsOkay == true && inputGotError == false) {
						array[placeInput - 1] = inputPlayer1;
						round++;
					}
					break;
				default:
					getErrorMessage();
					break;
				}
			}
			else if (SIZE == 4 * 4) {
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
				case 10:
				case 11:
				case 12:
				case 13:
				case 14:
				case 15:
				case 16:
					if (arrayForSavingPlaceInputs4x4[placeInput - 1] != 0) {
						getErrorMessage();
						inputGotError = true;
					}
					else {
						arrayForSavingPlaceInputs4x4[placeInput - 1] = inputPlayer1;
						inputIsOkay = true;
					}
					if (inputIsOkay == true && inputGotError == false) {
						array[placeInput - 1] = inputPlayer1;
						round++;
					}
					break;
				default:
					getErrorMessage();
					break;
				}
			}
			else if (SIZE == 5 * 5) {
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
				case 10:
				case 11:
				case 12:
				case 13:
				case 14:
				case 15:
				case 16:
				case 17:
				case 18:
				case 19:
				case 20:
				case 21:
				case 22:
				case 23:
				case 24:
				case 25:
					if (arrayForSavingPlaceInputs5x5[placeInput - 1] != 0) {
						getErrorMessage();
						inputGotError = true;
					}
					else {
						arrayForSavingPlaceInputs5x5[placeInput - 1] = inputPlayer1;
						inputIsOkay = true;
					}
					if (inputIsOkay == true && inputGotError == false) {
						array[placeInput - 1] = inputPlayer1;
						round++;
					}
					break;
				default:
					getErrorMessage();
					break;
				}
			}
		}
		else { // если раунд нечетный, то ходит игрок 2
			cin >> placeInput; //игрок 2 вводит, куда ставить inputPlayer2
			if (placeInput == 99) {
				return "\nИгра закончена\n";
			}
			inputIsOkay = false;
			inputGotError = false;
			if (SIZE == 3 * 3) {
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
					if (arrayForSavingPlaceInputs3x3[placeInput - 1] != 0) {
						getErrorMessage();
						inputGotError = true;
					}
					else {
						arrayForSavingPlaceInputs3x3[placeInput - 1] = inputPlayer2;
						inputIsOkay = true;
					}
					if (inputIsOkay == true && inputGotError == false) {
						array[placeInput - 1] = inputPlayer2;
						round++;
					}
					break;
				default:
					getErrorMessage();
					break;
				}
			}
			else if (SIZE == 4 * 4) {
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
				case 10:
				case 11:
				case 12:
				case 13:
				case 14:
				case 15:
				case 16:
					if (arrayForSavingPlaceInputs4x4[placeInput - 1] != 0) {
						getErrorMessage();
						inputGotError = true;
					}
					else {
						arrayForSavingPlaceInputs4x4[placeInput - 1] = inputPlayer2;
						inputIsOkay = true;
					}
					if (inputIsOkay == true && inputGotError == false) {
						array[placeInput - 1] = inputPlayer2;
						round++;
					}
					break;
				default:
					getErrorMessage();
					break;
				}
			}
			else if (SIZE == 5 * 5) {
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
				case 10:
				case 11:
				case 12:
				case 13:
				case 14:
				case 15:
				case 16:
				case 17:
				case 18:
				case 19:
				case 20:
				case 21:
				case 22:
				case 23:
				case 24:
				case 25:
					if (arrayForSavingPlaceInputs5x5[placeInput - 1] != 0) {
						getErrorMessage();
						inputGotError = true;
					}
					else {
						arrayForSavingPlaceInputs5x5[placeInput - 1] = inputPlayer2;
						inputIsOkay = true;
					}
					if (inputIsOkay == true && inputGotError == false) {
						array[placeInput - 1] = inputPlayer2;
						round++;
					}
					break;
				default:
					getErrorMessage();
					break;
				}
			}
		}
	}
	return "\nИгра закончена\n";
}
short getColor(short colorChoice) {
	switch (colorChoice) {
	case 1: return 0;
	case 2: return 90;
	case 3: return 91;
	case 4: return 92;
	case 5: return 93;
	case 6: return 94;
	case 7: return 95;
	case 8: return 96;
	default:
		getErrorMessage();
		return 0;
	}
}
void getXColorMenu(short colorX) {
	clearConsole();
	cout << "Выберите цвет для \x1b[" << colorX << "mX\x1b[0m:\n\n";
	cout << "1. Стандартный [\x1b[0mX\x1b[0m]\n";
	cout << "2. Серый [\x1b[90mX\x1b[0m]\n";
	cout << "3. Красный [\x1b[91mX\x1b[0m]\n";
	cout << "4. Зеленый  [\x1b[92mX\x1b[0m]\n";
	cout << "5. Желтый  [\x1b[93mX\x1b[0m]\n";
	cout << "6. Синий  [\x1b[94mX\x1b[0m]\n";
	cout << "7. Розовый  [\x1b[95mX\x1b[0m]\n";
	cout << "8. Голубой  [\x1b[96mX\x1b[0m]\n";
}
void getOColorMenu(short colorO) {
	clearConsole();
	cout << "Выберите цвет для \x1b[" << colorO << "mO\x1b[0m:\n\n";
	cout << "1. Стандартный [\x1b[0mO\x1b[0m]\n";
	cout << "2. Серый [\x1b[90mO\x1b[0m]\n";
	cout << "3. Красный [\x1b[91mO\x1b[0m]\n";
	cout << "4. Зеленый  [\x1b[92mO\x1b[0m]\n";
	cout << "5. Желтый  [\x1b[93mO\x1b[0m]\n";
	cout << "6. Синий  [\x1b[94mO\x1b[0m]\n";
	cout << "7. Розовый  [\x1b[95mO\x1b[0m]\n";
	cout << "8. Голубой  [\x1b[96mO\x1b[0m]\n";
}
void getColorsMenu(short colorX, short colorO) {
	clearConsole();
	cout << "Выберите для какого знака будете изменять цвет:\n 1. \x1b[" << colorX << "mX\x1b[0m\n ";
	cout << "2. \x1b[" << colorO << "mO\x1b[0m\n\n";
}
void clearArray(short array[], short SIZE) {//функция очистки массива от прошлой игры
	for (int i = 0; i < SIZE; i++) {
		array[i] = 0;
	}
}
void showReturningToMenuMessage() {
	cout << endl << "Введите любую цифру для возврата в меню. . ." << endl;
}
void getFieldSizeMenu() {
	clearConsole();
	cout << "Выбор размера поля:\n1. 3x3\n2. 4x4\n3. 5x5\n\n";
}
void showRules(short fieldSize, short firstInput) {
	string firstInputString = "";
	switch (firstInput) {
	case 1:
		firstInputString = "нолики";
		break;
	case 2:
		firstInputString = "крестики";
		break;
	default:
		getErrorMessage();
		break;
	}
	clearConsole();
	cout << "\t\tПравила:\n\n";
	cout << "\tИгроки по очереди ставят на свободные клетки поля размера [" << fieldSize + 2 << "x" << fieldSize + 2 << "] знаки ";
	cout << "(один всегда крестики, другой всегда нолики).\n";
	cout << "\tПервый, выстроивший в ряд [" << fieldSize + 2 << "] своих фигуры по вертикали, горизонтали или диагонали, выигрывает.\n";
	cout << "\tПервый ход делает игрок, ставящий [" << firstInputString << "].\n\n";
	cout << "*Данные в квадратных скобках можно изменить в меню \"Настройки\"\n\n";
}
int main() {
	setlocale(0, "");

	srand(time(NULL)); //инициализация функции генерации случайных чисел (чтобы каждый раз не генерировало одни и те же числа)

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

	//-- для настроек
	short firstInput = 2; //по умолчанию первый ходит крестик
	short inputSoloPlayer = 2; //по умолчанию пользователь в одиночной игре ходит крестиком
	short soloGameInput = 1; //по умолчанию в одиночной игре первый ходит пользователь

	short fieldSizeInput = 1; //по умолчанию выбрано поле 3х3


	short colorO = 0; //по умолчанию нолик без цвета (стандартный)
	short colorX = 0; //по умолчанию крестик без цвета (стандартный)
	//== для настроек

	short menu = 0;
	while (menu != 4) {
		getMenu();
		cin >> menu;
		short _; //нужно для того, чтобы сразу не закрывалось какое-либо окно в консоле

		switch (menu) {
		case 1: // начать игру
			getStartGameMenu();
			short menuStartGame;
			cin >> menuStartGame;
			switch (menuStartGame) {
			case 1: //Одиночная
				switch (fieldSizeInput) {
				case 1:
					cout << showSoloGame(array3x3, SIZE3x3, inputSoloPlayer, colorX, colorO, firstInput);
					showReturningToMenuMessage();
					clearArray(array3x3, SIZE3x3);
					break;
				case 2:
					cout << showSoloGame(array4x4, SIZE4x4, inputSoloPlayer, colorX, colorO, firstInput);
					showReturningToMenuMessage();
					clearArray(array4x4, SIZE4x4);
					break;
				case 3:
					cout << showSoloGame(array5x5, SIZE5x5, inputSoloPlayer, colorX, colorO, firstInput);
					showReturningToMenuMessage();
					clearArray(array5x5, SIZE5x5);
					break;
				default:
					getErrorMessage();
					break;
				}
				cin >> _;
				break;
			case 2: //Два игрока
				switch (fieldSizeInput) {
				case 1:
					cout << showTwoPlayerGame(array3x3, SIZE3x3, colorX, colorO, firstInput);
					showReturningToMenuMessage();
					clearArray(array3x3, SIZE3x3);
					break;
				case 2:
					cout << showTwoPlayerGame(array4x4, SIZE4x4, colorX, colorO, firstInput);
					showReturningToMenuMessage();
					clearArray(array4x4, SIZE4x4);
					break;
				case 3:
					cout << showTwoPlayerGame(array5x5, SIZE5x5, colorX, colorO, firstInput);
					showReturningToMenuMessage();
					clearArray(array5x5, SIZE5x5);
					break;
				default:
					getErrorMessage();
					break;
				}
				cin >> _;
				break;
			default:
				getErrorMessage();
				break;
			}
			break;
		case 2: {//настройки
			getSettingsMenu(colorX, colorO, fieldSizeInput, firstInput);
			short menuSettings;
			cin >> menuSettings;
			switch (menuSettings) {
			case 1: {// цвет крестика и нолика
				getColorsMenu(colorX, colorO);
				short choiceXO;
				cin >> choiceXO;
				switch (choiceXO) {
				case 1: { // цвет крестика
					getXColorMenu(colorX);
					short colorChoiceX;
					cin >> colorChoiceX;
					colorX = getColor(colorChoiceX);
					cout << "Выбран " << colorChoiceX << " пункт\n";
					showReturningToMenuMessage();
					break;
				}
				case 2: { //цвет нолика
					getOColorMenu(colorO);
					short colorChoiceO;
					cin >> colorChoiceO;
					colorO = getColor(colorChoiceO);
					cout << "Выбран " << colorChoiceO << " пункт\n";
					showReturningToMenuMessage();
					break;
				}
				default:
					getErrorMessage();
					break;
				}
				cin >> _;
				break;
			}
			case 2: // кто первый ходит
				clearConsole();
				cout << "1. Кто первый ходит из знаков\n";
				if (firstInput == inputSoloPlayer) {
					cout << "2. Настройка в одиночной игре [Первый ходит пользователь]\n";
				}
				else {
					cout << "2. Настройка в одиночной игре [Первый ходит компьютер]\n";
				}
				short menuFirstInput;
				cin >> menuFirstInput;
				switch (menuFirstInput) {
				case 1:
					clearConsole();
					cout << "Кто первый ходит из знаков\n\n";
					cout << "1. Крестик [X]\n";
					cout << "2. Нолик [O]\n";
					cin >> firstInput;
					switch (firstInput) {
					case 1:
						cout << "\nВыбран \"X\"\n";
						firstInput = 2;
						showReturningToMenuMessage();
						break;
					case 2:
						cout << "\nВыбран \"O\"\n";
						firstInput = 1;
						showReturningToMenuMessage();
						break;
					default:
						getErrorMessage();
						break;
					}
					break;
				case 2:
					clearConsole();
					cout << "Настройка в одиночной игре\n\n";
					cout << "Первый ходит:\n";
					cout << "1. Пользователь\n";
					cout << "2. Компьютер\n";
					cin >> soloGameInput;
					switch (soloGameInput) {
					case 1:
						inputSoloPlayer = firstInput;
						showReturningToMenuMessage();
						break;
					case 2:
						if (firstInput == 1) {
							inputSoloPlayer = 2;
						}
						else {
							inputSoloPlayer = 1;
						}
						showReturningToMenuMessage();
						break;
					default:
						getErrorMessage();
						break;
					}
					break;
				default:
					getErrorMessage();
					break;
				}
				if (soloGameInput == 1) {
					inputSoloPlayer = firstInput;
				}
				else if (soloGameInput == 2){
					if (firstInput == 1) {
						inputSoloPlayer = 2;
					}
					else {
						inputSoloPlayer = 1;
					}
				}
				cin >> _;
				break;
			case 3: // размер поля
				getFieldSizeMenu();
				cin >> fieldSizeInput;
				switch (fieldSizeInput) {
				case 1:
				case 2:
				case 3:
					cout << "Выбран " << fieldSizeInput << " пункт\n";
					showReturningToMenuMessage();
					break;
				default:
					getErrorMessage();
					break;
				}
				cin >> _;
				break;
			default:
				getErrorMessage();
				break;
			}
			break;
		}
		case 3: // правила
			showRules(fieldSizeInput, firstInput);
			showReturningToMenuMessage();
			cin >> _;
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