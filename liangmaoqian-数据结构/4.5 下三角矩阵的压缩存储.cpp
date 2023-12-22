#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// 生成随机数
int random_number(int min, int max) {
    return min + rand() % (max - min + 1);
}

// 生成下三角矩阵
vector<vector<int>> generate_lower_triangular_matrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            matrix[i][j] = random_number(1, 10);
        }
    }
    return matrix;
}

// 压缩存储下三角矩阵
vector<int> compress_lower_triangular_matrix(const vector<vector<int>>& matrix) {
    vector<int> compressed_matrix;
    for (const auto& row : matrix) {
        for (int val : row) {
            compressed_matrix.push_back(val);
        }
    }
    return compressed_matrix;
}

// 根据行列下标在一维数组中存取元素
int get_element(const vector<int>& compressed_matrix, int row, int col) {
    if (row >= col || row < 0 || col < 0 || row >= compressed_matrix.size() / (row + 1)) {
        throw out_of_range("Invalid row or column index");
    }
    return compressed_matrix[row * (row + 1) / 2 + col];
}

int main() {
    srand(time(0));
    int n = 4;
    vector<vector<int>> lower_triangular_matrix = generate_lower_triangular_matrix(n);
    vector<int> compressed_matrix = compress_lower_triangular_matrix(lower_triangular_matrix);

    cout << "下三角矩阵:" << endl;
    for (const auto& row : lower_triangular_matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "压缩矩阵:" << endl;
    for (int val : compressed_matrix) {
        cout << val << " ";
    }
    cout << endl;

    int row = 1, col = 2;
    cout << "元素在 (" << row << ", " << col << ")为 " << get_element(compressed_matrix, row, col) << endl;
cout<<endl<<"完成人：22网工李浩冉"<<endl;
    return 0;
}
