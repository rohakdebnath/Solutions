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
#define rep(ini, x) for (i64 i {ini}; i < x; ++i)

void solve()
{
    i64 n, q; cin >> n >> q;
    vector<i64> seq (n);

    rep(0, n) {cin >> seq[i];};
    
    int y = {30};
    while (q--)
    {
        int x; cin >> x;
        if (x > y) continue;
        for (int i {0}; i < n; ++i) if (seq[i] % (1 << x) == 0) seq[i] += (1 << (x - 1));
        y = x - 1; //The maximum divisibility amongst all the elements of the vector is now x - 1; because whatever was divisible by x is now only divisible by x - 1.
    }
    for (auto i : seq) cout << i << ' ';
    cout << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--)
    {
        solve();
    }

    return 0;
}
