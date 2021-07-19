#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 550;
const int maxK = 2050;

typedef struct {
	int s, e;
	int dir; //0 : s->e, 1: e->s;
}Edge;

int n ,m, k;
Edge e[maxK], pe[maxK]; //edge, pseudoedge; 
bool Answer[maxK];
int way[maxN][maxN], fixway[maxN][maxN];

void wayStatus() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			printf("%d ", way[i][j]);
		}
		cout<<endl;
	}
	cout<<endl;
}

bool DFS(int start, int index, bool* check) { //if there's cycle : true / else : false;
	check[index] = true;
	for(int i = 1; i <= n; i++) {
		if(way[index][i] == 0) continue;
		else {
			if(i == start) return true; //cycle			
			if(check[i] == true) continue;
			
			if(DFS(start, i, check) == true) return true;
		}
	}
	return false;
}

bool cycle() {
	bool check[maxN];
	for(int i = 1; i <= n; i++) check[i] = false;
	
	for(int i = 1; i <=n; i++) {
		if(check[i] == true) continue;
		else if(DFS(i, i, check)) return true;
	}
	return false;
}

void flipDir(int index, int to) {
	pe[index].dir= to;
	if(to == 0) {
		way[pe[index].s][pe[index].e] = 1;
		way[pe[index].e][pe[index].s] = 0;
		if(fixway[pe[index].e][pe[index].s]==1) way[pe[index].e][pe[index].s] = 1;
	}
	else {
		way[pe[index].e][pe[index].s] = 1;
		way[pe[index].s][pe[index].e] = 0;
		if(fixway[pe[index].s][pe[index].e]==1) way[pe[index].s][pe[index].e] = 1;
	}
}

bool makeDir(int index) {
	if(index <= k) {
		Answer[index] = false;
		flipDir(index, 0);
		if(makeDir(index+1)) return true;
		
		Answer[index]=true;
		flipDir(index, 1);
		if(makeDir(index+1)) return true;
	}
	else {
		if(cycle()) return false;
		else return true;
	}
	return false;
}

int main(int argc, char** argv)
{
	int T, test_case;
	
	freopen("/workspace/PS_Git/SCPC/input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		int temp1, temp2, j=1;
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		scanf("%d %d %d", &n, &m, &k);
		for(int i = 1; i <= m; i++) {
			scanf("%d %d", &temp1, &temp2);
			e[i].s = temp1, e[i].e = temp2;
			e[i].dir = 1; way[temp1][temp2] = 1;
			fixway[temp1][temp2] =1;
		}
		
		for(int i = 1; i <= k; i++) {
			scanf("%d %d", &temp1, &temp2);
			pe[i].s = temp1, pe[i].e= temp2;
			pe[i].dir = 1; way[temp1][temp2] = 1;
		}
		
		makeDir(1);
		
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		for(int i =1; i <= k; i++) printf("%d", Answer[i]);
		cout<<endl;
	}

	return 0;//Your program should return 0 on normal termination.
}