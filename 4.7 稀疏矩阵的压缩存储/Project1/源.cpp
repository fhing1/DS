#include <iostream>
#include <vector>
using namespace std;

// ��Ԫ��ṹ��
struct Triple {
    int row; // ���±�
    int col; // ���±�
    int val; // Ԫ��ֵ
};

// ��ϡ�����������ѹ���洢����Ԫ��˳�����
vector<Triple> compress_sparse_matrix(vector<vector<int>>& matrix) {
    int n = matrix.size(); // ��������
    int m = matrix[0].size(); // ��������
    int count = 0; // ����Ԫ�ظ���������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    vector<Triple> triples(count); // ������Ԫ��˳���
    int index = 0; // ��Ԫ��˳�������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                triples[index] = { i, j, matrix[i][j] }; // ������Ԫ�ش�����Ԫ��˳���
                index++;
            }
        }
    }
    return triples;
}

// ʹ�ÿ���ת���㷨��ϡ������ת�þ���
vector<Triple> transpose_sparse_matrix(vector<Triple>& triples, int n, int m) {
    vector<int> col_counts(m, 0); // �з���Ԫ�ظ�������
    for (auto t : triples) {
        col_counts[t.col]++; // ͳ��ÿ�з���Ԫ�ظ���
    }
    vector<int> col_starts(m + 1, 0); // ÿ����ʼλ����������
    for (int i = 1; i <= m; i++) {
        col_starts[i] = col_starts[i - 1] + col_counts[i - 1]; // ����ÿ����ʼλ������
    }
    vector<Triple> transposed_triples(triples.size()); // ����ת�ú����Ԫ��˳���
    for (auto t : triples) {
        int col_start = col_starts[t.col]; // ��ǰ�е���ʼλ������
        transposed_triples[col_start] = { t.col, t.row, t.val }; // ��ת�ú��Ԫ�ش���ת�ú����Ԫ��˳���
        col_starts[t.col]++; // ��ʼλ��������һ��Ϊ��һ��Ԫ����׼��
    }
    return transposed_triples;
}

int main() {
    vector<vector<int>> A = {
        {0, 0, 0, 5, 0},
        {0, 0, 6, 0, 0},
        {0, 7, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {8, 0, 0, 0, 9}
    };
    cout << "ϡ����� A��" << endl;
    for (const auto& row : A) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
    vector<Triple> triples_A = compress_sparse_matrix(A); // ѹ���洢ϡ����� A
    vector<Triple> triples_B = transpose_sparse_matrix(triples_A, A.size(), A[0].size()); // ��ϡ����� A ��ת�þ��� B

    cout << "ϡ����� A ����Ԫ��˳���" << endl;
    for (auto t : triples_A) {
        cout << "(" << t.row << ", " << t.col << ", " << t.val << ")" << endl; // ���ϡ����� A ����Ԫ��˳���
    }

    cout << "ϡ����� B ����Ԫ��˳���" << endl;
    for (auto t : triples_B) {
        cout << "(" << t.row << ", " << t.col << ", " << t.val << ")" << endl; // ���ϡ����� B ����Ԫ��˳���
    }
    cout << "�����:22������ϲ��" << endl;
    return 0;
}
