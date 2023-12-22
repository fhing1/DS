#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> spiral_matrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n)); // ����һ��n x n�ľ���
    int num = 1; // ��ǰҪ��������
    int row_start = 0, col_start = 0; // ��ʼ�к��е�����
    int row_end = n - 1, col_end = n - 1; // �����к��е�����

    while (row_start <= row_end && col_start <= col_end) {
        // �������ҵ���
        for (int j = col_start; j <= col_end; j++) {
            matrix[row_start][j] = num;
            num++;
        }
        row_start++;

        // �����ϵ��µ���
        for (int i = row_start; i <= row_end; i++) {
            matrix[i][col_end] = num;
            num++;
        }
        col_end--;

        // �����ʼ��С�ڵ��ڽ����У��������ҵ������
        if (row_start <= row_end) {
            for (int j = col_end; j >= col_start; j--) {
                matrix[row_end][j] = num;
                num++;
            }
            row_end--;
        }

        // �����ʼ��С�ڵ��ڽ����У��������µ��ϵ���
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
    cout << "��������������Ľ���n��";
    cin >> n;

    vector<vector<int>> matrix = spiral_matrix(n);

    cout << "��������Ϊ��" << endl;
    for (auto row : matrix) {
        for (int num : row) {
            cout <<setw(4)<< num << " ";
        }
        cout << endl;
    }
    cout << "�����:22������ϲ��" << endl;


    return 0;
}
