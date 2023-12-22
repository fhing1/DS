#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> even_magic_square(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0)); // ����һ��n x n�ľ���
    int half_n = n / 2; // n��һ��
    int num = 1; // ��ǰҪ��������

    // ������Ͻǵ�4��С������
    for (int i = 0; i < half_n; i++) {
        for (int j = 0; j < half_n; j++) {
            matrix[i][j] = num;
            num++;
        }
    }

    // ������Ͻǵ�4��С������
    for (int i = 0; i < half_n; i++) {
        for (int j = half_n + 1; j < n; j++) {
            matrix[i][j] = num;
            num++;
        }
    }

    // ������½ǵ�4��С������
    for (int i = half_n + 1; i < n; i++) {
        for (int j = 0; j < half_n; j++) {
            matrix[i][j] = num;
            num++;
        }
    }

    // ������½ǵ�4��С������
    for (int i = half_n + 1; i < n; i++) {
        for (int j = half_n + 1; j < n; j++) {
            matrix[i][j] = num;
            num++;
        }
    }

    // ����м���ı���
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
    cout << "������˫ż�׻÷��Ľ���n��������4�ı�������";
    cin >> n;

    vector<vector<int>> matrix = even_magic_square(n);

    cout << "˫ż�׻÷�Ϊ��" << endl;
    for (auto row : matrix) {
        for (int num : row) {
            cout << setw(4)<<num << " ";
        }
        cout << endl;
    }
    cout << "�����:22������ϲ��" << endl;
    return 0;
}
