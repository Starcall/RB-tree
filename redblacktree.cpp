#include "redblacktree.h"
#include "cassert"
#include "iostream"
#include "Node.h"


template <class Key>
void RedBlackTree<Key>::insert(const Key& value)
{
    countElements++;
    if (countElements == 1)
    {
        root->value = value;
        root->left = std::make_shared<Node<Key>>(Node<Key>(-1, root));
        root->right = std::make_shared<Node<Key>>(Node<Key>(-1, root));
        return;
    }
    std::shared_ptr<Node<Key>> curNode = root;
    std::shared_ptr<Node<Key>> nextNode = root;
    do {
        curNode = nextNode;
        if (value >= curNode->value)
        {
            nextNode = curNode->right;
        } else
        {
            nextNode = curNode->left;
        }
    } while (nextNode != nullptr);
    curNode->value = value;
    curNode->color = NodeColor::RED;
    curNode->left = std::make_shared<Node>(Node<Key>(-1, curNode));
    curNode->right = std::make_shared<Node>(Node<Key>(-1, curNode));
    BalanceTree(curNode);

}

template <class Key>
void RedBlackTree<Key>::BalanceTree(std::shared_ptr<Node<Key>> curNode)
{
    //std::assert(curNode == fakeNode);
    if (curNode->GetParent() == root)
    {
        //Root should always be black
        curNode->GetParent()->color = NodeColor::BLACK;
        return;
    }
    if (!curNode->GetParent() || curNode->GetParent()->color == NodeColor::BLACK)
    {
        //Our GetParent() is not red, ok
        return;
    }
    if (!curNode->GetParent()->GetParent() || curNode->GetParent()->GetParent()->left == curNode->GetParent())
    {
        //Father is left child
        std::shared_ptr<Node<Key>> uncle;
        if (!curNode->GetUncle() || curNode->GetUncle()->color == NodeColor::BLACK)
        {
            //We have Black uncle
            if (curNode->GetParent()->right == curNode)
            {
                //We are right child
                //Should become left child via rotate
                curNode = curNode->GetParent();
                LeftRotate(curNode);
            }
            curNode->GetParent()->color = NodeColor::BLACK;
            curNode->GetParent()->GetParent()->color = NodeColor::RED;
            RightRotate(curNode->GetParent()->GetParent());
            BalanceTree(curNode);

        } else {
            //We have Red uncle
            curNode->GetParent()->color = NodeColor::BLACK;
            curNode->GetUncle()->color = NodeColor::BLACK;
            curNode->GetParent()->GetParent()->color = NodeColor::RED;
            BalanceTree(curNode->GetParent()->GetParent());
        }
    } else {
        //Father is right child
        if (!curNode->GetUncle() || curNode->GetUncle()->color == NodeColor::BLACK)
        {
            //We have Black uncle
            if (curNode->GetParent()->left == curNode)
            {
                //We are left child
                //Should become right child via rotate
                curNode = curNode->GetParent();
                RightRotate(curNode);
            }
            curNode->GetParent()->color = NodeColor::BLACK;
            curNode->GetParent()->GetParent()->color = NodeColor::RED;
            LeftRotate(curNode->GetParent()->GetParent());
            BalanceTree(curNode);
        } else {
            //We have Red uncle
            curNode->GetParent()->color = NodeColor::BLACK;
            curNode->GetUncle()->color = NodeColor::BLACK;
            curNode->GetParent()->GetParent()->color = NodeColor::RED;
            BalanceTree(curNode->GetParent()->GetParent());
        }
    }
    root->color = NodeColor::BLACK;
}

template <class Key>
void RedBlackTree<Key>::LeftRotate(std::shared_ptr<Node<Key>> curNode)
{
    std::shared_ptr<Node<Key>> newNode = curNode->right;
    if (curNode == root) {
        root = newNode;
    }
    curNode->right = newNode->left;
    curNode->right->parent = curNode;
    newNode->left = curNode;
    newNode->parent = curNode->GetParent();
    curNode->parent = newNode;
    if (newNode->GetParent() && newNode->GetParent()->left == curNode)
    {
        newNode->GetParent()->left = newNode;
    } else if (newNode->GetParent() && newNode->GetParent()->right == curNode)
    {
        newNode->GetParent()->right = newNode;
    }
}

template <class Key>
void RedBlackTree<Key>::RightRotate(std::shared_ptr<Node<Key>> curNode)
{
    std::shared_ptr<Node<Key>> newNode = curNode->left;
    if (curNode == root)
    {
        root = newNode;
    }
    curNode->left = newNode->right;
    curNode->left->parent = curNode;
    newNode->right = curNode;
    newNode->parent = curNode->GetParent();
    curNode->parent = newNode;
    if (newNode->GetParent() && newNode->GetParent()->left == curNode)
    {
        newNode->GetParent()->left = newNode;
    }  else if (newNode->GetParent() && newNode->GetParent()->right == curNode)
    {
        newNode->GetParent()->right = newNode;
    }
}

template <class Key>
void RedBlackTree<Key>::dumpTree(std::shared_ptr<Node<Key>> curNode) const
{
    if (!curNode)
        return;
    std::cout << curNode->value << " " << curNode->color << "\n";
    dumpTree(curNode->left);
    dumpTree(curNode->right);
}

template <class Key>
size_t RedBlackTree<Key>::size() const
{
    return count;
}

template <class Key>
typename RedBlackTree<Key>::iterator RedBlackTree<Key>::find(const Key& value) const
{
    std::shared_ptr<Node<Key>> curNode = root;
    while (curNode && curNode->value != value)
    {
        if (value >= curNode->value)
        {
            curNode = curNode->right;
        } else {
            curNode = curNode->left;
        }
    }
    if (curNode && curNode->value == value)
        return true;
    return false;
}
