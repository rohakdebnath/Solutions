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
    int N, H; cin >> N >> H;
    vector<int> A (N), B (N);
    rep(i, 0, N){
        cin >> A[i] >> B[i];
    }
    sort(all(A)), sort(all(B));
    int ans = 0;
    int r = N - 1;
    while (H > 0 and r >= 0 and B[r] > A[N - 1]){
        H -= B[r--];
        ++ans;
    }
    if (H > 0){
        ans += (H - 1)/A[N - 1] + 1;
    }
    cout << ans << '\n';
    return 0;
}
