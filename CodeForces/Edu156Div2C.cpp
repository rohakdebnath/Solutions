#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

string ans {""};
void solve()
{
    string s;
    cin >> s;
    string process {s};
    process += 'a' - 1;


    int p;
    cin >> p;

    string concat {s};

    for(int i {1}; i < process.size(); ++i)
    {
        while (process[i - 1] > process[i])
        {
            process.erase(process.begin() + i - 1);
            concat += process;
            concat.erase(concat.end() - 1);
            --i;
        }
    }

    ans += concat[p - 1];
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

    cout << ans << '\n';

    return 0;
}
