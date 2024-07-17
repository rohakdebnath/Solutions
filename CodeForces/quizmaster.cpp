#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

VVI factors (1e5 + 1);
void init(){
    rep(i, 1, 1e5 + 1){
        for (int j = i; j < 1e5 + 1; j += i){
            factors[j].push_back(i);
        }
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    VI a (n); rep(i, 0, n) cin >> a[i];
    sort(all(a));

    VI freq (a[n - 1] + 1);

    int mingap = INT32_MAX;
    int count = 0;
    int j = 0;
    rep(i, 0, n){
        while (count < m and j < n){
            for (int f : factors[a[j]]){
                if (!freq[f] and f <= m) ++count;
                ++freq[f];
            }
            ++j;
        }
        if (count == m){
            mingap = min(mingap, a[j - 1] - a[i]);
        }
        for (int f : factors[a[i]]){
            --freq[f];
            if (freq[f] == 0 and f <= m) --count;
        }
    } 
    cout << (mingap == INT32_MAX ? -1 : mingap) << '\n';
}

int main()
{
    UNSYNC
    init();
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
