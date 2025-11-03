#pragma once
#include "HashTableClosed.hpp"

template <typename T>
class QuadraticProbing : public HashTableClosed<T> {
public:
    explicit QuadraticProbing(int size = 101)
        : HashTableClosed<T>(size) {}

    int probeIndex(const T& key, int i) const override {
        int h = this->hash1(key);
        int m = this->M;
        long long add = 1LL * i * i;
        int idx = (int)((h + add) % m);
        return idx;
    }
};
