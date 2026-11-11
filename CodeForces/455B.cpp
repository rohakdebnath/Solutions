#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

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

void solve() {
    int n, k; cin >> n >> k;
    Trie trie;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        trie.insert(s);
    }
    vector<vector<int>> dp (2, vector<int> (trie.trie.size(), -1));

    auto dfs = [&](auto&& self, int v, int t) -> bool {
        if (trie.trie[v].children.empty()) {
            return dp[t][v] = (t == 1); 
        }

        bool outc = false;
        for (auto& [c, s]: trie.trie[v].children) {
            outc |= !self(self, s, t);
            if (outc) break; 
        }
        return dp[t][v] = outc;
    };
    for (int t = 0; t < 2; ++t) {
        dfs(dfs, 0, t);
    } 
    if (dp[0][0] and (dp[1][0] or k % 2)) cout << "First\n";
    else cout << "Second\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
