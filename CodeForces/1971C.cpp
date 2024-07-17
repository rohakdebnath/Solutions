#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int a, b, c, d; cin >> a >> b >> c >> d;
    int at = a % 12 + 1;
    vector<int> div1, div2;
    while(at != b){
        div1.push_back(at);
        at = at % 12 + 1;
    }
    int bt = b % 12 + 1;
    while (bt != a){
        div2.push_back(bt);
        bt = bt % 12 + 1;
    }

    int ans = (find(all(div1), c) != div1.end()) + (find(all(div2), d) != div2.end());
    if (ans == 0 or ans == 2){
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
