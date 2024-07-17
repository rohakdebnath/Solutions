#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    i64 N; cin >> N;
    while (N){
        i64 d = N % 10;
        if (d <= 8) {
            N -= 10 + d;
            N /= 10;
            if (N and N < 10){
                cout << "NO\n";
                return;
            }
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
