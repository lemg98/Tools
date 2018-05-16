#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef set<int>::iterator set_it;

int main(){

	int n,k;
	int dp[11][51];
	for(int i = 1 ; i <= 50 ; i++){
		dp[1][i] = i;
	}

	for(int i = 2; i <= 10 ; i++){
		for(int j = 1; j <= 50 ; j++){
			if(i >= j) dp[i][j] = dp[i-1][j];
			else{
				dp[i][j] = 100;
				for(int k = 2 ; k < j ; k++){
					dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][k-1], dp[i][j-k])); 
				}
			}
		}
	}

	int t; cin >> t;
	while(t--){

		cin >> n >> k;
		cout << dp[n][k] << endl;

	}	
		
return 0;	
}