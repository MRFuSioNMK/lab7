#include <iostream>

// Функція для перевірки, чи є число непарним
bool isOdd(int num) {
    return num % 2 != 0;
}

// Функція для пошуку першого стовпця, що містить лише непарні числа
int findFirstOddColumn(int **matrix, int M, int N) {
    if (M == 0 || N == 0) return 0;  // Перевірка на випадок порожньої матриці

    for (int col = 0; col < N; ++col) {
        bool allOdd = true;
        for (int row = 0; row < M; ++row) {
            if (!isOdd(matrix[row][col])) {
                allOdd = false;
                break;
            }
        }
        if (allOdd) {
            return col + 1;  // Повертаємо 1-based індекс стовпця
        }
    }
    return 0;  // Повертаємо 0, якщо таких стовпців немає
}

int main() {
    int M, N;
    std::cout << "Введіть кількість рядків (M): ";
    std::cin >> M;
    std::cout << "Введіть кількість стовпців (N): ";
    std::cin >> N;

    if (M <= 0 || N <= 0) {
        std::cout << "Недійсні розміри матриці." << std::endl;
        return 1;
    }

    // Створення та заповнення матриці
    int **matrix = new int*[M];
    for (int i = 0; i < M; ++i) {
        matrix[i] = new int[N];
        std::cout << "Введіть елементи рядка " << i + 1 << ":\n";
        for (int j = 0; j < N; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Пошук результату та вивід його на екран
    int result = findFirstOddColumn(matrix, M, N);
    if (result == 0) {
        std::cout << "Жоден стовпець не містить тільки непарні числа." << std::endl;
    } else {
        std::cout << "Перший стовпець з лише непарними числами: " << result << std::endl;
    }

    // Звільнення пам'яті
    for (int i = 0; i < M; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
