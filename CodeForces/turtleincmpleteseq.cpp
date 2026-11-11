#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    if (count(a.begin(), a.end(), -1) == n) {
        for (int i = 0; i < n; ++i) {
            cout << i % 2 + 1 << " \n"[i == n - 1];
        }
        return;
    }

    int l = 0, r = n - 1;
    while (a[l] == -1) ++l;
    while (a[r] == -1) --r;

    for (int i = l - 1; i >= 0; --i) {
        if (a[i + 1] == 1) a[i] = 2;
        else a[i] = a[i + 1] / 2;
    }
    for (int i = r + 1; i < n; ++i) {
        if (a[i - 1] == 1) a[i] = 2;
        else a[i] = a[i - 1] / 2;
    }

    while (r - l > 1) {
        while (l + 1 < n and a[l + 1] != -1) ++l;
        int x = l + 1;
        while (a[x] == -1 and x < n) ++x;
        while (x - l > 1) {
            if (a[l] > a[x]) {
                if (a[l] == 1) a[l + 1] = 2;
                else a[l + 1] = a[l] / 2;
                ++l;
            } else {
                if (a[x] == 1) a[x - 1] = 2;
                else a[x - 1] = a[x] / 2;
                --x;
            }
        }

    }

    for (int i = 0; i < n - 1; ++i) {
        if ((a[i] / 2 == a[i + 1]) or (a[i] == a[i + 1] / 2)) continue;
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
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



