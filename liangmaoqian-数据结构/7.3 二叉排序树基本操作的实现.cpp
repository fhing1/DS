#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

class BiSortTree {
public:
    BiSortTree() : root(NULL) {}

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        return search(root, value);
    }

    void inorderTraversal() {
        inorderTraversal(root);
        cout << endl;
    }

private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value) {
        if (node == NULL) {
            return new TreeNode(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    bool search(TreeNode* node, int value) {
        if (node == NULL) {
            return false;
        }
        if (value < node->data) {
            return search(node->left, value);
        }
        else if (value > node->data) {
            return search(node->right, value);
        }
        else {
            return true;
        }
    }

    void inorderTraversal(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
};

int main() {
    BiSortTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    bst.inorderTraversal(); // 输出：20 30 40 50 60 70 80

    cout << "查找元素 40: " << (bst.search(40) ? "存在" : "不存在") << endl;
    cout << "查找元素 90: " << (bst.search(90) ? "存在" : "不存在") << endl;
		cout <<endl<< "完成人：李浩冉"<<endl;
    return 0;
}
