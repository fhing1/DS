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
            return i;  // 匹配成功，返回逻辑位置
        }
    }

    return -1;  // 匹配失败，返回-1
}

int main() {
    const char* S = "ABCABABCD";
    const char* T = "ABCD";
    int position = bfMatch(S, T);
    cout << "目标串(S):ABCABABCD" << endl;
    cout << "模式串(T):ABCD" << endl;

    if (position != -1) {
        cout << "在字符串S中找到了字符串T，起始位置为: " << position << endl;
    }
    else {
        cout << "在字符串S中未找到字符串T" << endl;
    }
    cout << "完成人:22网工方喜健" << endl;

    return 0;
}
