    //memoisation needed since the state is too complex to iterate for me
    //dp(i, j, k) means we are concerned about the subarray i..j and our current count of continuous element contains k 
    //we will use dfs and memoise
    //we are looking for removing contiguous subarrays, this continuous subarrays can come from discontinous parts of the array, which will nean that we need to remove the inbetween elements first, basically start the dfs from
    //the start of such in betweens with k = 0. k will be non zero from the start of a dfs node if it is intended to be merged with k equal values (equal to a[i], whatever that i is for that dfs node) first, then removed together
    //another thing to notice is that not all the occurances of a number need to be merged together first eg 1 2 2 1 2 2 1 1, leaving the 1 at index 3 is better, by removing that one first then the 2s and then the three 1s.
    //hence for each contiguous subarray with equal value, we have to take care of the case where we dont take it. essentially we only need to create branches of the dfs where: one where we remove the current contiguous and then move forward normally or we continue from another contiguous by skipping some contiguous subarrays (with value = targ) and remove the inbetweens separately first (this part can be iterated increasing the complexity by one more power of n)
    //1. ans = count^2 + dfs(i', j, 0); where i' is the next index within j which is not equal to a[i]
    //2. ans = max(ans, dfs(i', m - 1, 0) + dfs(m, j, count)), where m each of the position where a[i] == a[m]
    //note that the combination of these cases takes care of all the cases where we skip some contiguous subarrays (of each element value = targ, basically continuable with a[ini])
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<vector<int>>> dp (n, vector<vector<int>> (n, vector<int> (n, -1))); //if dp[i][j][k] = -1 means its not visited yet
    auto dfs = [&] (auto&& self, int i, int j, int k) -> int {
        if (i > j) return 0;
        if (dp[i][j][k] != -1) return dp[i][j][k];
        int ini = i, inik = k;
        while ((i <= j) and (a[i] == a[ini])) { //turn i into i'
            ++k;
            ++i;
        }
        int ans = k * k + self(self, i, j, 0);
        for (int x = i + 1; x <= j; ++x) {
            if (a[x] == a[ini]) {
                ans = max(ans, self(self, i, x - 1, 0) + self(self, x, j, k));
            }
        }
        return dp[ini][j][inik] = ans;
    };

    cout << dfs(dfs, 0, n - 1, 0) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
