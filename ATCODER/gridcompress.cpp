#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    string mat[110];
    bool f[110], c[110];
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i ++) cin >> mat[i];
    for(int i = 0; i < n; i ++)
    {
        bool flag = true;
        for(int j = 0; j < m; j ++)
        {
            if(mat[i][j] == '#')
            {
                flag = false;
                break;
            }
        }
        f[i] = flag;
    }
    for(int j = 0; j < m; j ++)
    {
        bool flag = true;
        for(int i = 0; i < n; i ++)
        {
            if(mat[i][j] == '#')
            {
                flag = false;
                break;
            }
        }
        c[j] = flag;
    }
    for(int i = 0; i < n; i ++)
    {
        if(f[i]) continue;
        for(int j = 0; j < m; j ++) if(!c[j]) cout << mat[i][j];
        cout << '\n';
    }
    return 0;
}
