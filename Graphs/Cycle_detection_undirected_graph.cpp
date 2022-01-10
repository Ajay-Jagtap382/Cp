#include <bits/stdc++.h>
using namespace std;

bool isCheck(vector<vector<int>>adj , vector<bool>& vis , int i, int par){
    vis[i]=1;
    
    for(auto x:adj[i]){
        if(!vis[x])
            return isCheck(adj ,vis, x, i);
        else if(x!=par){
            return true;
        }
        
    }
    return false;

}


int main(){
    int u , v;
    cin>>u>>v;
    vector<vector<int>>adj(u);
    vector<bool>vis(u ,0);

    for( int i=0 ;i< v ; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    string ans="NO";
    for( int i=0 ;i< u ; i++){
        if(!vis[i] && isCheck(adj , vis, i , -1)){
            ans="YES";
            break;
        }
    }
    cout<<ans;

    return 0;
}