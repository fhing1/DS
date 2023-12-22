#include <iostream>
#include <queue>
using namespace std;

// 二叉树节点类模板
template <typename T>
struct BiNode {
    T data;
    BiNode<T>* left;
    BiNode<T>* right;

    BiNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

// 二叉树类模板
template <typename T>
class BiTree {
private:
    BiNode<T>* root;

public:
    // 构造函数
    BiTree() : root(nullptr) {}

    // 递归前序遍历
    void recursivePreOrder(BiNode<T>* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            recursivePreOrder(node->left);
            recursivePreOrder(node->right);
        }
    }

    // 递归中序遍历
    void recursiveInOrder(BiNode<T>* node) {
        if (node != nullptr) {
            recursiveInOrder(node->left);
            cout << node->data << " ";
            recursiveInOrder(node->right);
        }
    }

    // 递归后序遍历
    void recursivePostOrder(BiNode<T>* node) {
        if (node != nullptr) {
            recursivePostOrder(node->left);
            recursivePostOrder(node->right);
            cout << node->data << " ";
        }
    }

    // 层序遍历
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

    // 公有方法，用于调用私有方法开始遍历
    void recursivePreOrder() {
        cout << "递归前序遍历：";
        recursivePreOrder(root);
        cout << endl;
    }

    void recursiveInOrder() {
        cout << "递归中序遍历：";
        recursiveInOrder(root);
        cout << endl;
    }

    void recursivePostOrder() {
        cout << "递归后序遍历：";
        recursivePostOrder(root);
        cout << endl;
    }

    void levelOrder() {
        cout << "层序遍历：";
        levelOrder(root);
        cout << endl;
    }

    // 设置根节点
    void setRoot(BiNode<T>* newRoot) {
        root = newRoot;
    }
};

int main() {
    // 创建二叉树（A的左子树为B，右子树为C，C的左子树为D）
    BiTree<char> tree;
    BiNode<char>* root = new BiNode<char>('A');
    root->left = new BiNode<char>('B');
    root->right = new BiNode<char>('C');
    root->right->left = new BiNode<char>('D');

    tree.setRoot(root);
    cout << "创建二叉树（A的左子树为B，右子树为C，C的左子树为D）" << endl;

    // 验证基本操作
    tree.recursivePreOrder();
    tree.recursiveInOrder();
    tree.recursivePostOrder();
    tree.levelOrder();
    cout << "完成人:22网工方喜健" << endl;
    return 0;
}
