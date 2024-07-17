#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (i64 i {ini}; i < x; ++i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 N; cin >> N;
    VI A (N); rep(0, N) cin >> A[i]; sort(all(A));
    VI ans;
    rep(1, N)
    {
        if (A[i] == A[i - 1]) 
        {
            ans.push_back(A[i]);
            ++i;
        }
    }
    cout << (ans.size() < 2 ? 0 : *(ans.end() - 1)*ans[ans.size() - 2]);
    cout << '\n';
    return 0;
}
