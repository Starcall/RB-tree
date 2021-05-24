#pragma once
#include <memory>
#include "starcallset.h"
#include "Node.h"


template <class Key>
class RedBlackTree : Set<Key>
{
public:
    typedef std::iterator<std::bidirectional_iterator_tag, Key> iterator;
    RedBlackTree() : Set<Key>()
    {
        root = std::make_shared<Node<Key>>();
    }
    ~RedBlackTree();
    RedBlackTree& operator=(const RedBlackTree<Key>&);

    virtual iterator begin() const = 0;
    virtual iterator end() const = 0;
    virtual iterator rbegin() const = 0;
    virtual iterator rend() const = 0;

    virtual bool empty() const override;
    virtual size_t size() const override;
    virtual void clear() override;
    void insert(const Key&) override;
    virtual void erase(const Key&) = 0;
    virtual void swap(Set<Key>&) = 0;

    virtual size_t count(const Key&) const override;
    virtual iterator find(const Key&) const override;
private:

    void BalanceTree(std::shared_ptr<Node<Key>> curNode);

    std::shared_ptr<Node<Key>> root;

    void LeftRotate(std::shared_ptr<Node<Key>> curNode);
    void RightRotate(std::shared_ptr<Node<Key>> curNode);

    void dumpTree(std::shared_ptr<Node<Key>> curNode) const;

    size_t countElements;

};
