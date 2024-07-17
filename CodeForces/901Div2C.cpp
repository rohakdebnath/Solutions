#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()

void solve()
{
    i64 n, m;
    cin >> n >> m;
    i64 cuts {0};
    i64 temp1 {n}, temp2 {m};

    while (temp1 % 2 == 0) temp1 = temp1 / 2;
    while (temp2 % 2 == 0) temp2 = temp2 / 2; //dry out factors of two

    if (temp1 % temp2 == 0) //our aim is to keep distributing everything equally whenever possible and then exhaust whatevers remaining

    {
        while (n != 0) //if we ever reach apple numbers equal to people , we have found the spot
        {
            while (n < m)
            {
                cuts += n; 
                n = n*2; //keep cutting unless the apples pieces reach more than the number of people
            }
            n = n % m;
        }
    }
    else //if the condition is not satisfied , the magic knife will never cut the apples in finite numbers
    {
        cout << -1 << '\n';
        return;
    }
    cout << cuts << '\n'; 
}

int main()
{
    Unsync
    i64 tests;
    cin >> tests;
    while(tests--)
    {
        solve();
    }

    return 0;
}
