#include <iostream>
#include <queue>
using namespace std;

// �������ڵ���
template<typename T>
struct BiNode {
    T data;
    BiNode<T>* left;
    BiNode<T>* right;

    BiNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

// ��������
template<typename T>
class BiTree {
public:
    BiTree() {
        root = nullptr;
    }

    // ���캯������������������д���������
    BiTree(const vector<T>& preOrder) {
        int index = 0;
        root = createTree(preOrder, index);
    }

    // �ݹ�ǰ�����
    void preOrderRecursive(BiNode<T>* node) {
        if (node) {
            cout << node->data << " ";
            preOrderRecursive(node->left);
            preOrderRecursive(node->right);
        }
    }

    // �ж϶������Ƿ�����ȫ������
    bool isCompleteTree() {
        if (!root) {
            return true;
        }

        queue<BiNode<T>*> q;
        q.push(root);
        bool flag = false;

        while (!q.empty()) {
            BiNode<T>* node = q.front();
            q.pop();

            // ���֮ǰ�Ѿ������սڵ㣬����ǰ�ڵ㲻Ϊ��
            if (flag && node) {
                return false;
            }

            // ��ǰ�ڵ�Ϊ�գ��򽫱����Ϊtrue
            if (!node) {
                flag = true;
                continue;
            }

            q.push(node->left);
            q.push(node->right);
        }

        return true;
    }

private:
    // ��������������д���������
    BiNode<T>* createTree(const vector<T>& preOrder, int& index) {
        if (index >= preOrder.size()) {
            return nullptr;
        }

        T value = preOrder[index++];
        if (value == '#') {
            return nullptr;
        }

        BiNode<T>* node = new BiNode<T>(value);
        node->left = createTree(preOrder, index);
        node->right = createTree(preOrder, index);
        return node;
    }

public:
    BiNode<T>* getRoot() {
        return root;
    }

private:
    BiNode<T>* root;
};

int main() {
    // ���������
    vector<char> preOrder = { 'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F', '#', '#', 'G', '#', '#' };
    BiTree<char> tree(preOrder);

    // ��֤�ݹ�ǰ�����
    cout << "�ݹ�ǰ����������" << endl;
    tree.preOrderRecursive(tree.getRoot());
    cout << endl;

    // �ж��Ƿ�����ȫ������
    bool isComplete = tree.isCompleteTree();
    if (isComplete) {
        cout << "�ö���������ȫ������" << endl;
    }
    else {
        cout << "�ö�����������ȫ������" << endl;
    }
    cout << "�����:22������ϲ��" << endl;
    return 0;
}
