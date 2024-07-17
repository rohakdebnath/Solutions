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
    int n;
    cin >> n;
    vector<string> matrix (n);
    rep(0, n) {cin >> matrix[i];}

    i64 changes {0};
    rep(0, n/2)
    {
        string s1 = matrix[i].substr(i, n - 2*i - 1);

        string s2;
        for (int j {i}; j < n - i - 1; ++j)
        {
            s2 += matrix[j].substr(n - i - 1 , 1);
        }
        
        string s3 = matrix[n - 1 - i].substr(i + 1, n - 2*i - 1);
        reverse(all(s3));

        string s4;
        for (int j {i + 1}; j < n - i; ++j)
        {
            s4 += matrix[j].substr(i, 1);
        }
        reverse(all(s4));

        for (int j {0}; j < n - 2*i - 1; ++j)
        {
            changes += (4*max({s1[j], s2[j], s3[j], s4[j]}) - s1[j] - s2[j] - s3[j] - s4[j]);
        }
    }

    cout << changes << '\n';
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
