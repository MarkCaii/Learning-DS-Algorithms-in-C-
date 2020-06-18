#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int answer[1000];

int tile(int n){
	//base case
	if(n == 1 || n == 2)
		return n;
	//if answer[n] is calculated, return it
	if(answer[n] != 0)
		return answer[n];

	//calculate and storing in answer[n]
	answer[n] = tile(n-1) + tile(n-2);

	//returning the stored answer
	return answer[n];
int main(){
	cout << "Number of ways of tiling 7x2 is: " << tile(7) << endl;
	return 0;
}
