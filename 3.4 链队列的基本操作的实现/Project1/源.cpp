#include <iostream>

using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

template <class T>
class LinkQueue {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    // 构造函数
    LinkQueue() : front(nullptr), rear(nullptr) {}

    // 析构函数
    ~LinkQueue() {
        while (front != nullptr) {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // 入队操作
    void enqueue(const T& value) {
        Node<T>* new_node = new Node<T>(value);
        if (front == nullptr) {
            front = new_node;
            rear = new_node;
        }
        else {
            rear->next = new_node;
            rear = new_node;
        }
        cout << "元素 " << value << " 入队成功！" << endl;
    }

    // 出队操作
    T dequeue() {
        if (front == nullptr) {
            cout << "队列已空，无法出队！" << endl;
            return T();
        }
        else {
            T data = front->data;
            Node<T>* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
            cout << "元素 " << data << " 出队成功！" << endl;
            return data;
        }
    }

    // 获取队头元素
    T getFront() const {
        if (front == nullptr) {
            cout << "队列已空，无法获取队头元素！" << endl;
            return T();
        }
        else {
            return front->data;
        }
    }

    // 判断队列是否为空
    bool isEmpty() const {
        return (front == nullptr);
    }
};

int main() {
    // 创建链队列对象
    LinkQueue<int> queue;

    // 输出功能菜单，等待用户选择操作
    cout << "欢迎使用链队列模板程序！" << endl;
    while (true) {
        cout << "请选择要进行的操作：" << endl;
        cout << "1. 入队" << endl;
        cout << "2. 出队" << endl;
        cout << "3. 获取队头元素" << endl;
        cout << "4. 判断队列是否为空" << endl;
        cout << "0. 退出程序" << endl;
        cout << "完成人:22网工方喜健" << endl;

        // 读入用户选择的操作编号
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "请输入要入队的元素值：";
            int value;
            cin >> value;
            queue.enqueue(value);
            break;
        }
        case 2: {
            queue.dequeue();
            break;
        }
        case 3: {
            int front_value = queue.getFront();
            cout << "当前队头元素为：" << front_value << endl;
            break;
        }
        case 4: {
            bool is_empty = queue.isEmpty();
            if (is_empty) {
                cout << "队列为空！" << endl;
            }
            else {
                cout << "队列不为空！" << endl;
            }
            break;
        }
        case 0: {
            cout << "程序已退出！" << endl;
            return 0;
        }
        default: {
            cout << "输入的操作编号无效，请重新输入！" << endl;
            break;
        }
        }
    }

    // 销毁链队列对象（析构函数会被自动调用）
    return 0;
}
