#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);
#define sz(x) static_cast<int>((x).size())
#define all(x) x.begin(), x.end()

void solve()
{
    int n;
    cin >> n;
    vector<int> deals (n); 
    for (int i {0}; i < n; ++i)
    {
        cin >> deals[i];
    }

    cout << accumulate(deals.begin(), deals.end(), 0) - *min_element(deals.begin(), deals.end()) << '\n';
}

int main()
{
    Unsync
    int tests;
    cin >> tests;

    while (tests--)
    {
        solve();
    }
    return 0;
}
