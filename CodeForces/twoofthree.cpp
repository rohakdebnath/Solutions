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
#define VI vector<int>
#define VVI vector<vector<int>>

void solve()
{
    VI twoatleasttwice;
    int n; cin >> n;
    VI v (n);
    unordered_map<int, int> mp;
    rep(0, n) 
    {
        cin >> v[i];
        ++mp[v[i]];
        if (mp[v[i]] == 2 and twoatleasttwice.size() < 2) twoatleasttwice.emplace_back(v[i]);
    }
    if (twoatleasttwice.size() < 2)
    {
        cout << -1 << '\n';
        return;
    }
    bool first = true;
    bool second = true;

    for (int i : v)
    {
        if (i == twoatleasttwice[0] and first)
        {
            cout << 1 << ' ';
            first = false;
        }
        else if (i == twoatleasttwice[1] and second)
        {
            cout << 1 << ' ';
            second = false;
        }
        else if (i == twoatleasttwice[0] and !first) cout << 2 << ' ';
        else if (i == twoatleasttwice[1] and !second) cout << 3 << ' ';
        else
        {
            cout << 1 << ' ';
        }
    }
    cout << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
