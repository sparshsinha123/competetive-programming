#define NCR 

const int TABLE_SIZE = 63;
long long ncr[TABLE_SIZE][TABLE_SIZE];

void compute_combinations_table(){
    ncr[0][0] = 1;
    ncr[1][0] = ncr[1][1] = 1;
    for(int i = 2; i < TABLE_SIZE; i++){
        for(int r = 0; r <= i; r++){
            if(r == 0 || r == i) ncr[i][r] = 1;
            else ncr[i][r] = (ncr[i - 1][r] + ncr[i - 1][r - 1]) ;
        }
    }
}