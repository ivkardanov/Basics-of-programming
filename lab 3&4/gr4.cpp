#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Проверка безопасности установки ферзя
bool isSafe(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'Q') {
            return false;  // Проверка вертикали вверх
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q') {
            return false;  // Проверка левой верхней диагонали
        }
    }

    for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
        if (board[i][j] == 'Q') {
            return false;  // Проверка правой верхней диагонали
        }
    }

    return true;
}

// Решение задачи о 8 ферзях
void solveNQueens(int row, int n, vector<string>& board, vector<vector<string>>& result) {
    if (row == n) {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueens(row + 1, n, board, result);
            board[row][col] = '.';  // Бэктрекинг
        }
    }
}

// Главная функция
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));

    solveNQueens(0, n, board, result);

    return result;
}

// Тестирование решения
int main() {
    string choice;
    do {
        int n = 4;
        vector<vector<string>> solutions = solveNQueens(n);

        cout << "Solutions for " << n << " queens on the board " << n << "x" << n << ":\n";
        for (const auto& solution : solutions) {
            for (const string& row : solution) {
                cout << row << endl;
            }
            cout << "-----------------\n";
        }
        cout << "Run again? (y/n): ";
        cin >> choice;
    } while (choice == "y" || choice == "Y");

    return 0;
}
