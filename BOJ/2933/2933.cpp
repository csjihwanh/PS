#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#define L 1
#define R 2

using namespace std;

typedef pair<int,int> pii;

int c, r, n;
const int max_size = 105;
char map[max_size][max_size];
bool chk[max_size][max_size];
int stick[max_size];
int xdir[4] = {1,-1,0,0};
int ydir[4] = {0,0,1,-1};

void input() {
    cin>>r>>c;
    for(int i = 1; i <= r; i++)
        cin>>&map[i][1];

    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>stick[i];
}

bool BFS(pii p) {
    memset(chk,false,sizeof(chk));
    queue<pii> q;
    bool ground = false;
    chk[p.first][p.second] = true;
    q.push(p);
    if(p.first==r) ground = true;
    
    while(!q.empty()) {
        pii cur = q.front();
        int x = cur.first, y = cur.second; 
        q.pop();
        for(int i = 0; i< 4; i++) {
            int nx = x + xdir[i], ny = y + ydir[i];
            if(map[nx][ny] == 'x' && chk[nx][ny] == false) {
                chk[nx][ny] = true;
                q.push({nx,ny});
                if(nx == r) ground = true;
            }
        }
    }
    return ground;
}

bool fall() {
    bool ground = false;

    for(int i = r; i > 0; i--) {
        for(int j = 1; j <= c; j++) {
            if(chk[i-1][j]) {
                chk[i-1][j] = false;
                chk[i][j] = true;
                map[i-1][j] = '.';
                map[i][j] = 'x';
                if((i+1 <= c && map[i+1][j] == 'x' && chk[i+1][j] == false) || i==r) {
                    //cout<<i+1<<" " << j<< " "<<map[i+1][j]<<endl;
                    ground =true;
                }
            }
        }
    }

    return ground;
}

void showMap() {
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) 
            cout<<map[i][j];
        cout<<'\n';
    }
}

void crush(int dir, int height) {
    pii dest = {-1,-1};
    
    for(int i = 1; i <= c; i++) {
        if(map[height][i] == 'x' && dir == L) {
            dest = {height,i};
            map[height][i] = '.';
            //showMap();
            break;
        }
        if(map[height][c-i+1] == 'x' && dir == R) {
            dest = {height, c-i+1};
            map[height][c-i+1] = '.';
            //showMap();
            break;
        }
    }
    
    if(dest.first == -1) return;

    //upper check
    int h = dest.first-1, w = dest.second;
    if(map[h][w] == 'x') {
        bool ground = BFS({h,w});
        while(!ground) {
            ground = fall();
        }
    }
    
    //side check
    h = dest.first, w = (dir==L)? dest.second+1 : dest.second-1;
    if(map[h][w] == 'x') {
        bool ground = BFS({h,w});
        while(!ground) {
            ground = fall();
            //cout<<ground;
        }
    }

    //down check
    h = dest.first+1, w = dest.second;
    if(map[h][w] == 'x') {
        bool ground = BFS({h,w});
        while(!ground) {
            ground = fall();
            //cout<<ground;
        }
    }

}

int main(void) {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    
    input();
    
    for(int i = 1; i<= n; i++)
        crush((i%2==1)?L:R, r - stick[i]+1);

    showMap();
}