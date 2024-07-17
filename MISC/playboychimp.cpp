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
    int N; cin >> N;
    VI h (N); rep(i, 0, N) cin >> h[i];
    int smol, beeg;
    int Q; cin >> Q;
    while (Q--){
        int q; cin >> q;
        int l = - 1, r = N;
        while (r - l > 1){
            int m = l + (r - l)/2;
            if (h[m] < q){
                l = m;
            } else {
                r = m;
            }
        }
        smol = l;

        l = - 1, r = N;
        while (r - l > 1){
            int m = l + (r - l)/2;
            if (h[m] > q){
                r = m;
            } else {
                l = m;
            }
        }
        beeg = r;

        if (smol == -1){
            cout << "X ";
        } else {
            cout << h[smol] << ' ';
        }
        if (beeg == N){
            cout << "X\n";
        } else {
            cout << h[beeg] << '\n';
        }
    }
    return 0;
}
