#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 n, k; cin >> n >> k;
    VI A (n); rep(i, 0, n) cin >> A[i];
    i64 l = 0, r = accumulate(all(A), 0LL) + 1;
    while (r - l > 1){
        i64 m = l + (r - l)/2; //check if divisions with atleast m or more sum is possible
        i64 sum = 0;
        i64 divs = 1;
        rep(i, 0, n){
            if (A[i] > m){
                divs += k;
                break;
            }
            if (sum + A[i] > m){
                ++divs;
                sum = A[i];
            } else {
                sum += A[i]; 
            }
        }
        if (divs > k){
            l = m;
        } else {
            r = m;
        }
    }
    cout << r << '\n';
    return 0;
}
