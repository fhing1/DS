#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// �������nxn�������Ǿ���
void generateUpperTriangleMatrix(std::vector<std::vector<int>>& matrix, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        std::vector<int> row(i + 1, 0);
        for (int j = 0; j <= i; j++) {
            row[j] = rand() % 100;  // ����Ԫ�ط�Χ��0-99֮��
        }
        matrix.push_back(row);
    }
}

// �������Ǿ���������ѹ���洢��һά������
std::vector<int> compressUpperTriangleMatrix(const std::vector<std::vector<int>>& matrix, int n) {
    std::vector<int> compressedArray(n * (n + 1) / 2, 0);
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            compressedArray[index++] = matrix[i][j];
        }
    }
    return compressedArray;
}

// ���������±���һά�����д�ȡԪ��
int getElement(const std::vector<int>& compressedArray, int n, int row, int col) {
    if (row < col || row >= n || col >= n) {
        std::cout << "Invalid index!" << std::endl;
        return -1;  // ����һ������ֵ
    }
    int index = row * (row + 1) / 2 + col;
    return compressedArray[index];
}

int main() {
    int n;
    std::cout << "�����������Ǿ���Ľ���n��";
    std::cin >> n;

    std::vector<std::vector<int>> matrix;
    generateUpperTriangleMatrix(matrix, n);

    std::cout << "���ɵ������Ǿ���" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int> compressedArray = compressUpperTriangleMatrix(matrix, n);

    std::cout << "ѹ���洢���һά���飺" << std::endl;
    for (int i = 0; i < compressedArray.size(); i++) {
        std::cout << compressedArray[i] << " ";
    }
    std::cout << std::endl;

    int row, col;
    std::cout << "�����������±�(row, col)��";
    std::cin >> row >> col;
    int element = getElement(compressedArray, n, row, col);
    if (element != -1) {
        std::cout << "��ָ��λ�õ�Ԫ��Ϊ��" << element << std::endl;
    }
    std::cout<<"�����:22������ϲ��" <<std::endl;
    return 0;
}
