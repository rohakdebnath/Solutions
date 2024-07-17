#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>


int main()
{
    UNSYNC
    string keyb = "qwertyuiopasdfghjkl;zxcvbnm,./";
    unordered_map<char, int> chartopos;
    rep(i, 0, 30) chartopos[keyb[i]] = i;

    char shift; cin >> shift;
    string s; cin >> s;
    int sht = (shift == 'L' ? 1 : -1);
    for (char c: s) cout << keyb[chartopos[c] + sht];
    cout << '\n';
    return 0;
}
