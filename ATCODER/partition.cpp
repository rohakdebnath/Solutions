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
    int N, M; cin >> N >> M;
    int g = 1;
    auto check = [&] (int d){
        if (M / d >= N){
            g = max(g, d);
        }
    };
    for (int i = 1; i * i <= M; ++i){
        if (M % i == 0){
            check(i);
            check(M / i);
        }
    }
    cout << g << '\n';
    return 0;
}
