#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <time.h>
#include <algorithm> 
#include <iostream>
#include "../include/lib.h"

void Print_Solution(tsolution Solution){
    for (int i = 0; i < Solution.item_id.size(); i++)
    {
        printf("%d, ", Solution.item_id[i]);
    }
    printf("\n");
}

void Update_Solution(tsolution Solution, tsolution Best_Solution) {
    if (Solution.value > Best_Solution.value)
    {
        Best_Solution.item_id = Solution.item_id;
        Best_Solution.value = Solution.value;
        Best_Solution.weight = Solution.weight;
    }
}

// void Local_Search(tsolution Solution, titem * itens, int Weight, int n) {

// }

int Partner_Check(int i, titem * itens, tsolution Solution){
    int aux, flag;
    int j = 0;
    int limit = itens[i].partners.size();
    printf("PARTNER CHECK\n");

    while (j < limit)
    {
        aux = itens[i].partners[j];
        flag = count(Solution.item_id.begin(), Solution.item_id.end(), aux); 
        if (flag > 0)
            return itens[i].value + itens[i].bonus;
        j++;
    }
    return itens[i].value;
}

void Initialize_Candidate_Set(titem * itens, std::vector<int> &Candidate_List, tsolution &Solution, int Weight, int n){
    int flag;
    Candidate_List.clear();
    printf("INITIALIZE CANDIDATE SET\n");

    for (int i = 0; i < n; i++)
    {
        flag = count(Solution.item_id.begin(), Solution.item_id.end(), i);
        if (flag == 0 && itens[i].weight <= Weight)
        {
            Candidate_List.push_back(i);
        }
    }  
}

void Values_Min_Max(titem * itens, std::vector<int> Candidate_List, tsolution &Solution, int &min, int &max){
    int aux;
    int v_min = itens[Candidate_List[0]].value;
    int v_max = itens[Candidate_List[0]].value;
    printf("MIN MAX\n");

    for (int i = 0; i < Candidate_List.size(); i++)
    {
        aux = Partner_Check(Candidate_List[i], itens, Solution);

        if (aux < v_min)
        {
            v_min = aux;
        }

        if (aux < v_max)
        {
            v_max = aux;
        }
    }

    min = v_min;
    max = v_max;
}

void Build_RCL(titem * itens, tsolution &Solution, std::vector<int> &Candidate_List, std::vector<int> &RCL, int alpha){
    int aux;
    RCL.clear();
    printf("BUILD RCL\n");

    for (int i = 0; i < Candidate_List.size(); i++)
    {
        aux = Partner_Check(Candidate_List[i], itens, Solution);
        
        if (aux >= alpha){
            RCL.push_back(Candidate_List[i]);
        }
    }
}

void Greedy_Randomized_Construction(titem * itens, tsolution &Solution, int n, int Weight){
    int min, max, alpha, x, aux;
    std::vector<int> Candidate_List {0};
    std::vector<int> RCL {0};
    printf("GREEDY RANDOMIZED CONSTRUCTION\n");

    // S <- NULL
    Solution.value = 0;
    Solution.weight = 0;
    Solution.item_id.clear();

    Initialize_Candidate_Set(itens, Candidate_List, Solution, Weight,n);

    while (Solution.weight <= Weight || Candidate_List.size() > 0)
    {
        // Finding Min and Max values from Candidate_List itens
        Values_Min_Max(itens, Candidate_List, Solution, min, max);
        // RCL
        alpha = 0.7*max + (1-0.7)*min;
        Build_RCL(itens, Solution, Candidate_List, RCL, alpha);
        // Select an element s from the RCL at random
        x = rand() % n;
        // Solution U s
        Solution.item_id.push_back(RCL[x]);
        Solution.value += Partner_Check(RCL[x], itens, Solution);
        Solution.weight += itens[RCL[x]].weight;
        // Update the candidate set
        Initialize_Candidate_Set(itens, Candidate_List, Solution, Weight-Solution.weight, n);
    }
}

void grasp(titem * itens, int Weight, int n, tsolution &Best_Solution){
    tsolution Solution;
    printf("GRASP\n");

    for (int i = 0; i < 10; i++)
    {
        printf("--------------- %d\n", i);
        Greedy_Randomized_Construction(itens, Solution, n, Weight);
        //Local_Search(Solution, itens, Weight, n);
        Update_Solution(Solution,Best_Solution);
        Print_Solution(Solution);
    }
}