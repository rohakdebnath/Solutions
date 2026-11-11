#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Trie {
private:
    struct TrieNode {
        map<char, int> children;
        int sum;
        TrieNode() : sum(0) {}
    };

    vector<TrieNode> trie;
    int cnt;

public:
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
    int partialPrefix(const string& str) {
        int p = 0; 
        int sum = 0;
        for (char c : str) {
            if (trie[p].children.find(c) == trie[p].children.end()) {
                return 0;
            }
            p = trie[p].children[c];
            sum += trie[p].sum;
        }
        return sum;
    }

    int countUniquePrefix () {
        return cnt - 1;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        Trie trie;

        for (int i = 0; i < n; ++i) {
            trie.insert(words[i]);
        }
        vector<int> ans (n);
        for (int i = 0; i < n; ++i) {
            ans[i] = trie.partialPrefix(words[i]);
        }
        return ans;
    }
};

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<string> words (n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    Solution a;
    auto v = a.sumPrefixScores(words);
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " \n"[i == n - 1];
    }
    return 0;
}
