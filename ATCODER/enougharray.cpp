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
    i64 N, K; cin >> N >> K;
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    i64 j = 0;
    i64 sum = 0;
    i64 count = 0;
    rep(i, 0, N){
        while (sum < K and j < N){
            sum += A[j];
            ++j;
        }
        if (sum >= K){
            count += N - j + 1;
        }
        sum -= A[i];
    }
    cout << count << '\n';
    return 0;
}
