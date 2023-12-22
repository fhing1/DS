#include <iostream>
using namespace std;

template <class T>
class InThrBiTree {
public:  // 将 BiThrNode 结构声明为公有
    struct BiThrNode {
        T data;
        BiThrNode* left;
        BiThrNode* right;
        int ltag, rtag;  // 线索标志

        BiThrNode(T value) : data(value), left(nullptr), right(nullptr), ltag(0), rtag(0) {}
    };

private:
    BiThrNode* root;  // 根结点
    BiThrNode* pre;   // 线索化时记录前一个访问的结点

    // 在中序线索化中使用的递归函数
    void InThreading(BiThrNode* p) {
        if (p != nullptr) {
            InThreading(p->left);  // 递归线索化左子树

            if (p->left == nullptr) {
                p->ltag = 1;         // 左指针为空，建立前驱线索
                p->left = pre;
            }
            if (pre != nullptr && pre->right == nullptr) {
                pre->rtag = 1;       // 建立后继线索
                pre->right = p;
            }

            pre = p;               // 更新前一个访问的结点

            InThreading(p->right);  // 递归线索化右子树
        }
    }

public:
    InThrBiTree() : root(nullptr), pre(nullptr) {}

    void CreateInThrBiTree() {
        root = new BiThrNode('A');
        root->left = new BiThrNode('B');
        root->right = new BiThrNode('C');
        root->left->left = new BiThrNode('D');
        root->left->right = new BiThrNode('E');
        root->right->left = new BiThrNode('F');
        root->right->right = new BiThrNode('G');
        // 根据需要补充创建二叉树的代码
        // 例如：root = new BiThrNode(value);
        //      root->left = new BiThrNode(value);
        //      root->right = new BiThrNode(value);
        //      ...
    }

    // 中序线索化
    void InOrderThreading() {
        if (root == nullptr) {
            cout << "树为空，无法线索化。" << endl;
            return;
        }
        InThreading(root);    // 开始线索化
        pre->right = nullptr;  // 处理遍历的最后一个结点，将其后继指针置为空
    }

    // 非递归中序遍历线索二叉树
    void InOrderTraverse() const {
        BiThrNode* p = root;
        while (p != nullptr) {
            // 寻找中序遍历的第一个结点
            while (p->ltag == 0) {
                p = p->left;
            }
            cout << p->data << " ";  // 访问结点

            // 若右指针是线索，沿着线索遍历下一个结点
            while (p->rtag == 1 && p->right != nullptr) {
                p = p->right;
                cout << p->data << " ";  // 访问结点
            }

            // 否则，转向右子树
            p = p->right;
        }
    }

    // 获取根结点
    BiThrNode* GetRoot() const {
        return root;
    }

    // 获取特定值的结点
    BiThrNode* GetNode(T value) const {
        return GetNode(root, value);
    }

    // 获取特定值的结点的辅助函数
    BiThrNode* GetNode(BiThrNode* p, T value) const {
        if (p != nullptr) {
            if (p->data == value) {
                return p;
            }
            BiThrNode* leftNode = GetNode(p->left, value);
            if (leftNode != nullptr) {
                return leftNode;
            }
            BiThrNode* rightNode = GetNode(p->right, value);
            return rightNode;
        }
        return nullptr;
    }
};

int main() {
    InThrBiTree<char> tree;
    tree.CreateInThrBiTree();


    // 创建二叉树，这里根据实际情况进行创建
    // 示例：tree.CreateInThrBiTree();

    // 中序线索化
    tree.InOrderThreading();

    // 非递归中序遍历线索二叉树
    cout << "中序线索二叉树的遍历结果：" << endl;
    tree.InOrderTraverse();
    cout << endl;

    // 获取特定值的结点
    InThrBiTree<char>::BiThrNode* nodeD = tree.GetNode('D');
    if (nodeD != nullptr) {
        cout << "找到结点D：" << nodeD->data << endl;
    }
    else {
        cout << "未找到结点D" << endl;
    }
    cout << "完成人22网工方喜健" << endl;
    return 0;
}
