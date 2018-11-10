//
// Created by stephanie on 08/11/18.
//

#ifndef LOG_HEAP_H
#define LOG_HEAP_H


#include <queue>

template<   class T,
            class Container = std::vector<T>,
            class Compare = std::less<typename Container::value_type>
        >
class Heap : public std::priority_queue<T, Container, Compare>
{
public:
    typedef typename
    std::priority_queue<
            T,
            Container,
            Compare>::container_type::const_iterator const_iterator;

    bool exists(const T&val) const
    {
        auto first = this->c.cbegin();
        auto last = this->c.cend();
        while (first!=last) {
            if (*first==val) return true;
            ++first;
        }
        return false;
    }
};


#endif //LOG_HEAP_H
