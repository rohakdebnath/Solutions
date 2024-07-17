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

void solve()
{
    int n; cin >> n;
    vector<int> a (n);
    rep(0, n) {cin >> a[i];}

    int mins = INT32_MAX;
    int maxs = 0;
    for (int i {1}; i < n; ++i)
    {
        if (a[i] > a[i - 1])
        {
            mins = min(mins, (a[i] + a[i - 1])/2);
        }
        else if (a[i] < a[i - 1])
        {
            maxs = max(maxs, int(ceil((a[i] + a[i - 1])*0.5000)));
        }
    }

    if (maxs > mins)
    {
        cout << - 1 << '\n';
        return;
    }
    cout << maxs << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
