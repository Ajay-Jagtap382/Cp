#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll MOD = 1e9 + 7;
#define fast_cin()  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)



// basic dfs through iterative and recursive method with calculating no of connected components.
// 6
// 4
// 1 2
// 2 3
// 1 3
// 4 5
// ans: 1 2 3 4 5 6 
//      Number of Connected Components: 3


const int r = 1e5 + 6;
vector<int> adj[r];
vector<bool> vis(r, false);

void dfs(int i)
{
    vis[i] = 1;
    cout << i << " ";

    for (auto x : adj[i])
    {
        if (!vis[x])
            dfs(x);
    }
}

int main()
{
    fast_cin();
    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int n, m;
        cin >> n >> m;
        adj[n].push_back(m);
        adj[m].push_back(n);
    }
    int connectedCom =0;

    //Iterative
    
    // stack<int> st;

    // for (int i = 1; i <= v; i++)
    // {
    //     if (!vis[i])
    //     {
    //         st.push(i);
    //         vis[i]=1;

    //         while (!st.empty())
    //         {
    //             int node = st.top();
    //             cout << node << " ";
    //             st.pop();

    //             for (auto x : adj[node])
    //             {
    //                 if (!vis[x])
    //                 {
    //                     st.push(x);
    //                     vis[x] = 1;
    //                 }
    //             }
    //         }
    //         connectedCom++;
    //     }
    // } cout<<endl;

    // Recursive
    for( int i=1 ;i<=v ;i++){
        if(!vis[i]){
            dfs(i);
            connectedCom++;
        }
    }
    cout<<endl;

    cout<<"Number of Connected Components: "<<connectedCom<<endl;

    return 0;
}