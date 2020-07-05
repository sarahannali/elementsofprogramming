#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <queue>
#include <unordered_map>
#include <utility>
#include <list>

namespace LRUCaches
{
    class LRUCache
    {
    public:
        bool Lookup(int, int *);
        void Insert(int, int);
        void Remove(int);

    private:
        typedef std::unordered_map<int, std::pair<std::list<int>::iterator, int>> Table;

        Table price_table;
        std::list<int> lru_list;
        int capacity;
        void MoveToFront(int, const Table::iterator &);
    };
} // namespace LRUCaches

#endif