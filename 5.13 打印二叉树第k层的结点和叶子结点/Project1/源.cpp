#include <iostream>
#include <cmath>

using namespace std;

// ��������㶨��
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// ��ӡ�������� k ��Ľ���Ҷ�ӽ��
void printKthLevel(const TreeNode* root, int k);

// ��ӡ������ĳ��Ľ���Ҷ�ӽ��
void printNodesAtLevel(const TreeNode* root, int currentLevel, int targetLevel);

int main() {
    string a = "        1\n"
        "       / \\\n"
        "      2   3\n"
        "     / \\ / \\\n"
        "    4  5 6  7\n"
        "   /\n"
        "  8\n";
    // ����ʾ��������
    cout << "�����:22������ϲ��" << endl;
    cout << a;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);

    // ��ӡ�������� 3 ��Ľ���Ҷ�ӽ��
    cout << "�������� 3 ��Ľ���Ҷ�ӽ�㣺" << endl;
    printKthLevel(root, 3);

    // TODO: �ͷŶ������ڴ棬��ֹ�ڴ�й©

    return 0;
}

void printKthLevel(const TreeNode* root, int k) {
    if (root == nullptr || k <= 0) {
        cout << "Invalid input." << endl;
        return;
    }

    // ������������ܲ���
    int height = static_cast<int>(log2(k)) + 1;

    // ��ӡ�� k ��Ľ���Ҷ�ӽ��
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
