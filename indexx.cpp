#include <iostream>
#include <locale>
#include <limits>
#include <cstdlib>
#include <windows.h>


using namespace std;

const int length = 10;

void displayMenu();
void inputArray (int arr[], int length, bool &isInitialized);
void printArray (const int arr[], int length, bool isInitialized);
void findMinMax (const int arr[], int length, bool isInitialized, int &min, int &max);
double calculateAverage (const int arr[], int length, bool isInitialized);
void sortArray (int arr[], int length, bool isInitialized); 
void displayError(const string &message);
void waitForReturnToMenu();
void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void ShowStartScreen() {

    clearConsole();

    cout << "============================================" << endl;
    cout << "     Лабораторна робота №5" << endl;
    cout << " Виконано студентом групи ІП-22" << endl;
    cout << "      Олександр Рахманов" << endl;
    cout << "============================================" << endl;
    cout << "   Вітаємо у програмі для роботи з масивом!" << endl;
    cout << "============================================" << endl;
    cout << " Натисніть Enter, щоб продовжити..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    clearConsole();
}


int main() {

     SetConsoleOutputCP(CP_UTF8);
     setlocale(LC_ALL, "uk_UA.UTF-8");

    int array[length];
    bool isInitialized = false; 
    int usedChoice = 0;

    ShowStartScreen();

    while (true) {
        displayMenu();
        cout << "Обереріть позицію (1-6):";
        cin >> usedChoice;

        if(cin.fail()) {
            displayError("Некоректне введення. Будь ласка, введіть число від 1 до 6.");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }   

        switch (usedChoice) {
            case 1:
                inputArray(array, length, isInitialized);
                break;
            case 2:
                printArray(array, length, isInitialized);
                break;
            case 3: {
                int min, max;
                findMinMax(array, length, isInitialized, min, max);
                if (isInitialized) {
                    cout << "Мінімальний елемент: " << min << endl;
                    cout << "Максимальний елемент: " << max << endl;
                }
                break;
            }
            case 4: {
                double average = calculateAverage(array, length, isInitialized);
                if (isInitialized) {
                    cout << "Середнє арифметичне: " << average << endl;
                }
                break;
            }
            case 5:
                sortArray(array, length, isInitialized);
                if (isInitialized) {
                    cout << "Масив відсортовано." << endl;
                }
                break;
            case 6:
                cout << "Вихід з програми." << endl;
                return 0;
            default:
                displayError("Некоректний вибір. Будь ласка, оберіть число від 1 до 6.");
        }   
    }
    return 0;
}

void displayMenu() {
    cout << "\nМеню вибору дії:\n";
    cout << "1. Ввести елементи масиву\n";
    cout << "2. Вивести елементи масиву\n";
    cout << "3. Знайти мінімальний та максимальний елементи\n";
    cout << "4. Обчислити середнє арифметичне\n";
    cout << "5. Відсортувати масив за зростанням\n";
    cout << "6. Вийти з програми\n";
}   

void inputArray(int arr[], int length, bool &isInitialized) {
    clearConsole();
    cout << "Введіть " << length << " цілих чисел:\n";
    for (int i = 0; i < length; ++i) {
        cout << "Елемент " << i + 1 << ": ";
        cin >> arr[i];
        if(cin.fail()) {
            displayError("Некоректне введення. Будь ласка, введіть ціле число.");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            --i; 
        }
    }
    isInitialized = true;

    cout << "Операція успішно виконана.\n";

    waitForReturnToMenu();
}



void printArray(const int arr[], int length, bool isInitialized) {
    clearConsole();

    if (!isInitialized) {
        displayError("Масив не ініціалізовано. Спочатку введіть елементи масиву.");
        return;
    }
    cout << "Елементи масиву:\n";
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Операція успішно виконана.\n";
    waitForReturnToMenu();
}

double calculateAverage(const int arr[], int length, bool isInitialized) {
      clearConsole();
    if (!isInitialized) {
        displayError("Масив не ініціалізовано. Спочатку введіть елементи масиву.");
        return 0.0;
    }
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += arr[i];
    }
    double average = static_cast<double>(sum) / length;

    cout << "Операція успішно виконана.\n";
    return average;
    waitForReturnToMenu();
}   

void sortArray(int arr[], int length, bool isInitialized) {
      clearConsole();
    if (!isInitialized) {
        displayError("Масив не ініціалізовано. Спочатку введіть елементи масиву.");
        return;
    }
    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Операція успішно виконана.\n";
    waitForReturnToMenu();
}   

void findMinMax(const int arr[], int length, bool isInitialized, int &min, int &max) {
      clearConsole();
    if (!isInitialized) {
        displayError("Масив не ініціалізовано. Спочатку введіть елементи масиву.");
        return;
    }

    if ( length <= 0 )
    {
        displayError("Некоректна довжина масиву.");
        return;
    }
    
    min = arr[0];
    max = arr[0];
    for (int i = 1; i < length; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "Операція успішно виконана.\n";
    waitForReturnToMenu();
}   

void waitForReturnToMenu(){
    int key = -1;
    cout << "Натистіть 0 для повернення до меню: ";
    while (key != 0) {
        cin >> key;
        if(cin.fail() || key != 0) {
            displayError("Некоректне введення. Будь ласка, натисніть 0 для повернення до меню.");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if(key == 0) {
            break;
        }
        else {
            cout << "Натистіть 0 для повернення до меню: ";
        }
    }
};

void displayError(const string &message) {
    cerr << "Помилка: " << message << endl;
}


