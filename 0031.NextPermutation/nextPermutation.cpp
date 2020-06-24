#include "../include/tools.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return;
        int n = nums.size() - 1;

        // 从右到左找第一个下降的 l
        int l = -1; 
        for (int i = n - 1; i >= 0; i--){
            if (nums[i] < nums[i + 1]){
                l = i;
                break;
            }
        }

        if (l == -1){
            // 3,2,1 --> 1,2,3
            reverse(nums, 0, n);
            return;
        }

        // 从右到左找第一个大于 nums[l] 的 r
        int r;
        for (int i = n; i > l; i--){
            if (nums[i] > nums[l]){
                r = i;
                break;
            }
        }

        // 交换 l, r
        swap(nums, l, r);

        // 翻转 l + 1 到结尾的数组
        reverse(nums, l + 1, n);
    }

    void reverse(vector<int>& nums, int i, int j){
        while (i < j){
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    vector<int> nums = tool.stringToVector(line);
    so.nextPermutation(nums);
    string output = tool.vectorToString(nums);
    cout << "输出:\n" << output << endl;
    return 0;
}


