#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)

double areaTrapezium(double b1, double b2, double heightDiff)
{
    return 0.5000000000000*heightDiff*(b1 + b2);
}

void solve()
{
    double n, d, h; cin >> n >> d >> h;

    vector<int> heights (n);
    rep(0, n) {cin >> heights[i];}
    double totalArea {0.500000000000000*d*h};

    for (int i = n - 2; i >= 0; --i)
    {
        double diff = heights[i + 1] - heights[i];
        if (diff >= h)
        {
            totalArea += areaTrapezium(0, d, h);
            continue;
        }
        totalArea += areaTrapezium((h - diff)/h*d, d, diff);
    }
    cout << setprecision(20) << fixed;
    cout << totalArea << '\n';
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
