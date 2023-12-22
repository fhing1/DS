#include <iostream>
#include <cmath>

using namespace std;

// 二叉树结点定义
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// 打印二叉树第 k 层的结点和叶子结点
void printKthLevel(const TreeNode* root, int k);

// 打印二叉树某层的结点和叶子结点
void printNodesAtLevel(const TreeNode* root, int currentLevel, int targetLevel);

int main() {
    string a = "        1\n"
        "       / \\\n"
        "      2   3\n"
        "     / \\ / \\\n"
        "    4  5 6  7\n"
        "   /\n"
        "  8\n";
    // 构造示例二叉树
    cout << "完成人:22网工方喜健" << endl;
    cout << a;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);

    // 打印二叉树第 3 层的结点和叶子结点
    cout << "二叉树第 3 层的结点和叶子结点：" << endl;
    printKthLevel(root, 3);

    // TODO: 释放二叉树内存，防止内存泄漏

    return 0;
}

void printKthLevel(const TreeNode* root, int k) {
    if (root == nullptr || k <= 0) {
        cout << "Invalid input." << endl;
        return;
    }

    // 计算二叉树的总层数
    int height = static_cast<int>(log2(k)) + 1;

    // 打印第 k 层的结点和叶子结点
    for (int level = 1; level <= height; ++level) {
        printNodesAtLevel(root, 1, level);
    }
}

void printNodesAtLevel(const TreeNode* root, int currentLevel, int targetLevel) {
    if (root == nullptr || currentLevel > targetLevel) {
        return;
    }

    if (currentLevel == targetLevel) {
        cout << "Node: " << root->data << endl;
        if (root->left == nullptr && root->right == nullptr) {
            cout << "Leaf: " << root->data << endl;
        }
    }
    else {
        printNodesAtLevel(root->left, currentLevel + 1, targetLevel);
        printNodesAtLevel(root->right, currentLevel + 1, targetLevel);
    }
}
