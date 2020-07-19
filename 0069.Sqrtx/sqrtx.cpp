#include "../include/tools.h"

class Solution {
public:
    int mySqrt_binarySearch(int x) {
        if (x == 0 || x == 1) return x;
        int l = 1, r = x;
        while (l <= r){
            long mid = l + (r - l)/2;
            long squre = mid*mid; // 防止越界
            if (squre == x){
                return mid;
            }
            else if (squre < x){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return r; // 最终 l = r + 1
    }

    int mySqrt_newton(int x){
        if (x == 0 || x == 1) return x;
        long res = x;
        while (res*res > x){
            // 牛顿法迭代公式
            res = (res + x/res)/2;
        }
        return res;
    }
};

int main(){
    Solution so;
    int x;
    cout << "输入 x:" << endl;
    cin >> x;
    int output_binary = so.mySqrt_binarySearch(x);
    cout << "二分搜索输出:\n" << output_binary << endl;
    int output_newton = so.mySqrt_newton(x);
    cout << "牛顿法输出:\n" << output_newton << endl;
    return 0;
}
