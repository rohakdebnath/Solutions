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
    int N, M, X, Y; cin >> N >> M >> X >> Y;
    rep(i, 0, N){
        rep(j, 0, M){
            cout << ((i < Y) ^ (j < X));
        }
        cout << '\n';
    }
    return 0;
}
