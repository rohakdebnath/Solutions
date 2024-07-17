#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);
#define sz(x) static_cast<int>((x).size())
#define all(x) x.begin(), x.end()

int main()
{
    Unsync
    int pn {};
    cin >> pn;
    if (pn <= 10 and pn >= 8) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
