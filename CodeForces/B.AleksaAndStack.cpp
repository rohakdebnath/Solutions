#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);
#define sz(x) static_cast<ll>((x).size())
#define all(x) x.begin(), x.end()
 
 
void solve()
{
    int n;
    cin >> n;
    for (int i {0}; i < n; ++i)
    {
        cout << 2*i+1 << ' ';
    }
}
 
int main()
{
    Unsync
    ll tests;
    cin >> tests;
 
    while (tests--)
    {
        solve();
    }
    return 0;
}
