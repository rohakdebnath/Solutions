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

void solve(vector<int>& sub)
{
    int len = sub.size();
    if (len == 0) {cout << "0\n";}
    else if (len == 1) cout << "pushStack\n1 popStack\n";
    else if (len == 2) cout << "pushStack\npushQueue\n2 popStack popQueue\n";
    else if (len == 3) cout << "pushStack\npushQueue\npushFront\n3 popStack popQueue popFront\n";
    else
    {
        vector<int> temp = sub;
        sort(temp.begin(), temp.end(), [](int& x, int& y) -> bool {return x > y;});
        vector<int> a (3, -1);

        for (int i {0}; i < len; ++i)
        {
            for (int j {0}; j < 3; ++j)
            {
                if (a[j] == -1 and sub[i] == temp[j])
                {
                    a[j] = i;
                    break;
                }
            }
        }
        sort(all(a));
        for (int i = 0; i < a[0]; ++i) cout << "pushStack\n";
        cout << "pushQueue\n";
        for (int i = a[0] + 1; i < a[1]; ++i) cout << "pushStack\n";
        cout << "pushFront\n";
        for (int i = a[1] + 1; i < a[2]; ++i) cout << "pushStack\n";
        cout << "pushStack\n";
        for (int i = a[2] + 1; i < len; ++i) cout << "pushBack\n";
        cout << "3 popQueue popFront popStack\n";
    }
}

int main()
{
    int n; cin >> n;
    vector<int> vn (n);
    rep(0, n) {cin >> vn[i];}
    int ini = 0;
    for (int i {0}; i < n; ++i)
    {
        if (vn[i] == 0)
        {
            vector<int> sub = {vn.begin() + ini, vn.begin() + i};
            solve(sub);
            ini = i + 1;
        }
    }

    for (int i {n - 1}; i >= 0; --i)
    {
        if (vn[i] == 0) break;
        cout << "pushBack\n";
    }
    return 0;
}
