#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);
#define sz(x) static_cast<ll>((x).size())
#define all(x) x.begin(), x.end()

vector<double> intersectionPoint(ll a1, ll b1, ll c1, ll a, ll b, ll c)
{
    vector<double> llersection (2);

    llersection[0] = static_cast<double>((b1 * c - b * c1)) / (a1 * b - a * b1);
    llersection[1] = static_cast<double>((c1 * a - c * a1)) / (a1 * b - a * b1);

    return llersection;
}


int main()
{
    Unsync
    ll n, x1, y1, x2, y2, a, b, c;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    ll crossedRoads {0};

    if (x1 == x2) a = 1 , b = 0, c = -x1;
    else a = (y1 - y2), b = (x2 - x1), c = (y2 - y1) * x1 - y1 * ((x2 - x1));
    
    while (n--)
    {
        ll a1, b1, c1;
        cin >> a1 >> b1 >> c1;
        vector<double> vec {intersectionPoint(a1, b1, c1, a, b, c)};
        if (((vec[0] <= x1 and vec[0] >= x2) or (vec[0] <= x2 and vec[0] >= x1)) and
        ((vec[1] <= y1 and vec[1] >= y2) or (vec[1] <= y2 and vec[1] >= y1))) ++crossedRoads;
    }

    cout << crossedRoads;
    return 0;
}
