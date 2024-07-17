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
    int N; cin >> N;
    string S; cin >> S;
    transform(all(S), S.begin(), [] (char c) {
        return tolower(c);
    });
    VI alphaonce (26);
    for(char c: S) if (!alphaonce[c - 'a']) alphaonce[c - 'a'] = 1;
    int ans = accumulate(all(alphaonce), 0);
    cout << (ans == 26 ? "YES\n": "NO\n");
    return 0;
}
