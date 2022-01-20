#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
ll MOD = 1e9+7;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
// here we have to count number of subsets which exist in pair whose differnce is given difference
// i.e  s1 - s2 =given diff   count these pairs of s1 and s2
//  where s1 + s2 =sum of vector elemnts
// e.g  2  1                     n=2  , diff=1
//      1 0                      arr
//ans:  2                        {1 ,0 } , {1 , {}}


int count(vector<int>& arr , int n , int s1){

    vector<vector<int>>dp(n+1 , vector<int>(s1+1) );

    for( int i=0 ;i< n+1 ; i++){
        for( int j=0 ;j< s1+1 ; j++){
            if(i==0) dp[i][j]=0;

            if(j==0) dp[i][j]=1;
        }
    }

    //start i and j with 1
    for( int i=1;i< n+1 ; i++){
        for( int j=1 ;j< s1+1 ; j++){
            if(arr[i-1] <=j) 
                dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
            
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][s1];

}


int main()
{
    fast_cin();
    int  n, diff;
    cin>>n>>diff;
    vector<int>arr(n);
    for( int i=0 ;i< n ;i++){
        cin>>arr[i];
    }

    // as given in problem s1-s2 =diff  and s1+s2 =sum  
    // add these two equations
    // s1= (diff + sum )/2 
    // then simply apply the logic of count subset for given sum 
    // where we replace or by +

    int sum=0;
    for( int i=0 ;i< n ; i++){
        sum+=arr[i];
    } 

    int s1 =(sum+ diff)/2;

    cout<<count(arr, n , s1);

    return 0;
}