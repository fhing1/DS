#include <iostream>
#include <algorithm>

using namespace std;

// ��������㶨��
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// ������������
int calculateDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth = calculateDepth(root->left);
    int rightDepth = calculateDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

// �����������������
int calculateDiameter(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    // �������������������
    int leftDepth = calculateDepth(root->left);
    int rightDepth = calculateDepth(root->right);

    // ���㵱ǰ������ֱ��
    int currentDiameter = leftDepth + rightDepth;

    // �ݹ��������������ֱ��
    int leftSubtreeDiameter = calculateDiameter(root->left);
    int rightSubtreeDiameter = calculateDiameter(root->right);

    // �������ֱ��
    return max(currentDiameter, max(leftSubtreeDiameter, rightSubtreeDiameter));
}

int main() {
    // �����������ʾ������
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);

    // �����������������
    int diameter = calculateDiameter(root);

    cout << "�����������������ǣ�" << diameter << endl;

    // TODO: �ͷŶ������ڴ棬��ֹ�ڴ�й©
    cout << "�����:22������ϲ��" << endl;
    return 0;
}
