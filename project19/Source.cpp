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
short showStructQuestion(short settingsHearts, short settingsQuestions) {
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
	cout << "Викторина заканчивается и выводятся окончательные результаты, если у пользователя:\n";
	cout << "1. Кончились жизни\n";
	cout << "2. Закончилось время\n\n";
}
void showSettings() {
	clearSystem();
	cout << "1. Сложность\n";
	cout << "2. Таймер\n";
	cout << "3. Жизни\n";
	cout << "4. Подсказка\n";
	short settingsChoice;
	cin >> settingsChoice;
	switch (settingsChoice) {
	case 1: // сложность
		break;
	case 2: // таймер
		break;
	case 3: // жизни
		break;
	case 4: // подсказка
		break;
	default: //ошибка
		getErrorMessage();
		break;
	}
}
void getQuiz(short settingsHearts, short settingsQuestions) {
	fillStructQuestion();
	short wrongAnswers = showStructQuestion(settingsHearts, settingsQuestions);
	clearSystem();
	cout << "Результат: " << settingsQuestions - wrongAnswers << " правильных ответов из " << settingsQuestions << ".\n\n";
	pauseSystem();
}
short showMainMenu() {
	while (true) {
		clearSystem();
		cout << "1. Запустить викторину\n";
		cout << "2. Настройки\n";
		cout << "3. Правила\n";
		cout << "4. Выход\n";
		short userChoice;
		cin >> userChoice;
		switch (userChoice) {
		case 1: //викторина
			getQuiz(2, 5);
			break;
		case 2: //настройки
			showSettings();
			break;
		case 3: // правила
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


	short hearts = 5; // по умолчанию 5 попыток
	short timer = 5; // по умолчанию викторина длится 5 минут 

	short question = 0;
	//fillStructQuestion();
	//showStructQuestion();

	if (showMainMenu() == 0) {
		return 0;
	}

	short _; cin >> _;
	return 0;
}