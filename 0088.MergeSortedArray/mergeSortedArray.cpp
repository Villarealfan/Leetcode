#include "../include/tools.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0){
            if (nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else{
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }

        while (j >=0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }

        return;
    }
};

int main(){
    Solution so;
    Tools tool;
    string s1, s2;
    int m, n;
    cout << "输入 s1:" << endl;
    getline(cin, s1);
    vector<int> nums1 = tool.stringToVector(s1);
    cout << "输入 s2:" << endl;
    getline(cin, s2);
    vector<int> nums2 = tool.stringToVector(s2); 
    cout << "输入 m:" << endl;
    cin >> m;
    cout << "输入 n:" << endl;
    cin >> n;
    so.merge(nums1, m, nums2, n);
    string output = tool.vectorToString(nums1);
    cout << "输出:\n" << output << endl;
    return 0;
}

