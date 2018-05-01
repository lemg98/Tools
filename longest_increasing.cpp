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

vector<int> tail,res; int longest;

//longest increasing subsequence, tal-set and longest-value
void LIS(vector<int> &vec){

	int n = vec.size();
	tail.push_back(vec[0]);

	res = tail;

	vector<int>::iterator it;
	for(int i = 1 ; i < n ; i++){
		it = upper_bound(tail.begin(), tail.end(), vec[i]);//lower-strictly, upper-less_equal

		if(it != tail.end())	(*it) = vec[i];
		else { tail.push_back(vec[i]); res = tail; }

	}	
	longest = tail.size();
}

int main(){

	vector<int> vec; int t;
	while(cin >> t) vec.push_back(t);

	LIS(vec);
	cout << longest << endl;

	for(int i = 0 ; i < res.size() ; i++)
		cout << res[i] << endl;

return 0;   
}