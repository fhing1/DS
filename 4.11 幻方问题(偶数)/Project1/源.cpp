#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> even_magic_square(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0)); // 创建一个n x n的矩阵
    int half_n = n / 2; // n的一半
    int num = 1; // 当前要填充的数字

    // 填充左上角的4个小正方形
    for (int i = 0; i < half_n; i++) {
        for (int j = 0; j < half_n; j++) {
            matrix[i][j] = num;
            num++;
        }
    }

    // 填充右上角的4个小正方形
    for (int i = 0; i < half_n; i++) {
        for (int j = half_n + 1; j < n; j++) {
            matrix[i][j] = num;
            num++;
        }
    }

    // 填充左下角的4个小正方形
    for (int i = half_n + 1; i < n; i++) {
        for (int j = 0; j < half_n; j++) {
            matrix[i][j] = num;
            num++;
        }
    }

    // 填充右下角的4个小正方形
    for (int i = half_n + 1; i < n; i++) {
        for (int j = half_n + 1; j < n; j++) {
            matrix[i][j] = num;
            num++;
        }
    }

    // 填充中间的四边形
    for (int i = 0; i < half_n; i++) {
        matrix[half_n][i] = num;
        num++;
    }
    for (int i = half_n + 1; i < n; i++) {
        matrix[half_n][i] = num;
        num++;
    }
    for (int i = 0; i < half_n; i++) {
        matrix[i][half_n] = num;
        num++;
    }
    for (int i = half_n + 1; i < n; i++) {
        matrix[i][half_n] = num;
        num++;
    }

    return matrix;
}

int main() {
    int n;
    cout << "请输入双偶阶幻方的阶数n（必须是4的倍数）：";
    cin >> n;

    vector<vector<int>> matrix = even_magic_square(n);

    cout << "双偶阶幻方为：" << endl;
    for (auto row : matrix) {
        for (int num : row) {
            cout << setw(4)<<num << " ";
        }
        cout << endl;
    }
    cout << "完成人:22网工方喜健" << endl;
    return 0;
}
