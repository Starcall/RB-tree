#pragma once
#include <cstddef>
#include <stdint.h>
#include <iterator>

template <class Key>
class Set
{
    typedef std::iterator<std::bidirectional_iterator_tag, Key> iterator;

    Set() = 0;
    virtual ~Set() = 0;

    virtual iterator begin() const = 0;
    virtual iterator end() const = 0;
    virtual iterator rbegin() const = 0;
    virtual iterator rend() const = 0;

    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
    virtual void clear() = 0;
    virtual void insert(const Key&) = 0;
    virtual void erase(const Key&) = 0;
    virtual void swap(Set<Key>&) = 0;

    virtual size_t count(Key) const = 0;
    virtual iterator find(int32_t) const = 0;

};
