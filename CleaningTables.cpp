#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fastread(){
	int x=0;
	int c=getchar_unlocked();
	while(c<48)
		c = getchar_unlocked();
	while(c>=48){
		x = x*10 + (c-48);
		c = getchar_unlocked();
	}
	return x;
}
int findLatest(int o[], int start, int m, int n, int tables[]){
	int latest, index;
	int c[401] = {0};
	for(int j = start; j < m; j++){
		if(c[o[j]] == 0){
			c[o[j]] = j;
		}
	}
	latest = c[tables[0]];
	for(int i = 0; i < n; i++){
		if(c[tables[i]] == 0){
			index = i;
			break;
		}
		if(c[tables[i]] >= latest){
			latest = c[tables[i]];
			index = i;
		}
	}
	return index;
}
int main(){
	int t;
	for(t = fastread(); t > 0; t--){
		int n = fastread(), m = fastread(), temp, sum{0};
	       	int tables[n] = {0};
	       	int o[m];
		for(int i = 0; i < m; i++){
			o[i] = fastread();
		}
		for(int i = 0; i < m; i++){
			bool seated = false;
			for(int j = 0; j < n; j++){
				if(tables[j] == o[i]){
					seated = true;
					break;
				}
			}
			if(seated){
				continue;
			}
			for(int j = 0; j < n; j++){
				if(tables[j] == 0){
					tables[j] = o[i];
					sum++;
					seated = true;
					break;
				}
			}
			if(!seated){
				tables[findLatest(o, i, m, n, tables)] = o[i];
				sum++;
				seated = true;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
