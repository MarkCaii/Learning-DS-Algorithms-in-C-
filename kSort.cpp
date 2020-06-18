#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int fastread(){
	int x = 0;
	int c = getchar_unlocked();
	while(c < 48)
		c = getchar_unlocked();
	while(c >= 48){
		x = x*10 + (c-48);
		c = getchar_unlocked();
	}
	return x;
}
void heapsort(priority_queue<int, vector<int>, greater<int>> pq){
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}
int main(){
	int t;
	t = fastread();
	while(t--){
		int k = fastread();
		priority_queue<int, vector<int>, greater<int>> pq; 
		for(int i = 0; i < k; i++){
			int n = fastread();
			for(int j = 0; j < n; j++){
				pq.push(fastread());
			}
		}
		heapsort(pq);
	}
}
