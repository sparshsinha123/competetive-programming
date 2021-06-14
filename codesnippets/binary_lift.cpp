for(int i = 1; i <= n; i++){
    for(int j = 1; j < 23; j++){
        if(ancestor[i][j - 1] == -1) ancestor[i][j] = -1;
        else ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
    }
}
