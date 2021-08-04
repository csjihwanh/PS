#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef struct { 
	int s, e;
}Line;

Line newLine(int s, int e){
	Line myLine;
	myLine.s = s, myLine.e = e;
	return myLine;
}

bool compLine(Line a, Line b) {
	return a.s < b.s;
}

int main (void ) {
	freopen("/workspace/PS_Git/BOJ/2170/input.txt", "r", stdin) ;
	
	int n,temp1,temp2;
	vector<Line> line;
	Line recentLine;
	ll sum = 0;

	cin>>n;
	for(int i =0;i<n;i++) {
		cin>>temp1>>temp2;
		line.emplace_back(newLine(temp1,temp2));
	}
	sort(line.begin(), line.end(), compLine);
	
	recentLine = line[0];
	for(int i =0; i<n; i++) {
		if(line[i].s <= recentLine.e) {
			if(line[i].e>recentLine.e) recentLine.e=line[i].e;
			if(i==n-1) sum+=recentLine.e-recentLine.s;
		}
		else {
			sum+= recentLine.e-recentLine.s;
			recentLine=line[i];
		}
		cout<<recentLine.s<<" "<<recentLine.e<<endl;
	}
	
	cout<<sum<<'\n';
	
	return 0;
}