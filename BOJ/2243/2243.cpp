#include <iostream>
#include <vector>

using namespace std;

const int maxV = 1000000;
vector<int> tree(4*maxV);

int query(int left, int right, int node, int cnt, int rank) {
	if(left==right)return left;
	int mid = (left+right)/2;
	if(cnt+tree[node*2]>=rank) {
		return query(left,mid,node*2,cnt,rank);
	}
	return query(mid+1,right,node*2+1,cnt+tree[node*2],rank);
}

void update(int left, int right, int node, int index, int dif) {
	if(left > index || right < index) return;
	tree[node]+=dif;
	if(left==right)return ;
	int mid = (left+right)/2;
	update(left,mid,node*2,index,dif);
	update(mid+1,right,node*2+1,index,dif);
}

int main () {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/2243/input.txt","r",stdin);
	int n;
	int a, b, c;
	
	cin>>n;
	for(int i = 1; i <=n; i++) {
		cin>>a;
		if(a==1) {
			cin>>b;
			int q = query(1,maxV,1,0,b);
			cout<<q<<'\n';
			update(1,maxV,1,q,-1);
		}
		else if(a==2) {
			cin>>b>>c;
			update(1,maxV,1,b,c);
		}
	}
	return 0;
}