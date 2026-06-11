vector<int> dist(n + 1, -1); // distance from source
int src = 1; // starting node
dist[src] = 0; // dist[i] gives distance from src to i

queue<int> q;
q.push(src);

while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int v : adj[u]) {
        if(dist[v] == -1) { // not visited
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}

//     bfs on Grid
// -----------------------
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0}; // 4 directions

vector<vector<int>> dist(n, vector<int>(m, -1));
queue<pair<int,int>> q;
q.push({0,0});
dist[0][0] = 0;

while(!q.empty()){
    auto [x,y] = q.front(); q.pop();
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny=y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && dist[nx][ny]==-1){ // not visited : dist[nx][ny]==-1
            dist[nx][ny] = dist[x][y]+1;
            q.push({nx, ny});
        }
    }
}

