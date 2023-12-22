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

    // 判断链表是否有序
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
};

int main() {
    LinkList<int> list;

    // 构造单链表
    list.addNode(5);
    list.addNode(3);
    list.addNode(8);
    list.addNode(-1);
    list.addNode(0);

    cout << "排序前：";
    list.traverse();

    // 判断链表是否有序
    if (list.isSorted()) {
        cout << "链表已经有序" << endl;
    }
    else {
        // 对链表进行排序
        list.insertionSort();
        cout << "排序后：";
        list.traverse();
    }
    cout << "完成人:22网工方喜健" << endl;
    return 0;
}
