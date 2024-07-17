#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

const int MX = 1000001;
int lowestfactor[MX];
void sieve(){
    rep(i, 1, MX) lowestfactor[i] = i;
    rep(i, 2, MX){
        if (lowestfactor[i] != i) continue;
        for (i64 j = 2 * i; j < MX; j += i){
            lowestfactor[j] = i;
        }
    }
}

int main()
{
    UNSYNC
    sieve();
    int N; cin >> N;
    while (N--){
        int Q; cin >> Q;
        map<int, int> factorcount;
        while (Q > 1){
            ++factorcount[lowestfactor[Q]];
            Q /= lowestfactor[Q];
        }
        i64 prod = 1;
        for (auto [u, v]: factorcount){
            prod *= (v + 1);
        }
        cout << prod << '\n';
    }

    return 0;
}
