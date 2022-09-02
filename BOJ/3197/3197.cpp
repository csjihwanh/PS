#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int max_n = 1505;
int w,h;

char map[max_n][max_n];
bool visited[max_n][max_n], swan_visited[max_n][max_n];
queue<pair<int,int>> Q, nextQ, swan_pos, swan, next_swan;
int ans = 0;

int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

bool adjacentX(pair<int,int> p) {
    int x = p.first, y = p.second;
    for(int i = 0; i<4; i++) {
        int nx = x+dx[i], ny= y+dy[i];
        if(nx>0 && nx <= h  && ny >0 && ny <= w && map[nx][ny] == 'X') {
            return true;
        }
    }
    return false;
}

bool swanTrav() {
    swap(swan,next_swan);
    
    while(!swan.empty()) {
        int x = swan.front().first, y = swan.front().second;
        if(adjacentX(swan.front())) next_swan.push(swan.front());
        swan.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x+dx[i], ny= y+dy[i];
                if(nx>0 && nx <= h  && ny >0 && ny <= w && map[nx][ny] == '.' && !swan_visited[nx][ny]) {
                    swan_visited[nx][ny] = true;
                    swan.push(make_pair(nx,ny));
                }
                if(map[nx][ny] == 'L' && !swan_visited[nx][ny]) return true;
        }
    }
    return false;
}

void traver(int x, int y) {
    Q.push(make_pair(x,y));
    visited[x][y] = true;
    while(!Q.empty()) {
        x = Q.front().first, y = Q.front().second;
        if(adjacentX(Q.front())) nextQ.push(Q.front());
        Q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x+dx[i], ny= y+dy[i];
            //cout<<nx<<","<<ny<<" "<<map[nx][ny]<<'\n';
            if(nx>0 && nx <= h && ny >0 && ny <= w && visited[nx][ny] == false && (map[nx][ny] == '.' || map[nx][ny]=='L')) {
                Q.push(make_pair(nx,ny));
                visited[nx][ny] = true;
            }
        }
    }
}

void melt(pair<int,int> p) {
    int x= p.first, y = p.second;
    for(int i = 0; i < 4; i++) {
        int nx = x+dx[i], ny= y+dy[i];
        if(nx>0 && nx <= h && ny >0 && ny <= w && visited[nx][ny] == false && map[nx][ny] == 'X') {
            map[nx][ny] = '.';
            visited[nx][ny] = true;
            nextQ.push(make_pair(nx,ny));
        }
    }
}

int main(void) {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    cin>>h>>w;
    for(int i = 1; i <= h; i++) cin>>&map[i][1];

    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            if((map[i][j] == '.' || map[i][j] == 'L') and visited[i][j] == false) {
                traver(i,j);
            }
            if(map[i][j] == 'L') swan_pos.push(make_pair(i,j));
        }
    }
    next_swan.push(swan_pos.front());
    swan_visited[swan_pos.front().first][swan_pos.front().second] = true;
    swanTrav();

    while(!nextQ.empty()) {
        ans ++;
        swap(Q, nextQ);
        while(!Q.empty()) {
            melt(Q.front());
            Q.pop();
        }

        /*cout<<'\n'<<"Result\n";
        for (int i = 1; i <= h;i++) { 
            for(int j = 1; j <= w; j++) 
                cout<<map[i][j];
            cout<<'\n';
        }
        
        
        for (int i = 1; i <= h;i++) { 
            for(int j = 1; j <= w; j++) 
                cout<<swan_visited[i][j];
            cout<<'\n';
        }*/
        
        if(swanTrav()) break;
    }

    cout<<ans;

    return 0;
}