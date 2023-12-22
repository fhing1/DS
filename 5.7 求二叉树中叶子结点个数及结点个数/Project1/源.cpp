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
        cout << "请输入根节点的值（空节点用#代替）：" << endl;
        root = create_node();

        cout << "二叉树创建成功！" << endl;
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
        if (!node) return 0; // 空节点不计入叶子结点

        if (!node->left && !node->right) {
            return 1; // 只有一个左孩子和右孩子为空的节点为叶子结点
        }

        return count_leaves(node->left) + count_leaves(node->right);
    }

    int count_nodes(Node* node) {
        if (!node) return 0; // 空节点不计入结点个数

        return 1 + count_nodes(node->left) + count_nodes(node->right);
    }
};

int main() {
    BiTree<char> tree;  // 将 BiTree<int> 修改为 BiTree<char>
    tree.create_tree();

    int leaf_count = tree.count_leaves();
    int node_count = tree.count_nodes();

    cout << "叶子结点个数：" << leaf_count << endl;
    cout << "结点个数：" << node_count << endl;
    cout << "完成人:22网工方喜健" << endl;
    return 0;
}
