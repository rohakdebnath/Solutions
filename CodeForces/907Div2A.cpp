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
    vector<int> seq (n);
    rep(0, n) {cin >> seq[i];}

    int twopm {1};
    int m {0};
    while (twopm <= n)
    {
        twopm *= 2;
        ++m;
    }
    m -= 1;
    for (int i {1}; i <= m; ++i)
    {
        for (int j = pow(2, i - 1) + 1; j < pow(2, i); ++j)
        {
            if (seq[j - 1] > seq[j])
            {
                cout << "NO\n";
                return;
            }
        }
    } 

    for (int i = pow(2, m) + 1; i < n; ++i)
    {
        if (seq[i - 1] > seq[i])
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
