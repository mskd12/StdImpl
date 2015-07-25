#include <bits/stdc++.h>
#define pp pair<int, int>
#define mp make_pair
#define ll long long
#define pb push_back
#define MAX (10 << 8)

using namespace std;

int seg[MAX];
vector<int> input;

void build(int node, int i, int j) {
	if(i==j) { // LEAF
		seg[node] = input[i];
		return;
	}
	build(2*node, i, (i+j)/2);
	build(2*node+1, ((i+j)/2)+1, j);
	seg[node] = seg[2*node] + seg[2*node+1];
}

// Update range-[i,j] by val, curr node range-[a,b]
void update(int node, int a, int b, int i, int j, int val) {
	if(a > b || a > j || b < i)
		return;
	if(a==b) {
		seg[node] += val;
		return;
	}
	update(2*node, a, (a+b)/2, i, j, val);
	update(2*node+1, ((a+b)/2)+1, b, i, j, val);
	seg[node] = seg[2*node] + seg[2*node+1];
}

// Query range-[i,j] , curr node range-[a,b]
int query(int node, int a, int b, int i, int j) {
	if(a > b || a > j || b < i)
		return 0;
	if((a==b) || (a>=i && b<=j)) {
		return seg[node];
	}
	int ans = query(2*node, a, (a+b)/2, i, j);
	ans += query(2*node+1, ((a+b)/2)+1, b, i, j);
	return ans;
}

int main() {
	int a[9] = {0,1,3,2,6,7,3,4,8};
	vector<int> A(a, a + sizeof(a)/sizeof(a[0]));
	input = A;
	int n = input.size();
	build(1, 1, n-1);
	for(int i=1; i<=15; i++)
		cout << seg[i] << " ";
	cout << endl;
	update(1, 1, n-1, 2, 4, 2);
	for(int i=1; i<=15; i++)
		cout << seg[i] << " ";
	cout << endl;
	cout << query(1, 1, n-1, 1, 5) << endl;
}