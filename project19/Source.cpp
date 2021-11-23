#include <iostream>
#include <windows.h> //для подключения функции Sleep
#include <ctime> //для подключения функции time

using namespace std;

struct Question {
	string question;
	string answer[4];
	string correctAnswer;
};
const short SIZE_QUESTIONS = 15;
Question question[SIZE_QUESTIONS];
void pauseSystem() {
	system("pause");
}
void clearSystem() {
	system("cls");
}
void getErrorMessage() {
	cout << "\n\n [Ошибка] Что-то пошло не так. . .\n\n";
	cout << "Если кроме ошибки ничего не происходит, то введено значение, превышающее максимальное или минимальное хранимое значение, и единственный выход - ALT+F4\n\n";
	pauseSystem();
}
short checkAnswer(short userAnswer, short questionNumber) {
	if (question[questionNumber].answer[userAnswer - 1] == question[questionNumber].correctAnswer) {
		cout << "\nОтвет верный.\n";
		return 0;
	}
	else {
		cout << "\nОтвет неверный.\n";
		return 1;
	}
}

//void showStructQuestion(Question question[], const short SIZE_QUESTIONS) {
short showStructQuestion(short settingsHearts, short settingsQuestions, short settingsTip) {
	short answerChecks = 0;
	short userAnswer[SIZE_QUESTIONS]{};
	for (int i = 0; i < SIZE_QUESTIONS; i++) {
		clearSystem();
		cout << i + 1 << ". " << question[i].question << endl;
		for (int j = 0; j < 4; j++) {
			cout << j + 1 << ". " << question[i].answer[j] << endl;
		}
		cout << endl;
		cin >> userAnswer[i];
		answerChecks += checkAnswer(userAnswer[i], i);
		if (answerChecks == settingsHearts || i + 1 == settingsQuestions) {
			return answerChecks;
		}
		pauseSystem();
	}
	return answerChecks;
}

