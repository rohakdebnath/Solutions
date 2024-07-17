#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (i64 i {ini}; i < x; ++i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

struct Shop
{
    i64 price;
    i64 drinks;
};

bool operator<(const Shop& a, const Shop& b)
{
    return a.price < b.price;
}

int main()
{
    UNSYNC
    i64 N, M; cin >> N >> M;
    vector<Shop> data (N);
    rep(0, N)
    {
        cin >> data[i].price >> data[i].drinks;
    }
    sort(all(data));
    i64 bought = 0;
    i64 cost = 0;
    i64 i = 0;
    while (bought < M and i < N)
    {

        i64 buys = min(data[i].drinks, M - bought);
        bought += buys;
        cost += data[i].price*buys;
        ++i;
    }
    cout << cost << '\n';
    return 0;
}
