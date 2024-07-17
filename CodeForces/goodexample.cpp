#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    int n, k; cin >> n >> k;
    vector<string> a (n);
    rep(i, 0, n){
        cin >> a[i];
    }
    int good = 0;
    rep(i, 0, n){
        bitset<10> occ;
        for (char c: a[i]){
            occ[c - '0'] = 1;
        }
        bool survive = true;
        rep(j, 0, k + 1){
            if (!occ[j]){
                survive = false;
                break;
            }
        }
        good += (survive? 1 : 0);
    }
    cout << good << '\n';
    return 0;
}
