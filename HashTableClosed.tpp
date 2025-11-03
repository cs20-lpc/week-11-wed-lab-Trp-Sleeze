template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    int probes = 0;
    for (int i = 0; i < M; i++) {
        int idx = probeIndex(key, i);
        probes++;

        if (!occupied[idx]) {
            table[idx] = key;
            occupied[idx] = true;
            N++;
            return probes;
        }
        if (occupied[idx] && table[idx] == key) {
            // already there
            return probes;
        }
    }
    // table full
    throw std::runtime_error("Hash table is full");
}

template <typename T>
std::pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    int probes = 0;
    for (int i = 0; i < M; i++) {
        int idx = probeIndex(key, i);
        probes++;

        if (!occupied[idx]) {
            // hit an empty spot => not found
            return {false, probes};
        }
        if (table[idx] == key) {
            return {true, probes};
        }
    }
    return {false, probes};
}
