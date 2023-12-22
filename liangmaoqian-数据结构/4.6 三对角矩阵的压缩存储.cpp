#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));
    int n;
    cout << "请输入矩阵的阶数：";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (abs(i - j) <= 1) {
                matrix[i][j] = rand() % 10 + 1;
            }
        }
    }

    cout << "生成的三对角矩阵为：" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    vector<int> compressed_matrix(n * (n + 1) / 2, 0);
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            compressed_matrix[index++] = matrix[i][j];
        }
    }

    cout << "按行优先压缩存储后的一维数组为：" << endl;
    for (int i = 0; i < compressed_matrix.size(); ++i) {
        cout << compressed_matrix[i] << " ";
    }
    cout << endl;

    int row, col;
    cout << "请输入要访问的元素的行列下标（用空格隔开）：";
    cin >> row >> col;

    int access_element = compressed_matrix[row * (row + 1) / 2 + col];
    cout << "在一维数组中，元素(" << row << ", " << col << ")的值为：" << access_element << endl;
	  cout<<endl<<"完成人：22网工李浩冉"<<endl;
    return 0;
}
