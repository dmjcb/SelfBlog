/*
 * @Brief        : 二叉排序树
 * @Author       : dmjcb
 * @Date         : 2022-04-08 22:47:18
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-10-12 16:04:59
 */

#include <iostream>
#include <vector>

// 节点定义
template <class T>
struct BSTNode
{
    T           mValue;
    BSTNode<T>* mLeftSon;
    BSTNode<T>* mRightSon;

    BSTNode(T value, BSTNode<T> *leftSon, BSTNode<T> *rightSon) : mValue(value), mLeftSon(leftSon), mRightSon(rightSon){}
};

// 查找
template <class T>
BSTNode<T> *SearchNode(BSTNode<T>* node, const T value) {
    while (node) {
        if (node->mValue == value) {
            return node;
        }
        if (node->mValue > value) {
            node = node->mLeftSon;
        }
        if (node->mValue < value) {
            node = node->mRightSon;
        }
    }
    return nullptr;
}

// 插入
template <class T>
BSTNode<T> *InsertNode(BSTNode<T>* node, const T value) {
    // 当前节点为空,说明是叶子节点,可以插入
    if (node == nullptr) {
        node = new BSTNode<T>(value, nullptr, nullptr);
        return node;
    }

    // 值小于根结点时,插入根节点的左子树
    if (node->mValue > value) {
        node->mLeftSon = InsertNode(node->mLeftSon, value);
    }

    // 值大于根结点时,插入根节点的右子树
    if (node->mValue < value) {
        node->mRightSon = InsertNode(node->mRightSon, value);
    }
    return node;
}

// 构建
template <class T>
void CreateBST(BSTNode<T> * &root, const std::vector<T> value) {
    for (auto v : value) {
        root = InsertNode(root, v);
    }
}

// 遍历
template <class T>
void PrintBST(BSTNode<T> *root)
{
    if (root == nullptr) {
        return;
    }

    PrintBST(root->mLeftSon);

    std::cout << root->mValue << " ";

    PrintBST(root->mRightSon);
}

// 删除
template <class T>
void DeleteNode(BSTNode<T> *root, const T value) {
    if (root == nullptr) {
        return;
    }

    // p为待删除节点,fp为其父节点
    BSTNode<T>* p = root;
    BSTNode<T>* fp = nullptr;
    while (p->mValue != value) {
        fp = p;
        if (p->mValue > value) {
            p = p->mLeftSon;
        }
        if (p->mValue < value) {
            p = p->mRightSon;
        }
    }

    // 情况1:p为叶子节点,则直接删
    if (p->mLeftSon == nullptr && p->mRightSon == nullptr) {
        if (fp->mLeftSon != nullptr) {
            fp->mLeftSon = nullptr;
        }
        if (fp->mRightSon != nullptr) {
            fp->mRightSon = nullptr;
        }
        delete (p);
        return;
    }

    // 情况2:p左子树为空,则重接右子树
    if (p->mLeftSon == nullptr) {
        p->mValue = p->mRightSon->mValue;
        p->mRightSon = nullptr;
        delete (p);
        return;
    }

    // 情况3:p右子树为空,则重接左子树
    if (p->mRightSon == nullptr) {
        p->mValue = p->mLeftSon->mValue;
        p->mLeftSon = nullptr;
        delete (p->mLeftSon);
        return;
    }

    // 情况4:p左右子树均不为空时,需要找p右子树中最小节点(最左节点)q
    BSTNode<T> *q = p->mRightSon;
    // fq为q的父节点
    BSTNode<T> *fq = q;
    // 循环查找左节点,就会找到最小值
    while (q->mLeftSon != nullptr) {
        fq = q;
        q = q->mLeftSon;
    }
    fq->mLeftSon = nullptr;
    // 用最小值节点代替欲删除节点
    p->mValue = q->mValue;
    delete (q);
}

int main(int argv, char *argc[]) {
    std::vector<int> v = {11, 45, 9, 23, 76, 68};

    BSTNode<int> *root = nullptr;

    CreateBST(root, v);

    std::cout << "二叉排序树的中序遍历结果: ";
    PrintBST(root);
    std::cout << std::endl;

    // 插入值
    int newNode = 35;
    std::cout << "插入新值:" << newNode << std::endl;
    root = InsertNode(root, newNode);
    std::cout << "插入新值后二叉排序树的中序遍历结果: ";

    PrintBST(root);
    std::cout << std::endl;

    // 删除值
    int delNode = 11;
    std::cout << "删除值:" << delNode << std::endl;

    DeleteNode(root, delNode);
    std::cout << "删除值后二叉排序树的中序遍历结果: ";

    PrintBST(root);
    std::cout << std::endl;
}