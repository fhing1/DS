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
        cout << "请输入根节点的值（空节点用#代替）：" << endl;
        root = create_node();

        cout << "二叉树创建成功！" << endl;
    }

    bool is_symmetric() {
        if (!root) return true; // 如果根节点为空，则认为是对称的

        stack<Node*> s1, s2;

        // 左子树入栈s1，右子树入栈s2
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
        cout << "二叉树是对称的！" << endl;
    }
    else {
        cout << "二叉树不是对称的！" << endl;
    }
    cout << "完成人:22网工方喜健" << endl;
    return 0;
}
