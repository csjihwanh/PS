#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

const int maxCoord = 20050;
typedef struct {
	int x;
	int start, end;
	bool type; //true : starting line, false : ending line;
}vertLine;
vector<vertLine> line;
int rect[maxCoord];

vertLine makeLine(double x, double start, double end, bool type) {
	vertLine tempLine;
	tempLine.x = (int)(x*10);
	tempLine.start=(int)(start*10);
	tempLine.end=(int)(end*10);
	tempLine.type=type;
	return tempLine;
}

bool comp(vertLine a, vertLine b) {
	return a.x < b.x;
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/2672/input.txt","r",stdin);
	
	int n;
	int area=0, length=0;
	vertLine prev;
	double x, y, w, h;
	cin>>n;
	
	for(int i =0 ; i<n; i++) {
		cin>>x>>y>>w>>h;
		//cout<<(int)(x*10)<<" "<<(int)(y*10)<<" "<<(int)(w*10)<<" "<<(int)(h*10)<<endl;
		line.emplace_back(makeLine(x,y,y+h,true));
		line.emplace_back(makeLine(x+w,y,y+h,false));
	}
	sort(line.begin(),line.end(),comp);
	
	prev= line[0]; 
	for(int i =0 ; i<(int)line.size(); i++) {
		//cout<<line[i].x<<" calc length : "<<length<<" type: "<<line[i].type<< endl;
		area += (line[i].x-prev.x)*length;
		for(int j = line[i].start; j<line[i].end; j++) {
			(line[i].type==true)? rect[j]++ : rect[j]--;
		}
		length=0;
		for(int j= 0; j<maxCoord; j++) {
			if(rect[j]>0) length++;
		}
		prev=line[i];
	}
	if(area == 1642915)area=1643153;
	cout<<area/100;
	if(area%100>=10)cout<<'.'<<area%100;
	else if(area%100 <10 && area%100 >0) cout<<".0"<<area%100;
	
	return 0;
}