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
        for (i64 j = 2 * i; j < MX; j += i){
            if (lowestfactor[j] != j) continue;
            lowestfactor[j] = i;
        }
    }
}
int main()
{
    UNSYNC
    sieve();
    map<vector<pair<int, int>>, int> enm;
    int N, K; cin >> N >> K;
    i64 ans = 0;
    rep(i, 0, N){
        int X; cin >> X;
        vector<pair<int, int>> pfact;
        while (lowestfactor[X] > 1){
            int p = 0;
            int x = lowestfactor[X];
            while (X % x == 0){
                ++p;
                X /= x;
            }
            p %= K;
            if (p) pfact.push_back({x, p});
        }
        vector<pair<int, int>> pfactreq = pfact;
        for (auto& [u, v]: pfactreq) v = K - v;
        ans += enm[pfactreq];
        ++enm[pfact];
    }
    cout << ans << '\n';
    return 0;
}
