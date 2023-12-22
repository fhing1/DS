#include <iostream>
#include <vector>
using namespace std;

// Լɪ��������⺯��
vector<int> josephus(int n, int m) {
    vector<int> result; // �洢���յ�����ֵ
    vector<int> nums(n); // �洢������Ϸ���˵ı��

    // ��ʼ��������Ϸ���˵ı��
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }

    int idx = 0; // ��ǰ�������˵��±�

    while (!nums.empty()) {
        // �ҵ�Ҫ���ֵ��˵��±�
        idx = (idx + m - 1) % nums.size();

        // �����ֵ��˵ı����ӵ������
        result.push_back(nums[idx]);

        // �Ƴ����ֵ���
        nums.erase(nums.begin() + idx);
    }

    return result;
}

int main() {
    int n, m;
    cout << "�����������Ϸ������n��";
    cin >> n;
    cout << "����������m��";
    cin >> m;

    vector<int> sequence = josephus(n, m);

    cout << "Լɪ�����������ֵΪ��";
    for (int num : sequence) {
        cout << num << " ";
    }
    cout << endl;
    cout << "�����:22������ϲ��" << endl;


    return 0;
}
