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

vector<int> results;
vector<int> nums (4);
int operand {0};

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}
int multiply(int a, int b)
{
    return a * b;
}
int divide(int a, int b)
{
    return a / b;
}

void operateRec(int n = 1)
{
    if (n == 4)
    {
        if (operand <= 24) 
        {
            results.emplace_back(operand);
            return;
        }
        return;
    }
    operand = add(operand, nums[n]);
    operateRec(n + 1);
    operand -= nums[n];

    operand = subtract(operand, nums[n]);
    operateRec(n + 1);
    operand += nums[n];

    operand = multiply(operand, nums[n]);
    operateRec(n + 1);
    operand /= nums[n];

    if (operand % nums[n] == 0)
    {
        operand = divide(operand, nums[n]);
        operateRec(n + 1);
        operand *= nums[n];
    }
}

void solve()
{
    rep(0, 4) {cin >> nums[i];}
    sort(all(nums));

    do
    {
        operand = nums[0];
        operateRec();
    }
    while (next_permutation(all(nums)));
    cout << *max_element(all(results)) << '\n';
    results.clear();
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
