#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

int main()
{
    UNSYNC
    i64 N; cin >> N;
    rep(i, 1, 3501){
        rep(j, 1, 3501){
            i64 k = N * i * j / (4 * i * j - N * (i + j));
            if (4 * i * j - N * (i + j) > 0 and (N * i * j % (4 * i * j - N * (i + j))) == 0){
                cout << i << ' ' << j << ' ' << k << '\n';
                return 0;
            }
        }
    }
    return 0;
}
