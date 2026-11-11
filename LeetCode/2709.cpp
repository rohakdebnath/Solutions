#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e5;

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

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& a) {
        int n = a.size();
        vector<int> lowestfactor (inf, 0);
        for (int i = 1; i <= inf; ++i) lowestfactor[i] = i;
        for (int i = 2; i <= inf; ++i) {
            for (int j = 2 * i; j <= inf; j += i) {
                if (lowestfactor[j] != j) continue;
                lowestfactor[j] = i;
            }
        }

        DSU dsu (n);
        map<int, int> rep;

        for (int i = 0; i < n; ++i) {
            int x = a[i];
            if (x == 1) continue;
            while (x > 1) {
                int p = lowestfactor[x];
                if (rep.find(p) == rep.end()) rep[p] = i;
                else dsu.merge(rep[p], i);

                while (x % p == 0) x /= p;
            }
        }

        return (dsu.size(0) == n);
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return 0;
}

