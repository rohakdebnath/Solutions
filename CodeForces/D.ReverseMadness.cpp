#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);
#define sz(x) static_cast<int>((x).size())
#define all(x) x.begin(), x.end()

int main()
{
    Unsync
    int tests;
    cin >> tests;

    while (tests--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> l(k), r(k);
        for (int i {0}; i < k; ++i)
        {
            cin >> l[i]; --l[i];
        }

        for (int i {0}; i < k; ++i)
        {
            cin >> r[i]; --r[i];
        }

        int q;
        cin >> q;

        vector<int> xi (n, 0);
        for (int i {0}; i < q; ++i)
        {
            int x;
            cin >> x;
            ++xi[x - 1]; // xi stores the symmetric flip positions, but note that the symmetric flips are wrt to each substrings and not the whole s itself
        }
        string ansS {""};

        for (int i {0}; i < k; ++i)
        {
            string subS = s.substr(l[i], r[i] - l[i] + 1);
            int a {l[i]};
            int b {r[i]};   // these are the end points of the substring 
            int sum {0};
            for (int j {a}; j <= (a + b) / 2; ++j)
            {
                sum += xi[j] + xi[a + b - j];
                if (sum % 2 == 1) swap(subS[j - a], subS[b - j]);
            }
            ansS += subS;
        }

        cout << ansS << '\n';
        }
    return 0;
}
