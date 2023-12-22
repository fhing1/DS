#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // �����ĸ�С��֮��ľ������
    vector<vector<int>> distances = {
        {0, 10, 20, 30},
        {10, 0, 15, 25},
        {20, 15, 0, 35},
        {30, 25, 35, 0}
    };

    // ����ÿ��С������������С��֮��ľ���֮��
    vector<int> sums(4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i != j) {
                sums[i] += distances[i][j];
            }
        }
    }

    // �ҵ�����֮����С��С��
    int min_sum_index = min_element(sums.begin(), sums.end()) - sums.begin();

    // ������
    cout << "�����Ӧλ�ڵ�" << min_sum_index + 1 << "��С����" << endl;
    cout <<endl<< "����ˣ����Ƚ"<<endl;
    return 0;
}
