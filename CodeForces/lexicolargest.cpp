#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N; cin >> N;
    vector<int> A (N);
    rep(i, 0, N){
        int x; cin >> x;
        A[i] = x + i + 1;
    }
    sort(all(A), greater<int> ()); // 5 4 3 2 1  -> 6 5 4 3 2 not 6 6 6 6 6
    rep(i, 1, N) A[i] = min(A[i], A[i - 1] - 1);

    rep(i, 0, N) cout << A[i] << " \n"[i == N - 1];

}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
