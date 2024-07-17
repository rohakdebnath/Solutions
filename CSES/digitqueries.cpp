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

i64 pow10(int n)
{
    i64 t = 1;
    for (int i {0}; i < n; ++i) t *= 10;
    return t;
}

int main()
{
    UNSYNC

    int q; cin >> q;
    while(q--)
    {
        i64 k; cin >> k;
        int n = 1;
        while (k > 9*n*pow10(n - 1))
        {
            k -= 9*n*pow10(n - 1);
            ++n;
        }

        i64 exactNum = pow10(n - 1) + (k - 1)/n;
        i64 loc = int((k - 1) % n);

        cout << to_string(exactNum)[loc] << '\n';

    }

    return 0;
}
