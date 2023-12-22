#include <iostream>
#include <vector>

using namespace std;

// ��������ķ�������
int partition(vector<int>& array, int low, int high) {
    int pivot = array[high]; // ѡ�����һ��Ԫ����Ϊ��׼��
    int i = low - 1;

    // ��С�ڻ�׼���Ԫ���Ƶ���࣬���ڻ�׼���Ԫ���Ƶ��Ҳ�
    for (int j = low; j < high; ++j) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }

    // ����׼��ŵ���ȷ��λ��
    swap(array[i + 1], array[high]);
    return i + 1;
}

// ����������
void quickSort(vector<int>& array, int low, int high) {
    if (low < high) {
        // �������鲢��ȡ������
        int pivotIndex = partition(array, low, high);

        // �ݹ���������������Ҳ��������
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

int main() {
    // ʾ������
    vector<int> exampleArray = { 12, 45, 23, 67, 89, 34, 56 };

    // ���ԭʼ����
    cout << "ԭʼ���飺";
    for (int num : exampleArray) {
        cout << num << " ";
    }
    cout << endl;
    cout << "�����:22������ϲ��" << endl;
    // ���п�������
    quickSort(exampleArray, 0, exampleArray.size() - 1);

    // �������������
    cout << "��������飺";
    for (int num : exampleArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}