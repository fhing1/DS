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
    // ���캯��
    LinkQueue() : front(nullptr), rear(nullptr) {}

    // ��������
    ~LinkQueue() {
        while (front != nullptr) {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // ��Ӳ���
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
        cout << "Ԫ�� " << value << " ��ӳɹ���" << endl;
    }

    // ���Ӳ���
    T dequeue() {
        if (front == nullptr) {
            cout << "�����ѿգ��޷����ӣ�" << endl;
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
            cout << "Ԫ�� " << data << " ���ӳɹ���" << endl;
            return data;
        }
    }

    // ��ȡ��ͷԪ��
    T getFront() const {
        if (front == nullptr) {
            cout << "�����ѿգ��޷���ȡ��ͷԪ�أ�" << endl;
            return T();
        }
        else {
            return front->data;
        }
    }

    // �ж϶����Ƿ�Ϊ��
    bool isEmpty() const {
        return (front == nullptr);
    }
};

int main() {
    // ���������ж���
    LinkQueue<int> queue;

    // ������ܲ˵����ȴ��û�ѡ�����
    cout << "��ӭʹ��������ģ�����" << endl;
    while (true) {
        cout << "��ѡ��Ҫ���еĲ�����" << endl;
        cout << "1. ���" << endl;
        cout << "2. ����" << endl;
        cout << "3. ��ȡ��ͷԪ��" << endl;
        cout << "4. �ж϶����Ƿ�Ϊ��" << endl;
        cout << "0. �˳�����" << endl;
        cout << "�����:22������ϲ��" << endl;

        // �����û�ѡ��Ĳ������
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "������Ҫ��ӵ�Ԫ��ֵ��";
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
            cout << "��ǰ��ͷԪ��Ϊ��" << front_value << endl;
            break;
        }
        case 4: {
            bool is_empty = queue.isEmpty();
            if (is_empty) {
                cout << "����Ϊ�գ�" << endl;
            }
            else {
                cout << "���в�Ϊ�գ�" << endl;
            }
            break;
        }
        case 0: {
            cout << "�������˳���" << endl;
            return 0;
        }
        default: {
            cout << "����Ĳ��������Ч�����������룡" << endl;
            break;
        }
        }
    }

    // ���������ж������������ᱻ�Զ����ã�
    return 0;
}
