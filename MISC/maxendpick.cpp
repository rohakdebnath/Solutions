//Q: A and B play a game, starting with A. given an array a player can pick either ends of the array and remove the element, adding points equal to that element to them, find maximum possible A - B if optimal play
//Ans: call f(i, j) the maximum point diff function for the game starting at seg i..j, then f(i, j) = max(a[i] - f(i + 1, j), a[j] - f(i, j - 1))
//need to know smaller windows before iterating wider windows, so a small to large window iteration can help find the answer, either pull from 1 length smaller windows, or push influence from a smaller window to a 1 length larger window on either side
//another way to implement is the one written below, a clever iteration path reduces memory complexity by one factor.
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp (n); //dp[j] = value of f for a segment ending at j, starting at i, by the end of the iteration i will be 0 and j will be n - 1
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            dp[j] = max(a[i] - dp[j], a[j] - dp[j - 1]);
        }
    }
    cout << dp[n - 1] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
