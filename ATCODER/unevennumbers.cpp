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
    int t = N;
    int oom = 0;
    while (t >= 10)
    {
        ++oom;
        t /= 10;
    }

    int nums = 0;
    for (int i = 0; i < oom; ++i)
    {
        if (i % 2 == 0) nums += pow(10, i + 1) - pow(10, i);
    }
    if (oom % 2 == 0) nums += N - pow(10, oom) + 1;

    cout << nums << '\n';
    return 0;
}
