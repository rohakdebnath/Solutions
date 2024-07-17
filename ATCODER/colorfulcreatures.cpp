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
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    sort(all(A));
    i64 sum = accumulate(all(A), 0LL) - A[N - 1];
    int count = 1;
    vector<int> ans (N); ans[N - 1] = N;
    per(i, N - 2, 0){
        if (2*sum >= A[i + 1]) ans[i] = ans[i + 1];
        else ans[i] = i + 1;
        count += (ans[i] == N);
        sum -= A[i];
    }
    cout << count << '\n';
    return 0;
}
