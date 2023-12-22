#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 合并两个有序数组的函数
void merge(vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1; // 左半部分的元素个数
    int n2 = right - mid;     // 右半部分的元素个数

    // 创建临时数组用于存储左右两部分的元素
    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    // 将元素复制到临时数组中
    for (int i = 0; i < n1; i++) {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArray[j] = array[mid + 1 + j];
    }

    // 合并左右两部分的元素到原数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // 将剩余的元素复制到原数组中
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

// 非递归实现的二路归并排序函数
void mergeSort(vector<int>& array) {
    int n = array.size();
    int currSize;  // 当前子数组的大小
    int leftStart; // 左侧子数组的起始索引

    // 依次将子数组大小从1、2、4、8、...递增，直到超过数组大小
    for (currSize = 1; currSize <= n - 1; currSize *= 2) {
        // 逐对合并子数组
        for (leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) {
            int mid = min(leftStart + currSize - 1, n - 1);
            int rightEnd = min(leftStart + 2 * currSize - 1, n - 1);

            // 合并左右两部分
            merge(array, leftStart, mid, rightEnd);
        }
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


    // 进行非递归实现的二路归并排序
    mergeSort(exampleArray);

    // 输出排序后的数组
    cout << "排序后数组：";
    for (int num : exampleArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}