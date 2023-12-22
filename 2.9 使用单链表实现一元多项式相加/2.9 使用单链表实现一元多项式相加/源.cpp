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
            cout << p->data;
            if (p->next != nullptr) {
                cout << " + ";
            }
            p = p->next;
        }
        cout << endl;
    }

    // ��ȡ������ͷ���
    ListNode<T>* getHead() {
        return head;
    }
};

// ����һԪ����ʽ��
class Polynomial {
private:
    LinkList<pair<int, int>> polyList;  // �洢һԪ����ʽ�ĵ�����

public:
    // ���һԪ����ʽ����
    void addItem(int coefficient, int exponent) {
        polyList.addNode(make_pair(coefficient, exponent));
    }

    // �������һԪ����ʽ
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

    // ���һԪ����ʽ
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

    // �����һ��һԪ����ʽ����
    cout << "�������һ��һԪ����ʽ�������ϵ����ָ�����Կո�ָ�������-1 -1��ʾ�������룩��" << endl;
    int coefficient, exponent;
    cin >> coefficient >> exponent;
    while (coefficient != -1 && exponent != -1) {
        poly1.addItem(coefficient, exponent);
        cin >> coefficient >> exponent;
    }

    // ����ڶ���һԪ����ʽ����
    cout << "������ڶ���һԪ����ʽ�������ϵ����ָ�����Կո�ָ�������-1 -1��ʾ�������룩��" << endl;
    cin >> coefficient >> exponent;
    while (coefficient != -1 && exponent != -1) {
        poly2.addItem(coefficient, exponent);
        cin >> coefficient >> exponent;
    }

    cout << "��һ��һԪ����ʽ��";
    poly1.print();

    cout << "�ڶ���һԪ����ʽ��";
    poly2.print();

    Polynomial sum = poly1.add(poly2);

    cout << "�ϲ����һԪ����ʽ��";
    sum.print();
    cout << "�����:22������ϲ��" << endl;
    return 0;
}
/*�������һ��һԪ����ʽ�������ϵ����ָ�����Կո�ָ�������-1 -1��ʾ�������룩��
12 6
-7 3
-8 2
100 0
-1 -1
������ڶ���һԪ����ʽ�������ϵ����ָ�����Կո�ָ�������-1 -1��ʾ�������룩��
5 4
3 2
-2 0
-1 -1
��һ��һԪ����ʽ��12X6 + -7X3 + -8X2 + 100
�ڶ���һԪ����ʽ��5X4 + 3X2 + -2
�ϲ����һԪ����ʽ��12X6 + 5X4 + -7X3 + 3X2 + -8X2 + -2 + 100
*/