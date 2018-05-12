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

//coin change iterative bottom up (nm)
void count(vector<int> & coins, int cents){

	int n = coins.size();

	for(int i = 0 ; i < n ; i++)
		dp[0][i] = 1;

	for(int i = 1 ; i <= cents ; i++){
		for(int j = 0 ; j < n ; j++){

			dp[i][j] = j-1 >= 0 ? dp[i][j-1] : 0;

			dp[i][j] += i-coins[j] >= 0 ? dp[i-coins[j]][j] : 0;			

		}
	}

}

//coin change iterative(n)
void _count(vector<int> & coins, int cents, vector<ll> & _dp){

	int n = coins.size();

	for(int i = 0 ; i < n ; i++)
		for(int j = coins[i]; j <= cents ; j++){
			_dp[j] += _dp[j-coins[i]];
		}

}

int main(){

	int n;
	vector<int> vec;
	while(cin >> n) vec.push_back(n);

	int may = *max_element(vec.begin(), vec.end());

	vector<ll> _dp(may+1, 0); 
	_dp[0] = 1;

	int tem[] = {1,5,10,25,50};
	vector<int> coins;
	for(int i = 0 ; i < 5; i++) coins.push_back(tem[i]);

	_count(coins, may, _dp);

	for(int i = 0 ; i < vec.size() ; i++){
		int n = vec[i];
		if(_dp[n] == 1) printf("There is only 1 way to produce %lld cents change.",n);
		else printf("There are %lld ways to produce %lld cents change.",_dp[n] ,n );
		cout << endl;
	}
		
		
return 0;	
}
