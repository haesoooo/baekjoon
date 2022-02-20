#include <iostream>
using namespace std;
#define MAX 101
int N;
char map[MAX][MAX];
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};
bool visited[MAX][MAX];

bool range(int y, int x){
    return y < N && y >= 0 && x < N && x >= 0;  
}

void dfs(int y, int x){
    visited[y][x] = true;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(range(ny, nx) && map[ny][nx] == map[y][x] && !visited[ny][nx]) dfs(ny, nx);
    }
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> map[i][j];
    }
    int normal_count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]) {
                dfs(i, j);
                normal_count++;

            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            visited[i][j] = false;
            if(map[i][j] == 'G') map[i][j] = 'R';
        }
    }
    int abnormal_count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]) {
                dfs(i, j);
                abnormal_count++;
              }
        }
    }
    cout << normal_count << ' ' << abnormal_count;
}