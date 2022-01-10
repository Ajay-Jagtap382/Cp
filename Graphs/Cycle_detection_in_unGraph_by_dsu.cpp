#include <bits/stdc++.h>  
 
using namespace std;
 
const int N=1e5+6;
vector<vector<int>>adj(N);
vector<int>par(N);
vector<int>size(N);
vector<pair<int ,int>>edges;

void makee(int a){
    par[a]=a;
    size[a]=1;
}

int findd(int a){
    if(par[a]==a)
        return a;
    return par[a]=findd(par[a]);
}

void unionn(int a , int b ){
    a=findd(a);
    b=findd(b);
    if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
        }
        par[b]=a;
        size[a]+=size[b];
    }
}

bool iscycle(int a , int b){
    int x=findd(a);
    int y=findd(b);
    if(x==y){
        return true;
    }
    unionn(x,y);
    return false;
}

int main()
{
    int  u , v; 
    cin>>u>>v;
    for( int  i= 0; i< v ; i++){
        int a , b;
        cin>>a>>b;
        makee(a);makee(b);
        edges.push_back({a,b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    string ans="No";
    int a,b;
    for(auto x:edges){
        a=x.first;
        b=x.second;
        if(iscycle(a,b)){
            ans="yes";
            break;
        }       
    }
    cout<<ans;
}