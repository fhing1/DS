#include <iostream>
#include <vector>

using namespace std;

// ֱ�Ӳ���������
void insertionSort(vector<int>& array) {
    int n = array.size();
    for (int i = 1; i < n; ++i) {
        int key = array[i]; // ��ǰҪ�����Ԫ��
        int j = i - 1;

        // ����key���Ԫ�ض�����ƶ�
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        // ����key�����ʵ�λ��
        array[j + 1] = key;
    }
}

int main() {
    // ʾ������
    vector<int> exampleArray = { 12, 45, 23, 67, 89, 34, 56 };
    cout << "�����:22������ϲ��" << endl;
    // ���ԭʼ����
    cout << "ԭʼ���飺";
    for (int num : exampleArray) {
        cout << num << " ";
    }
    cout << endl;

    // ����ֱ�Ӳ�������
    insertionSort(exampleArray);

    // �������������
    cout << "��������飺";
    for (int num : exampleArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}