#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct arrays{
	int a, b, d;
};
bool compare(const arrays &x, const arrays &y){
	return (x.a + x.b) > (y.a+y.b);
}
int fastread(){
	int x = 0;
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
	int t;
	t = fastread();
	while(t>0){
	       	int lara{0}, jonah{0};
		int n;
		vector<arrays> vec;
		arrays temp;
		n = fastread();
		int a[n], b[n];
		for(int i = 0; i < n; i++){
			a[i] = fastread();
		}
		for(int i = 0; i < n; i++){
			b[i] = fastread();
		}
		for(int i = 0; i < n; i++){
			temp.a = a[i];
			temp.b = b[i];
			temp.d = a[i]-b[i];
			vec.push_back(temp);
		}
		sort(vec.begin(), vec.end(), compare);
		int turn{0};
		int count = n;
		while(count > 0){
			if(turn == 0){
				turn = 1;
				for(int i = 0; i < n; i++){
					if(vec[i].a != 0){
						lara += vec[i].a;
						vec[i].b = 0;
						vec[i].a = 0;
						break;
					}
				}			
			}else if(turn == 1){
				turn = 0;
				for(int i = 0; i < n; i++){
					if(vec[i].b != 0){
						jonah += vec[i].b;
						vec[i].b = 0;
						vec[i].a = 0;
						break;
					}
				}
			}
			count--;
		}
		if(lara > jonah){
			cout << "First" << endl;
		}else if(jonah > lara){
			cout << "Second" << endl;
		}else{
			cout << "Tie" << endl;
		}
		t--;
	}
	return 0;
}
