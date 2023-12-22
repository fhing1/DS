#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// ����ɢ�еĲ��Һ���
int hashSearch(const unordered_map<int, int>& hashTable, int target) {
    auto it = hashTable.find(target);
    if (it != hashTable.end()) {
        return it->second; // �ҵ�Ŀ��Ԫ�أ�����ֵ
    }
    return -1; // Ŀ��Ԫ�ز���ɢ�б��У�����-1
}

// ����ɢ�б�
unordered_map<int, int> buildHashTable(const vector<int>& array) {
    unordered_map<int, int> hashTable;
    for (int i = 0; i < array.size(); ++i) {
        hashTable[array[i]] = i; // ʹ��Ԫ��ֵ��Ϊ����������Ϊֵ����ɢ�б�
    }
    return hashTable;
}

int main() {
    // ����ʾ������
    vector<int> searchArray = { 23, 45, 12, 67, 89, 34, 56 };

    // ����ɢ�б�
    unordered_map<int, int> hashTable = buildHashTable(searchArray);

    // ���ʾ������
    cout << "�������飺";
    for (int num : searchArray) {
        cout << num << " ";
    }
    cout << endl;
    cout << "�����:22������ϲ��" << endl;


    // ����Ҫ���ҵ�Ŀ��Ԫ��
    int targetElement;
    cout << "����Ҫ���ҵ�Ŀ��Ԫ�أ�";
    cin >> targetElement;

    // ����ɢ�в���
    int result = hashSearch(hashTable, targetElement);

    // ������ҽ��
    if (result != -1) {
        cout << "Ŀ��Ԫ�� " << targetElement << " �������е������ǣ�" << result << endl;
    }
    else {
        cout << "Ŀ��Ԫ�� " << targetElement << " ���������С�" << endl;
    }

    return 0;
}