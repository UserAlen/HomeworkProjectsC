#include <iostream>
using namespace std;
int main() {
	setlocale(0, "");
	cout << "[+] Месяца года" << endl;
	cout << "[1] Январь" << endl;
	cout << "[2] Февраль" << endl;
	cout << "[3] Март" << endl;
	cout << "[4] Апрель" << endl;
	cout << "[5] Май" << endl;
	cout << "[6] Июнь" << endl;
	cout << "[7] Июль" << endl;
	cout << "[8] Август" << endl;
	cout << "[9] Сентябрь" << endl;
	cout << "[10] Октябрь" << endl;
	cout << "[11] Ноябрь" << endl;
	cout << "[12] Декабрь" << endl << endl;
	cout << "Выберите месяц: ";
	short month;
	cin >> month;
	switch (month) {
	case 1:
		cout << "Выбран месяц \"Январь\"";
		break;
	case 2:
		cout << "Выбран месяц \"Февраль\"";
		break;
	case 3:
		cout << "Выбран месяц \"Март\"";
		break;
	case 4:
		cout << "Выбран месяц \"Апрель\"";
		break;
	case 5:
		cout << "Выбран месяц \"Май\"";
		break;
	case 6:
		cout << "Выбран месяц \"Июнь\"";
		break;
	case 7:
		cout << "Выбран месяц \"Июль\"";
		break;
	case 8:
		cout << "Выбран месяц \"Август\"";
		break;
	case 9:
		cout << "Выбран месяц \"Сентябрь\"";
		break;
	case 10:
		cout << "Выбран месяц \"Октябрь\"";
		break;
	case 11:
		cout << "Выбран месяц \"Ноябрь\"";
		break;
	case 12:
		cout << "Выбран месяц \"Декабрь\"";
		break;
	default:
		cout << "Неправильно введен номер месяца!";
		break;
	}
	short _; cin >> _;
	return 0;
}