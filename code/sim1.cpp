// complete graph with steady influence simulation with classic update

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
ofstream outfile;


void print_bel() {
	for(int i=0; i<bel.size(); i++) {
		outfile << "" << i << "" << bel[i] << endl; //belief printing function
	}	
	cout << endl;
}

void update_bel(double inf) {

	double sum = 0;
	for(auto u : bel) sum += u;

	for(int i=0; i<bel.size(); i++) {
		bel[i] = (1-inf)*bel[i] + ((inf/(double)bel.size())*sum);
	}
}

int main(){ _
	
	outfile.open("result.txt");

	int A; cin >> A; // A is the number of agents
	double inf; cin >> inf; // inf is the influence
	int t; cin >> t; // t is the last time stamp in the simulation

	double bel_i;
	for(int i=0; i<A; i++) {
		cin >> bel_i;
		bel.pb(bel_i); // reads the belief of i_th agent
	}

	for(int i=0; i<t; i++) {
		if(i%1 == 0) {
			outfile << "" << i << "" << endl; // prints time stamp
			print_bel(); // prints beliefs
		}
		double sum = 0;
		for(auto u : bel) sum += u;

		//if(i%1 == 0) cout << "" << sum << endl << endl; printed agent
		
		update_bel(inf);
	}


	exit(0);
}
