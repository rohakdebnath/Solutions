#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int ans[200001];

int calc(int i){
    int ret = 0;
    while (i){
        ret += i % 10;
        i /= 10;
    }

    return ret;
}

int rec(int i){
    if (i == 0) return 0;

    ans[i] = rec(i - 1) + calc(i);
    return ans[i];
}

void solve()
{
    int N; cin >> N;
    cout << ans[N] << '\n';
}

int main()
{
    UNSYNC
    rec(200000);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
