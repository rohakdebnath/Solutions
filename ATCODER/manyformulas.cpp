#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

i64 N;
string s; 

i64 dfs(i64 x, i64 val){
    if (x == N) return val;
    i64 ret = 0;
    rep(i, x, N) ret += dfs(i + 1, val + stol(s.substr(x, i - x + 1)));
    return ret;
}

int main()
{
    UNSYNC
    cin >> s;
    N = s.size();
    i64 ans = dfs(0, 0);
    cout << ans << '\n';
    return 0;
}
