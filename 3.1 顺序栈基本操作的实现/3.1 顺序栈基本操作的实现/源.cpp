#include <iostream>
using namespace std;

template<class T>
class SeqStack {
private:
    T* data;  // 数据元素存储数组
    int maxSize;  // 栈的最大容量
    int topIndex;  // 栈顶元素下标

public:
    // 构造函数
    SeqStack(int size) {
        data = new T[size];
        maxSize = size;
        topIndex = -1;
    }

    // 取栈顶元素
    T getTop() {
        if (isEmpty()) {
            cerr << "栈为空，无法取栈顶元素" << endl;
            exit(1);
        }
        return data[topIndex];
    }

    // 出栈
    void pop() {
        if (isEmpty()) {
            cerr << "栈为空，无法执行出栈操作" << endl;
            exit(1);
        }
        topIndex--;
    }

    // 入栈
    void push(T value) {
        if (isFull()) {
            cerr << "栈已满，无法执行入栈操作" << endl;
            exit(1);
        }
        topIndex++;
        data[topIndex] = value;
    }

    // 判断栈是否为空
    bool isEmpty() {
        return topIndex == -1;
    }

    // 判断栈是否已满
    bool isFull() {
        return topIndex == maxSize - 1;
    }
};

int main() {
    SeqStack<int> stack(5);

    // 入栈
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    cout << "当前栈内元素" << endl;
    while (!stack.isEmpty()) {
        cout << stack.getTop() << endl;
        stack.pop();
    }
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    // 判断栈是否已满
    if (stack.isFull()) {
        cout << "栈已满" << endl;
    }

    // 取栈顶元素
    cout << "栈顶元素为：" << stack.getTop() << endl;
    cout << "栈顶出栈后,栈内元素：" << endl;
    // 出栈
    stack.pop();
   
    // 判断栈是否为空
    if (stack.isEmpty()) {
        cout << "栈为空" << endl;
    }

    // 遍历栈并输出元素
    while (!stack.isEmpty()) {
        cout << stack.getTop() << endl;
        stack.pop();
    }
    cout << "完成人：22网工方喜健" << endl;
    return 0;
}
