#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// ����n��n�׶Գƾ���
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

// ��������ѹ���洢�Գƾ���һά����
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

// ���������±���һά�����д�ȡԪ��
int get_element(const vector<int>& compressed_matrix, int row, int col) {
    int n = static_cast<int>(sqrt(compressed_matrix.size()));
    return compressed_matrix[row * n + col];
}

int main() {
    int n;
    cout << "���������Ľ���n: ";
    cin >> n;

    vector<vector<int>> matrix = generate_symmetric_matrix(n);
    cout << "���ɵĶԳƾ���Ϊ��" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    vector<int> compressed_matrix = compress_symmetric_matrix(matrix);
    cout << "ѹ�����һά����Ϊ��" << endl;
    for (int val : compressed_matrix) {
        cout << val << " ";
    }
    cout << endl;

    int row, col;
    cout << "������Ҫ���ʵ�Ԫ�ص������±꣨�ÿո��������";
    cin >> row >> col;
    int element = get_element(compressed_matrix, row - 1, col - 1);
    cout << "Ԫ��ֵΪ��" << element << endl;
cout<<endl<<"����ˣ�22�������Ƚ"<<endl;
    return 0;
}
