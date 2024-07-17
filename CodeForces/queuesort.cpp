#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void solve()
{
    int N; cin >> N;
    deque<int> A (N); rep(i, 0, N) cin >> A[i];
    int ans = 0;
    int end = *min_element(all(A));
    rep(i, 0, N){
        if (A[0] == end or A.size() == 0) break;
        A.pop_front();
        ++ans;
    }
    cout << (is_sorted(all(A)) ? ans : -1) << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
