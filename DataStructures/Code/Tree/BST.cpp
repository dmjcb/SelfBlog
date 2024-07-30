/*
 * @Description: 二叉排序树
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:
 * @Date: 2022-04-08 22:47:18
 * @LastEditors: dmjcb
 * @LastEditTime: 2024-07-30 13:04:12
 */

#include <iostream>
#include <vector>

using namespace std;

// 节点定义
template <class T>
struct BSTNode
{
    T value;
    BSTNode<T> *leftSon;
    BSTNode<T> *rightSon;
    BSTNode(T value, BSTNode<T> *leftSon, BSTNode<T> *rightSon)
    {
        this->value = value;
        this->leftSon = leftSon;
        this->rightSon = rightSon;
    }
};

// 查找
template <class T>
BSTNode<T> *SearchNode(BSTNode<T> *&node, const T value)
{
    while (node)
    {
        if (node->value == value)
        {
            return node;
        }
        if (node->value > value)
        {
            node = node->leftSon;
        }
        if (node->value < value)
        {
            node = node->rightSon;
        }
    }
    return nullptr;
}

// 插入
template <class T>
BSTNode<T> *InsertNode(BSTNode<T> *&node, const T value)
{
    // 当前节点为空,说明是叶子节点,可以插入
    if (node == nullptr)
    {
        node = new BSTNode<T>(value, nullptr, nullptr);
        return node;
    }
    // 值小于根结点时,插入根节点的左子树
    if (node->value > value)
    {
        node->leftSon = InsertNode(node->leftSon, value);
    }
    // 值大于根结点时,插入根节点的右子树
    if (node->value < value)
    {
        node->rightSon = InsertNode(node->rightSon, value);
    }
    return node;
}

// 构建
template <class T>
void CreateBST(BSTNode<T> *&root, vector<T> v)
{
    for (int i = 0, size = v.size(); i < size; i++)
    {
        root = InsertNode(root, v[i]);
    }
}

// 遍历
template <class T>
void PrintBST(BSTNode<T> *&root)
{
    if (root == nullptr)
    {
        return;
    }
    PrintBST(root->leftSon);

    cout << root->value << " ";

    PrintBST(root->rightSon);
}

// 删除
template <class T>
void DeleteNode(BSTNode<T> *&root, T value)
{
    if (root == nullptr)
    {
        return;
    }
    // p为待删除节点,fp为其父节点
    BSTNode<T> *p = root;
    BSTNode<T> *fp = nullptr;
    while (p->value != value)
    {
        fp = p;
        if (p->value > value)
        {
            p = p->leftSon;
        }
        if (p->value < value)
        {
            p = p->rightSon;
        }
    }

    // 情况1:p为叶子节点,则直接删
    if (p->leftSon == nullptr && p->rightSon == nullptr)
    {
        if (fp->leftSon != nullptr)
        {
            fp->leftSon = nullptr;
        }
        if (fp->rightSon != nullptr)
        {
            fp->rightSon = nullptr;
        }
        delete (p);
        return;
    }

    // 情况2:p左子树为空,则重接右子树
    if (p->leftSon == nullptr)
    {
        p->value = p->rightSon->value;
        p->rightSon = nullptr;
        delete (p);
        return;
    }

    // 情况3:p右子树为空,则重接左子树
    if (p->rightSon == nullptr)
    {
        p->value = p->leftSon->value;
        p->leftSon = nullptr;
        delete (p->leftSon);
        return;
    }

    // 情况4:p左右子树均不为空时,需要找p右子树中最小节点(最左节点)q
    BSTNode<T> *q = p->rightSon;
    // fq为q的父节点
    BSTNode<T> *fq = q;
    // 循环查找左节点,就会找到最小值
    while (q->leftSon != nullptr)
    {
        fq = q;
        q = q->leftSon;
    }
    fq->leftSon = nullptr;
    // 用最小值节点代替欲删除节点
    p->value = q->value;
    delete (q);
}

int main(int argv, char *argc[])
{
    std::vector<int> v = {11, 45, 9, 23, 76, 68};

    BSTNode<int> *root = nullptr;

    CreateBST(root, v);

    std::cout << "二叉排序树的中序遍历结果: ";
    PrintBST(root);
    std::cout << endl;

    // 插入值
    int newNode = 35;
    std::cout << "插入新值:" << newNode << endl;
    root = InsertNode(root, newNode);
    std::cout << "插入新值后二叉排序树的中序遍历结果: ";
    
    PrintBST(root);
    std::cout << endl;

    // 删除值
    int delNode = 11;
    std::cout << "删除值:" << delNode << endl;

    DeleteNode(root, delNode);
    std::cout << "删除值后二叉排序树的中序遍历结果: ";

    PrintBST(root);
    std::cout << endl;
}