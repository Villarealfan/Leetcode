# [题目](https://leetcode.com/problems/first-missing-positive)

* FirstMissingPositive

> 	Given an unsorted integer array, find the smallest missing positive integer.

*	Example 1:

>	Input: [1,2,0]

> Output: 3
	
* Example 2:

> Input: [3,4,-1,1]
	
> Output: 2

* Example 3:

>	Input: [7,8,9,11,12]

> Output: 1
	
* Note:

> Your algorithm should run in O(n) time and uses constant extra space.


# 代码

```cpp
class Solution{
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
```

# 复杂度

* 时间复杂度: $O(n)$
* 空间复杂度: $O(n)$

# 思路

* 桶排序

* 利用数组的下标i表示1-n这n个数，如果数组当中出现了1-n之间的元素那么一次遍历将可以将这些元素放置在对应的位置。没有出现的元素对应位置的值一定就不满足nums[i]==i+1，那么第一个出现的就是最小的！
