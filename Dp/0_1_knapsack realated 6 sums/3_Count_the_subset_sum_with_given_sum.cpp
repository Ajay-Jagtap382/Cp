#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
ll MOD = 1e9+7;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
//Here we have given a sum we have to tell the number of subsets whose sum is equal to given sum
//e.g   5 10                              n=5 , sum=10
//      5 5 4 6 10                        arr
//ans:  3
 
int count(vector<int>& arr , int  n , int sum){
    vector<vector<int>>dp(n+1 , vector<int>(sum+1));

    for( int i=0 ;i< n+1 ;i++){
        for( int j=0 ; j< sum+1 ; j++){
            if(i==0) 
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;
        }
    }

    for( int i=1 ;i< n+1 ;i++){
        for( int j=1 ;j<sum+1 ; j++){
            if(arr[i-1] <= j){
                dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else    
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    fast_cin();
    int n ,sum;
    cin>>n>>sum;
    vector<int>arr(n);
    for( int i=0 ;i< n; i++){
        cin>>arr[i];
    }

    // It is similar to subset sum just instead f or we have to put '+' and change the 
    // initialization part

    cout<<count(arr, n ,sum);

    return 0;
}