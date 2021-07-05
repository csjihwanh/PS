#include <iostream>
#include <string.h>
#include <algorithm>

const int maxRC = 800;
const int UL = 1, UR =2, DL =3, DR = 4;
const int DIR = 4;
const int dirRef[5][2] = {{0,0,},{-1,-1},{-1,1},{1,-1},{1,1}};

using namespace std;

int r, c;
int map[maxRC][maxRC];
int diaRow[DIR+1][maxRC][maxRC];

int minAmongFour(int a, int b, int c, int d) {
	if( a<b&&a<c&&a<d) return a;
	else if(b<c&&b<d) return b;
	else if(c<d) return c;
	else return d;
}

void findMaxRow() {
	for(int i = UL; i <= UR; i++) {
		for(int j = 1; j <= r; j++) {
			for(int k = 1; k <= c; k++) {
				if(map[j][k] == 0) diaRow[i][j][k] =0;
				else 
					diaRow[i][j][k] = max(diaRow[i][j+dirRef[i][0]][k+dirRef[i][1]]+1, 1);
			}
		}
	}
	
	for(int i = DL; i <= DR; i++) {
		for(int j = r; j >= 1; j--) {
			for(int k = 1; k <= c; k++) {
				if(map[j][k] == 0) diaRow[i][j][k] =0;
				else 
					diaRow[i][j][k] = max(diaRow[i][j+dirRef[i][0]][k+dirRef[i][1]]+1, 1);
			}
		}
	}
	
}


int findMaxDia() {
	int maxAbleSize;
	int maxDia = 0;
	for(int i = 1; i <= r; i++) { // col
		for(int j = 1; j <= c; j++) { //row
			maxAbleSize = minAmongFour(i,j,r-i+1, c-j+1);
			for(int k = maxAbleSize; k>=1; k--) { //옆으로 확장시키며
				if(diaRow[UL][i][j+k-1] >= k && diaRow[UR][i][j-k+1] >= k &&
				   diaRow[DL][i][j+k-1] >= k && diaRow[DR][i][j-k+1] >= k) { //다 k보다 크다면
					maxDia = max(maxDia, k);
					break;
				}
			}
		}
	}
	return maxDia;
}

int main(void) {
	
	freopen("/workspace/PS_Git/BOJ/1028/input.txt", "r", stdin);
	
	char tempString[maxRC];
	
	scanf("%d %d", &r, &c);
	
	for(int i = 1; i <= r; i++) {
		scanf("%s", tempString);
		for(int j = 0; j< strlen(tempString); j++) {
			map[i][j+1] = (tempString[j]=='0'? 0:1); 
		}
	}
	
	findMaxRow();
	
	cout<<findMaxDia()<<endl;
	
}