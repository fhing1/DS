#include <iostream>
#include <algorithm>

using namespace std;

// 二叉树结点定义
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// 计算二叉树深度
int calculateDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth = calculateDepth(root->left);
    int rightDepth = calculateDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

// 计算二叉树最大结点距离
int calculateDiameter(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    // 计算根结点左右子树深度
    int leftDepth = calculateDepth(root->left);
    int rightDepth = calculateDepth(root->right);

    // 计算当前根结点的直径
    int currentDiameter = leftDepth + rightDepth;

    // 递归计算左右子树的直径
    int leftSubtreeDiameter = calculateDiameter(root->left);
    int rightSubtreeDiameter = calculateDiameter(root->right);

    // 返回最大直径
    return max(currentDiameter, max(leftSubtreeDiameter, rightSubtreeDiameter));
}

int main() {
    // 构造二叉树，示例数据
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);

    // 计算二叉树最大结点距离
    int diameter = calculateDiameter(root);

    cout << "二叉树的最大结点距离是：" << diameter << endl;

    // TODO: 释放二叉树内存，防止内存泄漏
    cout << "完成人:22网工方喜健" << endl;
    return 0;
}
