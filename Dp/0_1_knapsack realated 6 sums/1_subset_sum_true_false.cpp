#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

// here we just checking the existance of the subset of array whose sum is equal to the given sum 
// e.g. 5 8                   here n=5 , sum=8,
//      2 3 10 55 4           ans=0 i.e false

int main()
{
    fast_cin();
    int n  , sum;
    cin>>n>>sum;
    vector<int>arr(n);
    for( int i=0 ;i< n ;i++){
        cin>>arr[i];
    }

    vector<vector<bool>>dp(n+1 , vector<bool>(sum+1));

    for( int i=0 ;i<n+1;i++){
        for( int j=0 ;j< sum+1 ; j++){
            if(i==0)
                dp[i][j]=false;
            if(j==0)    
                dp[i][j]=true;
        }
    }

    for( int i=1 ;i< n+1; i++){
        for( int j=1 ;j<sum+1 ;j++){
            if(arr[i-1]<=j)
                dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    
    cout<<dp[n][sum];
    return 0;
}