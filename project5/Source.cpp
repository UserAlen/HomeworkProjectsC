#include <iostream>
using namespace std;
int main() {
	setlocale(0, "");
	cout << "[+] Переводчик" << endl << endl;
	cout << "[1] Русские слова" << endl;
	cout << "[2] Английские слова" << endl << endl;
	cout << "[3] Выйти" << endl;
	cout << "Выберите пункт: ";
	short menu;
	cin >> menu;
	switch (menu) {
	case 1:
		system("cls");
		cout << "Переводчик \"Список русских слов\"" << endl << endl;
		cout << "[1] Дом" << endl;
		cout << "[2] Дорога" << endl;
		cout << "[3] Путь" << endl;
		cout << "[4] Цвет" << endl;
		cout << "[5] Цветок" << endl;
		cout << "[6] Дерево" << endl;
		cout << "[7] Компьютер" << endl;
		cout << "[8] Монитор" << endl;
		cout << "[9] Мышь" << endl;
		cout << "[10] Волк" << endl;
		cout << "[11] Яблоко" << endl;
		cout << "[12] Клавиатура" << endl;
		cout << "[13] Собака" << endl;
		cout << "[14] Кот" << endl;
		cout << "[15] Лошадь" << endl;
		cout << endl << "[16] Выберите номер слова: ";
		short numberOfRussianWord;
		cin >> numberOfRussianWord;
		cout << endl;
		switch (numberOfRussianWord) {
		case 1:
			cout << "[+] Перевод: дом -> house";
			break;
		case 2:
			cout << "[+] Перевод: дорога -> road";
			break;
		case 3:
			cout << "[+] Перевод: путь -> path";
			break;
		case 4:
			cout << "[+] Перевод: цвет -> colour";
			break;
		case 5:
			cout << "[+] Перевод: цветок -> flower";
			break;
		case 6:
			cout << "[+] Перевод: дерево -> tree";
			break;
		case 7:
			cout << "[+] Перевод: компьютер -> computer";
			break;
		case 8:
			cout << "[+] Перевод: монитор -> monitor";
			break;
		case 9:
			cout << "[+] Перевод: мышь -> mouse";
			break;
		case 10:
			cout << "[+] Перевод: волк -> wolf";
			break;
		case 11:
			cout << "[+] Перевод: яблоко -> apple";
			break;
		case 12:
			cout << "[+] Перевод: клавиатура -> keyboard";
			break;
		case 13:
			cout << "[+] Перевод: собака -> dog";
			break;
		case 14:
			cout << "[+] Перевод: кот -> cat";
			break;
		case 15:
			cout << "[+] Перевод: лошадь -> horse";
			break;
		default:
			cout << "Неверно введен номер слова";
			break;
		}
		break;
	case 2:
		system("cls");
		cout << "Переводчик \"Список английских слов\"" << endl << endl;
		cout << "[1] House" << endl;
		cout << "[2] Road" << endl;
		cout << "[3] Path" << endl;
		cout << "[4] Colour" << endl;
		cout << "[5] Flower" << endl;
		cout << "[6] Tree" << endl;
		cout << "[7] Computer" << endl;
		cout << "[8] Monitor" << endl;
		cout << "[9] Mouse" << endl;
		cout << "[10] Wolf" << endl;
		cout << "[11] Apple" << endl;
		cout << "[12] Keyboard" << endl;
		cout << "[13] Dog" << endl;
		cout << "[14] Cat" << endl;
		cout << "[15] Horse" << endl;
		cout << endl << "[16] Выберите номер слова: ";
		short numberOfEnglishWord;
		cin >> numberOfEnglishWord;
		cout << endl;
		switch (numberOfEnglishWord) {
		case 1:
			cout << "[+] Перевод: house -> дом";
			break;
		case 2:
			cout << "[+] Перевод: road -> дорога";
			break;
		case 3:
			cout << "[+] Перевод: path -> путь";
			break;
		case 4:
			cout << "[+] Перевод: colour -> цвет";
			break;
		case 5:
			cout << "[+] Перевод: flower -> цветок";
			break;
		case 6:
			cout << "[+] Перевод: tree -> дерево";
			break;
		case 7:
			cout << "[+] Перевод: computer -> компьютер";
			break;
		case 8:
			cout << "[+] Перевод: monitor -> монитор";
			break;
		case 9:
			cout << "[+] Перевод: mouse -> мышь";
			break;
		case 10:
			cout << "[+] Перевод: wolf -> волк";
			break;
		case 11:
			cout << "[+] Перевод: apple -> яблоко";
			break;
		case 12:
			cout << "[+] Перевод: keyboard -> клавиатура";
			break;
		case 13:
			cout << "[+] Перевод: dog -> собака";
			break;
		case 14:
			cout << "[+] Перевод: cat -> кот";
			break;
		case 15:
			cout << "[+] Перевод: horse -> лошадь";
			break;
		default:
			cout << "Неверно введен номер слова";
			break;
		}
		break;
	case 3:
		return 0;
		break;
	default:
		cout << "Неверно введен номер пункта";
		break;
	}
	short _; cin >> _;
	return 0;
}