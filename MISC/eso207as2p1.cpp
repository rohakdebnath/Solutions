//[Read about multisource BFS] not easy to implement with dfs. With bfs, instead of adding the starting node in the queue, add all the starting points.
//Basic idea: Start from all the marked nodes (friend's rooms) simultaneously, storing the distances from the started nodes, if a node has been visited note that that particular node will be closest from it's starting node, at most it can be equal, in othe words a non visited node when reached for the first time is the closest from the starting node of that search
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using i64 = long long;

const int SZ = 100000;
int main()
{
    vector<int> tree[SZ]; 
    vector<int> dis (SZ, SZ); //stores the distance of the closest room
    vector<int> minode (SZ, SZ); //stores the ID of the closest room
    int N; cin >> N;
    for (int i = 0; i < N; ++i){
        int a; cin >> a; --a;
        if (i == 0) continue;
        tree[i].push_back(a);
        tree[a].push_back(i);
    }
    queue<int> mbfs; //multisource bfs, where the IDs will be put all queued at the start, read about bfs first
    int F; cin >> F;
    for (int i = 0; i < F; ++i){
        int f; cin >> f; --f;     
        dis[f] = 0;
        minode[f] = f;
        mbfs.push(f);
    }

    while (!mbfs.empty()){
        int top = mbfs.front();
        mbfs.pop();
        int d = dis[top] + 1;
        int mdc = minode[top]; 
        for (int u: tree[top]){
            if (dis[u] < d) continue; //visited nodes must be ignored
            if (dis[u] > d){ //dis[u] has to be equal to SZ in this case
                dis[u] = d;
                minode[u] = mdc;
            } else if (dis[u] == d){
                minode[u] = min(mdc, minode[u]);
            }
            mbfs.push(u);
        }
    }
    int Q; cin >> Q;
    for (int i = 0; i < Q; ++i){
        int q; cin >> q; --q;
        cout << minode[q] + 1 << '\n'; 
    }
    //O(N) pre calculation and O(1) per query
    return 0;
}
