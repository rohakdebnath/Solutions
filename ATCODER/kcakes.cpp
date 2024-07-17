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
    int K, T; cin >> K >> T;
    vector<int> A (T); rep(i, 0, T) cin >> A[i];
    cout << max(0, 2**max_element(all(A)) - K - 1) << '\n';
    return 0;
}
