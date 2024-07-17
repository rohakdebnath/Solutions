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

int main()
{
    int n, k; cin >> n >> k;
    vector<int> a (n), b (k);
    rep(0, n) {cin >> a[i];}
    rep(0, k) {cin >> b[i];}

    for (int i {1}; i < n; ++i) a[i] += a[i - 1];
    set<int> uniqa (all(a));
    vector<int> pallowed (8000001);
    vector<int> nallowed (8000001);
    for (int i : b) for (int j : uniqa)
    {
        if (j - i >= 0) ++pallowed[j - i];
        else ++nallowed[i - j];
    }
    
    cout << count(all(pallowed), k) + count(all(nallowed),k) << '\n';
    return 0;
}
