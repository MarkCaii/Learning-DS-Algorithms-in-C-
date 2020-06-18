#include<vector>
#include<iostream>
using namespace std;
struct Cust{
	public:
		int s, f, r;
};
bool comparator(const Cust &x, const Cust &y){
	if(x.r != y.r){
		return x.r < y.r;
	}
	return x.f < y.f;
}
int fastread(){
	int x = 0;
	int c = getchar_unlocked();
	while(c > 47 && c < 58){
		x = x*10 + (c-48);
		c = getchar_unlocked();
	}
	return x;
}
int main(){
	Cust c;
	int t;
	for(t = fastread(); t > 0; t--){
		int n = fastread(), k = fastread(), last = 0;
		int max{0};
		vector<Cust> vec;
		for(int i  = 0; i < n; i++){
			c.s = fastread();
			c.f = fastread();
			c.r = fastread();
			vec.push_back(c);
		}
		sort(vec.begin(), vec.end(), &comparator);
		for(int i = 0; i < n; i++){
			cout << vec[i].s << " " << vec[i].f << " " << vec[i].r << endl;
		}
		for(int i = 1; i < n; i++){
			if(vec[last].r != vec[i].r){
				max++;
				last = i;
			}else if(vec[i].s >= vec[last].f){
				max++;
				last = i;
			}
		}
		//cout << max << endl;
	}
	return 0;
}
