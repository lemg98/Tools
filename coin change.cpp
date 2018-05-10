#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <list>
#include <map>

using namespace std;

typedef long long ll;


int dp[301][301];

//coing change recursive top down
int gen(vector<int> & coins, int cents, int n){

	if(cents == 0) return 1;
	if(cents < 0 || n == -1) return 0;

	if(dp[cents][n] > 0) return dp[cents][n];

	else dp[cents][n] = gen(coins, cents, n-1) + gen(coins, cents-coins[n], n);

	return dp[cents][n];
}

//coin change iterative bottom up
void count(vector<int> & coins, int cents, int n){

	for(int i = 0 ; i < n ; i++)
		dp[0][i] = 1;

	for(int i = 1 ; i <= cents ; i++){
		for(int j = 0 ; j < n ; j++){

			dp[i][j] = j-1 >= 0 ? dp[i][j-1] : 0;

			dp[i][j] += i-coins[j] >= 0 ? dp[i-coins[j]][j] : 0;			

		}
	}

}

int main(){

	int t;
	cin >> t;

	while(t){

		int n; cin >> n;
		vector<int> coins(n);
		for(int i = 0 ; i < n ; i++)
			cin >> coins[i];	
		int cents; cin >> cents;

		for(int i = 0 ; i <= cents ; i++)
			fill(dp[i], dp[i] + n, 0);

		count(coins, cents, n); cout << dp[cents][n-1] << endl;
		//cout << gen(coins, cents, n-1) << endl;

	t--;
	}
		
return 0;	
}