#include <iostream>
using namespace std;

void hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        cout << "����" << n << "�����Ӵ�" << a << "�ƶ���" << c << endl;
    }
    else {
        hanoi(n - 1, a, c, b);
        cout << "����" << n << "�����Ӵ�" << a << "�ƶ���" << c << endl;
        hanoi(n - 1, b, a, c);
    }
}

int main() {
    int n;
    cout << "���������ӵĸ�����";
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
 cout<<endl<<"����ˣ�22�������Ƚ"<<endl;
    return 0;
}
