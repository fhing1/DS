#include <iostream>
#include <queue>
using namespace std;

// �������ڵ���ģ��
template <typename T>
struct BiNode {
    T data;
    BiNode<T>* left;
    BiNode<T>* right;

    BiNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

// ��������ģ��
template <typename T>
class BiTree {
private:
    BiNode<T>* root;

public:
    // ���캯��
    BiTree() : root(nullptr) {}

    // �ݹ�ǰ�����
    void recursivePreOrder(BiNode<T>* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            recursivePreOrder(node->left);
            recursivePreOrder(node->right);
        }
    }

    // �ݹ��������
    void recursiveInOrder(BiNode<T>* node) {
        if (node != nullptr) {
            recursiveInOrder(node->left);
            cout << node->data << " ";
            recursiveInOrder(node->right);
        }
    }

    // �ݹ�������
    void recursivePostOrder(BiNode<T>* node) {
        if (node != nullptr) {
            recursivePostOrder(node->left);
            recursivePostOrder(node->right);
            cout << node->data << " ";
        }
    }

    // �������
    void levelOrder(BiNode<T>* root) {
        if (root == nullptr)
            return;

        queue<BiNode<T>*> q;
        q.push(root);

        while (!q.empty()) {
            BiNode<T>* node = q.front();
            q.pop();
            cout << node->data << " ";

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    // ���з��������ڵ���˽�з�����ʼ����
    void recursivePreOrder() {
        cout << "�ݹ�ǰ�������";
        recursivePreOrder(root);
        cout << endl;
    }

    void recursiveInOrder() {
        cout << "�ݹ����������";
        recursiveInOrder(root);
        cout << endl;
    }

    void recursivePostOrder() {
        cout << "�ݹ���������";
        recursivePostOrder(root);
        cout << endl;
    }

    void levelOrder() {
        cout << "���������";
        levelOrder(root);
        cout << endl;
    }

    // ���ø��ڵ�
    void setRoot(BiNode<T>* newRoot) {
        root = newRoot;
    }
};

int main() {
    // ������������A��������ΪB��������ΪC��C��������ΪD��
    BiTree<char> tree;
    BiNode<char>* root = new BiNode<char>('A');
    root->left = new BiNode<char>('B');
    root->right = new BiNode<char>('C');
    root->right->left = new BiNode<char>('D');

    tree.setRoot(root);
    cout << "������������A��������ΪB��������ΪC��C��������ΪD��" << endl;

    // ��֤��������
    tree.recursivePreOrder();
    tree.recursiveInOrder();
    tree.recursivePostOrder();
    tree.levelOrder();
    cout << "�����:22������ϲ��" << endl;
    return 0;
}
