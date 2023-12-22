#include <iostream>
#include <stack>

using namespace std;

// 二叉树节点结构
template <typename t>
struct bitreenode {
    t data;
    bitreenode* left;
    bitreenode* right;

    bitreenode(t value) : data(value), left(nullptr), right(nullptr) {}
};

// 二叉树类模板
template <typename t>
class bitree {
private:
    bitreenode<t>* root;

public:
    // 构造函数
    bitree() : root(nullptr) {}

    // 插入节点
    void insertnode(t value) {
        root = insertnoderecursive(root, value);
    }

    // 非递归前序遍历
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

    // 非递归中序遍历
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

    // 非递归后序遍历
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
    // 递归插入节点
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
    // 创建二叉树
    bitree<char> tree;
    tree.insertnode('a');
    tree.insertnode('b');
    tree.insertnode('c');
    tree.insertnode('d');

    // 非递归前序遍历
    cout << "非递归前序遍历: ";
    tree.nonrecursivepreordertraversal();

    // 非递归中序遍历
    cout << "非递归中序遍历: ";
    tree.nonrecursiveinordertraversal();

    // 非递归后序遍历
    cout << "非递归后序遍历: ";
    tree.nonrecursivepostordertraversal();
    cout <<endl<< "完成人：22网工李浩冉"<<endl;
    return 0;
}
