#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> odd_magic_square(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0)); // 创建一个n x n的矩阵
    int row = 0, col = n / 2; // 起始行和列的索引
    int num = 1; // 当前要填充的数字

    while (num <= n * n) {
        matrix[row][col] = num;
        num++;

        // 计算下一个位置
        int next_row = (row - 1 + n) % n;
        int next_col = (col + 1) % n;

        if (matrix[next_row][next_col] != 0) {
            // 如果下一个位置已经有数字了，则向下移动一格
            row = (row + 1) % n;
        }
        else {
            // 否则向右上移动一格
            row = next_row;
            col = next_col;
        }
    }

    return matrix;
}

int main() {
    int n;
    cout << "请输入奇数阶幻方的阶数n：";
    cin >> n;

    vector<vector<int>> matrix = odd_magic_square(n);

    cout << "奇数阶幻方为：" << endl;
    for (auto row : matrix) {
        for (int num : row) {
            cout <<setw(4)<<num << " ";
        }
        cout << endl;
    }
    cout << "完成人:22网工方喜健" << endl;
    return 0;
}
