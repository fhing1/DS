#include <iostream>
#include <vector>
using namespace std;

// 三元组结构体
struct Triple {
    int row; // 行下标
    int col; // 列下标
    int val; // 元素值
};

// 将稀疏矩阵按行优先压缩存储到三元组顺序表中
vector<Triple> compress_sparse_matrix(vector<vector<int>>& matrix) {
    int n = matrix.size(); // 矩阵行数
    int m = matrix[0].size(); // 矩阵列数
    int count = 0; // 非零元素个数计数器
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    vector<Triple> triples(count); // 创建三元组顺序表
    int index = 0; // 三元组顺序表索引
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                triples[index] = { i, j, matrix[i][j] }; // 将非零元素存入三元组顺序表
                index++;
            }
        }
    }
    return triples;
}

// 使用快速转置算法求稀疏矩阵的转置矩阵
vector<Triple> transpose_sparse_matrix(vector<Triple>& triples, int n, int m) {
    vector<int> col_counts(m, 0); // 列非零元素个数数组
    for (auto t : triples) {
        col_counts[t.col]++; // 统计每列非零元素个数
    }
    vector<int> col_starts(m + 1, 0); // 每列起始位置索引数组
    for (int i = 1; i <= m; i++) {
        col_starts[i] = col_starts[i - 1] + col_counts[i - 1]; // 计算每列起始位置索引
    }
    vector<Triple> transposed_triples(triples.size()); // 创建转置后的三元组顺序表
    for (auto t : triples) {
        int col_start = col_starts[t.col]; // 当前列的起始位置索引
        transposed_triples[col_start] = { t.col, t.row, t.val }; // 将转置后的元素存入转置后的三元组顺序表
        col_starts[t.col]++; // 起始位置索引加一，为下一个元素做准备
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
    cout << "稀疏矩阵 A：" << endl;
    for (const auto& row : A) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
    vector<Triple> triples_A = compress_sparse_matrix(A); // 压缩存储稀疏矩阵 A
    vector<Triple> triples_B = transpose_sparse_matrix(triples_A, A.size(), A[0].size()); // 求稀疏矩阵 A 的转置矩阵 B

    cout << "稀疏矩阵 A 的三元组顺序表：" << endl;
    for (auto t : triples_A) {
        cout << "(" << t.row << ", " << t.col << ", " << t.val << ")" << endl; // 输出稀疏矩阵 A 的三元组顺序表
    }

    cout << "稀疏矩阵 B 的三元组顺序表：" << endl;
    for (auto t : triples_B) {
        cout << "(" << t.row << ", " << t.col << ", " << t.val << ")" << endl; // 输出稀疏矩阵 B 的三元组顺序表
    }
    cout << "完成人:22网工方喜健" << endl;
    return 0;
}
