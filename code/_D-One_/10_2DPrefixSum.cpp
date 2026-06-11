for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
        p[i][j] = a[i][j]
                  + p[i-1][j]
                  + p[i][j-1]
                  - p[i-1][j-1];
    }
}