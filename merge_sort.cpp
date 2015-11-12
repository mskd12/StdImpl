#include <bits/stdc++.h>
#define pb push_back

using namespace std;

void mergesort(vector<int> &V, int start, int end) {
	if(start>=end)
		return;
	int mid=(start+end)/2;
	mergesort(V, start, mid);
	mergesort(V, mid+1, end);
	// merge(V, start, mid, end);
	vector<int> V1=V;
	int it1=start, it2=mid+1, curr=start;
	while(curr<=end) {
		if(it1>mid) {
			V[curr] = V1[it2];
			curr++;
			it2++;
			continue;
		}
		if(it2>end || V1[it1]<=V1[it2]) {
			V[curr] = V1[it1];
			curr++;
			it1++;
			continue;
		}
		if(V1[it1]>V1[it2]) {
			V[curr] = V1[it2];
			curr++;
			it2++;
			continue;			
		}
	}
}

int main() {
	int N;
	cin >> N;
	vector<int> V(N);
	for(int i=0; i<N; i++)
		cin >> V[i];
	mergesort(V, 0, N-1);
	for(int i=0; i<N; i++)
		cout << V[i];
	cout << endl;
}