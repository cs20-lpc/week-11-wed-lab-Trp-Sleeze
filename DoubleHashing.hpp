#pragma once
#include "HashTableClosed.hpp"

template <typename T>
class DoubleHashing : public HashTableClosed<T> {
public:
    DoubleHashing(int size = 101)
        : HashTableClosed<T>(size) {}

    int hash2(const T& key) const {
        int k = static_cast<int>(key);
        int x = k % 7;
        int d = 7 - x;
        if (d == 0) d = 1;
        return d;
    }

    int probeIndex(const T& key, int i) const override {
        int h = this->hash1(key);
        int m = this->M;
        int d = hash2(key);
        long long add = 1LL * i * d;
        int idx = (int)((h + add) % m);
        return idx;
    }
};
