#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    int N; cin >> N;
    string s; cin >> s;
    int ans = 0;
    int p = 0;
    map<int, int, greater<int>> M;
    ++M[0];
    rep(i, 0, N){
        p += s[i] == '(' ? 1 : -1;
        ans += M[p];
        ++M[p];
        while (M.begin() ->first > p) M.erase(M.begin());
    }
    cout << ans << '\n';
    return 0;
}
