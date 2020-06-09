/*=============================================================================
# 作者: 桂继宏
# 最近修改时间: 2020-05-29 09:54
# 文件名: global.h
=============================================================================*/
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
