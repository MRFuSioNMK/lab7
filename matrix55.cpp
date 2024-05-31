#include <iostream>

using namespace std;

void swapUpperLowerHalves(int **matrix, int M, int N) {
    int halfM = M / 2; // Половина кількості рядків

    // Обмін верхньої та нижньої половини матриці
    for (int i = 0; i < halfM; ++i) {
        for (int j = 0; j < N; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i + halfM][j];
            matrix[i + halfM][j] = temp;
        }
    }
}

int main() {
    int M, N;
    cout << "Введіть кількість рядків (M): ";
    cin >> M;
    cout << "Введіть кількість стовпців (N): ";
    cin >> N;

    if (M % 2 != 0 || M <= 0 || N <= 0) {
        cout << "Помилка: кількість рядків повинна бути парним числом та більше нуля." << endl;
        return 1;
    }

    // Створення та заповнення матриці
    int **matrix = new int*[M];
    for (int i = 0; i < M; ++i) {
        matrix[i] = new int[N];
        cout << "Введіть елементи рядка " << i + 1 << ":\n";
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Обмін верхньої та нижньої половини матриці
    swapUpperLowerHalves(matrix, M, N);

    // Виведення результату
    cout << "Матриця після обміну половин:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Звільнення пам'яті
    for (int i = 0; i < M; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
