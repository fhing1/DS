#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 定义四个小区之间的距离矩阵
    vector<vector<int>> distances = {
        {0, 10, 20, 30},
        {10, 0, 15, 25},
        {20, 15, 0, 35},
        {30, 25, 35, 0}
    };

    // 计算每个小区与其他三个小区之间的距离之和
    vector<int> sums(4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i != j) {
                sums[i] += distances[i][j];
            }
        }
    }

    // 找到距离之和最小的小区
    int min_sum_index = min_element(sums.begin(), sums.end()) - sums.begin();

    // 输出结果
    cout << "活动中心应位于第" << min_sum_index + 1 << "个小区。" << endl;
    cout <<endl<< "完成人：李浩冉"<<endl;
    return 0;
}
