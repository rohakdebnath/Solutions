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
    string S; cin >> S;
    int closest = INT32_MAX;
    for (int i = 2; i < sci(S.size()); ++i)
    {
        int n = stoi(S.substr(i - 2, 3));
        closest = min(closest, abs(753 - n));
    }

    cout << closest << '\n';
    return 0;
}
