#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Trie {
    public:
    struct TrieNode {
        array<int, 2> children {};
        int sum;
        TrieNode() : sum(0) {}
    };

    vector<TrieNode> trie;
    int cnt;

    Trie() {
        trie.emplace_back(); 
        cnt = 1;
    }

    void add(int& n, int t = 1) {
        int p = 0;
        trie[p].sum += t;
        for (int i = 29; i >= 0; --i) {
            int c = n >> i & 1;
            if (trie[p].children[c] == 0) {
                trie[p].children[c] = cnt++;
                trie.emplace_back();
            }
            p = trie[p].children[c];
            trie[p].sum += t;
        }
    }

    void insert(int s) {
        add(s, 1);
    }

    void erase(int s) {
        add(s, -1);
    }

    int query(int& n) {
        int p = 0, xors = 0;
        for (int i = 29; i >= 0; --i) {
            int c = (n >> i) & 1;
            if (trie[p].children[!c] != 0 and trie[trie[p].children[!c]].sum > 0) {
                p = trie[p].children[!c];
                xors ^= (1 << i);
            } else {
                p = trie[p].children[c];
            }
        }
        return xors; 
    }
}; 

void solve() {
    int n; cin >> n;
    Trie t;
    t.insert(0);
    while (n--) {
        char c; cin >> c;
        int x; cin >> x;
        if (c == '+') t.insert(x);
        else if (c == '-') t.erase(x);
        else {
            cout << t.query(x) << '\n';
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
