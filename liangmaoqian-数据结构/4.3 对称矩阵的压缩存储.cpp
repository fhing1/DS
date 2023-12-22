#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// 生成n乘n阶对称矩阵
vector<vector<int>> generate_symmetric_matrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            matrix[i][j] = rand() % 10;
            matrix[j][i] = matrix[i][j];
        }
    }
    return matrix;
}

// 按行优先压缩存储对称矩阵到一维数组
vector<int> compress_symmetric_matrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> compressed_matrix(n * (n + 1) / 2);
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            compressed_matrix[index++] = matrix[i][j];
        }
    }
    return compressed_matrix;
}

// 根据行列下标在一维数组中存取元素
int get_element(const vector<int>& compressed_matrix, int row, int col) {
    int n = static_cast<int>(sqrt(compressed_matrix.size()));
    return compressed_matrix[row * n + col];
}

int main() {
    int n;
    cout << "请输入矩阵的阶数n: ";
    cin >> n;

    vector<vector<int>> matrix = generate_symmetric_matrix(n);
    cout << "生成的对称矩阵为：" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    vector<int> compressed_matrix = compress_symmetric_matrix(matrix);
    cout << "压缩后的一维数组为：" << endl;
    for (int val : compressed_matrix) {
        cout << val << " ";
    }
    cout << endl;

    int row, col;
    cout << "请输入要访问的元素的行列下标（用空格隔开）：";
    cin >> row >> col;
    int element = get_element(compressed_matrix, row - 1, col - 1);
    cout << "元素值为：" << element << endl;
cout<<endl<<"完成人：22网工李浩冉"<<endl;
    return 0;
}
