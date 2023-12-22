#include <iostream>
#include <stack>

using namespace std;

// �������ڵ�ṹ
template <typename t>
struct bitreenode {
    t data;
    bitreenode* left;
    bitreenode* right;

    bitreenode(t value) : data(value), left(nullptr), right(nullptr) {}
};

// ��������ģ��
template <typename t>
class bitree {
private:
    bitreenode<t>* root;

public:
    // ���캯��
    bitree() : root(nullptr) {}

    // ����ڵ�
    void insertnode(t value) {
        root = insertnoderecursive(root, value);
    }

    // �ǵݹ�ǰ�����
    void nonrecursivepreordertraversal() {
        stack<bitreenode<t>*> nodestack;
        bitreenode<t>* currentnode = root;

        while (currentnode || !nodestack.empty()) {
            while (currentnode) {
                cout << currentnode->data << " ";
                nodestack.push(currentnode);
                currentnode = currentnode->left;
            }

            if (!nodestack.empty()) {
                currentnode = nodestack.top();
                nodestack.pop();
                currentnode = currentnode->right;
            }
        }

        cout << endl;
    }

    // �ǵݹ��������
    void nonrecursiveinordertraversal() {
        stack<bitreenode<t>*> nodestack;
        bitreenode<t>* currentnode = root;

        while (currentnode || !nodestack.empty()) {
            while (currentnode) {
                nodestack.push(currentnode);
                currentnode = currentnode->left;
            }

            if (!nodestack.empty()) {
                currentnode = nodestack.top();
                nodestack.pop();
                cout << currentnode->data << " ";
                currentnode = currentnode->right;
            }
        }

        cout << endl;
    }

    // �ǵݹ�������
    void nonrecursivepostordertraversal() {
        if (!root)
            return;

        stack<bitreenode<t>*> nodestack;
        stack<bitreenode<t>*> outputstack;
        nodestack.push(root);

        while (!nodestack.empty()) {
            bitreenode<t>* currentnode = nodestack.top();
            nodestack.pop();
            outputstack.push(currentnode);

            if (currentnode->left)
                nodestack.push(currentnode->left);
            if (currentnode->right)
                nodestack.push(currentnode->right);
        }

        while (!outputstack.empty()) {
            cout << outputstack.top()->data << " ";
            outputstack.pop();
        }

        cout << endl;
    }

private:
    // �ݹ����ڵ�
    bitreenode<t>* insertnoderecursive(bitreenode<t>* node, t value) {
        if (!node) {
            return new bitreenode<t>(value);
        }

        if (value < node->data) {
            node->left = insertnoderecursive(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertnoderecursive(node->right, value);
        }

        return node;
    }
};

int main() {
    // ����������
    bitree<char> tree;
    tree.insertnode('a');
    tree.insertnode('b');
    tree.insertnode('c');
    tree.insertnode('d');

    // �ǵݹ�ǰ�����
    cout << "�ǵݹ�ǰ�����: ";
    tree.nonrecursivepreordertraversal();

    // �ǵݹ��������
    cout << "�ǵݹ��������: ";
    tree.nonrecursiveinordertraversal();

    // �ǵݹ�������
    cout << "�ǵݹ�������: ";
    tree.nonrecursivepostordertraversal();
    cout <<endl<< "����ˣ�22�������Ƚ"<<endl;
    return 0;
}
