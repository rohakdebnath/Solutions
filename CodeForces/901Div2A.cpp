#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);
#define sz(x) static_cast<int>((x).size())
#define all(x) x.begin(), x.end()

void solve()
{
    int max, ini, n;
    cin >> max >> ini >> n;
    vector<int> tools (n);
    for (int i {0}; i < n; ++i)
    {
        cin >> tools[i];
    }

    i64 net {ini};
    for (int i {0}; i < n; ++i)
    {
        if (tools[i]+1 > max) net += max - 1;
        else net += tools[i];
    }
    cout << net << '\n';
}

int main()
{
    Unsync
    int tests;
    cin >> tests;
    while(tests--)
    {
        solve();
    }

    return 0;
}
