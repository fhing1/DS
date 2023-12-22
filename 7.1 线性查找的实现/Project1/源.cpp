#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// ���Բ��Һ���
int linearSearch(const vector<int>& array, int target) {
    for (int i = 0; i < array.size(); ++i) {
        if (array[i] == target) {
            return i; // �ҵ�Ŀ��Ԫ�أ���������
        }
    }
    return -1; // Ŀ��Ԫ�ز��������У�����-1
}

// ������ɰ���n��Ԫ�صĲ�������
vector<int> generateRandomArray(int n) {
    vector<int> array;
    for (int i = 0; i < n; ++i) {
        array.push_back(rand() % 100); // �������������0��99֮�䣩
    }
    return array;
}

int main() {
    // �����������
    srand(static_cast<unsigned int>(time(nullptr)));

    // ������ɲ�������
    int arraySize = 10; // �ɸ�����Ҫ�޸����д�С
    vector<int> searchArray = generateRandomArray(arraySize);

    // ������ɵĲ�������
    cout << "�������У�";
    for (int num : searchArray) {
        cout << num << " ";
    }
    cout << endl;

    // ����Ҫ���ҵ�Ŀ��Ԫ��
    int targetElement;
    cout << "����Ҫ���ҵ�Ŀ��Ԫ�أ�";
    cin >> targetElement;
    cout << "�����:22������ϲ��" << endl;
    // �������Բ���
    int result = linearSearch(searchArray, targetElement);

    // ������ҽ��
    if (result != -1) {
        cout << "Ŀ��Ԫ�� " << targetElement << " �������е������ǣ�" << result << endl;
    }
    else {
        cout << "Ŀ��Ԫ�� " << targetElement << " ���������С�" << endl;
    }

    return 0;
}