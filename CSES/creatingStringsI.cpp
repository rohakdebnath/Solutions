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

string s; 
vector<int> alphabets (26);

void stringRec(string perm = "")
{
    if (perm.length() == s.size())
    {
        cout << perm << '\n';
        return;
    }
    for (int i {0}; i < 26; ++i)
    {
        if (alphabets[i])
        {
            --alphabets[i];
            perm += 'a' + i;
            stringRec(perm);
            ++alphabets[i];
            perm.erase(perm.end() - 1);
        }
    }
}

int fact(int n)
{
    if (n == 0 or n == 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int main()
{
    cin >> s;
    for (char c : s) ++alphabets[c - 'a'];
    int permutes {fact(s.size())};

    for (int i {0}; i < 26; ++i)
    {
        if (alphabets[i])
        {
            permutes /= fact(alphabets[i]);
        }
    }
    cout << permutes << '\n';
    stringRec();
    return 0;
}
