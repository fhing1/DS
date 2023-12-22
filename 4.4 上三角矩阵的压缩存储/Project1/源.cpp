#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// 随机生成nxn阶上三角矩阵
void generateUpperTriangleMatrix(std::vector<std::vector<int>>& matrix, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        std::vector<int> row(i + 1, 0);
        for (int j = 0; j <= i; j++) {
            row[j] = rand() % 100;  // 假设元素范围在0-99之间
        }
        matrix.push_back(row);
    }
}

// 将上三角矩阵按行优先压缩存储到一维数组中
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

// 根据行列下标在一维数组中存取元素
int getElement(const std::vector<int>& compressedArray, int n, int row, int col) {
    if (row < col || row >= n || col >= n) {
        std::cout << "Invalid index!" << std::endl;
        return -1;  // 返回一个错误值
    }
    int index = row * (row + 1) / 2 + col;
    return compressedArray[index];
}

int main() {
    int n;
    std::cout << "请输入上三角矩阵的阶数n：";
    std::cin >> n;

    std::vector<std::vector<int>> matrix;
    generateUpperTriangleMatrix(matrix, n);

    std::cout << "生成的上三角矩阵：" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int> compressedArray = compressUpperTriangleMatrix(matrix, n);

    std::cout << "压缩存储后的一维数组：" << std::endl;
    for (int i = 0; i < compressedArray.size(); i++) {
        std::cout << compressedArray[i] << " ";
    }
    std::cout << std::endl;

    int row, col;
    std::cout << "请输入行列下标(row, col)：";
    std::cin >> row >> col;
    int element = getElement(compressedArray, n, row, col);
    if (element != -1) {
        std::cout << "在指定位置的元素为：" << element << std::endl;
    }
    std::cout<<"完成人:22网工方喜健" <<std::endl;
    return 0;
}
