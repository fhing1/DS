#include <iostream>
using namespace std;

// 定义单链表结点类
template<class T>
class ListNode {
public:
    T data;
    ListNode<T>* next;

    ListNode(T value) : data(value), next(nullptr) {}
};

// 定义单链表类
template<class T>
class LinkList {
private:
    ListNode<T>* head;  // 头结点

public:
    // 构造函数
    LinkList() : head(nullptr) {}

    // 尾插法添加结点
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

    // 遍历单链表
    void traverse() {
        ListNode<T>* p = head;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // 删除单链表中的重复元素
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

    // 输入单链表的值
    cout << "请输入单链表的值（输入-1表示结束输入）：" << endl;
    int value;
    cin >> value;
    while (value != -1) {
        list.addNode(value);
        cin >> value;
    }

    cout << "删除前的单链表：";
    list.traverse();
    
    list.removeDuplicates();

    cout << "删除后的单链表：";
    list.traverse();
    cout << "完成人:22网工方喜健" << endl;
    return 0;
}
