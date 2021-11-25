#include <iostream>
#include <windows.h> //для подключения функции Sleep
#include <ctime> //для подключения функции time, чтобы обнулять рандом

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
	cout << "Если ошибка зависла, то введено значение, превышающее максимальное или минимальное хранимое, ";
	cout << "и единственный выход - ALT + F4\n\n";
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
void showTipQuestion(short questionNumber) {
	short correctAnswerNumber = 0;
	short randomAnswerNumber = rand() % 4;
	for (int i = 0; i < 4; i++) {
		if (question[questionNumber].answer[i] == question[questionNumber].correctAnswer) {
			correctAnswerNumber = i;
			break;
		}
	}
	while (randomAnswerNumber == correctAnswerNumber) {
		randomAnswerNumber = rand() % 4;
	}
	if (correctAnswerNumber < randomAnswerNumber) {
		cout << correctAnswerNumber + 1 << ". " << question[questionNumber].correctAnswer << endl;
		cout << randomAnswerNumber + 1 << ". " << question[questionNumber].answer[randomAnswerNumber];
	}
	else {
		cout << randomAnswerNumber + 1 << ". " << question[questionNumber].answer[randomAnswerNumber] << endl;
		cout << correctAnswerNumber + 1 << ". " << question[questionNumber].correctAnswer;
	}
}

short showStructQuestion(short settingsHearts, short settingsQuestions, short settingsTip) {
	short answerChecks = 0;
	short userAnswer = 0;
	short hearts = settingsHearts;
	bool answerIsNotOkay = true; //Флаг для задержки вопроса, 
	//если его нужно просмотреть повторно в программе.
	//Например, если пользователь ввел некорректное значение,
	//из цикла с нужным вопросом программа не выйдет,
	//пока пользователь не введет нужное значение 
	//(правильное или неправильное, 
	//но которое есть в проверках (в данной функции это case)
	//и ни в какой default не заходит)
	for (int i = 0; i < SIZE_QUESTIONS; i++) {
		while (answerIsNotOkay) {
			clearSystem();
			cout << "Всего вопросов: " << settingsQuestions << "\tЖизней: " << hearts << "\n\n";
			cout << "Вопрос №" << i + 1 << ". " << question[i].question << endl << endl;
			for (int j = 0; j < 4; j++) {
				cout << j + 1 << ". " << question[i].answer[j] << endl;
			}
			if (settingsTip == 1) {
				cout << "5. Подсказка\n";
			}
			if (settingsTip == 1 && userAnswer == 5) {
				cout << "\n[Подсказка]\n";
				showTipQuestion(i);
				cout << endl;
			}
			cout << endl;
			cout << "Введите номер ответа: ";
			cin >> userAnswer;
			switch (userAnswer) {
			case 1:
			case 2:
			case 3:
			case 4:
				answerChecks += checkAnswer(userAnswer, i);
				if (answerChecks == settingsHearts) {
					pauseSystem();
					return i + 1 - answerChecks;//возвращает кол-во правильных ответов
					//вычетом неправильных ответов от текущего номера вопроса,
					//если количество жизней равно нулю.
				}
				else if (i + 1 == settingsQuestions) {
					pauseSystem();
					return settingsQuestions - answerChecks; //возвращает кол-во правильных ответов,
					//если пользователь достиг последнего вопроса и ответил на него.
				}
				else {
					hearts = settingsHearts - answerChecks;
				}
				answerIsNotOkay = false;//означает то, что можно перейти к следующему вопросу
				pauseSystem();
				break;
			case 5:
				if (settingsTip == 0) {
					cout << "\nВы не включили подсказку в настройках!\n";
					pauseSystem();
				}
				break;
			default:
				getErrorMessage();
				break;
			}
		}
		answerIsNotOkay = true;
	}
	return answerChecks;
}

