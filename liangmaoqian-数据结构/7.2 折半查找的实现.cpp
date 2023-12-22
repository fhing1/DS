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
    int n = 10; // ������ɵ����г���
    std::vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100; // ����0-99֮��������
    }

    // ���ԭʼ����
    std::cout << "ԭʼ���У� ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int target = 42; // Ҫ���ҵ�Ŀ��ֵ
    int index = binary_search(arr, target);

    if (index != -1) {
        std::cout << "�ҵ�Ŀ��ֵ " << target << " ������ " << index << std::endl;
    }
    else {
        std::cout << "δ�ҵ�Ŀ��ֵ " << target << std::endl;
    }
		cout <<endl<< "����ˣ����Ƚ"<<endl;
    return 0;
}
