#include <iostream>
using namespace std;

void hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        cout << "将第" << n << "个盘子从" << a << "移动到" << c << endl;
    }
    else {
        hanoi(n - 1, a, c, b);
        cout << "将第" << n << "个盘子从" << a << "移动到" << c << endl;
        hanoi(n - 1, b, a, c);
    }
}

int main() {
    int n;
    cout << "请输入盘子的个数：";
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
 cout<<endl<<"完成人：22网工李浩冉"<<endl;
    return 0;
}
