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
    cout << "请输入两组有序单链表，其中输入的最后一位为结束标志位“-1”他不包括在链表中:" << endl;
    cout << "第一组：" << endl;
    while (cin >> x && x != -1)
    {
        Node* s = new Node;
        s->data = x;
        s->next = NULL;
        p->next = s;
        p = p->next;
    }
    p = l2;
    cout << "第二组：" << endl;
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
        if (p->data <= p2->data) {//取小的
            if (p->data != p3->data) {//比较是否l3与l1有重复的元素
                p3->next = p;
                p3 = p;
                p = p->next;
                p3->next = NULL;
            }
            else {//若重复相等则跳过下一个节点
                p = p->next;
            }
        }
        else {
            if (p2->data != p3->data) {//比较是否l3与l2有重复的元素
                p3->next = p2;
                p3 = p2;
                p2 = p2->next;
                p3->next = NULL;
            }
            else {//若重复相等则跳过下一个节点
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
                p3->next = NULL;//防止最后一个重复
            }
            else {
                p2 = p2->next;
            }
        }
    }
    p3 = l3;
    p3 = p3->next;
    cout << "合并两组数据后的单链表为：" << endl;
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
    cout << "完成人：22网工李浩冉";
    return 0;
}
