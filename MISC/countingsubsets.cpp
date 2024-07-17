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
    int n = 3;
    vector<int> sum (1 << n);
    vector<int> value = {3, -2, 43, 3, 1, 3, 9, 3};
    for (int s = 0; s < (1 << n); s++) {
        sum[s] = value[s];
    }

    for (int s = 0; s < (1 << n); s++) {
        for (int k = 0; k < n; k++) {
           if (s & (1 << k)) sum[s] += sum[s ^ (1 << k)];
        }
    }
    rep(i, 0, 1 << n){
        cout << sum[i] << " \n"[i == (1 << n) - 1];
    }


    for (int s = 0; s < (1 << n); s++) {
        sum[s] = value[s];
    }
    for (int k = 0; k < n; k++) {
        for (int s = 0; s < (1<<n); s++) {
           if (s&(1<<k)) sum[s] += sum[s^(1<<k)];
        }
    }
    rep(i, 0, 1 << n){
        cout << sum[i] << " \n"[i == (1 << n) - 1];
    }

    return 0;
}
