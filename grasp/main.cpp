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
    char c[500];
    int Weight, n, j;
    int temp[4];
    char *token;
    FILE *arq;
    arq = fopen("input.txt", "r");

    // ------- ENTRADA DE DADOS ---------------

    fgets(c, 500, arq);
    Weight = atoi(c);

    fgets(c, 500, arq);
    n = atoi(c);

    titem itens[n];

    for(int i=0; i<n; i++){
        j = 0;
        fgets(c, 500, arq);
        token = strtok(c, " ");

        while (token != NULL) { 
            temp[j] = atoi(token);
            token = strtok(NULL, " "); 
            j++;
        }

        itens[i].weight = temp[0];
        itens[i].value = temp[1];
        itens[i].partners.clear();
        itens[i].partners.push_back(temp[2]);
        itens[i].bonus = temp[3];
    }

    // -----------------------

    tsolution Best_Solution;
    Best_Solution.weight = 0;
    Best_Solution.value = 0;

    printf("ANTES\n");
    grasp(itens, Weight, n, Best_Solution);
    printf("OI\n");
    printf("%d\n", Best_Solution.value);
    printf("%d\n", Best_Solution.weight);
    for (int i = 0; i < Best_Solution.item_id.size(); i++)
    {
        printf("%d\n", Best_Solution.item_id[i]);
    }
    
}