void fillStructQuestion() {//функция для заполнения структуры через заполненный массив

	//изначально программа писалась через массивы,
	//поэтому, чтобы заново не переписывать,
	//функция заполняет структуру значениями массива

	const short SIZE_ANSWERS = 6; // всего 4 варианта ответа. 
	//+2 для вопроса и верного варианта ответа, 
	// т.е questions[y][0] - выдает сам вопрос, 
	//questions[y][1-4] - выдает варианты ответов,
	//questions[y][5] - выдает правильный ответ,
	//где y - число от 0 до 14, которое означает номер вопроса 
	//(вопросов всего SIZE_QUESTIONS = 15 (инициализировано глобально))

	string questions[SIZE_QUESTIONS][SIZE_ANSWERS]{
		{"Размер типа данных short",
		"1", "2", "4", "8", "2"},
		{"Тип данных, описывающий вещественные числа двоичной точности.",
		"double", "float", "long", "char", "double"},
		{"Максимальное хранимое число в типе данных int.",
		"2 147 483 647", "2 147 483 648", "32 768", "32 767", "2 147 483 647"},
		{"Максимальное хранимое число в типе данных short.",
		"2 147 483 647", "2 147 483 648", "32 768", "32 767", "32 767"},
		{"string userName;\nСтиль написания данной переменной.",
		"Pascal Case", "Camel Case", "Kebab Case", "Snake Case", "Camel Case"},
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
}
void showRules() {
	clearSystem();
	cout << "====Правила.\n\n";
	cout << "==Во время викторины пользователь может:\n";
	cout << "1. Ответить на вопрос, выбрав один вариант из предложенных\n";
	cout << "2. Убрать 2 неправильных варианта ответа из 4, если в настройках включен пункт \"Подсказка\"";
	cout << "\n\n==Викторина заканчивается и выводятся окончательные результаты, если пользователь:\n";
	cout << "1. Имеет 0 жизней\n";
	cout << "2. Ответил на все вопросы\n\n";
	cout << "==Система монет:\n\n";//еще не реализовано
	cout << "1. За каждый правильный ответ начисляется 1 монета\n";
	cout << "2. За каждый неправильный ответ вычитываются 2 монеты\n";
	cout << "3. Количество монет не может быть меньше 0\n";
	cout << "4. Если у пользователя 0 монет, то ";
	cout << "за каждый неправильный ответ ничего не начисляется и не вычитается\n\n";
	cout << "\n(Если пользователь ввел некорректное значение, то выведется сообщение об этом)\n\n";
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
		case 5:
			pauseSystem();
			return 5;
		case 2: // 10
		case 10:
			pauseSystem();
			return 10;
		case 3: // 15
		case 15:
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
		cout << "4. В меню\n";
		short settingsChoice;
		cin >> settingsChoice;
		switch (settingsChoice) {
		case 1: // сложность
			return showSettingsDifficulty();
		case 2: // жизни
			return showSettingsHearts();
		case 3: // подсказка
			return showTip();
		case 4: //выход из настроек
			return -9;
		default: //ошибка
			getErrorMessage();
			break;
		}
	}
}
void getRandomAnswersInQuestion(short questionNumber) {
	string randomAnswers[4]{}; //для хранения уже зарандомленных ответов
	short randomNum = rand() % 4;
	string tempAnswer;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			while (randomAnswers[i] == question[questionNumber].answer[randomNum]) {
				randomNum = rand() % 4;
			}
		}
		tempAnswer = question[questionNumber].answer[i];
		question[questionNumber].answer[i] = question[questionNumber].answer[randomNum];
		question[questionNumber].answer[randomNum] = tempAnswer;
	}
}
void getRandomQuestions() {
	string randomQuestions[SIZE_QUESTIONS]{};//для хранения уже зарандомленных вопросов
	short randomNum = rand() % SIZE_QUESTIONS;
	string temp;//для хранения временных данных, 
	//которые могут стереться, но их нужно присвоить
	for (int i = 0; i < SIZE_QUESTIONS; i++) {
		for (int j = 0; j < SIZE_QUESTIONS; j++) {
			while (randomQuestions[j] == question[randomNum].question) {
				randomNum = rand() & SIZE_QUESTIONS;
			}
		}
		randomQuestions[i] = question[i].question;
		question[i].question = question[randomNum].question;
		question[randomNum].question = randomQuestions[i];
		for (int k = 0; k < 4; k++) {
			temp = question[i].answer[k];
			question[i].answer[k] = question[randomNum].answer[k];
			question[randomNum].answer[k] = temp;
		}
		temp = question[i].correctAnswer;
		question[i].correctAnswer = question[randomNum].correctAnswer;
		question[randomNum].correctAnswer = temp;
		getRandomAnswersInQuestion(randomNum);//функция с рандомом ответов
		getRandomAnswersInQuestion(i);
	}
}
void getQuiz(short settingsHearts, short settingsQuestions, short settingsTip) {
	fillStructQuestion();//функция заполнения структуры вопросами
	getRandomQuestions();//функция с рандомом вопросов
	short correctAnswers = showStructQuestion(settingsHearts, settingsQuestions, settingsTip);
	clearSystem();
	cout << "Результат: " << correctAnswers << " ";
	if (correctAnswers == 1) {
		cout << "правильный ответ";
	}
	else if (correctAnswers > 1 && correctAnswers < 5) {
		cout << "правильных ответа";
	}
	else if (correctAnswers >= 5 || correctAnswers == 0) {
		cout << "правильных ответов";
	}
	cout << " из " << settingsQuestions << ".\n\n";
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
			case -2: //подсказка выключена 
				//(значения подсказки в отрицательном виде, 
				//чтобы с другими значениями не конфликтовало)
				settingsTip = 0;
				break;
			case -1: //подсказка включена
				settingsTip = 1;
				break;
			case -9: //выход из настроек 
				//(значение ничего не делает, но помогает выйти из меню настроек;
				//присутствует в кейсе, чтобы программа не зашла в default
				//и не вывелось сообщение с ошибкой)
				break;
			case 0: //количество жизней
			case 1:
			case 2:
			case 3:
			case 4:
				settingsHearts = settings + 1;
				break;
			case 5://сложность (количество вопросов)
			case 10:
			case 15:
				settingsDifficulty = settings;
				break;
			default://ошибка
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
	// попытки (в данной программе - жизни) от 1 до 5


	/*Question question[15] = fillStructQuestion(); //не работает, поэтому инициализирую глобально*/

	srand(time(NULL)); //Обнуление рандома при каждом запуске программы (чтобы не было каждый раз одинакового рандома)
	return showMainMenu();
}