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
    int A, B; cin >> A >> B;
    int pals = 0;
    for (int i = A; i <= B; ++i)
    {
        string pp = to_string(i);
        if (pp[0] == pp[4] and pp[1] == pp[3]) ++pals;
    }
    cout << pals << '\n';
    return 0;
}
