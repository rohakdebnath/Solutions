#include <bits/stdc++.h>
#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);

using ll = long long;
using namespace std;

int main()
{
    Unsync
    string str;
    cin >> str;

    for (int i {2}; i < str.size(); ++i)
    {
        if (str[i] == str[i - 1] and str[i - 1] == str[i - 2])
        {
            while (i < str.size() and str[i] == str[i - 1] and str[i - 1] == str[i - 2])
            {
                str.erase(str.begin() + i);
            }
        }
    }

    for (int i {3}; i < str.size(); ++i)
    {
        if (str[i] == str[i - 1] and str[i - 2] and str[i - 3])
        {
            while (i < str.size() and str[i] == str[i - 1] and str[i - 2] == str[i - 3])
            {
                str.erase(i - 1, 1);
            }
        }
    }

    cout << str <<'\n';

    return 0;
}
