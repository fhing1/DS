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
            cout << p->data;
            if (p->next != nullptr) {
                cout << " + ";
            }
            p = p->next;
        }
        cout << endl;
    }

    // 获取单链表头结点
    ListNode<T>* getHead() {
        return head;
    }
};

// 定义一元多项式类
class Polynomial {
private:
    LinkList<pair<int, int>> polyList;  // 存储一元多项式的单链表

public:
    // 添加一元多项式的项
    void addItem(int coefficient, int exponent) {
        polyList.addNode(make_pair(coefficient, exponent));
    }

    // 相加两个一元多项式
    Polynomial add(Polynomial& other) {
        Polynomial result;

        ListNode<pair<int, int>>* p = polyList.getHead();
        ListNode<pair<int, int>>* q = other.polyList.getHead();

        while (p != nullptr && q != nullptr) {
            if (p->data.second == q->data.second) {
                int sum = p->data.first + q->data.first;
                if (sum != 0) {
                    result.addItem(sum, p->data.second);
                }
                p = p->next;
                q = q->next;
            }
            else if (p->data.second > q->data.second) {
                result.addItem(p->data.first, p->data.second);
                p = p->next;
            }
            else {
                result.addItem(q->data.first, q->data.second);
                q = q->next;
            }
        }

        while (p != nullptr) {
            result.addItem(p->data.first, p->data.second);
            p = p->next;
        }

        while (q != nullptr) {
            result.addItem(q->data.first, q->data.second);
            q = q->next;
        }

        return result;
    }

    // 输出一元多项式
    void print() {
        ListNode<pair<int, int>>* p = polyList.getHead();
        while (p != nullptr) {
            if (p->data.first != 0) {
                cout << p->data.first;
                if (p->data.second != 0) {
                    cout << "X" << p->data.second;
                }
                if (p->next != nullptr && p->next->data.first != 0) {
                    cout << " + ";
                }
            }
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    Polynomial poly1, poly2;

    // 输入第一个一元多项式的项
    cout << "请输入第一个一元多项式的项（输入系数和指数，以空格分隔，输入-1 -1表示结束输入）：" << endl;
    int coefficient, exponent;
    cin >> coefficient >> exponent;
    while (coefficient != -1 && exponent != -1) {
        poly1.addItem(coefficient, exponent);
        cin >> coefficient >> exponent;
    }

    // 输入第二个一元多项式的项
    cout << "请输入第二个一元多项式的项（输入系数和指数，以空格分隔，输入-1 -1表示结束输入）：" << endl;
    cin >> coefficient >> exponent;
    while (coefficient != -1 && exponent != -1) {
        poly2.addItem(coefficient, exponent);
        cin >> coefficient >> exponent;
    }

    cout << "第一个一元多项式：";
    poly1.print();

    cout << "第二个一元多项式：";
    poly2.print();

    Polynomial sum = poly1.add(poly2);

    cout << "合并后的一元多项式：";
    sum.print();
    cout << "完成人:22网工方喜健" << endl;
    return 0;
}
/*请输入第一个一元多项式的项（输入系数和指数，以空格分隔，输入-1 -1表示结束输入）：
12 6
-7 3
-8 2
100 0
-1 -1
请输入第二个一元多项式的项（输入系数和指数，以空格分隔，输入-1 -1表示结束输入）：
5 4
3 2
-2 0
-1 -1
第一个一元多项式：12X6 + -7X3 + -8X2 + 100
第二个一元多项式：5X4 + 3X2 + -2
合并后的一元多项式：12X6 + 5X4 + -7X3 + 3X2 + -8X2 + -2 + 100
*/