//Question 
void fillStructQuestion() {
	const short SIZE_ANSWERS = 6; // всего 4 варианта ответа. 
	//+2 для вопроса и верного варианта ответа, 
	// т.е questions[y][0] - выдает сам вопрос, 
	//questions[y][1-4] - выдает варианты ответов,
	//questions[y][5] - выдает правильный ответ,
	//где y - число от 0 до 14, которое означает номер вопроса (вопросов всего SIZE_QUESTIONS = 15)

	string questions[SIZE_QUESTIONS][SIZE_ANSWERS]{
		{"Тип данных программирования.",
		"числовой", "символьный", "логический", "все перечисленные", "все перечисленные"},
		{"Тип данных, описывающий вещественные числа двоичной точности.",
		"double", "float", "long", "char", "double"},
		{"Максимальное хранимое число в типе данных int.",
		"2 147 483 647", "2 147 483 648", "32 768", "32 767", "2 147 483 647"},
		{"Максимальное хранимое число в типе данных short.",
		"2 147 483 647", "2 147 483 648", "32 768", "32 767", "32 767"},
		{"string userName;\nСтиль написания данной переменной.",
		"PascalCase", "CamelCase", "KebabCase", "SnakeCase", "CamelCase"},
		{"int a{5};\nСпособ инициализации данной переменной.",
		"Копирующая инициализация", "Прямая инициализация", "Uniform-инициализация",
		"Инициализирующая инициализация", "Uniform-инициализация"},
		{"Определенная конструкция языка, которая позволяет выполнять какие-либо действия с данными.",
		"Оператор", "Константа", "Переменная", "Компилятор", "Оператор"},
		{"Построчный анализ, обработка и выполнение исходного кода программы или запроса.",
		"Интерпретация", "Компиляция", "Трансляция", "Инструкция", "Интерпретация"},
		{"Команда, чистящая консоль.",
		"system(\"cls\")", "system(\"clear\")", "clear(\"console\")", "console(\"cls\")", "system(\"cls\")"},
		{"Команда, отвечающая за ввод.",
		"cin", "cout", "sin", "insert", "cin"},
		{"Команда, выводящая сообщения в консоль.",
		"cin", "cout", "write", "output", "cout"},
		{"Оператор ввода.",
		"<<", ">>", ">", "<", ">>"},
		{"Оператор вывода.",
		"<<", ">>", ">", "<", "<<"},
		{"Оператор, которому для действий нужно два операнда.",
		"Унарный оператор", "Бинарный оператор", "Двунарный оператор", "Тернарный оператор", "Бинарный оператор"},
		{"Размер типа данных long.",
		"1", "8", "4", "5", "4"}
	};
	for (short y = 0; y < SIZE_QUESTIONS; y++) {
		question[y].question = questions[y][0];
		question[y].correctAnswer = questions[y][5];
		for (short x = 0; x < SIZE_ANSWERS - 1; x++) {
			question[y].answer[x] = questions[y][x + 1];
		}
	}
	//return question[SIZE_QUESTIONS];
}
void showRules() {
	clearSystem();
	cout << "Правила.\n";
	cout << "Во время викторины пользователь может:\n";
	cout << "1. Ответить на вопрос, выбрав один вариант из предложенных\n";
	cout << "2. Убрать 2 неправильных варианта ответа, если в настройках включен пункт \"Подсказка\"";
	cout << "Викторина заканчивается и выводятся окончательные результаты, если пользователь:\n";
	cout << "1. Имеет 0 жизней\n";
	cout << "2. Ответил на все вопросы\n\n";
	pauseSystem();
}
short showSettingsDifficulty() {
	while (true) {
		clearSystem();
		cout << "Сложность.\n\n";
		cout << "Количество вопросов:\n";
		cout << "1. 5\n";
		cout << "2. 10\n";
		cout << "3. 15\n";
		short settingsChoice;
		cin >> settingsChoice;
		switch (settingsChoice) {
		case 1: // 5
			pauseSystem();
			return 5;
		case 2: // 10
			pauseSystem();
			return 10;
		case 3: // 15
			pauseSystem();
			return 15;
		default: //ошибка
			getErrorMessage();
			break;
		}
	}
}
short showSettingsHearts() {
	while (true) {
		clearSystem();
		cout << "Жизни.\n\n";
		cout << "Количество жизней от 1 до 5:\n";
		short settingsChoice;
		cin >> settingsChoice;
		switch (settingsChoice) {
		case 1:
		case 2:
		case 3: 
		case 4:
		case 5:
			pauseSystem();
			return settingsChoice - 1;
		default: //ошибка
			getErrorMessage();
			break;
		}
	}
}
short showTip() {
	while (true) {
		clearSystem();
		cout << "Подсказка.\n\n";
		cout << "1. Включить\n";
		cout << "2. Выключить\n";
		short settingsChoice;
		cin >> settingsChoice;
		switch (settingsChoice) {
		case 1: 
		case 2:
			return -settingsChoice;
		default: //ошибка
			getErrorMessage();
			break;
		}
	}
}
short showSettings(short difficulty, short hearts, short tip) {
	while (true) {
		clearSystem();
		cout << "Настройки\n\n";
		cout << "1. Сложность [" << difficulty << " вопросов]\n";
		cout << "2. Жизни [" << hearts << " жизней]\n";
		cout << "3. Подсказка";
		if (tip == 0) {
			cout << " [Выключена]";
		}
		else {
			cout << " [Включена]";
		}
		cout << "\n";
		cout << "4. Выход из настроек\n";
		short settingsChoice;
		cin >> settingsChoice;
		switch (settingsChoice) {
		case 1: // сложность
			return showSettingsDifficulty();
		case 2: // жизни
			return showSettingsHearts();
		case 3: // подсказка
			return showTip();
		case 4:
			return -9;
		default: //ошибка
			getErrorMessage();
			break;
		}
	}
}
void getQuiz(short settingsHearts, short settingsQuestions, short settingsTip) {
	fillStructQuestion();
	short wrongAnswers = showStructQuestion(settingsHearts, settingsQuestions, settingsTip);
	clearSystem();
	cout << "Результат: " << settingsQuestions - wrongAnswers << " правильных ответов из " << settingsQuestions << ".\n\n";
	pauseSystem();
}
short showMainMenu() {
	short settingsDifficulty = 5; // по умолчанию 5 вопросов
	short settingsHearts = 5; // по умолчанию 5 жизней
	short settingsTip = 0; // по умолчанию подсказка выключена (0)

	//добавить число неправильных и число правильных и в процентах - рейтинг
	//рейтинг обнуляется при выходе
	while (true) {
		clearSystem();
		cout << "Главное меню\n\n";
		cout << "1. Запустить викторину\n";
		cout << "2. Настройки\n";
		cout << "3. Правила\n";
		cout << "4. Выход\n";
		short userChoice;
		cin >> userChoice;
		switch (userChoice) {
		case 1: //викторина
			getQuiz(settingsHearts, settingsDifficulty, settingsTip);
			break;
		case 2: //настройки
			{
				short settings = showSettings(settingsDifficulty, settingsHearts, settingsTip);
				switch (settings) {
				case -2:
					settingsTip = 0;
					break;
				case -1:
					settingsTip = 1;
					break;
				case -9:
					break;
				case 0:
				case 1:
				case 2:
				case 3:
				case 4:
					settingsHearts = settings + 1;
					break;
				case 5:
				case 10:
				case 15:
					settingsDifficulty = settings;
					break;
				default:
					getErrorMessage();
					break;
				}
				break;
			}
		case 3: // правила
			showRules();
			break;
		case 4: // выход
			return 0;
			break;
		default:
			getErrorMessage();
			break;
		}
	}
}
int main() {
	setlocale(0, "");
	// 5 10 15 вопросов 
	// 4 варианта ответа
	// вопросы и ответы рандомно выбираются при каждом запуске программы
	// подсказка 50 на 50 - 2 неверных варианта удаляются, остаются верный и неверный варианты
	// таймер - пользователь вводит любое число, которое определяет минуты на таймере
	// попытки от 1 до 5


	/*Question question[15] = fillStructQuestion(); //не работает, поэтому инициализирую глобально
	showStructQuestion(question[15], 15);*/


	return showMainMenu();
}