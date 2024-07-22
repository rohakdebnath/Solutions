#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int inf = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp (n + 1, inf), b (n + 1); dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = min(dp[i + 1], dp[i] + (a[i] > 0));
        if (i + 1 < n and a[i] <= 4 and a[i + 1] <= 4) {
            b[i + 2] = min(b[i] + 2, b[i + 2]);
        }
        if (a[i] <= 2) {
            b[i + 1] = min(dp[i] + 1, b[i + 1]);
            dp[i + 1] = min(dp[i + 1], b[i]);
        }
    }
    cout << dp[n] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

//we can define dp[i] = min ops till ith index, and we need another array call it b, which will help us place the squares
//we will never need more than two two stacked squared to remove black ink, in fact there are only two forms of squares required
//1. Plain old square at the base. we can place this if current height is \leq 2 if we place this we will set b[i] = chmin dp[i - 1] + 1, then if the next black length (a[i]) is <= 2 we can do chmin(dp[i], b[i - 1]), because placing the square on base of i - 1 will cover the element at i also as long as it's less than equal to 2
//2. 2 4 2 type squares, where 2 of the upper left height is covered and 2 upper middle by one box and lower mid 2 and right 2 by the second box, 
// this one can be placed if current height and height of next is \leq 4, then we can do chmin b[i + 1], b[i - 1] + 2, it is clear that b[i - 1]'s use implies that the lower 2 of the current index is expectec to be cleared by base square box of i - 1
// this lower 2 clearing box can come from a 1. type box from i - 1 or a 2 type box itself or not get cleared at all, in which case its still inf
// this dp therefore considers the best amongst all possible box or row placement
