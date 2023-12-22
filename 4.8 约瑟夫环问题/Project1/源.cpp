#include <iostream>
#include <vector>
using namespace std;

// 约瑟夫环问题求解函数
vector<int> josephus(int n, int m) {
    vector<int> result; // 存储最终的序列值
    vector<int> nums(n); // 存储参与游戏的人的编号

    // 初始化参与游戏的人的编号
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }

    int idx = 0; // 当前报数的人的下标

    while (!nums.empty()) {
        // 找到要出局的人的下标
        idx = (idx + m - 1) % nums.size();

        // 将出局的人的编号添加到结果中
        result.push_back(nums[idx]);

        // 移除出局的人
        nums.erase(nums.begin() + idx);
    }

    return result;
}

int main() {
    int n, m;
    cout << "请输入参与游戏的人数n：";
    cin >> n;
    cout << "请输入密码m：";
    cin >> m;

    vector<int> sequence = josephus(n, m);

    cout << "约瑟夫环问题的序列值为：";
    for (int num : sequence) {
        cout << num << " ";
    }
    cout << endl;
    cout << "完成人:22网工方喜健" << endl;


    return 0;
}
