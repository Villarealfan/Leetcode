#include "../include/tools.h"

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.empty()) return 1;
		int n = (int)nums.size();
		// 桶排序
        for (int i = 0; i < n; i++){
			while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
				int temp = nums[nums[i] - 1];
				nums[nums[i] - 1] = nums[i];
				nums[i] = temp;
			}
		}

		for (int i = 0; i < n; i++){
			if (nums[i] != i + 1){
				return i + 1;
			}
		}
		return n + 1;
    }
};


int main(){
    Solution so;
    Tools tool;

    string line;
    cout << "输入:" << endl;
    getline(cin, line);
    vector<int> nums = tool.stringToVector(line);

    int output = so.firstMissingPositive(nums);
    cout << "输出:\n" << output << endl;
    return 0;
}
