#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <vector>

typedef struct _item
{
    int value;
    int weight;
    int bonus;
    std::vector<int> partners {0};
} titem;

typedef struct _solution
{
    int value;
    int weight;
    std::vector<int> item_id {0};
} tsolution;

void Print_Solution(tsolution Solution);

void Update_Solution(tsolution Solution, tsolution Best_Solution);

void Local_Search(tsolution Solution, titem * itens, int Weight, int n);

int Partner_Check(int i, titem * itens, tsolution Solution);

void Initialize_Candidate_Set(titem * itens, std::vector<int> &Candidate_List, tsolution &Solution, int Weight, int n);

void Values_Min_Max(titem * itens, std::vector<int> Candidate_List, tsolution &Solution, int &min, int &max);

void Build_RCL(titem * itens, tsolution &Solution, std::vector<int> &Candidate_List, std::vector<int> &RCL, int alpha);

void Greedy_Randomized_Construction(titem * itens, tsolution &Solution, int n, int Weight);

void grasp(titem * itens, int Weight, int n, tsolution &Best_Solution);