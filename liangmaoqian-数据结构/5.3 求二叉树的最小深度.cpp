#include <iostream>
#include <queue>
using namespace std;

// 二叉树节点类
template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

// 二叉树类模板
template <typename T>
class BiTree {
private:
    TreeNode<T>* root;

public:
    BiTree() : root(nullptr) {}

    // 析构函数，释放节点内存
    ~BiTree() {
        destroyTree(root);
    }

    // 构造二叉树
    void createTree(T arr[], int size) {
        root = createTreeFromArray(arr, 0, size - 1);
    }

    // 递归方式构造二叉树
    TreeNode<T>* createTreeFromArray(T arr[], int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = (start + end) / 2;
        TreeNode<T>* newNode = new TreeNode<T>(arr[mid]);

        newNode->left = createTreeFromArray(arr, start, mid - 1);
        newNode->right = createTreeFromArray(arr, mid + 1, end);

        return newNode;
    }

    // 求二叉树的最小深度
    int minDepth() {
        return minDepth(root);
    }

    // 递归方式求最小深度
    int minDepth(TreeNode<T>* node) {
        if (!node) {
            return 0;
        }

        int leftDepth = minDepth(node->left);
        int rightDepth = minDepth(node->right);

        // 当前节点是叶子节点或只有一个孩子时，返回不为零的深度
        if (leftDepth == 0 || rightDepth == 0) {
            return max(leftDepth, rightDepth) + 1;
        }

        return min(leftDepth, rightDepth) + 1;
    }

    // 销毁二叉树
    void destroyTree(TreeNode<T>* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
};

int main() {
    // 测试输入
    int arr[] = { 1,2, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // 创建二叉树
    BiTree<int> tree;
    tree.createTree(arr, size);

    // 求二叉树的最小深度
    int minDepth = tree.minDepth();

    // 输出结果
    cout << "二叉树的最小深度为：" << minDepth << endl;

    cout << endl << "完成人：22网工李浩冉" << endl;
    return 0;
}
