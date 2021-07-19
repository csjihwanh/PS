#include <iostream>

using namespace std;

const int maxN = 50050;

int Answer;

int n, k;
bool binary[maxN], root[maxN];

bool leftCheck(int index) {
	return (binary[index-k]);
}

bool rightCheck(int index) {
	return (binary[index+k]);
}

bool binaryCondition(int index) { //그 바이너리가 왼쪽 또는 오른쪽에 1을 갖고 있는지
	if(index < 1 || index > n) return true; //체크할 필요 없음
	if(index-k < 1 && index+k>n) return true;
	if(index-k < 1) return root[index+k];
	if(index+k > n) return root[index-k];
	return (root[index+k] || root[index-k]);
}


int main(int argc, char** argv)
{
	int T, test_case;
	char temp[maxN];
	
	freopen("/workspace/PS_Git/SCPC/input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    Answer = 0;
		
		scanf("%d %d %s", &n, &k, temp);
		
        for(int i = 1; i <= n; i++)	binary[i] = (temp[i-1]=='0')? 0:1;

		for(int i = 1; i <= n; i++)	{
			if(i-k<1 && i+k>n) root[i]=0;
			else if(i-k<1) root[i] = rightCheck(i);
			else if(i+k>n) root[i] = leftCheck(i);
			else root[i] = leftCheck(i)&&rightCheck(i);
		}
		
		for(int i = 1; i <= n; i++) {
			if(root[i]==0) continue;
			
			root[i] = 0;
			if(binaryCondition(i-k) == false || binaryCondition(i+k) == false) root[i]=1;
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		for(int i = 1; i <=n; i++) printf("%d", root[i]);
		cout<<endl;
	}

	return 0;//Your program should return 0 on normal termination.
}