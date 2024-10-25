// GREEDY RANDOMIZED ADAPTIVE SEARCH PROCEDURES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <time.h>
#include <algorithm> 
#include <iostream>
#include "include/lib.h"

int main(){
    int Capacity, n;

    Get_n(n);

    titem itens;
    itens.quadratic_coeficients = (int**)malloc (n * sizeof (int*));
    for (int i=0; i < n-1; i++){
        itens.quadratic_coeficients[i] = (int*)malloc ((n-i-1) * sizeof (int));
    }

    Read_Instance(Capacity, n, itens);

    printf("N %d\n", n);
    printf("LINEAR COEFICIENTS\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", itens.linear_coeficients[i]);
    }
    printf("\n");

    printf("QUADRATIC COEFICIENTS\n");
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            printf("%d ", itens.quadratic_coeficients[i][j-i-1]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("CAPACITY %d\n", Capacity);

    printf("CAPACITY CONSTRAINTS\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", itens.capacity_constraints[i]);
    }
    printf("\n");

    // tsolution Best_Solution;
    // Best_Solution.weight = 0;
    // Best_Solution.value = 0;

    // printf("ANTES\n");
    // grasp(itens, Capacity, n, Best_Solution);
    // printf("OI\n");
    // printf("%d\n", Best_Solution.value);
    // printf("%d\n", Best_Solution.weight);
    // for (int i = 0; i < Best_Solution.item_id.size(); i++)
    // {
    //     printf("%d\n", Best_Solution.item_id[i]);
    // }
    
    // libera a memória da matriz
    for (int i=0; i < n; i++){
        free (itens.quadratic_coeficients[i]);
    }
    free (itens.quadratic_coeficients);
}