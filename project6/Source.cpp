#include <iostream>
using namespace std;
int main() {
	setlocale(0, "");
	cout << "[+] Календарь" << endl;
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
	short day;
	switch (month) {
	case 1:
		cout << endl << "Выбран месяц - \"Январь\"";
		cout << endl << "Выберите день месяца: ";
		cin >> day;
		switch (day) {
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
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
			cout << endl << "[+] Календарь: " << day << " января";
			break;
		default:
			cout << endl << "Неверно введен день";
			break;
		}
		break;
	case 2:
		cout << endl << "Выбран месяц - \"Февраль\"";
		cout << endl << endl << "Год високосный?";
		cout << endl << "[1] Да";
		cout << endl << "[2] Нет";
		cout << endl << "Ввод: ";
		short typeOfYear;
		cin >> typeOfYear;
		switch (typeOfYear) {
		case 1:
			cout << endl << "Выберите день месяца: ";
			cin >> day;
			switch (day) {
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
			case 26:
			case 27:
			case 28:
			case 29:
				cout << endl << "[+] Календарь: " << day << " февраля";
				break;
			default:
				cout << endl << "Неверно введен день (год високосный)";
				break;
			}
			break;
		case 2:
			cout << endl << "Выберите день месяца: ";
			cin >> day;
			switch (day) {
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
			case 26:
			case 27:
			case 28:
				cout << endl << "[+] Календарь: " << day << " февраля";
				break;
			default:
				cout << endl << "Неверно введен день (год не високосный)";
				break;
			}
			break;
		default:
			cout << endl << "Неверный ввод ответа";
			break;
		}
		break;
	case 3:
		cout << endl << "Выбран месяц - \"Март\"";
		cout << endl << "Выберите день месяца:";
		cin >> day;
		switch (day) {
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
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
			cout << endl << "[+] Календарь: " << day << " марта";
			break;
		default:
			cout << endl << "Неверно введен день";
			break;
		}
		break;
	case 4:
		cout << endl << "Выбран месяц - \"Апрель\"";
		cout << endl << "Выберите день месяца:";
		cin >> day;
		switch (day) {
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
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
			cout << endl << "[+] Календарь: " << day << " апреля";
			break;
		default:
			cout << endl << "Неверно введен день";
			break;
		}
		break;
	case 5:
		cout << endl << "Выбран месяц - \"Май\"";
		cout << endl << "Выберите день месяца:";
		cin >> day;
		switch (day) {
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
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
			cout << endl << "[+] Календарь: " << day << " мая";
			break;
		default:
			cout << endl << "Неверно введен день";
			break;
		}
		break;
	case 6:
		cout << endl << "Выбран месяц - \"Июнь\"";
		cout << endl << "Выберите день месяца:";
		cin >> day;
		switch (day) {
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
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
			cout << endl << "[+] Календарь: " << day << " июня";
			break;
		default:
			cout << endl << "Неверно введен день";
			break;
		}
		break;
	case 7:
		cout << endl << "Выбран месяц - \"Июль\"";
		cout << endl << "Выберите день месяца:";
		cin >> day;
		switch (day) {
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
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
			cout << endl << "[+] Календарь: " << day << " июля";
			break;
		default:
			cout << endl << "Неверно введен день";
			break;
		}
		break;
	case 8:
		cout << endl << "Выбран месяц - \"Август\"";
		cout << endl << "Выберите день месяца:";
		cin >> day;
		switch (day) {
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
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
			cout << endl << "[+] Календарь: " << day << " августа";
			break;
		default:
			cout << endl << "Неверно введен день";
			break;
		}
		break;
	case 9:
		cout << endl << "Выбран месяц - \"Сентябрь\"";
		cout << endl << "Выберите день месяца:";
		cin >> day;
		switch (day) {
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
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
			cout << endl << "[+] Календарь: " << day << " сентября";
			break;
		default:
			cout << endl << "Неверно введен день";
			break;
		}
		break;
	case 10:
		cout << endl << "Выбран месяц - \"Октябрь\"";
		cout << endl << "Выберите день месяца:";
		cin >> day;
		switch (day) {
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
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
			cout << endl << "[+] Календарь: " << day << " октября";
			break;
		default:
			cout << endl << "Неверно введен день";
			break;
		}
		break;
	case 11:
		cout << endl << "Выбран месяц - \"Ноябрь\"";
		cout << endl << "Выберите день месяца:";
		cin >> day;
		switch (day) {
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
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
			cout << endl << "[+] Календарь: " << day << " ноября";
			break;
		default:
			cout << endl << "Неверно введен день";
			break;
		}
		break;
	case 12:
		cout << endl << "Выбран месяц - \"Декабрь\"";
		cout << endl << "Выберите день месяца:";
		cin >> day;
		switch (day) {
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
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
			cout << endl << "[+] Календарь: " << day << " декабря";
			break;
		default:
			cout << endl << "Неверно введен день";
			break;
		}
		break;
	default:
		cout << endl << "Неправильно введен номер месяца!";
		break;
	}
	short _; cin >> _;
	return 0;
}