#include <iostream>
using namespace std;

template <class T>
class InThrBiTree {
public:  // �� BiThrNode �ṹ����Ϊ����
    struct BiThrNode {
        T data;
        BiThrNode* left;
        BiThrNode* right;
        int ltag, rtag;  // ������־

        BiThrNode(T value) : data(value), left(nullptr), right(nullptr), ltag(0), rtag(0) {}
    };

private:
    BiThrNode* root;  // �����
    BiThrNode* pre;   // ������ʱ��¼ǰһ�����ʵĽ��

    // ��������������ʹ�õĵݹ麯��
    void InThreading(BiThrNode* p) {
        if (p != nullptr) {
            InThreading(p->left);  // �ݹ�������������

            if (p->left == nullptr) {
                p->ltag = 1;         // ��ָ��Ϊ�գ�����ǰ������
                p->left = pre;
            }
            if (pre != nullptr && pre->right == nullptr) {
                pre->rtag = 1;       // �����������
                pre->right = p;
            }

            pre = p;               // ����ǰһ�����ʵĽ��

            InThreading(p->right);  // �ݹ�������������
        }
    }

public:
    InThrBiTree() : root(nullptr), pre(nullptr) {}

    void CreateInThrBiTree() {
        root = new BiThrNode('A');
        root->left = new BiThrNode('B');
        root->right = new BiThrNode('C');
        root->left->left = new BiThrNode('D');
        root->left->right = new BiThrNode('E');
        root->right->left = new BiThrNode('F');
        root->right->right = new BiThrNode('G');
        // ������Ҫ���䴴���������Ĵ���
        // ���磺root = new BiThrNode(value);
        //      root->left = new BiThrNode(value);
        //      root->right = new BiThrNode(value);
        //      ...
    }

    // ����������
    void InOrderThreading() {
        if (root == nullptr) {
            cout << "��Ϊ�գ��޷���������" << endl;
            return;
        }
        InThreading(root);    // ��ʼ������
        pre->right = nullptr;  // ������������һ����㣬������ָ����Ϊ��
    }

    // �ǵݹ������������������
    void InOrderTraverse() const {
        BiThrNode* p = root;
        while (p != nullptr) {
            // Ѱ����������ĵ�һ�����
            while (p->ltag == 0) {
                p = p->left;
            }
            cout << p->data << " ";  // ���ʽ��

            // ����ָ������������������������һ�����
            while (p->rtag == 1 && p->right != nullptr) {
                p = p->right;
                cout << p->data << " ";  // ���ʽ��
            }

            // ����ת��������
            p = p->right;
        }
    }

    // ��ȡ�����
    BiThrNode* GetRoot() const {
        return root;
    }

    // ��ȡ�ض�ֵ�Ľ��
    BiThrNode* GetNode(T value) const {
        return GetNode(root, value);
    }

    // ��ȡ�ض�ֵ�Ľ��ĸ�������
    BiThrNode* GetNode(BiThrNode* p, T value) const {
        if (p != nullptr) {
            if (p->data == value) {
                return p;
            }
            BiThrNode* leftNode = GetNode(p->left, value);
            if (leftNode != nullptr) {
                return leftNode;
            }
            BiThrNode* rightNode = GetNode(p->right, value);
            return rightNode;
        }
        return nullptr;
    }
};

int main() {
    InThrBiTree<char> tree;
    tree.CreateInThrBiTree();


    // �������������������ʵ��������д���
    // ʾ����tree.CreateInThrBiTree();

    // ����������
    tree.InOrderThreading();

    // �ǵݹ������������������
    cout << "���������������ı��������" << endl;
    tree.InOrderTraverse();
    cout << endl;

    // ��ȡ�ض�ֵ�Ľ��
    InThrBiTree<char>::BiThrNode* nodeD = tree.GetNode('D');
    if (nodeD != nullptr) {
        cout << "�ҵ����D��" << nodeD->data << endl;
    }
    else {
        cout << "δ�ҵ����D" << endl;
    }
    cout << "�����22������ϲ��" << endl;
    return 0;
}
