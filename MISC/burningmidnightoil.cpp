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
    int l = 0, r = 9e8 + 1;
    while (r - l > 1){
        int M = l + (r - l)/2;
        int m = M;
        int sum = 0;
        while (m > 0){
            sum += m;
            m /= k;
        }
        if (sum < n){
            l = M;
        } else {
            r = M;
        }
    }
    cout << r << '\n';
    return 0;
}
