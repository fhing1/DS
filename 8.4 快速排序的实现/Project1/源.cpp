#include <iostream>
#include <vector>

using namespace std;

// 快速排序的分区函数
int partition(vector<int>& array, int low, int high) {
    int pivot = array[high]; // 选择最后一个元素作为基准点
    int i = low - 1;

    // 将小于基准点的元素移到左侧，大于基准点的元素移到右侧
    for (int j = low; j < high; ++j) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }

    // 将基准点放到正确的位置
    swap(array[i + 1], array[high]);
    return i + 1;
}

// 快速排序函数
void quickSort(vector<int>& array, int low, int high) {
    if (low < high) {
        // 划分数组并获取分区点
        int pivotIndex = partition(array, low, high);

        // 递归排序分区点左侧和右侧的子数组
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

int main() {
    // 示例数组
    vector<int> exampleArray = { 12, 45, 23, 67, 89, 34, 56 };

    // 输出原始数组
    cout << "原始数组：";
    for (int num : exampleArray) {
        cout << num << " ";
    }
    cout << endl;
    cout << "完成人:22网工方喜健" << endl;
    // 进行快速排序
    quickSort(exampleArray, 0, exampleArray.size() - 1);

    // 输出排序后的数组
    cout << "排序后数组：";
    for (int num : exampleArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}