#include<bits/stdc++.h>
using namespace std;

int main(){
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(5);
	pq.push(2);
	pq.push(10);
	cout << pq.top() << endl;
	pq.pop();
	cout << pq.top() << endl;
	pq.pop();
	pq.push(7);
	pq.push(12);
	cout << pq.top() << endl;
	pq.pop();
	cout << pq.top() << endl;
	pq.pop();

	return 0;
}
