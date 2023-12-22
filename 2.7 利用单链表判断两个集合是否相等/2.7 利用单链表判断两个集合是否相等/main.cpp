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

    // �ж������������Ƿ����
    bool isEqual(LinkList<T>& other) {
        if (head == nullptr && other.head == nullptr) {
            return true;
        }
        if (head == nullptr || other.head == nullptr) {
            return false;
        }

        // �������������������
        insertionSort();
        other.insertionSort();

        ListNode<T>* p = head;
        ListNode<T>* q = other.head;
        while (p != nullptr && q != nullptr) {
            if (p->data != q->data) {
                return false;
            }
            p = p->next;
            q = q->next;
        }
        return p == nullptr && q == nullptr;
    }
};

int main() {
    LinkList<int> set1;
    LinkList<int> set2;

    // ���켯��1
    set1.addNode(5);
    set1.addNode(3);
    set1.addNode(8);
    set1.addNode(-1);
    set1.addNode(0);

    // ���켯��2
    set2.addNode(5);
    set2.addNode(3);
    set2.addNode(8);
    set2.addNode(-1);
    set2.addNode(9);

    cout << "����1��";
    set1.traverse();
    cout << "����2��";
    set2.traverse();

    if (set1.isEqual(set2)) {
        cout << "����1�ͼ���2���" << endl;
    }
    else {
        cout << "����1�ͼ���2�����" << endl;
    }
    cout << "�����:22������ϲ��" << endl;
    return 0;
}
