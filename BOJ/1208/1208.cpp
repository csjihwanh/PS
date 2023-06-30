#include <iostream>
#include <set>
#define MAX_S 1000050

using namespace std;


int arr[2*MAX_S], nextArr[2*MAX_S];
set<int> elements, nextElements;

const int MID = MAX_S;

int main (void) {

    int n, s; 
    int current; 

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>s;

    for(int i = 1; i <= n; i++) {
        cin>>current ;

        for(auto j : elements) {
            nextArr[MID + j] = arr[MID + j];
        }

        for(auto j : elements) { 
            if(j + current < -1e6 or j + current > 1e6) continue;
            nextArr[MID + j+current] += arr[MID + j];
            nextElements.insert(j+current);
        }
        nextElements.insert(current);
        nextArr[MID + current] ++;

        cout<<endl;
        for(auto j : nextElements) 
            elements.insert(j);

        for(auto j : elements) {
            arr[MID + j] = nextArr[MID + j];
            nextArr[MID + j] = 0;
        }
    }

    cout<<arr[MID+ s];
    return 0;

}