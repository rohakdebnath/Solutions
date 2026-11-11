#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, x; cin >> n >> x;
    vector<i64> p (n); for (i64 i = 0; i < n; ++i) cin >> p[i];
    
    auto run = [&] (i64 r, i64 t) -> vector<i64> {
        vector<i64> f;
        auto sub = [&] (auto&& self, i64 i, i64 s) -> void {
            if (i == t) {
                f.push_back(s);
                return;
            }
            self(self, i + 1, s);
            self(self, i + 1, s + p[i]);
        };
        sub(sub, r, 0LL);
        return f;
    };
    vector<i64> l = run(0, n / 2), r = run(n / 2, n);
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    i64 ans = 0;

	for (i64 i : l) {
        ans += distance(lower_bound(r.begin(), r.end(), x - i), upper_bound(r.begin(), r.end(), x - i));
	}

    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}


class Trie {
    public:
    struct TrieNode {
        map<char, int> children;
        int sum;
        TrieNode() : sum(0) {}
    };

    vector<TrieNode> trie;
    int cnt;

    Trie() {
        trie.emplace_back(); 
        cnt = 1;
    }

    void add(const string& s, int t = 1) {
        int p = 0;
        trie[p].sum += t;
        for (char c : s) {
            if (trie[p].children.find(c) == trie[p].children.end()) {
                trie[p].children[c] = cnt++;
                trie.emplace_back();
            }
            p = trie[p].children[c];
            trie[p].sum += t;
        }
    }

    void insert(const string& s) {
        add(s, 1);
    }

    void erase(const string& s) {
        add(s, -1);
    }

    bool search(const string& s) {
        int p = 0;
        for (char c : s) {
            if (trie[p].children.find(c) == trie[p].children.end()) {
                return false;  
            }
            p = trie[p].children[c];
        }
        return trie[p].sum > 0; 
    }

    int countPrefix(const string& prefix) {
        int p = 0; 
        for (char c : prefix) {
            if (trie[p].children.find(c) == trie[p].children.end()) {
                return 0;
            }
            p = trie[p].children[c];
        }
        return trie[p].sum;
    }
}; 
