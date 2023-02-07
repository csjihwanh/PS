#include <iostream>
#include <map>
#include <string.h>
#include <vector>
#define DE cout<<"debug"<<endl;

using namespace std;

map<string, int> name;
int nameCnt = 0;
vector<int> parent;
vector<int> friends;

int nameMap(string myName) {
    if( name.count(myName) > 0 ) 
        return name[myName];
    else {
        name.insert(make_pair(myName, nameCnt));
        parent.emplace_back(nameCnt);
        friends.emplace_back(1);
        return nameCnt++;
    }
}

int Root(int a) {
    if(parent[a] == a) return a; 
    else return Root(parent[a]);
}

void Union(int a, int b) {
    int root_a = Root(a);
    int root_b = Root(b);
    parent[b] = root_a;
    
    if(root_a == root_b) return;
    parent[root_b] = root_a;
    friends[root_a] += friends[root_b];
}

int main(void) {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string namestr1, namestr2;
    int name1, name2;
    int n, f; 

    cin>>n;
    for (int i = 1; i<= n;i++) {
        cin>>f;
        name.clear();
        parent.clear();
        friends.clear();
        nameCnt=0;
        for(int j = 1; j <= f; j++) {

            cin>>namestr1>>namestr2;
            name1 = nameMap(namestr1);
            name2 = nameMap(namestr2);

            Union(name1, name2); 
            cout<< friends[Root(name1)]<<'\n';
        }
    }
    return 0;

}