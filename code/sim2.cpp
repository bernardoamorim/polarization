// complete graph with variating influence simulation of classic update

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<double> bel;
vector<double> aux_bel;
vector<vector<double> > inf;

void print_bel() {
	for(int i=0; i<bel.size(); i++) {
		cout << "agent: " << i << " bel: " << bel[i] << endl;
	}	
	cout << endl;
}

void update_bel() {

	aux_bel = bel;
	double sum = 0;
	for(auto u : bel) sum += u;

	double bel_i;
	for(int i=0; i<bel.size(); i++) {
		bel_i = 0;
		for(int j=0; j<bel.size(); j++) {
			bel_i += aux_bel[i] + inf[j][i]*(aux_bel[j]-aux_bel[i]);
		}
		bel_i /= (double) bel.size();
		bel[i] = bel_i;
	}
}

int main(){ _

	int A; cin >> A; // A is the number of agents
	int t; cin >> t; // t is the last time stamp in the simulation

	double bel_i;
	for(int i=0; i<A; i++) {
		cin >> bel_i;
		bel.pb(bel_i); // reads the belief of i_th agent
	}

	inf.resize(A);
	double inf_i_j;
	for(int i=0; i<A; i++) {
		for(int j=0; j<A; j++) {
			cin >> inf_i_j;
			inf[i].pb(inf_i_j); // reads the influence of agent i over agent j
		}	
	}

	for(int i=0; i<t; i++) {
		if(i%1 == 0) {
			cout << "time t = " << i << ":" << endl;
			print_bel();
		}
		
		double maxi = -1, mini = 2, posmax, posmin;
		for(int j=0; j<bel.size(); j++) {
			auto u = bel[j];
			if(u < mini) {mini = u; posmin = j;}
			if(u > maxi) {maxi = u; posmax = j;}
		}

		cout << "posmax = " << posmax << endl;
		cout << "posmin = " << posmin << endl;
		

		cout << "max " << maxi << endl;
		cout << "min " << mini << endl;

		update_bel();
	}


	exit(0);
}
