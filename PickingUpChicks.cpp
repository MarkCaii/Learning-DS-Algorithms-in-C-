#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int fastread(){
	int x =0;
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
	int c{fastread()};
	for(int i = 0;i<c;i++){
		int n, k, b, t, temp;
		cin >> n >> k >> b >> t;
		int pos[n], speed[n];
		for(int j = 0; j < n; j++){
			cin >> pos[j];
		}
		for(int j = 0; j < n; j++){
			cin >> speed[j];
		}
		if(k == 0){
			cout << "Case #" << i+1 << ": 0" << endl;
			continue;
		}
		double times[n];
		temp = k;
		for(int j = 0; j < n; j++){
			times[j] = double(b-pos[j])/speed[j];
			if(times[j] <= t){
				temp--;
			}
		}
		if(temp > 0){
			cout << "Case #" << i+1 << ": IMPOSSIBLE" << endl;
			continue;
		}
		int swaps{0}, ints{0};
		for(int j = n-1; j>=0; j--){
			double time = (double)(b-pos[j])/speed[j];
			if(time <= t){
				k--;
				swaps += ints;
			}else{
				ints++;
			}
			if(k==0){
				cout << "Case #" << i+1 << ": " << swaps << endl;
				break;
			}
		}
	}
	return 0;
}
