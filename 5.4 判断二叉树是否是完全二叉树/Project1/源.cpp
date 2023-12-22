#include <iostream>
#include <queue>
using namespace std;

// 二叉树节点类
template<typename T>
struct BiNode {
    T data;
    BiNode<T>* left;
    BiNode<T>* right;

    BiNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

// 二叉树类
template<typename T>
class BiTree {
public:
    BiTree() {
        root = nullptr;
    }

    // 构造函数，根据先序遍历序列创建二叉树
    BiTree(const vector<T>& preOrder) {
        int index = 0;
        root = createTree(preOrder, index);
    }

    // 递归前序遍历
    void preOrderRecursive(BiNode<T>* node) {
        if (node) {
            cout << node->data << " ";
            preOrderRecursive(node->left);
            preOrderRecursive(node->right);
        }
    }

    // 判断二叉树是否是完全二叉树
    bool isCompleteTree() {
        if (!root) {
            return true;
        }

        queue<BiNode<T>*> q;
        q.push(root);
        bool flag = false;

        while (!q.empty()) {
            BiNode<T>* node = q.front();
            q.pop();

            // 如果之前已经遇到空节点，但当前节点不为空
            if (flag && node) {
                return false;
            }

            // 当前节点为空，则将标记置为true
            if (!node) {
                flag = true;
                continue;
            }

            q.push(node->left);
            q.push(node->right);
        }

        return true;
    }

private:
    // 根据先序遍历序列创建二叉树
    BiNode<T>* createTree(const vector<T>& preOrder, int& index) {
        if (index >= preOrder.size()) {
            return nullptr;
        }

        T value = preOrder[index++];
        if (value == '#') {
            return nullptr;
        }

        BiNode<T>* node = new BiNode<T>(value);
        node->left = createTree(preOrder, index);
        node->right = createTree(preOrder, index);
        return node;
    }

public:
    BiNode<T>* getRoot() {
        return root;
    }

private:
    BiNode<T>* root;
};

int main() {
    // 构造二叉树
    vector<char> preOrder = { 'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F', '#', '#', 'G', '#', '#' };
    BiTree<char> tree(preOrder);

    // 验证递归前序遍历
    cout << "递归前序遍历结果：" << endl;
    tree.preOrderRecursive(tree.getRoot());
    cout << endl;

    // 判断是否是完全二叉树
    bool isComplete = tree.isCompleteTree();
    if (isComplete) {
        cout << "该二叉树是完全二叉树" << endl;
    }
    else {
        cout << "该二叉树不是完全二叉树" << endl;
    }
    cout << "完成人:22网工方喜健" << endl;
    return 0;
}
