#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    string s; cin >> s;
    string sn = s;
    sort(all(sn));
    if (*sn.begin() == *(sn.end() - 1)){
        cout << "NO\n";
    } else {
        cout << "YES\n";
        if (sn == s){
            reverse(all(sn));
            cout << sn << '\n';
        } else {
            cout << sn << '\n';
        }
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
