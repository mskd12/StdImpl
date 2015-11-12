// Kruskal's algorithm - MST (Minimum spanning tree)
// Institute Coding test
#include <bits/stdc++.h>
#define pp pair<int, int>
#define mp make_pair
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;

int findparent(int val, vector<int> &parent){
	if(parent[val]==val){
		return val;
	}
	parent[val] = findparent(parent[val],parent);
	return parent[val];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int e;
		cin>>e;
		vector<pair<ll,pp> > edges;
		for(int i=0; i<e; i++){
			int start, end, weight;
			cin>>start>>end>>weight;
			start--;
			end--;
			edges.pb(mp(weight,mp(start,end)));
		}
		sort(edges.begin(), edges.end());
		vector<int> parent(n);
		for(int i=0; i<n; i++){
			parent[i] = i;
		}
		ll sumAllCosts = 0;
		for(int i=0; i<e; i++){
			int start = edges[i].second.first;
			int end = edges[i].second.second;
			ll weight = edges[i].first;
			int p1 = findparent(start,parent);
			int p2 = findparent(end,parent);
			if(p1!=p2){
				parent[p1] = p2;
				sumAllCosts += weight;
			}
		}
		cout<<sumAllCosts<<endl;
	}
}