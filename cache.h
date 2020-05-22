#pragma once

#include <list>
#include <unordered_map>

/**
 * Класс должен реализовать кэш. Кэш должен быть фиксированного
 * размера, внутри должна быть очередь на "вытеснение" из кэша.
 * Все операции над кэшом должны иметь сложность O(1).
 */
template <typename K, typename V>
class Cache
{
public:
    Cache(size_t sz): map_(sz), sz_(sz) {}

    /**
     * Если элемент был запрошен с помощью метода get, запрошенный
     * элемент должен переместиться в самое начало очереди.
     */
    V& get(const K& k);

    /**
     * Метод has должен проверять наличие элемента, но не менять положение элемента в очереди.
     */
    bool has(const K& k) const;

    /**
     * При добавлении элемента в кэш с помощью set он должен оказаться в начале очереди.
     * Если элемент уже присутствовал в очереди, он должен переместиться в самое начало очереди.
     * Если элемента в очереди не было и очередь достигла максимального
     * размера, из нее должен быть "вытеснен" элемент с самого конца.
     */
    void set(const K& k, const V& v);

    size_t size() const { return map_.size(); }

    size_t capacity() const { return sz_; }

    void pop();

private:
    typedef std::list<K> Queue;
    Queue q_;
    std::unordered_map<K, std::pair<V, typename Queue::iterator>> map_;
    const size_t sz_;
};

template <typename K, typename V>
V& Cache<K, V>::get(const K& k) {
    auto& [v, it] = map_.at(k);
    auto begin = q_.begin();
    if (it == begin)
        return v;

    q_.splice(begin, q_, it);
    return v;
}

template <typename K, typename V>
bool Cache<K, V>::has(const K& k) const {
    return sz_ && map_.find(k) != map_.end();
}

template <typename K, typename V>
void Cache<K, V>::set(const K& k, const V& v) {
    if (!sz_)
        return;

    if (has(k)) {
        get(k) = v;
        return;
    }

    if (size() == sz_)
        pop();

    q_.push_front(k);
    map_[k] = {v, q_.begin()};
}

template <typename K, typename V>
void Cache<K, V>::pop() {
    if (q_.empty())
        return;

    map_.erase(q_.back());
    q_.pop_back();
}
