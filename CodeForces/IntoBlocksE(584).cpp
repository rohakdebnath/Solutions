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
    int n, q;
    cin >> n >> q;

    vector<int> seq (n);
    rep(0, n) {cin >> seq[i];}

    vector<int> partition {0};

    unordered_map<int, pair<int, int>> startsandends;

    rep(0, n)
    {
        if (startsandends[seq[i]].first == 0) startsandends[seq[i]].first = i + 1; 
    }
    for (int i {n - 1}; i >= 0; --i)
    {
        if (startsandends[seq[i]].second == 0) startsandends[seq[i]].second = i + 1; 
    }

    int blockfinder {0};
    unordered_map<int, int> freq;
    int maxFreq {0};
    int constants {0};

    for (int i {0}; i < n; ++i)
    {
        ++freq[seq[i]];
        maxFreq = max(maxFreq, freq[seq[i]]);
        if (i == startsandends[seq[i]].first - 1) ++blockfinder;
        if (i == startsandends[seq[i]].second - 1) --blockfinder;
        if (blockfinder == 0)
        {
            constants += maxFreq;
            maxFreq = 0;
            freq.clear();
        }
    }

    cout << n - constants << '\n';

    return 0;
}
