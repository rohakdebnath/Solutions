#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> v (n); for (int i = 0; i < n; ++i) cin >> v[i], --v[i];
    vector<int> s (n, -1), e (n, -1);
    for (int i = 0; i < n; ++i) {
        if (s[v[i]] == -1) s[v[i]] = i;
        e[v[i]] = i;
    }
    
    int l = n, r = -1; //valid range to start
    int a = 0, b = n - 1;
    for (int i = 0; i < n; ++i){
        int x = s[i], y = e[i];
        if (s[i] != -1) l = min(l, x), r = max(r, y);
        int extra = i - r + l; 

        if (extra < 0) {
            cout << "0\n";
            return;
        }
        int p = max(0, l - extra), q = min(n - 1, r + extra);
        a = max(a, p), b = min(b, q);
    }

    cout << max(b - a + 1, 0) << '\n';
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

