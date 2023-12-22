//#include <iostream>
//using namespace std;
//
//// 定义二叉树节点结构体
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//// 定义二叉树类模板BiTree
//template <typename T>
//class BiTree {
//public:
//    BiTree() : root(NULL) {}
//
//    // 插入节点
//    void insert(T value) {
//        if (root == NULL) {
//            root = new TreeNode(value);
//        } else {
//            insert(root, value);
//        }
//    }
//
//    // 计算叶子结点个数
//    int countLeafNodes() {
//        return countLeafNodes(root);
//    }
//
//    // 计算结点个数
//    int countNodes() {
//        return countNodes(root);
//    }
//
//private:
//    TreeNode *root;
//
//    // 递归插入节点
//    void insert(TreeNode *node, T value) {
//        if (value < node->val) {
//            if (node->left == NULL) {
//                node->left = new TreeNode(value);
//            } else {
//                insert(node->left, value);
//            }
//        } else {
//            if (node->right == NULL) {
//                node->right = new TreeNode(value);
//            } else {
//                insert(node->right, value);
//            }
//        }
//    }
//
//    // 递归计算叶子结点个数
//    int countLeafNodes(TreeNode *node) {
//        if (node == NULL) {
//            return 0;
//        }
//        if (node->left == NULL && node->right == NULL) {
//            return 1;
//        }
//        return countLeafNodes(node->left) + countLeafNodes(node->right);
//    }
//
//    // 递归计算结点个数
//    int countNodes(TreeNode *node) {
//        if (node == NULL) {
//            return 0;
//        }
//        return 1 + countNodes(node->left) + countNodes(node->right);
//    }
//};
//
//int main() {
//    BiTree<int> tree;
//    tree.insert(5);
//    tree.insert(3);
//    tree.insert(7);
//    tree.insert(2);
//    tree.insert(4);
//    tree.insert(6);
//    tree.insert(8);
//
//    cout << "叶子结点个数：" << tree.countLeafNodes() << endl;
//    cout << "结点个数：" << tree.countNodes() << endl;
//    cout << endl << "完成人：22网工李浩冉" << endl;
//    return 0;
//}
