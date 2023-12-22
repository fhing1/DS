#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class SeqStack {
private:
    T* data;
    int top;  // ջ��ָ��
    int maxSize;  // ջ���������

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
            cout << "ջ�������޷���ջ��" << endl;
            return;
        }
        top++;
        data[top] = item;
    }
    T pop() {
        if (isEmpty()) {
            cout << "ջΪ�գ��޷���ջ��" << endl;
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

    cout << "ת�����Ϊ��";
    while (!stack.isEmpty()) {
        cout << stack.pop();
    }
    cout << endl;
}

int main() {
    int decimal, base;
    cout << "������һ���Ǹ���ʮ��������";
    cin >> decimal;
    cout << "������Ҫת���Ľ��ƣ�2-16����";
    cin >> base;

    if (base < 2 || base > 16) {
        cout << "����Ľ�������" << endl;
        return 0;
    }

    decimalToBase(decimal, base);
cout<<endl<<"����ˣ�22�������Ƚ"<<endl;
    return 0;
}
