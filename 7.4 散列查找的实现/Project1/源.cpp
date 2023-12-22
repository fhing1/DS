#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 基于散列的查找函数
int hashSearch(const unordered_map<int, int>& hashTable, int target) {
    auto it = hashTable.find(target);
    if (it != hashTable.end()) {
        return it->second; // 找到目标元素，返回值
    }
    return -1; // 目标元素不在散列表中，返回-1
}

// 构建散列表
unordered_map<int, int> buildHashTable(const vector<int>& array) {
    unordered_map<int, int> hashTable;
    for (int i = 0; i < array.size(); ++i) {
        hashTable[array[i]] = i; // 使用元素值作为键，索引作为值构建散列表
    }
    return hashTable;
}

int main() {
    // 构建示例数组
    vector<int> searchArray = { 23, 45, 12, 67, 89, 34, 56 };

    // 构建散列表
    unordered_map<int, int> hashTable = buildHashTable(searchArray);

    // 输出示例数组
    cout << "查找数组：";
    for (int num : searchArray) {
        cout << num << " ";
    }
    cout << endl;
    cout << "完成人:22网工方喜健" << endl;


    // 设置要查找的目标元素
    int targetElement;
    cout << "输入要查找的目标元素：";
    cin >> targetElement;

    // 进行散列查找
    int result = hashSearch(hashTable, targetElement);

    // 输出查找结果
    if (result != -1) {
        cout << "目标元素 " << targetElement << " 在数组中的索引是：" << result << endl;
    }
    else {
        cout << "目标元素 " << targetElement << " 不在数组中。" << endl;
    }

    return 0;
}