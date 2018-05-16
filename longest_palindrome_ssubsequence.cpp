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

int dp[1000][1000];

string cad;
int L(int i, int j){

	if(i > j) return 0;

	if(dp[i][j] > 0) 
		return dp[i][j];

	if(i == j)
		return ++dp[i][j];
	
	if(cad[i] == cad[j])
		dp[i][j] = L(i+1,j-1) + 2;

	else dp[i][j] = max(L(i,j-1), L(i+1,j));

	return dp[i][j];

}

int main(){

	int t; cin >> t;

	while(t--){
		
		cin >> cad;

		int n = cad.size();
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				dp[i][j] = 0;

		cout << L(0,cad.size()-1) << endl;

	}

return 0;	
}