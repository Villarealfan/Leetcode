#include "../include/tools.h"

class Solution{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2){
        int n1 = nums1.size(), n2 = nums2.size(); // 数组各自的长度 ；
        if (n1 > n2){
            return findMedianSortedArrays(nums2, nums1);
        }
        int n = n1 + n2; // 总长度；
        int m1 = 0, m2 = 0; // 最终前 k 个数中，n1 数组贡献 m1 个数，n2 数组贡献 m2 个数；
        int l = 0, r = n1; // 二分搜索的上下界，在较短的 n1 数组中搜索;
        while (l <= r){
            int m1 = l + (r - l)/2; // n1 数组贡献的数量，二分搜索;
            int m2 = n/2 - m1; // n2 数组贡献的数量，n/2 为前 k 个数;
            double L1 = (m1 == 0) ? INT_MIN:nums1[m1 - 1]; // L1: n1 数组 m1 位置左边的数，即第 m1 - 1 位置的数;
            double L2 = (m2 == 0) ? INT_MIN:nums2[m2 - 1]; // L2: n2 数组 m2 位置左边的数，即第 m2 - 1 位置的数;
            double R1 = (m1 == n1)? INT_MAX:nums1[m1]; // R1: n1 数组第 m1 位置的数;
            double R2 = (m2 == n2)? INT_MAX:nums2[m2]; // R2: n2 数组第 m2 位置的数;
            if (L1 > R2){ // 说明 n1 数组贡献的数量多了，需要左移
                r = m1 - 1;
            }
            else if (L2 > R1){ // 说明 n1 数组贡献的数量少了，n2 多了，需要右移
                l = m1 + 1;
            }
            else{ // 此时正好使得 n1 中的 m1 个数和 n2 中的 m2 个数构成全体的前 k = n/2 个数;
                if (n % 2 == 0){ // 总数量为偶数，需要取全局的第 k - 1 个数和第 k 个数，求平均
                    return (max(L1, L2) + min(R1, R2))/2.0; 
                }
                else{ // 总数量为奇数，需要返回第 k 个数
                    return min(R1,R2);
                }
            }
        }
        return -1;
    }
};

int main(){
    Tools tool;
    Solution so;

    string line;
    cout << "输入 nums1:" << endl;
    getline(cin, line);
    vector<int> nums1 = tool.stringToVector(line);
    cout << "输入 nums2:" << endl;
    getline(cin, line);
    vector<int> nums2 = tool.stringToVector(line);

    double output = so.findMedianSortedArrays(nums1, nums2);
    cout << "输出:\n" << output  << endl;
    return 0;
}
