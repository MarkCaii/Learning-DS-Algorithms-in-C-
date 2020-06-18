#include<iostream>
using namespace std;
int binary_search(int a[], int val, int low, int high){
	if(low > high){
		return -1;
	}
	int mid = (low+high)/2;
	if(a[mid] < val){
		binary_search(a, val, mid+1, high);
	}else if(a[mid] > val){
		binary_search(a, val, low, mid-1);
	}else{
		return mid;
	}
}
int main(){
	int t;
	cin >> t;
	while(t > 0){
		int n, q, val;
		cin >> n >> q;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < q; i++){
			cin >> val;
			cout << binary_search(a, val, 0, n-1) << " ";
		}
		cout << endl;
		t--;
	}
}
