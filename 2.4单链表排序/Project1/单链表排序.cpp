#include <iostream>
using namespace std;

// ���嵥��������
template<class T>
class ListNode {
public:
    T data;
    ListNode<T>* next;

    ListNode(T value) : data(value), next(nullptr) {}
};

// ���嵥������
template<class T>
class LinkList {
private:
    ListNode<T>* head;  // ͷ���

public:
    // ���캯��
    LinkList() : head(nullptr) {}

    // ͷ�巨��ӽ��
    void addNode(T value) {
        ListNode<T>* newNode = new ListNode<T>(value);
        newNode->next = head;
        head = newNode;
    }

    // ����������
    void traverse() {
        ListNode<T>* p = head;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // �ж������Ƿ�����
    bool isSorted() {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode<T>* p = head;
        while (p->next != nullptr) {
            if (p->data > p->next->data) {
                return false;
            }
            p = p->next;
        }
        return true;
    }

    // ֱ�Ӳ�������
    void insertionSort() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        ListNode<T>* p = head->next;
        head->next = nullptr;
        while (p != nullptr) {
            ListNode<T>* q = head;
            ListNode<T>* pre = nullptr;
            while (q != nullptr && q->data < p->data) {
                pre = q;
                q = q->next;
            }
            if (pre == nullptr) {
                head = p;
            }
            else {
                pre->next = p;
            }
            ListNode<T>* tmp = p->next;
            p->next = q;
            p = tmp;
        }
    }
};

int main() {
    LinkList<int> list;

    // ���쵥����
    list.addNode(5);
    list.addNode(3);
    list.addNode(8);
    list.addNode(-1);
    list.addNode(0);

    cout << "����ǰ��";
    list.traverse();

    // �ж������Ƿ�����
    if (list.isSorted()) {
        cout << "�����Ѿ�����" << endl;
    }
    else {
        // �������������
        list.insertionSort();
        cout << "�����";
        list.traverse();
    }
    cout << "�����:22������ϲ��" << endl;
    return 0;
}
