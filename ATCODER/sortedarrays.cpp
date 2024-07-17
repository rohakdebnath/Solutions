#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int N; cin >> N;
    vector<int> A; 
    int ini; cin >> ini;
    A.push_back(ini);
    rep(1, N)
    {
        int a; cin >> a;
        if (A.back() != a) A.push_back(a);
    }
    int segs = 1;
    rep(1, A.size() - 1)
    {
        if ((A[i] < A[i - 1] and A[i] < A[i + 1]) or (A[i] > A[i - 1] and A[i] > A[i + 1]))
        {
            ++segs;
            ++i;
        }
    }
    cout << segs << '\n';
    return 0;
}
