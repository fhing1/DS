#include <iostream>
#include <cstring>

using namespace std;

int bfMatch(const char* S, const char* T) {
    int lenS = strlen(S);
    int lenT = strlen(T);

    for (int i = 0; i <= lenS - lenT; i++) {
        int j;
        for (j = 0; j < lenT; j++) {
            if (S[i + j] != T[j])
                break;
        }
        if (j == lenT) {
            return i;  // ƥ��ɹ��������߼�λ��
        }
    }

    return -1;  // ƥ��ʧ�ܣ�����-1
}

int main() {
    const char* S = "ABCABABCD";
    const char* T = "ABCD";
    int position = bfMatch(S, T);
    cout << "Ŀ�괮(S):ABCABABCD" << endl;
    cout << "ģʽ��(T):ABCD" << endl;

    if (position != -1) {
        cout << "���ַ���S���ҵ����ַ���T����ʼλ��Ϊ: " << position << endl;
    }
    else {
        cout << "���ַ���S��δ�ҵ��ַ���T" << endl;
    }
    cout << "�����:22������ϲ��" << endl;

    return 0;
}
