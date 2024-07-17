#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int N;
int dfs(string s){
    int ans = 0;
    int sz = s.size();
    if (sz == N){
        cout << s << '\n';
        return 1;
    }
    int h = (sz == 0 ? 0 : *max_element(all(s)) - 'a' + 1);
    rep(i, 0, h + 1) ans += dfs(s + char(i + 'a'));

    return ans;
}

int main()
{
    UNSYNC
    cin >> N;
    int ans = dfs("");
    // cout << ans << '\n';
    return 0;
}
