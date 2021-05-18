#pragma once
#include <memory>

class RedBlackTree
{
public:
    RedBlackTree() : count(0) {
        root = std::make_shared<Node>();
    };
    void insert(const int32_t value);
    void erase(const int32_t value) {};
    bool find(const int32_t value) const;
    size_t kth(const int32_t k) const {return 0;};
    size_t size() const;
private:
    struct Node;
    enum NodeColor
    {
        RED,
        BLACK
    };

    void BalanceTree(std::shared_ptr<Node> curNode);
    struct Node
    {
        Node() : color(NodeColor::BLACK), left(nullptr), right(nullptr), value(0)
        {
        }
        Node(const int32_t value, std::shared_ptr<Node> parent) : Node()
        {
            this->value = value;
            this->parent = parent;
        }
        Node(const int32_t value, std::shared_ptr<Node> parent, NodeColor color) : Node(value, parent)
        {
            this->color = color;
        }
        std::shared_ptr<Node> GetUncle() {
            if (GetParent() != nullptr)
            {
                if (GetParent()->GetParent() != nullptr) {
                    if (GetParent()->GetParent()->left == GetParent()) {
                        return GetParent()->GetParent()->right;
                    } else {
                        return GetParent()->GetParent()->left;
                    }
                }
            }
            return nullptr;
        }
        std::shared_ptr<Node> GetParent() {
            return parent.lock();
        }
        std::shared_ptr<Node> left, right;// parent;
        std::weak_ptr<Node> parent;
        NodeColor color;
        int32_t value;
    };


    size_t count;
    std::shared_ptr<Node> root;

    void LeftRotate(std::shared_ptr<Node> curNode);
    void RightRotate(std::shared_ptr<Node> curNode);

    void dumpTree(std::shared_ptr<Node> curNode) const;

};
