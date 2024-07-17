#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

void solve()
{
    int n;
    cin >> n;

    vector<int> b (n);

    rep1(n) {cin >> b[i];}

    vector<int> changeLog;
    for (int i {1}; i < n; ++i)
    {
        if (b[i - 1] > b[i]) 
        {
            changeLog.emplace_back(i);
        }
    }

    cout << n + changeLog.size() << '\n';
    for (int i {1}; i < n; ++i)
    {
        cout << b[i - 1] << ' ';
        if (b[i - 1] > b[i])
        {
            cout << 1 << ' ';
        }
    }
    cout << b[n - 1] << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }

    return 0;
}
