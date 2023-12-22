#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));
    int n;
    cout << "���������Ľ�����";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (abs(i - j) <= 1) {
                matrix[i][j] = rand() % 10 + 1;
            }
        }
    }

    cout << "���ɵ����ԽǾ���Ϊ��" << endl;
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

    cout << "��������ѹ���洢���һά����Ϊ��" << endl;
    for (int i = 0; i < compressed_matrix.size(); ++i) {
        cout << compressed_matrix[i] << " ";
    }
    cout << endl;

    int row, col;
    cout << "������Ҫ���ʵ�Ԫ�ص������±꣨�ÿո��������";
    cin >> row >> col;

    int access_element = compressed_matrix[row * (row + 1) / 2 + col];
    cout << "��һά�����У�Ԫ��(" << row << ", " << col << ")��ֵΪ��" << access_element << endl;
	  cout<<endl<<"����ˣ�22�������Ƚ"<<endl;
    return 0;
}
