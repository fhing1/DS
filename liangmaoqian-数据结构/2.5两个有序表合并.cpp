#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node* next;
}Node, * LinkList;

int main() {
    LinkList l1 = new Node, l2 = new Node, l3 = new Node;
    l1->next = NULL;
    l2->next = NULL;
    l3->next = NULL;

    int x;

    Node* p = l1;
    cout << "������������������������������һλΪ������־λ��-1������������������:" << endl;
    cout << "��һ�飺" << endl;
    while (cin >> x && x != -1)
    {
        Node* s = new Node;
        s->data = x;
        s->next = NULL;
        p->next = s;
        p = p->next;
    }
    p = l2;
    cout << "�ڶ��飺" << endl;
    while (cin >> x && x != -1) {
        Node* s = new Node;
        s->data = x;
        s->next = NULL;
        p->next = s;
        p = p->next;

    }
    p = l1->next;
    Node* p2 = l2->next;
    Node* p3 = l3;

    while (p && p2) {
        if (p->data <= p2->data) {//ȡС��
            if (p->data != p3->data) {//�Ƚ��Ƿ�l3��l1���ظ���Ԫ��
                p3->next = p;
                p3 = p;
                p = p->next;
                p3->next = NULL;
            }
            else {//���ظ������������һ���ڵ�
                p = p->next;
            }
        }
        else {
            if (p2->data != p3->data) {//�Ƚ��Ƿ�l3��l2���ظ���Ԫ��
                p3->next = p2;
                p3 = p2;
                p2 = p2->next;
                p3->next = NULL;
            }
            else {//���ظ������������һ���ڵ�
                p2 = p2->next;
            }
        }
    }

    if (p) {
        while (p) {
            if (p->data != p3->data) {
                p3->next = p;
                p3 = p;
                p = p->next;
                p3->next = NULL;
            }
            else {
                p = p->next;
            }
        }

    }
    else if (p2) {
        while (p2) {
            if ((p2->data != p3->data)) {
                p3->next = p2;
                p3 = p2;
                p2 = p2->next;
                p3->next = NULL;//��ֹ���һ���ظ�
            }
            else {
                p2 = p2->next;
            }
        }
    }
    p3 = l3;
    p3 = p3->next;
    cout << "�ϲ��������ݺ�ĵ�����Ϊ��" << endl;
    if (p3 == NULL) {
        cout << "NULL";
    }
    else {
        while (p3 != NULL) {
            if (p3->next == NULL)
                cout << p3->data;
            else
                cout << p3->data << " ";
            p3 = p3->next;
        }
    }
    cout << endl;
    cout << "����ˣ�22�������Ƚ";
    return 0;
}
