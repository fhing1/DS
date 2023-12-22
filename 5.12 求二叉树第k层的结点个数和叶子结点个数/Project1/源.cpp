#include <iostream>
#include <queue>
#include <string>

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BiTree {
public:
    BiTree() : root(nullptr) {}
    ~BiTree() {
        clear(root);
    }

    // 插入结点
    void insert(T value) {
        root = insert(root, value);
    }

    // 打印二叉树
    void printTree() const {
        printTree(root, 0);
    }

    // 求第 k 层的结点个数和叶子结点个数
    void nodesAndLeavesAtLevel(int k) const {
        int nodesCount = 0, leavesCount = 0;
        nodesAndLeavesAtLevel(root, k, 1, nodesCount, leavesCount);
        std::cout << "第 " << k << " 层的结点个数: " << nodesCount << std::endl;
        std::cout << "第 " << k << " 层的叶子结点个数: " << leavesCount << std::endl;
    }

private:
    TreeNode<T>* root;

    // 插入结点的辅助函数
    TreeNode<T>* insert(TreeNode<T>* node, T value) {
        if (node == nullptr) {
            return new TreeNode<T>(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // 清空二叉树的辅助函数
    void clear(TreeNode<T>* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    // 打印二叉树的辅助函数
    void printTree(const TreeNode<T>* node, int spaces, const std::string& prefix = "") const {
        const int SPACES = 4;
        if (node != nullptr) {
            printTree(node->right, spaces + SPACES, "R" + prefix);
            for (int i = 0; i < spaces; ++i) {
                std::cout << " ";
            }
            std::cout << prefix << node->data << std::endl;
            printTree(node->left, spaces + SPACES, "L" + prefix);
        }
    }

    // 求第 k 层的结点个数和叶子结点个数的辅助函数
    void nodesAndLeavesAtLevel(const TreeNode<T>* node, int k, int currentLevel, int& nodesCount, int& leavesCount) const {
        if (node == nullptr) {
            return;
        }

        if (currentLevel == k) {
            nodesCount++;
            if (node->left == nullptr && node->right == nullptr) {
                leavesCount++;
            }
        }
        else {
            nodesAndLeavesAtLevel(node->left, k, currentLevel + 1, nodesCount, leavesCount);
            nodesAndLeavesAtLevel(node->right, k, currentLevel + 1, nodesCount, leavesCount);
        }
    }
};

int main() {
    BiTree<int> tree;
    // 插入结点
    tree.insert(3);
    tree.insert(1);
    tree.insert(5);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);

    // 打印二叉树
    std::cout << "二叉树的形状：" << std::endl;
    tree.printTree();

    // 求第 k 层的结点个数和叶子结点个数
    int k = 3;
    tree.nodesAndLeavesAtLevel(k);
    std::cout << "完成人：22网工方喜健" << std::endl;
    return 0;
}
