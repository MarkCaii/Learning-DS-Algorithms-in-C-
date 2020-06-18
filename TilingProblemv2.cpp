#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int fastread(){

	int x = 0;
	int c = getchar_unlocked();
	while(c<48)
		c = getchar_unlocked();
	while(c>=48){
		x = x*10 + (c-48);
		c = getchar_unlocked();
	}
	return x;
}
int main(){
	int t = fastread();
	while(t--){
		int n = fastread(), tile{0};
		int answer[n+1];
		answer[1] = 1;
		answer[2] = 2;
		int g[n+1];
		g[1] = 1;
		g[2] = 2;
		for(int i = 3; i < n+1; i++){
			g[i] = g[i-1] + answer[i-1];
			answer[i] = answer[i-1] + answer[i-2] + 2*g[i-2];
		}
		int ans = answer[n]%100003;
		cout << ans << endl;
	}
}
