#pragma once
#include "HashTableClosed.hpp"

template <typename T>
class LinearProbing : public HashTableClosed<T> {
private:
    int skip;
public:
    LinearProbing(int size = 101, int skipFactor = 3)
        : HashTableClosed<T>(size), skip(skipFactor) {}

    int probeIndex(const T& key, int i) const override {
        int h = this->hash1(key);
        int m = this->M;
        int step = (i * skip) % m;
        int idx = h + step;
        if (idx >= m) idx -= m;
        return idx;
    }
};
