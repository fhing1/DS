#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class SeqStack {
private:
    T* data;
    int top;  // 栈顶指针
    int maxSize;  // 栈的最大容量

public:
    SeqStack(int size) {
        data = new T[size];
        top = -1;
        maxSize = size;
    }
    ~SeqStack() {
        delete[] data;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == maxSize - 1;
    }

    void push(T item) {
        if (isFull()) {
            cout << "栈已满，无法入栈！" << endl;
            return;
        }
        top++;
        data[top] = item;
    }
    T pop() {
        if (isEmpty()) {
            cout << "栈为空，无法出栈！" << endl;
            return NULL;
        }
        T item = data[top];
        top--;
        return item;
    }
};

void decimalToBase(int decimal, int base) {
    SeqStack<char> stack(100);
    char digit[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

    while (decimal > 0) {
        stack.push(digit[decimal % base]);
        decimal /= base;
    }

    cout << "转换结果为：";
    while (!stack.isEmpty()) {
        cout << stack.pop();
    }
    cout << endl;
}

int main() {
    int decimal, base;
    cout << "请输入一个非负的十进制数：";
    cin >> decimal;
    cout << "请输入要转换的进制（2-16）：";
    cin >> base;

    if (base < 2 || base > 16) {
        cout << "错误的进制数！" << endl;
        return 0;
    }

    decimalToBase(decimal, base);
cout<<endl<<"完成人：22网工李浩冉"<<endl;
    return 0;
}
