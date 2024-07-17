#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

const int MX = 100001;
int primes[MX];
void sieve(){
    rep(i, 2, MX){
        if (!primes[i]) continue;
        for (i64 j = 1LL * i * i; j < MX; j += i){
            primes[j] = 0;
        }
    }
}

int main()
{
    UNSYNC
    rep(i, 0, MX) primes[i] = 1;
    sieve(); primes[1] = primes[0] = 0;

    vector<int> primepf (MX);
    rep(i, 1, MX){
        if (i & 1){
            primepf[i] = primepf[i - 1] + (primes[i] and primes[(i + 1)/2]);
        } else {
            primepf[i] = primepf[i - 1];
        }
    }

    int Q; cin >> Q;
    rep(i, 0, Q){
        int l, r; cin >> l >> r;
        cout << primepf[r] - primepf[l - 1] << '\n';
    }
    return 0;
}
