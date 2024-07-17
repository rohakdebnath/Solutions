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
    int A, B, C; cin >> A >> B >> C;
    if (A % 2 == 0 and A == B and B == C)
    {
        cout << -1 << '\n';
        return 0;
    }
    int count = 0;
    while (!(A % 2) and !(B % 2) and !(C % 2))
    {
        ++count;
        int tempA = A;
        int tempB = B;
        A = (B + C)/2;
        B = (C + tempA)/2;
        C = (tempA + tempB)/2;
    }

    cout << count << '\n';
    return 0;
}
