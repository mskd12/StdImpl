// Prim's algorithm - MST (Minimum spanning tree)
// Institute Coding test
#include <bits/stdc++.h>
#define pp pair<int, int>
#define mp make_pair
#define pb push_back
#define pf push_front
#define MAX 10000000001

using namespace std;

typedef long long ll;

int cost[1001][1001];

int main() {
	int T;
	cin >> T;
	while(T>0) {
		T--;
		int N, H;
		cin >> N >> H;
		vector<vector<int> > edges(N+1, vector<int>());
		int minCost=MAX;
		for(int i=0; i<H; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			cost[a][b] = c;
			cost[b][a] = c;
			edges[a].pb(b);
			edges[b].pb(a);
		}
		int start=1;
		//cout << start << endl;
		ll ans=0;
		set<pp> Q;
		vector<bool> visited(N,false);
		visited[start]=true;
		vector<int> succ=edges[start];
		for(int i=0; i<succ.size(); i++) {
			Q.insert(mp(cost[start][succ[i]], succ[i]));
		}
		while(Q.size()!=0) {
			pp elem=*(Q.begin());
			Q.erase(Q.begin());
			int node=elem.second;
			if(visited[node])
				continue;
			visited[node]=true;
			ans+=elem.first;
			vector<int> succ=edges[node];
			for(int i=0; i<succ.size(); i++) {
				if(!visited[succ[i]])
					Q.insert(mp(cost[node][succ[i]], succ[i]));
			}
		}
		cout << ans << endl;
	}
}