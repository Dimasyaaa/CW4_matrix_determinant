#include <vector>

using namespace std;

// Функция для получения минорной матрицы
vector<vector<long long>> getMinor(const vector<vector<long long>>& arr, int col) {
    int size = arr.size();
    vector<vector<long long>> minorMatrix(size - 1, vector<long long>(size - 1)); // Создание минорной матрицы

    for (int i = 1; i < size; ++i) { // Начинаем с 1, чтобы пропустить первую строку
        int shift = 0; // Сдвиг для столбцов
        for (int j = 0; j < size; ++j) {
            if (j == col) {
                shift++; // Увеличиваем сдвиг, если столбец совпадает
                continue;
            }
            minorMatrix[i - 1][j - shift] = arr[i][j]; // Копируем элементы
        }
    }
    return minorMatrix;
}
// Функция для вычисления определителя матрицы
long long determinant(const vector<vector<long long>>& arr) {
    int size = arr.size();
    if (size == 1) {
        return arr[0][0]; // Определитель 1x1
    }
    if (size == 2) {
        return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0]; // Определитель 2x2
    }

    long long det = 0;

    for (int col = 0; col < size; ++col) {
        long long sign = (col % 2 == 0) ? 1 : -1; // Знак определителя
        det += sign * arr[0][col] * determinant(getMinor(arr, col)); // Рекурсивный вызов
    }
    return det;
}