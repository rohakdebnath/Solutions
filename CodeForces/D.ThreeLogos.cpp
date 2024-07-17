#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

vector<pair<int, int>> dims (3);
int area {0};
int len {1};
vector<bool> rotation (3, false);
bool found {false};
vector<vector<char>> billboard;

void checkandstore(vector<pair<int, int>>& arrangement)
{
    billboard.resize(len, vector<char> (len));

    int& x1 = arrangement[0].first;
    int& y1 = arrangement[0].second;
    int& x2 = arrangement[1].first;
    int& y2 = arrangement[1].second;
    int& x3 = arrangement[2].first;
    int& y3 = arrangement[2].second;

    pair<int, int> maxPair;
    pair<int, int> midPair;
    pair<int, int> minPair; // max pair means highest x value , similar for other two
    char maxC {'D'};
    char midC {'D'};
    char minC {'D'};
    if (x1 == len)
    {
        maxPair = arrangement[0];
        if ( x2 >= x3) {midPair = arrangement[1]; minPair = arrangement[2]; maxC = 'A'; midC = 'B'; minC = 'C';}
        else {midPair = arrangement[2]; minPair = arrangement[1]; maxC = 'A'; midC = 'C'; minC = 'B';}
    }
    else if (x2 == len)
    {
        maxPair = arrangement[1];
        if ( x3 >= x1) {midPair = arrangement[2]; minPair = arrangement[0]; maxC = 'B'; midC = 'C'; minC = 'A';} 
        else {midPair = arrangement[0]; minPair = arrangement[2]; maxC = 'B'; midC = 'A'; minC = 'C';}
    }
    else if (x3 == len)
    {
        maxPair = arrangement[2];
        if ( x1 >= x2) {midPair = arrangement[0]; minPair = arrangement[1]; maxC = 'C'; midC = 'A'; minC = 'B';}
        else {midPair = arrangement[1]; minPair = arrangement[0]; maxC = 'C'; midC = 'B'; minC = 'A';}
    }

    if (x1 == len and x2 == len and x3 == len and y1 + y2 + y3 == len)
    {
        found = true;
        for (int v {0}; v < y1; ++v)
        {
            for (int h {0}; h < len; ++h)
            billboard[v][h] = 'A';
        }
        for (int v {y1}; v < y1 + y2; ++v)
        {
            for (int h {0}; h < len; ++h)
            billboard[v][h] = 'B';
        }
        for (int v {y1 + y2}; v < len; ++v)
        {
            for (int h {0}; h < len; ++h)
            billboard[v][h] = 'C';
        }
    }

    else if (maxPair.first == len and (midPair.first + minPair.first == len) and (maxPair.second + midPair.second == len) and (midPair.second == minPair.second))
    {
        found = true;
        for (int v {0}; v < maxPair.second; ++v)
        {
            for (int h {0}; h < len; ++h)
            billboard[v][h] = maxC;
        }
        for (int v {maxPair.second}; v < len; ++v)
        {
            for(int h {0}; h < midPair.first; ++h)
            billboard[v][h] = midC;
        }
        for (int v {maxPair.second}; v < len; ++v)
        {
            for(int h {midPair.first}; h < len; ++h)
            billboard[v][h] = minC;
        }
    }
}

void rotRec(int c = 0)
{
    if (found) return;
    if (c == 3)
    {
        checkandstore(dims);
        return;
    }

    rotation[c] = true;
    swap(dims[c].first, dims[c].second);
    rotRec(c + 1);
    rotation[c] = false;
    swap(dims[c].first, dims[c].second);
    rotRec(c + 1);
}

int main()
{
    UNSYNC

    cin >> dims[0].first >> dims[0].second >> dims[1].first >> dims[1].second >> dims[2].first >> dims[2].second;

    for (auto pair : dims)
    {
        area += pair.first * pair.second;
    }

    while (len * len < area) ++len;

    if (len * len != area)
    {
        cout << -1 << '\n';
        return 0;
    }

    rotRec();

    if (found)
    {
        cout << len << '\n';
        for (int i {0}; i < len; ++i)
        {
            for (auto c : billboard[i])
            {
                cout << c;
            }
            cout << '\n';
        }
    }
    else cout << -1 << '\n';
    
    return 0;
}
