#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

string lw;
class Trie {
    public:
    struct TrieNode {
        map<char, int> children;
        int sum;
        int end;
        bool mark;
        TrieNode() : sum(0), end(0) {}
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
        for (char c: s) {
            if (trie[p].children.find(c) == trie[p].children.end()) {
                trie[p].children[c] = cnt++;
                trie.emplace_back();
            }
            p = trie[p].children[c];
            if (lw.find(c) != string::npos) {
                trie[p].mark = true;
            }
            trie[p].sum += t;
        }
        trie[p].end += t > 0;
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
    int n; cin >> n;
    vector<string> words (n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    lw = *max_element(words.begin(), words.end(), [] (const string &a, const string &b) {
        return a.size() < b.size();
    });

    Trie tr;
    for (int i = 0; i < n; ++i) {
        tr.insert(words[i]);
    }
    vector<char> ans;
    int count = 0;
    auto dfs = [&](auto&& self, int v) -> void {
        if (tr.trie[v].end != 0) {
            count += tr.trie[v].end;
            for (int i = 0; i < tr.trie[v].end; ++i) {
                ans.push_back('P');
            } 
        }
        if (tr.trie[v].children.empty()) {
            if (count < n) ans.push_back('-');
            return;
        }

        vector<pair<char, int>> csorted;
        for(auto &[c, s] : tr.trie[v].children){
            csorted.emplace_back(c, s);
        }
        sort(csorted.begin(), csorted.end(), [&](const pair<char, int> &a, const pair<char, int> &b) -> bool {
            return tr.trie[a.second].mark < tr.trie[b.second].mark;
        });

        for(auto& [c, s] : csorted){
            ans.push_back(c);
            self(self, s);
        }
        if (count < n) ans.push_back('-');
    };
    dfs(dfs, 0);

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
