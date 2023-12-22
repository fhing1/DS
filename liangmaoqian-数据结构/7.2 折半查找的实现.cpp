#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
int binary_search(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    srand(time(0));
    int n = 10; // 随机生成的序列长度
    std::vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100; // 生成0-99之间的随机数
    }

    // 输出原始序列
    std::cout << "原始序列： ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int target = 42; // 要查找的目标值
    int index = binary_search(arr, target);

    if (index != -1) {
        std::cout << "找到目标值 " << target << " 在索引 " << index << std::endl;
    }
    else {
        std::cout << "未找到目标值 " << target << std::endl;
    }
		cout <<endl<< "完成人：李浩冉"<<endl;
    return 0;
}
