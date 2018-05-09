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

int main(){

	string cad1, cad2;

	while(getline(cin,cad1)){

		getline(cin,cad2);

		int n = cad1.size(), m = cad2.size();

		vector<int> dp[n+1];

		for(int i = 0 ; i <= n ; i++){
			dp[i].resize(m+1,0);
			for(int j = 0 ; j <= m ; j++)
				
				if(i == 0 || j == 0)
					dp[i][j] = 0;

				else if(cad1[i-1] == cad2[j-1]) 
					dp[i][j] = 1 + dp[i-1][j-1];

				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);	 
		}
		cout << dp[n][m] << endl;
	}	
		
return 0;	
}