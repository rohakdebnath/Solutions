#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

struct Order
{
    int x;
    int y;
    Order(int a, int b) : x(a), y(b) {}
};

bool operator<(const Order& a, const Order& b)
{
    return a.x < b.x;
}

int main()
{
    UNSYNC
    int N; cin >> N;
    vector<Order> order;
    rep(1, N + 1)
    {
        int n; cin >> n;
        order.emplace_back(n, i);
    }

    sort(all(order));

    for (auto i: order) cout << i.y << ' ';
    cout << '\n';
    
    return 0;
}
