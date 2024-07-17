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
    VI a (2*n + 1); rep(i, 0, 2*n + 1) cin >> a[i];
    int peakred = 0;
    for(int i = 1; i < 2*n and peakred < k; i += 2){
        if (a[i] - 1 > a[i - 1] and a[i] - 1 > a[i + 1]){
            ++peakred;
            --a[i];
        }
    }
    for (int i : a) cout << i << ' ';
    cout << '\n';
    return 0;
}
