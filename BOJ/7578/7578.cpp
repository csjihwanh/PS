#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include<map>
#define D cout<<":C"<<endl;

typedef long long int ll;
using namespace std;

const int maxN = 500500;
vector<int> num={0};
map<int,int> assign;
vector<ll> tree(maxN*4);

void update(int left, int right, int node, int index) {
	if(right < index || left > index) return ;
	tree[node]++;
	
	if(left==right)return;
	int mid = (left+right)/2;
	update(left,mid,node*2,index);
	update(mid+1,right,node*2+1,index);
}

ll query(int left, int right, int node, int qleft, int qright) {
	if(qright < left || qleft > right) return 0;
	if(qleft <= left && right <= qright) return tree[node];
	int mid = (left+right)/2;
	return query(left,mid,node*2,qleft,qright)+query(mid+1,right,node*2+1,qleft,qright);
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/7578/input.txt","r",stdin);
	
	int n,temp;
	ll sum=0;
	cin>>n;
	
	for(int i = 1; i<=n; i++) {
		cin>>temp;
		assign.insert(make_pair(temp,i));
	} 
	for(int i = 1; i<=n; i++) {
		cin>>temp;
		num.push_back(assign[temp]);
	}
	
	for(int i = 1; i<=n; i++) {
		if(num[i]+1<=n)sum+=query(1,n,1,num[i]+1,n);
		cout<<i<<"th value "<<num[i]<<"'s query value : "<<query(1,n,1,num[i]+1,n)<<endl;
		update(1,n,1,num[i]);
	}
	cout<<sum;
	return 0;
}