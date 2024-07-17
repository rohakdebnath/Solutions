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
    sort(all(A));
    cout << A[N - 1] << ' ';
    auto it = lower_bound(all(A), (A[N - 1] + 1)/2);
    int c1 = *it;
    int c2 = it != A.begin() ? *(--it) : -INT32_MAX/2;
    if ((A[N - 1] + 1)/2 - c2 > c1 - (A[N - 1] + 1)/2){
        cout << c1 << '\n';
    } else {
        cout << c2 << '\n';
    }
    return 0;
}
