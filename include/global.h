#ifndef GLOBAL_H
#define GLOBAL_H

#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <stdlib.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //GLOBAL_H
