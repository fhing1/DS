#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> odd_magic_square(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0)); // ����һ��n x n�ľ���
    int row = 0, col = n / 2; // ��ʼ�к��е�����
    int num = 1; // ��ǰҪ��������

    while (num <= n * n) {
        matrix[row][col] = num;
        num++;

        // ������һ��λ��
        int next_row = (row - 1 + n) % n;
        int next_col = (col + 1) % n;

        if (matrix[next_row][next_col] != 0) {
            // �����һ��λ���Ѿ��������ˣ��������ƶ�һ��
            row = (row + 1) % n;
        }
        else {
            // �����������ƶ�һ��
            row = next_row;
            col = next_col;
        }
    }

    return matrix;
}

int main() {
    int n;
    cout << "�����������׻÷��Ľ���n��";
    cin >> n;

    vector<vector<int>> matrix = odd_magic_square(n);

    cout << "�����׻÷�Ϊ��" << endl;
    for (auto row : matrix) {
        for (int num : row) {
            cout <<setw(4)<<num << " ";
        }
        cout << endl;
    }
    cout << "�����:22������ϲ��" << endl;
    return 0;
}
