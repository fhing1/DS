//#include <iostream>
//using namespace std;
//
//// ����������ڵ�ṹ��
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//// �����������ģ��BiTree
//template <typename T>
//class BiTree {
//public:
//    BiTree() : root(NULL) {}
//
//    // ����ڵ�
//    void insert(T value) {
//        if (root == NULL) {
//            root = new TreeNode(value);
//        } else {
//            insert(root, value);
//        }
//    }
//
//    // ����Ҷ�ӽ�����
//    int countLeafNodes() {
//        return countLeafNodes(root);
//    }
//
//    // ���������
//    int countNodes() {
//        return countNodes(root);
//    }
//
//private:
//    TreeNode *root;
//
//    // �ݹ����ڵ�
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
//    // �ݹ����Ҷ�ӽ�����
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
//    // �ݹ���������
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
//    cout << "Ҷ�ӽ�������" << tree.countLeafNodes() << endl;
//    cout << "��������" << tree.countNodes() << endl;
//    cout << endl << "����ˣ�22�������Ƚ" << endl;
//    return 0;
//}
