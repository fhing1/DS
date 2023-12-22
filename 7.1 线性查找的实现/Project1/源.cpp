#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// 线性查找函数
int linearSearch(const vector<int>& array, int target) {
    for (int i = 0; i < array.size(); ++i) {
        if (array[i] == target) {
            return i; // 找到目标元素，返回索引
        }
    }
    return -1; // 目标元素不在数组中，返回-1
}

// 随机生成包含n个元素的查找序列
vector<int> generateRandomArray(int n) {
    vector<int> array;
    for (int i = 0; i < n; ++i) {
        array.push_back(rand() % 100); // 生成随机整数（0到99之间）
    }
    return array;
}

int main() {
    // 设置随机种子
    srand(static_cast<unsigned int>(time(nullptr)));

    // 随机生成查找序列
    int arraySize = 10; // 可根据需要修改序列大小
    vector<int> searchArray = generateRandomArray(arraySize);

    // 输出生成的查找序列
    cout << "查找序列：";
    for (int num : searchArray) {
        cout << num << " ";
    }
    cout << endl;

    // 设置要查找的目标元素
    int targetElement;
    cout << "输入要查找的目标元素：";
    cin >> targetElement;
    cout << "完成人:22网工方喜健" << endl;
    // 进行线性查找
    int result = linearSearch(searchArray, targetElement);

    // 输出查找结果
    if (result != -1) {
        cout << "目标元素 " << targetElement << " 在序列中的索引是：" << result << endl;
    }
    else {
        cout << "目标元素 " << targetElement << " 不在序列中。" << endl;
    }

    return 0;
}