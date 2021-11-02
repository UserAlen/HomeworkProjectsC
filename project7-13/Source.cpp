#include <iostream>
using namespace std;

int main() {
	setlocale(0, "");

	cout << "[+] Программа - \"Геометрические фигуры\"" << endl << endl;
	cout << "[1] Линия" << endl;
	cout << "[2] Квадрат" << endl;
	cout << "[3] Прямоугольник" << endl;
	cout << "[4] Треугольник" << endl;
	cout << "[5] Решетка" << endl;
	cout << "[6] Крестик" << endl;
	cout << "[7] Плюс" << endl;
	cout << "[8] Выйти" << endl;

	cout << endl << "[+] Введите номер нужного Вам пункта: ";
	short mainMenu;
	cin >> mainMenu;

	short lineVertical = 0; //Счетчик для вертикальной линии
	short lineHorizontal = 0; //Счетчик для горизонтальной линии

	short squareHigh = 0; //Счетчик для линий в высоту в квадрате (y)
	short squareWidth = 0; //Счетчик для линий в ширину в квадрате (x)

	short rectangleHighCount = 0; //Счетчик для линий в высоту в прямоугольнике (y)
	short rectangleWidthCount = 0; //Счетчик для линий в ширину в прямоугольнике (x)

	switch (mainMenu) {
	case 1:
		system("cls");
		cout << "[+] Фигура: \"Линия\"" << endl << endl;
		cout << "[+] Введите размер линии в символах: ";
		short lineSize;
		cin >> lineSize;
		while (lineSize < 1) {
			cout << endl << "[+] Введите размер линии в символах: ";
			cin >> lineSize;
		}

		cout << endl << "[+] Выберите текстуру: ";
		char lineTexture;
		cin >> lineTexture;
		cout << endl << "[1] Вертикальная линия";
		cout << endl << "[2] Горизонтальная линия" << endl;
		cout << endl << "[+] Выберите номер с типом линии из указанных выше: ";
		short lineType;
		cin >> lineType;
		cout << endl;
		switch (lineType) {
		case 1:
			while (lineVertical < lineSize) {
				cout << lineTexture << endl;
				lineVertical++;
			}
			break;
		case 2:
			while (lineHorizontal < lineSize) {
				if (lineHorizontal == lineSize - 1) { //Чтобы не было лишнего пробела и был перенос на следующую строку
					cout << lineTexture << endl;
					break;
				}
				else {
					cout << lineTexture << " ";
					lineHorizontal++;
				}
			}
			break;
		default:
			cout << endl << "[+] Неверно введен номер";
			break;
		}
		break;
	case 2:
		system("cls");
		cout << "[+] Фигура: \"Квадрат\"" << endl << endl;

		cout << "[+] Квадрат пустой или заполненный?" << endl << endl;
		cout << "[1] Пустой" << endl;
		cout << "[2] Заполненный" << endl;
		cout << endl << "[+] Выберите нужный пункт из вышеперечисленных: ";
		short squareType;
		cin >> squareType;

		cout << endl;

		short squareSize; // размер квадрата
		char squareTexture; // текстура квадрата

		switch (squareType) {
		case 1: //пустой квадрат
			system("cls");
			cout << "[+] Квадрат: пустой" << endl << endl;


			cout << "[+] Введите длину одной стороны квадрата в символах: ";
			cin >> squareSize;
			while (squareSize < 1) {
				cout << endl << "[+] Введите длину одной стороны квадрата в символах: ";
				cin >> squareSize;
			}
			cout << endl << "[+] Выберите текстуру: ";
			cin >> squareTexture;
			cout << endl;
			while (squareHigh < squareSize) {
				while (squareWidth < squareSize) {
					if (squareHigh == 0) {
						if (squareWidth + 1 == squareSize) {
							cout << squareTexture;
						}
						else {
							cout << squareTexture << " ";
						}
					}
					else if (squareHigh + 1 == squareSize) {
						if (squareWidth + 1 == squareSize) {
							cout << squareTexture;
						}
						else {
							cout << squareTexture << " ";
						}
					}
					else {
						if (squareWidth + 1 == squareSize) { //Чтобы не было лишнего пробела и был перенос на следующую строку
							cout << squareTexture;
						}
						else if (squareWidth == 0) {
							cout << squareTexture << " ";
						}
						else {
							cout << "  "; //2 пробела
						}
					}
					squareWidth++;
				}
				cout << endl;
				squareHigh++;
				squareWidth = 0;
			}
			break;
		case 2: //заполненный квадрат
			system("cls");
			cout << "[+] Квадрат: заполненный" << endl << endl;


			cout << "[+] Введите длину одной стороны квадрата в символах: ";
			cin >> squareSize;
			while (squareSize < 1) {
				cout << endl << "[+] Введите длину одной стороны квадрата в символах: ";
				cin >> squareSize;
			}
			cout << endl << "[+] Выберите текстуру: ";
			cin >> squareTexture;
			cout << endl;
			while (squareHigh < squareSize) {
				while (squareWidth < squareSize) {
					if (squareWidth + 1 == squareSize) { //Чтобы не было лишнего пробела и был перенос на следующую строку
						cout << squareTexture;
					}
					else {
						cout << squareTexture << " ";
					}
					squareWidth++;
				}
				cout << endl;
				squareHigh++;
				squareWidth = 0;
			}
			break;
		default:
			cout << "[+] Неверно введен пункт";
			break;
		}
		break;
	case 3:
		system("cls");
		cout << "[+] Фигура: \"Прямоугольник\"" << endl << endl;

		cout << "[+] Прямоугольник пустой или заполненный?" << endl << endl;
		cout << "[1] Пустой" << endl;
		cout << "[2] Заполненный" << endl;
		cout << endl << "[+] Введите нужный пункт из вышеперечисленных: ";
		short rectangleType;
		cin >> rectangleType;

		cout << endl;

		short rectangleHigh;
		short rectangleWidth;
		char rectangleTexture;
		switch (rectangleType) {
		case 1: //Пустой прямоугольник
			system("cls");
			cout << "[+] Прямоугольник: пустой" << endl << endl;

			cout << "[+] Введите длину высоты прямоугольника в символах: ";
			cin >> rectangleHigh;
			while (rectangleHigh < 1) {
				cout << endl << "[+] Введите длину высоты прямоугольника в символах: ";
				cin >> rectangleHigh;
			}
			cout << endl << "[+] Введите длину ширины прямоугольника в символах: ";
			cin >> rectangleWidth;
			while (rectangleWidth < 1) {
				cout << endl << "[+] Введите длину ширины прямоугольника в символах: ";
				cin >> rectangleWidth;
			}

			cout << endl << "[+] Выберите текстуру: ";
			cin >> rectangleTexture;
			cout << endl;

			while (rectangleHighCount < rectangleHigh) {
				while (rectangleWidthCount < rectangleWidth) {
					if (rectangleHighCount == 0) {
						if (rectangleWidthCount + 1 == rectangleWidth) {
							cout << rectangleTexture;
						}
						else {
							cout << rectangleTexture << " ";
						}
					}
					else if (rectangleHighCount + 1 == rectangleHigh) {
						if (rectangleWidthCount + 1 == rectangleWidth) {
							cout << rectangleTexture;
						}
						else {
							cout << rectangleTexture << " ";
						}
					}
					else {
						if (rectangleWidthCount == 0) {
							cout << rectangleTexture << " ";
						}
						else if (rectangleWidthCount + 1 == rectangleWidth) {
							cout << rectangleTexture;
						}
						else {
							cout << "  "; // 2 пробела
						}
					}
					rectangleWidthCount++;
				}
				cout << endl;
				rectangleHighCount++;
				rectangleWidthCount = 0;
			}
			break;
		case 2: //Заполненный прямоугольник
			system("cls");
			cout << "[+] Прямоугольник: заполненный" << endl << endl;


			cout << "[+] Введите длину высоты прямоугольника в символах: ";
			cin >> rectangleHigh;
			while (rectangleHigh < 1) {
				cout << endl << "[+] Введите длину высоты прямоугольника в символах: ";
				cin >> rectangleHigh;
			}
			cout << endl << "[+] Введите длину ширины прямоугольника в символах: ";
			cin >> rectangleWidth;
			while (rectangleWidth < 1) {
				cout << endl << "[+] Введите длину ширины прямоугольника в символах: ";
				cin >> rectangleWidth;
			}

			cout << endl << "[+] Выберите текстуру: ";
			cin >> rectangleTexture;
			cout << endl;

			while (rectangleHighCount < rectangleHigh) {
				while (rectangleWidthCount < rectangleWidth) {
					if (rectangleWidthCount + 1 == rectangleWidth) {
						cout << rectangleTexture;
					}
					else {
						cout << rectangleTexture << " ";
					}
					rectangleWidthCount++;
				}
				cout << endl;
				rectangleHighCount++;
				rectangleWidthCount = 0;
			}
			break;
		default:
			cout << "[+] Неверно введен пункт";
			break;
		}
		break;
	case 4: {
		system("cls");
		cout << "[+] Фигура: \"Треугольник\"" << endl << endl;

		cout << "[+] Треугольник пустой или заполненный?" << endl << endl;
		cout << "[1] Пустой" << endl;
		cout << "[2] Заполненный" << endl;
		cout << endl << "[+] Выберите пункт из вышеуказанных: ";
		short triangleType;
		cin >> triangleType;

		short triangleHigh;
		char triangleTexture;

		short triangleCounterY = 0;
		switch (triangleType) {
		case 1: // пустой треугольник
			system("cls");
			cout << "[+] Треугольник: пустой" << endl << endl;
			cout << "[+] Введите высоту треугольника: ";
			cin >> triangleHigh;
			while (triangleHigh < 1) {
				cout << endl << "[+] Введите высоту треугольника: ";
				cin >> triangleHigh;
			}
			triangleHigh *= 2;
			cout << endl << "Выберите текстуру: ";
			cin >> triangleTexture;
			cout << endl; //циклы
			for (int y = 0; y < triangleHigh; y++) {
				for (int x = 1; x < triangleHigh; x++) {
					if (x == triangleHigh / 2 + y || x == triangleHigh / 2 - y) {
						if (x + 1 == triangleHigh) {
							cout << triangleTexture;
						}
						else {
							cout << triangleTexture << " ";
						}
					}
					else if (y + 1 == triangleHigh / 2) {
						cout << triangleTexture << " ";
					}
					else {
						if (y + 1 < triangleHigh / 2) {
							cout << "  ";
						}
						else {
							break;
						}
					}
				}
				if (y + 1 < triangleHigh / 2) {
					cout << endl;
				}
			}
			break;
		case 2: // заполненный треугольник
			system("cls");
			cout << "[+] Треугольник: заполненный" << endl << endl;

			cout << "[+] Введите высоту треугольника: ";
			cin >> triangleHigh;
			while (triangleHigh < 1) {
				cout << endl << "[+] Введите высоту треугольника: ";
				cin >> triangleHigh;
			}
			triangleHigh *= 2;
			cout << endl << "Выберите текстуру: ";
			cin >> triangleTexture;
			cout << endl; //циклы
			for (int y = 0; y < triangleHigh; y++) {
				for (int x = 1; x < triangleHigh; x++) {
					if (x == triangleHigh / 2 + y || x == triangleHigh / 2 - y) {
						if (x + 1 == triangleHigh) {
							cout << triangleTexture;
						}
						else {
							cout << triangleTexture << " ";
							if (y > 0) {
								triangleCounterY++;
							}
						}
					}
					else if (y + 1 == triangleHigh / 2) {
						cout << triangleTexture << " ";
					}
					else {
						if (y + 1 < triangleHigh / 2) {
							if (triangleCounterY == 1) {
								cout << triangleTexture << " ";
							}
							else if (triangleCounterY == 2) {
								triangleCounterY = 0;
							}
							else {
								cout << "  ";
							}
						}
						else {
							break;
						}
					}
				}
				if (y + 1 < triangleHigh / 2) {
					cout << endl;
				}
			}
			break;
		default:
			cout << "[+] Неверно введен пункт";
			break;
		}
	}
		  break;
	case 5:
		system("cls");
		cout << "[+] Фигура: \"Решетка\"" << endl << endl;
		cout << "[+] Введите нечетный размер решетки в символах: ";
		short gridSize;
		cin >> gridSize;
		while (gridSize < 1 || gridSize % 2 == 0) {
			cout << endl << "[+] Введите нечетный размер решетки в символах: ";
			cin >> gridSize;
		}

		cout << endl << "[+] Выберите текстуру: ";
		char gridTexture;
		cin >> gridTexture;

		for (int y = 0; y < gridSize; y++) {
			for (int x = 0; x < gridSize; x++) {
				if (x % 2 == 0 && y % 2 == 0) {
					cout << "  ";
				}
				else {
					cout << gridTexture << " ";
				}
			}
			cout << endl;
		}
		break;
	case 6:
		system("cls");
		cout << "[+] Фигура: \"Крестик\"" << endl << endl;
		cout << "[+] Введите размер крестика в символах: ";
		short crossSize;
		cin >> crossSize;
		while (crossSize < 1 || crossSize % 2 == 0) {
			cout << endl << "[+] Введите нечетный размер крестика в символах: ";
			cin >> crossSize;
		}

		cout << endl << "[+] Выберите текстуру: ";
		char crossTexture;
		cin >> crossTexture;

		for (int y = 0; y < crossSize; y++) {
			for (int x = 0; x < crossSize; x++) {
				if (x == y || x == crossSize - 1 - y) {
					cout << crossTexture << " ";
				}
				else {
					cout << "  ";
				}
			}
			cout << endl;
		}
		break;
	case 7:
		system("cls");
		cout << "[+] Фигура: \"Плюс\"" << endl << endl;
		cout << "[+] Введите нечетный размер плюса в символах: ";
		short plusSize;
		cin >> plusSize;
		while (plusSize < 1 || plusSize % 2 == 0) {
			cout << endl << "[+] Введите нечетный размер плюса в символах: ";
			cin >> plusSize;
		}

		cout << endl << "[+] Выберите текстуру: ";
		char plusTexture;
		cin >> plusTexture;

		for (int y = 0; y < plusSize; y++) {
			for (int x = 0; x < plusSize; x++) {
				if (x == plusSize / 2 || y == plusSize / 2) {
					cout << plusTexture << " ";
				}
				else {
					cout << "  ";
				}
			}
			cout << endl;
		}
		break;
	case 8:
		return 0;
		break;
	default:
		cout << endl << "[+] Неверно введен номер";
		break;
	}

	int _; cin >> _;
	return 0;
}