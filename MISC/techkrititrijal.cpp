#include<iostream>
#include<algorithm>

#include<vector>
int inp[200001];
int vis[200001];

using namespace std;

void solve(){
    int n;
    cin>>n;
    for(int k=1;k<=n;k++){
        cin>>inp[k];
        vis[k]=0;
    }
    int ans=0; 
    bool flag = false;
    
    for(int i=1;i<=n;i++){
        int j = i;
        int cycle_size=0;
        if (vis[i] || inp[i] == i)continue; 
        vector<int>cycle;
        while(!vis[j]){
            vis[j]=1; 
            cycle.push_back(j);
            j = inp[j];
            cycle_size++;    
        }
        if(!flag){
        sort(cycle.begin(),cycle.end());
        for(int k=0;k<cycle.size();k++){
            if(cycle[k+1]-cycle[k]==1){
                flag = true;
            }
        }
        }
        if (cycle_size > 0) { 
            ans += (cycle_size - 1); 
        } 
        
    }
    if(flag)cout<<ans-1<<endl;
    else cout<<ans+1<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
     return 0;
}
