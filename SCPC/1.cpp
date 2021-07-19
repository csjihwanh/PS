/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/
#include <iostream>
#include <stdio.h>

using namespace std;

const int maxN = 100500;

int set[maxN];
bool setCheck[maxN];

int n;
int Answer;

void initSet() {
	for(int i = 1; i < maxN; i++) {
		set[i]=i;
		setCheck[i] = false;
	}
}

void swap(int* a, int* b) {
	int temp = *a;
	*a= *b;
	*b = temp;
}

int Find(int index) {
	if(set[index]==index) return index;
	else return set[index]=Find(set[index]);
}

void Union(int index1, int index2) {
	int root1 = Find(index1), root2 = Find(index2);
	if(root1 > root2) swap(&root1, &root2);
	set[root2] = set[root1];
}

int main(int argc, char** argv)
{
	int T, test_case;
	int nextFriend;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	freopen("/workspace/PS_Git/SCPC/input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		initSet();
		
		scanf("%d", &n);
		
		for(int i = 1; i <= n; i++) {
			scanf("%d", &nextFriend);
			if(i+nextFriend >n) continue;
			Union(i,i+nextFriend);
		}
		
		for(int i = 1; i <= n; i++) {
			if(setCheck[Find(i)] == false) {
				Answer++;
				setCheck[Find(i)] = true;
			}
		}
		
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}