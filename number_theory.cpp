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
#include <math.h>

using namespace std;

//generate primes less to n with segmented sieve
void vector_primes(int n, vector<int> &primes){

	if(n < 2) return;

	//first generate primes smaller than n
	primes.push_back(2);

	int N = sqrt(n) + 1;
	for(int i = 3 ; i < N ; i+=2){
		
		bool isprime = true;
		int cap = sqrt(i) + 1;

		for(int j = 0 ; j < primes.size() ; j++){
			
			if(primes[j] >= cap) break;
			if(i % primes[j] == 0){
				isprime = false;
				break;
			}
		}
		if(isprime) primes.push_back(i);
	}

	int low = N;
	int high = 2*N;

	int size = primes.size();
	while(low < n){

		if(high >= n)
			high = n;

		vector<bool> bin(N+1,0);

		for(int i = 0 ; i < size ; i++){

			int loLim = (low/primes[i]) * primes[i];
			if(loLim < low)
				loLim += primes[i];

			for(int j = loLim; j < high ; j+=primes[i])
				bin[j-low] = 1;
		}

		for(int i = low ; i < high ; i++){
			if(bin[i-low] == 0)
				primes.push_back(i); 
		}

		low += N;
		high += N;

	}


}


int main(){

	
	
return 0;   
}