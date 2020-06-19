#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int ans[1000][1000] = {0};
int findmax(string s1, string s2, int i, int j){
	if(i > s1.length()-1 || j > s2.length()-1){
		return 0;
	}
	if(s1[i] == s2[j]){
		if(ans[i][j] == 0){
			ans[i][j] = 1+findmax(s1, s2, i+1, j+1);
		}
		return ans[i][j];
	}else if(s1[i] != s2[j]){
		if(ans[i][j] == 0){
			int a, b;
			a = findmax(s1,s2,i+1,j);
			b = findmax(s1,s2,i,j+1);
			if(a > b){
				ans[i+1][j] = a;
				return ans[i+1][j];
			}else{
				ans[i][j+1] = b;
				return ans[i][j+1];
			}
		}

	}
}
int main(){
	string s1, s2;
	cin >> s1 >> s2;
	int index = 0;
	if(s1.length() < s2.length()){
		cout << findmax(s1, s2, 0, 0);
	}else{
		cout << findmax(s2, s1, 0, 0);
	}
}
