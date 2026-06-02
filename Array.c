#include <stdio.h> 

void printMatrix(int *matrix, int c){ 

    for(int i = 0; i < c; i++){ 

        for(int j = 0; j < c; j++){ 

            printf("%d ", *(matrix + i*c + j)); 

        } 

        printf("\n"); 

    } 

} 

 

int searchMatrix(int *matrix, int n, int key){ 

    printMatrix(matrix,n); 

    int i = 0; 

    int j = n - 1; 

     

    while(i < n && j >= 0){ 

        int current = *(matrix + i*n + j); 

 

        if(current == key){ 

            printf("%d found @ (%d,%d)\n", key, i+1, j+1); 

            return 1; 

        } 

        else if(current > key){ 

            printf("%d compared with %d\nmoving left\n", key, current); 

            j--; 

        } 

        else{ 

            printf("%d compared with %d\nmoving below\n", key, current); 

            i++; 

        } 

    } 

    return 0; 

} 

 

int main() { 

    int r,c; 

    printf("Enter number of rows: "); 

    scanf("%d",&r); 

 

    printf("Enter number of columns: "); 

    scanf("%d",&c); 

     

    int matrix[r][c]; 

 

    printf("Enter the matrix elements:\n"); 

    for(int i = 0; i < r; i++){ 

        for(int j = 0; j < c; j++){ 

            scanf("%d",&matrix[i][j]); 

        } 

    } 

     

    int key; 

    printf("Enter key to search: "); 

    scanf("%d",&key); 

     

    if(searchMatrix((int *)matrix, c, key)){ 

        printf("key found\n"); 

    } 

    else{ 

        printf("key not found!!\n"); 

    } 

} 
