#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

int main()
{
    UNSYNC
    int T;
    cin >> T;

    int totSeats {2 * T};

    vector<string> seats;
    while(T--)
    {
        string line;
        cin >> line;

        seats.emplace_back(line.substr(0,2));
        seats.emplace_back(line.substr(3,5));
    }

    bool survive = false;
    for (string& seat : seats)
    {
        if (seat == "OO")
        {
            seat = "++";
            survive = true;
            break;
        }
    }

    if (survive)
    {
        cout << "YES\n";

        for (int i {0}; i < totSeats; ++i)
        {
            cout << seats[i];
            if (i % 2 == 0) cout << "|";
            else cout << '\n';
        }
    }

    else cout << "NO\n";

    return 0;
}
