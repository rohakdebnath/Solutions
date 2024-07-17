#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int N; cin >> N;
    int l = inf, h = inf;
    int pen = 0;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        if (x > h){
            ++pen;
            l = h;
            h = x;
        } else if (x < h and x > l){
            h = x;
        } else if (x < l){
            l = x;
        }
    }
    cout << pen << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
