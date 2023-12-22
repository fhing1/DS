#include <iostream>
using namespace std;

template<class T>
class SeqStack {
private:
    T* data;  // ����Ԫ�ش洢����
    int maxSize;  // ջ���������
    int topIndex;  // ջ��Ԫ���±�

public:
    // ���캯��
    SeqStack(int size) {
        data = new T[size];
        maxSize = size;
        topIndex = -1;
    }

    // ȡջ��Ԫ��
    T getTop() {
        if (isEmpty()) {
            cerr << "ջΪ�գ��޷�ȡջ��Ԫ��" << endl;
            exit(1);
        }
        return data[topIndex];
    }

    // ��ջ
    void pop() {
        if (isEmpty()) {
            cerr << "ջΪ�գ��޷�ִ�г�ջ����" << endl;
            exit(1);
        }
        topIndex--;
    }

    // ��ջ
    void push(T value) {
        if (isFull()) {
            cerr << "ջ�������޷�ִ����ջ����" << endl;
            exit(1);
        }
        topIndex++;
        data[topIndex] = value;
    }

    // �ж�ջ�Ƿ�Ϊ��
    bool isEmpty() {
        return topIndex == -1;
    }

    // �ж�ջ�Ƿ�����
    bool isFull() {
        return topIndex == maxSize - 1;
    }
};

int main() {
    SeqStack<int> stack(5);

    // ��ջ
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    cout << "��ǰջ��Ԫ��" << endl;
    while (!stack.isEmpty()) {
        cout << stack.getTop() << endl;
        stack.pop();
    }
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    // �ж�ջ�Ƿ�����
    if (stack.isFull()) {
        cout << "ջ����" << endl;
    }

    // ȡջ��Ԫ��
    cout << "ջ��Ԫ��Ϊ��" << stack.getTop() << endl;
    cout << "ջ����ջ��,ջ��Ԫ�أ�" << endl;
    // ��ջ
    stack.pop();
   
    // �ж�ջ�Ƿ�Ϊ��
    if (stack.isEmpty()) {
        cout << "ջΪ��" << endl;
    }

    // ����ջ�����Ԫ��
    while (!stack.isEmpty()) {
        cout << stack.getTop() << endl;
        stack.pop();
    }
    cout << "����ˣ�22������ϲ��" << endl;
    return 0;
}
