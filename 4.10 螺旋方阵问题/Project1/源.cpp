#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> spiral_matrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n)); // 创建一个n x n的矩阵
    int num = 1; // 当前要填充的数字
    int row_start = 0, col_start = 0; // 起始行和列的索引
    int row_end = n - 1, col_end = n - 1; // 结束行和列的索引

    while (row_start <= row_end && col_start <= col_end) {
        // 填充从左到右的行
        for (int j = col_start; j <= col_end; j++) {
            matrix[row_start][j] = num;
            num++;
        }
        row_start++;

        // 填充从上到下的列
        for (int i = row_start; i <= row_end; i++) {
            matrix[i][col_end] = num;
            num++;
        }
        col_end--;

        // 如果起始行小于等于结束行，则填充从右到左的行
        if (row_start <= row_end) {
            for (int j = col_end; j >= col_start; j--) {
                matrix[row_end][j] = num;
                num++;
            }
            row_end--;
        }

        // 如果起始列小于等于结束列，则填充从下到上的列
        if (col_start <= col_end) {
            for (int i = row_end; i >= row_start; i--) {
                matrix[i][col_start] = num;
                num++;
            }
            col_start++;
        }
    }

    return matrix;
}

int main() {
    int n;
    cout << "请输入螺旋方阵的阶数n：";
    cin >> n;

    vector<vector<int>> matrix = spiral_matrix(n);

    cout << "螺旋方阵为：" << endl;
    for (auto row : matrix) {
        for (int num : row) {
            cout <<setw(4)<< num << " ";
        }
        cout << endl;
    }
    cout << "完成人:22网工方喜健" << endl;


    return 0;
}
