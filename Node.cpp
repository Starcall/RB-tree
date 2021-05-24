#include "Node.h"

template <class Key>
Node<Key>::Node()  : color(NodeColor::BLACK), left(nullptr), right(nullptr)
{
    value = Key();
}

template <class Key>
Node<Key>::Node(const Key& value, std::shared_ptr<Node<Key>> parent) : Node()
{
    this->value = value;
    this->parent = parent;
}

template <class Key>
Node<Key>::Node(const Key& value, std::shared_ptr<Node<Key>> parent, const NodeColor color) : Node(value, parent)
{
    this->color = color;
}

template <class Key>
std::shared_ptr<Node<Key>> Node<Key>::GetUncle() const
{
    if (GetParent() != nullptr)
    {
        if (GetParent()->GetParent() != nullptr)
        {
            if (GetParent()->GetParent()->left == GetParent())
            {
                return GetParent()->GetParent()->right;
            } else {
                return GetParent()->GetParent()->left;
            }
        }
    }
    return nullptr;
}

template <class Key>
std::shared_ptr<Node<Key>> Node<Key>::GetParent() const
{
    return parent.lock();
}
