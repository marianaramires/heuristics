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