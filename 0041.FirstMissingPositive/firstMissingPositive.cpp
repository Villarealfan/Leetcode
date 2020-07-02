#include "../include/tools.h"

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.empty()) return 1;
		int n = (int)nums.size();
		//  [3,4,-1,1] --> [1,-1,3,4]
        for (int i = 0; i < n; i++){
			while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
				int temp = nums[nums[i] - 1];
				nums[nums[i] - 1] = nums[i];
				nums[i] = temp;
			}
		}
		
		// [1,-1,3,4] 中找到 -1
		for (int i = 0; i < n; i++){
			if (nums[i] != i + 1){
				return i + 1;
			}
		}
		
		// [1,2,3]
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
