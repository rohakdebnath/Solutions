#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    int n; cin >> n;
    string s; cin >> s;
    bitset<58> types;
    for (char c: s) types[c - 'A'] = 1;
    int tt = types.count();

    int mingap = INT32_MAX;

    int currtype = 0;
    VI currvis (58);
    int j = 0;
    rep(i, 0, n){
        while (currtype < tt and j < n){
            if (!currvis[s[j] - 'A']) ++currtype;
            ++currvis[s[j] - 'A'];
            ++j;
        }
        if (currtype == tt) mingap = min(mingap, j - i);
        if (currvis[s[i] - 'A'] == 1) --currtype;
        --currvis[s[i] - 'A'];
    }
    cout << mingap << '\n';
    return 0;
}
