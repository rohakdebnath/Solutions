#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    int N; cin >> N;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    map<int, int> dp;

    int ans = 0;
    int lst = -1;
    rep(i, 0, N){
        int x = A[i];
        dp[x] = max(dp[x], dp[x - 1] + 1);
        if (dp[x] > ans){
            ans = dp[x];
            lst = x;
        }
    }
    cout << ans << '\n';
    deque<int> arr;
    per(i, N - 1, 0){
        if (A[i] == lst){
            arr.push_front(i + 1);
            --lst;
        }
    }
    rep(i, 0, arr.size()) cout << arr[i] << " \n"[i == arr.size() - 1];
    return 0;
}
