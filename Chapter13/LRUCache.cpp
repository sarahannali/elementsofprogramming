#include "LRUCache.h"

namespace LRUCaches
{
    bool LRUCache::Lookup(int given_ISBN, int *price)
    {
        auto it = price_table.find(given_ISBN);
        if (it != price_table.cend())
        {
            *price = it->second.second;
            MoveToFront(given_ISBN, it);
            return true;
        }
        return false;
    }

    void LRUCache::Insert(int given_ISBN, int price)
    {
        auto it = price_table.find(given_ISBN);
        if (it != price_table.cend())
        {
            MoveToFront(given_ISBN, it);
        }
        else
        {
            if (price_table.size() == capacity)
            {
                price_table.erase(lru_list.back());
                lru_list.pop_back();
            }

            lru_list.push_front(given_ISBN);
            price_table[given_ISBN] = {lru_list.begin(), price};
        }
    }

    void LRUCache::Remove(int given_ISBN)
    {
        auto it = price_table.find(given_ISBN);
        if (it != price_table.cend())
        {
            lru_list.erase(it->second.first);
            price_table.erase(it);
        }
    }

    void LRUCache::MoveToFront(int given_ISBN, const Table::iterator& it)
    {
        lru_list.remove(given_ISBN);
        lru_list.push_front(given_ISBN);

        it->second.first = lru_list.begin();
    }

} // namespace LRUCaches