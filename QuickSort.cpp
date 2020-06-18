#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low-1;
	for(int j = low; j < high; j++){
		if(arr[j] <= pivot){
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
	return(i+1);
}
void quicksort(int a[], int low, int high){
	if(low < high){
		int p = partition(a, low, high);
		quicksort(a, low, p-1);
		quicksort(a, p+1, high);
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		quicksort(a, 0, n-1);
		for(int i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
