#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i {ini}; i < x; ++i)
#define per(i, fin, x) for (int i {fin}; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int N; cin >> N;
    VI A (N); rep(i, 0 , N) cin >> A[i];
    sort(all(A));
    if (A[N - 1] == 0)
    {
        cout << "Yes\n";
        return 0;
    }
    if (N % 3 != 0) cout << "No\n";
    else
    {
        if ((A[0]^A[2*N/3]) == A[N/3] and A[0] == A[N/3 - 1] and A[N/3] == A[2*N/3 - 1] and A[2*N/3] == A[N - 1]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
