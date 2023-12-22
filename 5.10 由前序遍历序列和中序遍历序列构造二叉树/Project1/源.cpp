#include <iostream>
#include <vector>
#include <unordered_map>

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
public:
    // ��ǰ�����������������й��������
    TreeNode<T>* buildTree(std::vector<T>& preorder, std::vector<T>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    // ǰ�����
    void preOrderTraversal(TreeNode<T>* root) const {
        if (root != nullptr) {
            std::cout << root->data << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }

    // �������
    void inOrderTraversal(TreeNode<T>* root) const {
        if (root != nullptr) {
            inOrderTraversal(root->left);
            std::cout << root->data << " ";
            inOrderTraversal(root->right);
        }
    }

    // �������
    void postOrderTraversal(TreeNode<T>* root) const {
        if (root != nullptr) {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            std::cout << root->data << " ";
        }
    }

    // ��ӡ����������״
    void printTree(TreeNode<T>* root, int spaces, const std::string& prefix = "") const {
        const int SPACES = 4;
        if (root != nullptr) {
            printTree(root->right, spaces + SPACES, "R" + prefix);
            for (int i = 0; i < spaces; ++i) {
                std::cout << " ";
            }
            std::cout << prefix << root->data << std::endl;
            printTree(root->left, spaces + SPACES, "L" + prefix);
        }
    }

private:
    std::unordered_map<T, int> inorder_map;

    TreeNode<T>* buildTreeHelper(std::vector<T>& preorder, int pre_start, int pre_end,
        std::vector<T>& inorder, int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end) {
            return nullptr;
        }

        T root_value = preorder[pre_start];
        TreeNode<T>* root = new TreeNode<T>(root_value);

        int root_index_inorder = inorder_map[root_value];
        int num_left_nodes = root_index_inorder - in_start;

        root->left = buildTreeHelper(preorder, pre_start + 1, pre_start + num_left_nodes,
            inorder, in_start, root_index_inorder - 1);
        root->right = buildTreeHelper(preorder, pre_start + num_left_nodes + 1, pre_end,
            inorder, root_index_inorder + 1, in_end);

        return root;
    }
};

int main() {
    // ����ǰ������������������
    std::vector<int> preorder = { 1, 2, 4, 5, 3, 6, 7 };
    std::vector<int> inorder = { 4, 2, 5, 1, 6, 3, 7 };

    // ���������
    BinaryTree<int> binaryTree;
    TreeNode<int>* root = binaryTree.buildTree(preorder, inorder);

    // ��ӡ������
    std::cout << "����Ķ�������״��" << std::endl;
    binaryTree.printTree(root, 0);

    // ǰ�����
    std::cout << "ǰ�������" << std::endl;
    binaryTree.preOrderTraversal(root);
    std::cout << std::endl;

    // �������
    std::cout << "���������" << std::endl;
    binaryTree.inOrderTraversal(root);
    std::cout << std::endl;
    std::cout << "�����:22������ϲ��" << std::endl;
    // �������
    std::cout << "���������" << std::endl;
    binaryTree.postOrderTraversal(root);
    std::cout << std::endl;

    return 0;
    
}
