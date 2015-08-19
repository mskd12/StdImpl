// SPOJ - NHAY
#include <bits/stdc++.h>
#define pp pair<int, int>
#define mp make_pair
#define pb push_back
#define MAX 1000000

using namespace std;

typedef long long ll;

int main() {
	int patlen;
	while(cin >> patlen) {
		vector<char> pattern(patlen);
		vector<int> pifunc(patlen,0);
		int k=0;
		for(int i=0; i<patlen; i++) {
			cin >> pattern[i];
			if(i==0)
				continue;
			while(k>0 && pattern[i]!=pattern[k])
				k=pifunc[k-1];
			if(pattern[i]==pattern[k])
				k++;
			pifunc[i]=k;
		}
		char c;
		k=0;
		int i=0;
		bool b=false;
		cin.ignore();
		while(cin.get(c)) {
			if(c=='\n')
				break;
			while(k>0 && c!=pattern[k])
				k=pifunc[k-1];
			if(c==pattern[k])
				k++;
			if(k==patlen) {
				b=true;
				cout << i - patlen + 1 << "\n";
				k=pifunc[k-1];
			}
			i++;
		}
		if(!b)
			cout << "\n";
	}
}