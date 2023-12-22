#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// �ϲ�������������ĺ���
void merge(vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1; // ��벿�ֵ�Ԫ�ظ���
    int n2 = right - mid;     // �Ұ벿�ֵ�Ԫ�ظ���

    // ������ʱ�������ڴ洢���������ֵ�Ԫ��
    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    // ��Ԫ�ظ��Ƶ���ʱ������
    for (int i = 0; i < n1; i++) {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArray[j] = array[mid + 1 + j];
    }

    // �ϲ����������ֵ�Ԫ�ص�ԭ����
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // ��ʣ���Ԫ�ظ��Ƶ�ԭ������
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

// �ǵݹ�ʵ�ֵĶ�·�鲢������
void mergeSort(vector<int>& array) {
    int n = array.size();
    int currSize;  // ��ǰ������Ĵ�С
    int leftStart; // ������������ʼ����

    // ���ν��������С��1��2��4��8��...������ֱ�����������С
    for (currSize = 1; currSize <= n - 1; currSize *= 2) {
        // ��Ժϲ�������
        for (leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) {
            int mid = min(leftStart + currSize - 1, n - 1);
            int rightEnd = min(leftStart + 2 * currSize - 1, n - 1);

            // �ϲ�����������
            merge(array, leftStart, mid, rightEnd);
        }
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


    // ���зǵݹ�ʵ�ֵĶ�·�鲢����
    mergeSort(exampleArray);

    // �������������
    cout << "��������飺";
    for (int num : exampleArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}