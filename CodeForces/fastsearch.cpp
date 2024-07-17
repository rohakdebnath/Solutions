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

int main()
{
    UNSYNC
    int N; cin >> N;
    VI A (N); rep(i, 0, N) cin >> A[i];
    sort(all(A));

    int k; cin >> k;
    rep(i, 0, k) {
        int s, e; cin >> s >> e;
        int l = -1, r = N;
        while(r > l + 1){
            int m = (l + r)/2;
            if (A[m] <= e){
                l = m;
            } else {
                r = m;
            }
        }
        int ans = l;
        l = -1; r = N;
        while(r > l + 1){
            int m = (l + r)/2;
            if (A[m] < s){
                l = m;
            } else {
                r = m;
            }
        }
        ans -= r;
        cout << ans + 1 << '\n';
    }
    return 0;
}
