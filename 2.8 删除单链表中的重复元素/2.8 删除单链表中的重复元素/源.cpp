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

    // β�巨��ӽ��
    void addNode(T value) {
        ListNode<T>* newNode = new ListNode<T>(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            ListNode<T>* p = head;
            while (p->next != nullptr) {
                p = p->next;
            }
            p->next = newNode;
        }
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

    // ɾ���������е��ظ�Ԫ��
    void removeDuplicates() {
        if (head == nullptr) {
            return;
        }

        ListNode<T>* p = head;
        while (p != nullptr && p->next != nullptr) {
            ListNode<T>* q = p;
            while (q->next != nullptr) {
                if (q->next->data == p->data) {
                    ListNode<T>* tmp = q->next;
                    q->next = q->next->next;
                    delete tmp;
                }
                else {
                    q = q->next;
                }
            }
            p = p->next;
        }
    }
};

int main() {
    LinkList<int> list;

    // ���뵥�����ֵ
    cout << "�����뵥�����ֵ������-1��ʾ�������룩��" << endl;
    int value;
    cin >> value;
    while (value != -1) {
        list.addNode(value);
        cin >> value;
    }

    cout << "ɾ��ǰ�ĵ�����";
    list.traverse();
    
    list.removeDuplicates();

    cout << "ɾ����ĵ�����";
    list.traverse();
    cout << "�����:22������ϲ��" << endl;
    return 0;
}
