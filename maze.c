#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <omp.h>
#include "stack.h"

#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"

const int MAGIC_NUM_THREADS = 4;
const int MAGIC_NUM_DIRECTIONS = 4;

void swap(int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void genPermutation(int n, int arr[n]) { 
    for (int i = 1; i < n; i++) { 
        int j = rand() % (i+1); 
        swap(&arr[i], &arr[j]); 
    }
} 

int main(int argc, char* argv[]) {
    bool printMaze = true;
    int seed;
    int dimensions = 11;
    int n = 1;
    do {
        if(argv[n] != NULL && argv[n+1] != NULL && strcmp(argv[n], "-s") == 0 && strtol(argv[n+1], NULL, 10) > 0) {
            seed = strtol(argv[n+1], NULL, 10);
            srand(seed); 
        }
        if(argv[n] != NULL && argv[n+1] != NULL && strcmp(argv[n], "-n") == 0 && strtol(argv[n+1], NULL, 10) > 4) {
            dimensions = strtol(argv[n+1], NULL, 10);
        }
        if(argv[n] != NULL && strcmp(argv[n], "-p") == 0) {
            printMaze = false;
        }
        n += 1;
    } while(argv[n] != NULL);

    char ** grid;
    grid = malloc(dimensions * sizeof(char *));
    for (int i = 0; i < dimensions; i++) {
        grid[i] = malloc(dimensions * sizeof(char));
    }

    for(int i = 0; i < dimensions; i++){
        for(int j = 0; j < dimensions; j++){
            grid[i][j] = '.';
        }
    }
    int threadCount = 1;
    int numClaimed[4] = {0};
    //start conditional section//
    #if defined(_OPENMP)
    threadCount = MAGIC_NUM_THREADS; 
    #pragma omp parallel num_threads(threadCount)
    {
    #endif
    //end conditional section

    int myRank = 0;
    
    Node * stack = NULL;
    Node * cur;

    //start conditional section//
    #if defined(_OPENMP)
        myRank = omp_get_thread_num();
    #endif
    //end conditional section

    switch(myRank) {
        case 0:
            push(1, 1, &stack);
            grid[1][1] = myRank + '0';
            break;
        case 1:
            push(1, dimensions - 2, &stack);
            grid[1][dimensions - 2] = myRank + '0';
            break;
        case 2:
            push(dimensions - 2, 1, &stack);
            grid[dimensions - 2][1] = myRank + '0';
            break;
        case 3:
            push(dimensions - 2, dimensions - 2, &stack);
            grid[dimensions - 2][dimensions - 2] = myRank + '0';
            break;
    }

    while(stack != NULL) {
        cur = pop(&stack);
        int perm[] = {0, 1, 2, 3};
        genPermutation(MAGIC_NUM_DIRECTIONS, perm);
        
        for(int i = 0; i < MAGIC_NUM_DIRECTIONS; i++) {
            bool add = false;
            int newX;
            int newY;

            switch(perm[i]) {
                case 0:
                    if(cur -> xCor - 2 > 0 && grid[(cur -> xCor) - 2][cur -> yCor] == '.'){
                        add = true;
                        newX = (cur -> xCor) - 2;
                        newY = (cur -> yCor); 
                    }
                    break;
                case 1:
                    if(cur -> yCor - 2 > 0 && grid[cur -> xCor][(cur -> yCor) - 2] == '.'){
                        add = true;
                        newX = (cur -> xCor);
                        newY = (cur -> yCor) - 2; 
                    }
                    break;
                case 2:
                    if(cur -> xCor + 2 < dimensions - 1 && grid[(cur -> xCor) + 2][cur -> yCor] == '.'){
                        add = true;
                        newX = (cur -> xCor) + 2;
                        newY = (cur -> yCor); 
                    }
                    break;
                case 3:
                    if(cur -> yCor + 2 < dimensions - 1 && grid[cur -> xCor][(cur -> yCor) + 2] == '.'){
                        add = true;
                        newX = (cur -> xCor);
                        newY = (cur -> yCor) + 2; 
                    }
                    break;
            }

            if(add) {

                //start conditional section//
                #if defined(_OPENMP)
                #pragma omp critical
                {
                #endif
                //end conditional section

                grid[newX][newY] = myRank + '0';
                grid[(newX + (cur -> xCor)) / 2][(newY + (cur -> yCor)) / 2] = myRank + '0';
                
                //start conditional section//
                #if defined(_OPENMP)
                }
                #endif
                //end conditional section

                numClaimed[myRank] += 1;
                push(newX, newY, &stack);
            }
        }
        free(cur);
    }
    
    //start conditional section//
    #if defined(_OPENMP)
    }
    #endif
    //end conditional section

    //print results
    if(printMaze) {
        for(int i = 0; i < dimensions; i++) {
            for(int j = 0; j < dimensions; j++){
                switch(grid[i][j] - '0'){
                    case 0:
                        printf("%s%c ", RED, grid[i][j]);
                        break;
                    case 1:
                        printf("%s%c ", BLU, grid[i][j]);
                        break;
                    case 2:
                        printf("%s%c ", GRN, grid[i][j]);
                        break;
                    case 3:
                        printf("%s%c ", YEL, grid[i][j]);
                        break;
                    default:
                        printf("%s%c ", NRM, grid[i][j]);
                }
            }
            printf("\n");
        }
    }
    
    for(int i = 0; i < threadCount; i++) {
        switch(i){
            case 0:
                printf("%sThread %d claimed %d neighbors.\n", RED, i, numClaimed[i]);
                break;
            case 1:
                printf("%sThread %d claimed %d neighbors.\n", BLU, i, numClaimed[i]);
                break;
            case 2:
                printf("%sThread %d claimed %d neighbors.\n", GRN, i, numClaimed[i]);
                break;
            case 3:
                printf("%sThread %d claimed %d neighbors.\n", YEL, i, numClaimed[i]);
                break;
        }
    }

    for (int i = 0; i < dimensions; i++) {
        free(grid[i]);
    }
    free(grid);
}

