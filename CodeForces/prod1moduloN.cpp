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
    vector<i64> cop;
    rep(i, 0, N){
        if (gcd(i + 1, N) == 1) cop.push_back(i + 1);
    }

    i64 prod = 1;
    for (i64 i: cop){
        prod = prod * i % N;
    }
    i64 d = prod != 1;
    cout << cop.size() - d << '\n';
    rep(i, 0, cop.size() - d){
        cout << cop[i] << " \n"[i == cop.size() - d - 1];
    }

    return 0;
}
