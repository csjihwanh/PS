#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<map>

using namespace std;

const int maxN = 500500;
vector<int> player;
vector<int> tree(maxN*4);

int query(int left, int right, int node, int qleft, int qright) {
	if(qright<left || qleft > right) return 0;
	if(left>=qleft&&right<=qright) return tree[node];
	int mid = (left+right)/2;
	return query(left,mid,node*2,qleft,qright)+query(mid+1,right,node*2+1,qleft,qright);
}

void update(int left, int right, int node, int index) {
	if(index < left || index > right) return ;
	
	tree[node]++;
	
	if(left==right) return;
	int mid = (left+right)/2;
	update(left,mid,node*2,index);
	update(mid+1,right,node*2+1,index);
}

void coordCompress(int n) {
	vector<int> tempVec;
	map<int,int> contAbility;
	
	tempVec.resize(player.size());
	copy(player.begin(),player.end(),tempVec.begin());
	sort(tempVec.begin(),tempVec.end());
	
	int temp=1;
	contAbility.insert(make_pair(tempVec[0],1));
	for(int i =1; i<n; i++) {
		if(tempVec[i]>tempVec[i-1]) temp++;
		contAbility.insert(make_pair(tempVec[i],temp));
	}
	for(int i =0; i<n; i++)	player[i]=contAbility[player[i]];
}

int main () {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/2517/input.txt","r",stdin);
	
	int n,temp;
	cin>>n;
	for(int i = 0; i<n;i++) {
		cin>>temp;
		player.push_back(temp);
	}
	coordCompress(n);
	
	for(int i =0; i<n; i++) {
		cout<<i-query(1,n,1,1,player[i])+1<<'\n';
		update(1,n,1,player[i]);
	}
	return 0;
}
