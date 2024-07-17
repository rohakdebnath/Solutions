#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

struct rstrnt
{
    string city;
    int n;
    int order;
};

bool operator<(const rstrnt& c1, const rstrnt& c2)
{
    return (c1.city < c2.city or (c1.city == c2.city and c1.n > c2.n));
}

int main()
{
    UNSYNC
    int n; cin >> n;
    vector<rstrnt> book (n);
    rep(0, n)
    {
        cin >> book[i].city >> book[i].n;
        book[i].order = i + 1;
    }

    sort(all(book));
    rep(0, n) cout << book[i].order << '\n';

    return 0;
}
