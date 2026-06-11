int n, m;
cin >> n >> m;

vector<vector<int>> a(n+1, vector<int>(m+1));

for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        cin >> a[i][j];

vector<vector<int>> p(n+1, vector<int>(m+1, 0));

for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
        p[i][j] = a[i][j]
                  + p[i-1][j]
                  + p[i][j-1]
                  - p[i-1][j-1];
    }
}

auto query = [&](int x1, int y1, int x2, int y2) -> int {
    return p[x2][y2]
         - p[x1-1][y2]
         - p[x2][y1-1]
         + p[x1-1][y1-1];
};

int q;
cin >> q;
while(q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << query(x1, y1, x2, y2) << "\n";
}