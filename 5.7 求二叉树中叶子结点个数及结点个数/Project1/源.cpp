#include <iostream>
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

    int count_leaves() {
        return count_leaves(root);
    }

    int count_nodes() {
        return count_nodes(root);
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

    int count_leaves(Node* node) {
        if (!node) return 0; // �սڵ㲻����Ҷ�ӽ��

        if (!node->left && !node->right) {
            return 1; // ֻ��һ�����Ӻ��Һ���Ϊ�յĽڵ�ΪҶ�ӽ��
        }

        return count_leaves(node->left) + count_leaves(node->right);
    }

    int count_nodes(Node* node) {
        if (!node) return 0; // �սڵ㲻���������

        return 1 + count_nodes(node->left) + count_nodes(node->right);
    }
};

int main() {
    BiTree<char> tree;  // �� BiTree<int> �޸�Ϊ BiTree<char>
    tree.create_tree();

    int leaf_count = tree.count_leaves();
    int node_count = tree.count_nodes();

    cout << "Ҷ�ӽ�������" << leaf_count << endl;
    cout << "��������" << node_count << endl;
    cout << "�����:22������ϲ��" << endl;
    return 0;
}
