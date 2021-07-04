#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1050;

int t, n, k;
int cnt[maxN], cost[maxN];
bool order[maxN][maxN];
bool chk[maxN];
int obj= 0;
vector<pair<int,int> > onBuild, temp;
	
void initVar() {
	onBuild.clear();
	temp.clear();
	
	for(int i =0 ; i < maxN; i++) {
		cnt[i]=0;
		chk[i] = false;
		cost[i] = 0;
		for(int j = 0 ; j<maxN; j++) {
			order[i][j] = false;
		}
	}
}

void scanVar() {
	
	int temp1, temp2;
	
	scanf("%d %d", &n, &k);
		
	for(int j = 1; j <= n; j++) {
		scanf("%d", &cost[j]);
	}
	
	for(int j = 0; j < k; j++) {
		scanf("%d %d", &temp1, &temp2);
		order[temp1][temp2] = true;
		cnt[temp2]++;
	}
	scanf("%d", &obj);
}

int findMinIndex() {
	int valueMin = 987654321;
	int minIndex = -1;
	for(int i = 0 ; i < onBuild.size(); i++) {
		if(onBuild[i].second < valueMin) {
			minIndex= i;
			valueMin = onBuild[i].second;
		}
	}
	return minIndex;
}

void subMinTime(int minIndex) {
	int minTime = onBuild[minIndex].second;
	temp.clear();
	for(int i = 0; i < onBuild.size(); i++) {
		pair<int, int> tempPair = onBuild[i];
		temp.push_back(tempPair);
	}
	onBuild.clear();
	for(int i = 0; i < temp.size(); i++) {
		if(i == minIndex) continue;
		onBuild.push_back(make_pair(temp[i].first, temp[i].second - minTime));
	}
}

void checkNewBuild(int index) {
	for(int i = 1 ; i<= n; i++) {
		if(order[index][i] == true) {
			cnt[i]--;
			if(cnt[i] == 0 && chk[i] == false) {
				onBuild.push_back(make_pair(i, cost[i]));
				
				chk[i] = true;
			}
		}
	}
}

int main ( void ) {
	freopen("/workspace/PS_Git/BOJ/1005/input.txt","r", stdin);
	
	int minIndex, minNum; //minIndex는 벡터상에서의 index, minNum은 건물 번호 
	int sum;
	
	scanf("%d", &t);
	for(int i = 0 ; i< t ; i++) {
		initVar();
		scanVar();
		minIndex= -1, minNum = -1;
		sum =0;
		
		for(int j = 1; j <= n; j++) { //initializing
			if(cnt[j] == 0) {
				onBuild.push_back(make_pair(j, cost[j]));
				chk[j] = true;
			}
		}
		
		
		
		while(minNum!= obj) {
			minIndex = findMinIndex();
			minNum = onBuild[minIndex].first;
			sum+= onBuild[minIndex].second;
			subMinTime(minIndex); //renewed onBuild vector
			checkNewBuild(minNum);
		}
		
		printf("%d\n", sum);
		
	}
	return 0;
	
}