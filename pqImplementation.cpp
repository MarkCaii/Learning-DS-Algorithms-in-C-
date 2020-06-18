#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int fastread(){
	int x = 0;
	int c = getchar_unlocked();
	while(c<48)
		c = getchar_unlocked();
	while(c >= 48){
		x = x*10 + (c-48);
		c = getchar_unlocked();
	}
	return x;
}
void heapsort(int a[], int n){
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; i++){
		pq.push(a[i]);
	}
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();	
	}
	cout << endl;
}
int main(){
	priority_queue<int, vector<int>, greater<int>> pq;
	int t = fastread();
	while(t--){
		int n = fastread();
		int a[n];
		for(int i = 0; i < n; i++){
			a[i] = fastread();
		}
		heapsort(a, n);
	}
}
