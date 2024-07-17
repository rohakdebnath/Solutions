#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int m, x; cin >> m >> x;
    priority_queue<int> taken;
    int money = 0;
    rep(i, 0, m){
        int h; cin >> h;
        money -= h;
        taken.push(h);
        if (money < 0){
            money += taken.top();
            taken.pop();
        }
        money += x;
    }
    cout << taken.size() << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
