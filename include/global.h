#ifndef GLOBAL_H
#define GLOBAL_H

#include <vector>
#include <unordered_map>
#include <string>
#include <string.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <stdlib.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

#endif //GLOBAL_H
