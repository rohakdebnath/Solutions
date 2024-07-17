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
    vector<int> C (N - 1), S (N - 1), F (N - 1);
    rep(i, 0, N - 1) cin >> C[i] >> S[i] >> F[i];

    rep(i, 0, N){
        int ans = 0;
        rep(j, i, N - 1){ //we can simulate going to each station and reaching the end by going to the next stations.
            if (ans < S[j]) ans = S[j]; //if we are currently running at time t, and the initial wait in a station is even greater than that, then we have to wait till S[j] no other way
            else if (ans % F[j] != 0){ //if we are in time but not in the perfect time to get a train, then we have to wait till the next train
                ans += F[j] - ans % F[j];
            }
            ans += C[j]; //the additional travel time adds either way
        }
        cout << ans << '\n'; //accumulating the times and printing
    }
    return 0;
}
