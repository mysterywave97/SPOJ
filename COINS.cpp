#include<bits/stdc++.h>
using namespace std;
map<int,long long int> dp;  //int range 2147483647
long long int f(int n){
	if(n==0)
	return 0;
	if(dp[n]==0){
		long long int x=f(n/2)+f(n/3)+f(n/4);
		if(x>n)
		dp[n]=x;
		else
		dp[n]=n;
	}
	return dp[n];
}
main(){
	int n;
	while(cin>>n){
		cout<<f(n)<<"\n";
	}
}
