#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

// typical knapsack problem 
// 5 60
// 10 20 30 40 50 
// 8 2 5 3 12
// ans=20

int main()
{
    fast_cin();
    int n , weight;
    cin>>n;
    cin>>weight;
    vector<int>w(n) ,val(n);

    for( int i=0 ;i< n ;i++){
        cin>>w[i];
    }
    for( int i=0 ;i< n ;i++){
        cin>>val[i];
    }

    vector<vector<int>>dp(n+1 ,vector<int>(weight+1));

    for( int i=0 ;i< n+1; i++){
        for( int j=0 ;j<weight+1 ; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    for( int i=1 ;i< n+1; i++){
        for( int j=1 ;j< weight+1 ;j++){
            if(w[i-1] <= j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-w[i-1]] , dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][weight];
    
    return 0;
}