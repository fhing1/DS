#include <iostream>
#include <queue>
using namespace std;

// �������ڵ���
template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

// ��������ģ��
template <typename T>
class BiTree {
private:
    TreeNode<T>* root;

public:
    BiTree() : root(nullptr) {}

    // �����������ͷŽڵ��ڴ�
    ~BiTree() {
        destroyTree(root);
    }

    // ���������
    void createTree(T arr[], int size) {
        root = createTreeFromArray(arr, 0, size - 1);
    }

    // �ݹ鷽ʽ���������
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

    // �����������С���
    int minDepth() {
        return minDepth(root);
    }

    // �ݹ鷽ʽ����С���
    int minDepth(TreeNode<T>* node) {
        if (!node) {
            return 0;
        }

        int leftDepth = minDepth(node->left);
        int rightDepth = minDepth(node->right);

        // ��ǰ�ڵ���Ҷ�ӽڵ��ֻ��һ������ʱ�����ز�Ϊ������
        if (leftDepth == 0 || rightDepth == 0) {
            return max(leftDepth, rightDepth) + 1;
        }

        return min(leftDepth, rightDepth) + 1;
    }

    // ���ٶ�����
    void destroyTree(TreeNode<T>* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
};

int main() {
    // ��������
    int arr[] = { 1,2, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // ����������
    BiTree<int> tree;
    tree.createTree(arr, size);

    // �����������С���
    int minDepth = tree.minDepth();

    // ������
    cout << "����������С���Ϊ��" << minDepth << endl;

    cout << endl << "����ˣ�22�������Ƚ" << endl;
    return 0;
}
