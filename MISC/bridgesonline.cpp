template <typename T = int>
class DSU {
private:
    vector<T> parent;
    vector<int> s;

public:
    DSU(T n) : parent(n), s(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    T find(T x) {
        while (x != parent[x]) {
            x = parent[x] = parent[parent[x]];
        }
        return x;
    }

    bool merge(T x_, T y_) {
        T x = find(x_);
        T y = find(y_);

        if (x == y) return false; 

        if (s[x] < s[y]) {
            parent[x] = y;
            s[y] += s[x];
        } else {
            parent[y] = x;
            s[x] += s[y];
        };
        return true;
    }

    bool connected(T x, T y) {
        return find(x) == find(y);
    }

    int size (int x) {
        return s[find(x)];
    }
};



