#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

typedef struct line{

	float lx, rx, y;
	bool begin;
	line(float a, float b, float c, bool d) {
		lx = a; rx = b; y=c; begin=d;
	}	

}Line;

vector<Line> l;
vector<float> xs; 

bool Comp(Line a, Line b) {
	return a.y < b.y;
}
	
void getInput() {
	int n;
	float x, y, w, h;
	cin>>n;
	for(int i =1; i<= n; i++) {
		cin>>x>>y>>w>>h;
		l.emplace_back(x,x+w, y,true);
		l.emplace_back(x,x+w, y+h,false);;
		xs.emplace_back(x), xs.emplace_back(x+w);
	}
	sort(l.begin(), l.end(), Comp);
	sort(xs.begin(), xs.end());
}

float getAnswer() {
	float answer; 
	float mass=0, prev_x; 
	for(float i : xs)  {
		//cout<<i<<" "<<mass<<" " << mass * (i - prev_x)<<endl;
		if(i != xs.front()) answer += mass * (i - prev_x);

		mass= 0; prev_x = i;
		float line_begin = 0; 
		int count = 0;
		for(Line j : l) {
			if(j.rx <= i || j.lx > i) continue; 
			if(j.begin) {
				count++;
				if(count == 1) line_begin = j.y;
			}
			else {
				count--;
				if(count == 0) mass += j.y-line_begin;
			}
			//cout<<"count: "<<count<<" j : "<<j.begin<< " y : "<<j.y<<endl;
		}

	}
	return answer; 
}


int main(void) {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	float answer = 0;
	getInput();
	answer = getAnswer();
	

	if(answer != floor(answer)) {
		cout<<fixed;
		cout.precision(2);
	}
	cout<<answer<<endl;
	return 0;
}
	