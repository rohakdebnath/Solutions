#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

const i64 MOD = 1e9 + 7;
int main()
{
    UNSYNC
    i64 N; cin >> N;
    vector<i64> freq (N);
    vector<i64> A (N); 
    rep(i, 0, N){
        cin >> A[i];
        ++freq[A[i]];
    } 
    if (N & 1LL){
        rep(i, 0, N){
            if ((i & 1LL) == 0){
                if (i == 0 and freq[i] != 1){
                    cout << "0\n";
                    return 0;
                }
                else if (i > 0 and freq[i] != 2){
                    cout << "0\n";
                    return 0;
                }
            } else {
                if (freq[i]) {
                    cout << "0\n";
                    return 0;
                }
            }
        }
    } else {
        rep(i, 0, N){
            if (i & 1){
                if (freq[i] != 2){
                    cout << "0\n";
                    return 0;
                }
            } else {
                if (freq[i]){
                    cout << "0\n";
                    return 0;
                }
            }
        }
    }

    i64 res = 1;
    i64 base = 2, pow = N/2;
    while (pow){
        if (pow & 1LL) res = (res * base) % MOD;
        base = (base * base) % MOD;
        pow /= 2LL;
    }
    cout << res << '\n';
    return 0;
}
