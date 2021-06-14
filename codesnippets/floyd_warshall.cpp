
ll g[N][N], dist[N][N], new_dist[N][N];
void floyd_warshall(){
    /*

        dist[i][j][k] --> 
                (i) -------------{1,2,3,...k}-------------- (j)

        if(k == 0) then dist[i][j][k] = g[i][j]

        Otherwise, k >= 1, we have the following recurrence.

        Visualization:
        
        distance[i][j][k] --->

                (i)-------------{1,2,....,k}------------- (j)
                                   
                                   |
                                   |
                                   |
                                   v

                (i) -----{1,2,...,k-1}-------(k)-----{1,2...,k-1}-------(j) (if we intend to use k)
                or 
                (i) -------------{1,2,....k-1}-----------------(j) (if we intend to go without k)


        Hence, 
        distance[i][j][k] = min(distance[i][k][k-1] + distance[k][j][k - 1], distance[i][j][k-1])
    */

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = g[i][j];
        }
    }

    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                new_dist[i][j] = INF;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                new_dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = new_dist[i][j];
            }
        }
    }

}