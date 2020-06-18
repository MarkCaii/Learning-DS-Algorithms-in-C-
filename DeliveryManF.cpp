#include<cstdio>
#include<iostream>
using namespace std;
void merge(int a[], int index[], int low, int high, int mid){
	int i, j, k, c[high+1], ind[high+1];
	i = low; 
	k = low;
	j = mid +1;
	while(i <= mid && j<=high){
		if(a[i] > a[j]){
			ind[k] = index[i];
			c[k] = a[i];
			k++;
			i++;	
		}else{
			ind[k] = index[j];
			c[k] = a[j];
			k++;
			j++;
		}
	}
	while(i <= mid){
		ind[k] = index[i];
		c[k] = a[i];
		k++;
		i++;
	}
	while(j<= high){
		ind[k] = index[j];
		c[k] = a[j];
		k++;
		j++;
	}
	for(i = low; i < k; i++){
		index[i] = ind[i];
		a[i] = c[i];
	}
}

void mergeSort(int a[], int index[], int low, int high){
	if(low < high){
		int mid{(low+high)/2};
		mergeSort(a, index, low, mid);
		mergeSort(a, index, mid+1, high);
		merge(a, index, low, high, mid);
	}
	return;
}
int main(){
	int n, x, y, temp;
	cin >> n >> x >> y;
	int aTips[n];
	int bTips[n];
	for(int i = 0; i < n; i++){
		cin >> aTips[i];
	}
	for(int i = 0; i < n; i++){
		cin >> bTips[i];
	}
	int tipDiff[n];
	for(int i = 0; i < n; i++){
		tipDiff[i] = abs(aTips[i]-bTips[i]);
	}
	int index[n];
	for(int i = 0; i < n; i++){
		index[i] = i;
	}
	mergeSort(tipDiff, index, 0, n-1);
	int total{0};
	for(int i = 0; i < n; i++){
		if(aTips[index[i]] > bTips[index[i]]){
			if(x>0){
				total += aTips[index[i]];
				x--;
			}else{
				total += bTips[index[i]];
				y--;
			}
		}else{
			if(y>0){
				total += bTips[index[i]];
				y--;
			}else{
				total += aTips[index[i]];
				x--;
			}
		}
	}
	cout << total;
	return 0;
}
