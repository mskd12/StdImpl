// Segment tree - Non-recursive
#include <bits/stdc++.h>
#define pp pair<int, int>
#define mp make_pair
#define ll long long
#define pb push_back
#define MAX (10 << 8)

using namespace std;

int n = 8;
int seg[MAX];

void build(int input[]) {
	// BUILD
	for(int i=2*n-1; i>=1; i--) {
		if(i>=n) {
			seg[i] = input[i-n];
		}
		else {
			seg[i] = seg[2*i]+seg[2*i+1];
		}
	}
}

int query(int i, int j) {
	// QUERY
	// if(i>j)
	// 	return query(i,n-1) + query(0,j);
	i+=n;
	j+=n;
	int ans = 0;
	for(; i<=j; i=(i+1)>>1, j=(j-1)>>1) {
		if(i&1) {
			ans = ans+seg[i];
		}
		if(!(j&1)) {
			ans = ans+seg[j];
		}
	}
	return ans;
}

void update(int i, int val) {
	i+=n;
	seg[i] = val;
	i = i>>1;
	for(; i>=1; i=i>>1) {
		seg[i] = seg[2*i]+seg[2*i+1];
	}
}

int main() {
	int input[8] = {1,4,6,3,2,7,5,2};
	build(input);
	cout << query(1,5) << endl;
	update(2,0);
	cout << query(1,5) << endl;
}