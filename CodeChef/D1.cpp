#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void solve()
{
    i64 N; cin >> N;
    VI A (N); rep(i, 0, N) cin >> A[i];
    sort(all(A));
    VI ans {A[0]};
    VI junk;
    i64 i = 1;
    i64 sum = A[0];
    i64 cursed = 0;
    while (i < N)
    {
        while (A[i] <= sum and i < N)
        {
            junk.push_back(A[i]);
            ++i;
            ++cursed;
        }
        if (i < N)
        {
            sum += A[i];
            ans.push_back(A[i]);
        }
        ++i;
    }
    ans.insert(ans.end(), all(junk));
    cout << cursed << '\n';
    for(i64 x : ans) cout << x << ' ';
    cout << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
