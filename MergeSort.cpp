#include<iostream>
using namespace std; 
void merge(int a[], int low, int high, int mid){
	int c[high+1];
	int i = low, j = mid+1, k = low;
	while(i <= mid && j <= high){
		if(a[i] <= a[j])
			c[k++] = a[i++];
		else
			c[k++] = a[j++]; 
	}
	while(i <= mid)
		c[k++] = a[i++];
	while(j <= high)
		c[k++] = a[j++];
	for(i = low; i < high; i++){
		a[i] = c[i];
	}
}
void mergesort(int a[],int low, int high){
	if(low < high){
		int mid = (low+high)/2;
		mergesort(a, low, mid);
		mergesort(a, mid+1, high);

		merge(a, low, high, mid);
	}
}
int main(){
	int size_a = 6;
	int a[] = {22, 43, 59, 17, 31, 64};
	mergesort(a, 0, size_a-1);
	for(int i = 0; i < size_a; i++){
		cout << a[i] << " ";
	}
	return 0;
}
