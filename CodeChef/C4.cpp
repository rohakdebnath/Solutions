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

void solve()
{
    i64 N; cin >> N;
    i64 sqt = sqrt(N);
    if (N & 1){
        if (sqt & 1) cout << (i64(sqrt(N)) + 1)/2<< '\n';
        else cout << i64(sqrt(N)/2) << '\n';
    } else {
        cout << i64(sqrt(N)/2) << '\n';
    }
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
