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

vector<int> UP {-1, 0};
vector<int> DOWN {1, 0};
vector<int> LEFT {0, -1};
vector<int> RIGHT {0, 1};
vector<vector<int>> CW {UP, RIGHT, DOWN, LEFT};
vector<vector<int>> ACW {UP, LEFT, DOWN, RIGHT};
int n, m, k; 
vector<vector<int>> ans;

void spiral(int r, int c, bool sense)
{
    vector<vector<int>> dir = sense ? ACW : CW;
    int count = 0, step = 1, length = 1, remain = length, dirId = 0;
    bool incLen = false;
    while (count < n * m)
    {
        if (!(r < 0 or c < 0 or r >= n or c >= m))
        {
            ans[r][c] = min(ans[r][c], step);
            ++count;
        }
        ++step;
        r += dir[dirId][0];
        c += dir[dirId][1];
        --remain;
        if (remain == 0)
        {
            if (incLen) ++length;
            incLen = !incLen;
            dirId = (dirId + 1) % 4;
            remain = length;
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    ans = vector<vector<int>> (n, vector<int> (m, INT32_MAX));
    while (k--)
    {
        int x, y, t; cin >> x >> y >> t;
        spiral(x - 1, y - 1, t);
    }
    for (auto v : ans) rep(0, m) cout << v[i] << ((i == m - 1) ? '\n' : ' ');
    return 0;
}
