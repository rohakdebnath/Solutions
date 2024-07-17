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
    int c = count(all(s), '1');
    if (c == 1){
        cout << "11\n";
    } else if (c == 3){
        cout << "231\n";
    } else if (c == 4){
        cout << "441\n";
    } else {
        if (s == "1100" or s == "0011") cout << "21\n";
        else cout << "121\n";
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
