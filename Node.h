#pragma once
#include <memory>

enum NodeColor
{
    RED,
    BLACK
};

template <class Key>
class Node
{
    Node();
    Node(const Key& value, std::shared_ptr<Node<Key>> parent);
    Node(const Key& value, std::shared_ptr<Node<Key>> parent, NodeColor color);
    std::shared_ptr<Node<Key>> GetUncle() const;
    std::shared_ptr<Node<Key>> GetParent() const;
    std::shared_ptr<Node<Key>> left, right;
    std::weak_ptr<Node<Key>> parent;
    NodeColor color;
    Key value;
};
