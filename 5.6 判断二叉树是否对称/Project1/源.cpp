#include <iostream>
#include <stack>
using namespace std;

template<class T>
class BiTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T data) : data(data), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    BiTree() : root(nullptr) {}

    void create_tree() {
        cout << "��������ڵ��ֵ���սڵ���#���棩��" << endl;
        root = create_node();

        cout << "�����������ɹ���" << endl;
    }

    bool is_symmetric() {
        if (!root) return true; // ������ڵ�Ϊ�գ�����Ϊ�ǶԳƵ�

        stack<Node*> s1, s2;

        // ��������ջs1����������ջs2
        s1.push(root->left);
        s2.push(root->right);

        while (!s1.empty() && !s2.empty()) {
            Node* node1 = s1.top();
            s1.pop();
            Node* node2 = s2.top();
            s2.pop();

            if (!node1 && !node2) {
                continue;
            }
            else if (!node1 || !node2 || node1->data != node2->data) {
                return false;
            }

            s1.push(node1->left);
            s2.push(node2->right);

            s1.push(node1->right);
            s2.push(node2->left);
        }

        return true;
    }

private:
    Node* create_node() {
        T data;
        cin >> data;

        if (data == '#') return nullptr;

        Node* node = new Node(data);
        node->left = create_node();
        node->right = create_node();

        return node;
    }
};

int main() {
    BiTree<char> tree;
    tree.create_tree();

    bool is_symmetric = tree.is_symmetric();
    if (is_symmetric) {
        cout << "�������ǶԳƵģ�" << endl;
    }
    else {
        cout << "���������ǶԳƵģ�" << endl;
    }
    cout << "�����:22������ϲ��" << endl;
    return 0;
}
