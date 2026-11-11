#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Hero {
public:
    static int timeToComplete;      
    static void random() {
        cout << timeToComplete << endl;
    }
};
    
int Hero::timeToComplete = 100;     
    

signed main() {
    Hero::random();
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
