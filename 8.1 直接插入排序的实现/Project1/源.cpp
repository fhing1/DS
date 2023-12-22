#include <iostream>
#include <vector>

using namespace std;

// 直接插入排序函数
void insertionSort(vector<int>& array) {
    int n = array.size();
    for (int i = 1; i < n; ++i) {
        int key = array[i]; // 当前要插入的元素
        int j = i - 1;

        // 将比key大的元素都向后移动
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        // 插入key到合适的位置
        array[j + 1] = key;
    }
}

int main() {
    // 示例数组
    vector<int> exampleArray = { 12, 45, 23, 67, 89, 34, 56 };
    cout << "完成人:22网工方喜健" << endl;
    // 输出原始数组
    cout << "原始数组：";
    for (int num : exampleArray) {
        cout << num << " ";
    }
    cout << endl;

    // 进行直接插入排序
    insertionSort(exampleArray);

    // 输出排序后的数组
    cout << "排序后数组：";
    for (int num : exampleArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}