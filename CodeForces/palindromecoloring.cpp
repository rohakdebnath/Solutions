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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> freq (26);

    for(char c : s) ++freq[c - 'a'];

    int totalPairs {0};
    int singlets {0};

    rep(0, 26)
    {
        totalPairs += freq[i]/2;
        singlets += freq[i] % 2;
    }

    if (singlets + 2*(totalPairs % k) >= k) cout << 2*(totalPairs/k) + 1 << '\n';
    else cout << 2*(totalPairs/k) << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
