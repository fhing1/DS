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

    // 头插法添加结点
    void addNode(T value) {
        ListNode<T>* newNode = new ListNode<T>(value);
        newNode->next = head;
        head = newNode;
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

    // 直接插入排序
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

    // 判断两个单链表是否相等
    bool isEqual(LinkList<T>& other) {
        if (head == nullptr && other.head == nullptr) {
            return true;
        }
        if (head == nullptr || other.head == nullptr) {
            return false;
        }

        // 对两个单链表进行排序
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

    // 构造集合1
    set1.addNode(5);
    set1.addNode(3);
    set1.addNode(8);
    set1.addNode(-1);
    set1.addNode(0);

    // 构造集合2
    set2.addNode(5);
    set2.addNode(3);
    set2.addNode(8);
    set2.addNode(-1);
    set2.addNode(9);

    cout << "集合1：";
    set1.traverse();
    cout << "集合2：";
    set2.traverse();

    if (set1.isEqual(set2)) {
        cout << "集合1和集合2相等" << endl;
    }
    else {
        cout << "集合1和集合2不相等" << endl;
    }
    cout << "完成人:22网工方喜健" << endl;
    return 0;
}
