# [题目](https://leetcode.com/problems/median-of-two-sorted-arrays/)

* Median of Two Sorted Arrays

> There are two sorted arrays nums1 and nums2 of size m and n respectively.

> Find the median of the two sorted arrays. The overall run time complexity should be **O(log (m+n))**.

> You may assume nums1 and nums2 cannot be both empty.

* Example 1:

> nums1 = [1, 3]

> nums2 = [2]

> The median is **2.0**

* Example 2:

> nums1 = [1, 2]

> nums2 = [3, 4]

> The median is (2 + 3)/2 = 2.5


# 代码
```cpp
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
```

# 复杂度
* 时间复杂度: O(log(max(m, n)))
* 空间复杂度: O(m + n)

# 思路

 * **核心思想: 二分搜索**
 
考虑找合并数组nums的中位数（第 k 个数）, 这 k 个数需要 nums1 提供 m1 个数，nums2 提供 m2 = k-m1 个数；
   
那么问题就转化为如果找到合适的 m1，使得 nums1 中前 m1 个数和 nums2 中前 m2 个数刚好构成 nums 的前 k 个数。

| nums1 |   前 m1 个 |  后 n1 - m1 个  | 
| ---- |  :---- | :---- | 
| **nums2** |  **前 m2 个** |  **后 n2 - m2 个**  | 
| ---- | ---- | ---- | 
| **nums** | **前 k = m1 (nums1 贡献) + m2 (nums2 贡献) 个** |  **后 n - k = n1 - m1 + n2 - m2 个**  | 

 
这个寻找的过程就可以使用二分搜索,为了搜索更快，选择在较短的数组中搜索，不妨假设 nums1 更短。
 
则搜索范围: 下界 l = 0, 上界 r = n1, 每次搜索的位置为 l 和 r 的中点，每次移动的是上下界。
 
 区别于传统的二分搜索（上下界重合时，搜索结束）， 此处上下界重合时也不一定能满足中位数要求。那么怎么满足中位数的要求呢？
 
进一步观察： 

nums1 被分为两段，分隔两边为左段的最大数 L1 和右段的最小数 R1，nums2 也被分为两段，分隔两边为左段的最大数 L2 和右段的最小数 R2。

| nums1  | ...      |   L1   |  R1    | ...      | 
| ----   | ---- | ---- | ---- | ---- |
| **nums2** | ....     |   **L2**   |  **R2**   | ...      | 


L1 <= R1 和 L2 <= R2 是必然成立的，如果选取合适的cut1能满足中位数要求，则 L1 和 L2 都该在 R1 和 R2 的左边，因此 max(L1,L2) <= min(R1,R2)。结合L1 <= R1 和 L2 <= R2，则此时 L1<= R2 且 L2 <= R1。

    如果 L1 > R2呢？ 说明 nums1 中选的 m1 元素过多， 将上界下移： r = m1 - 1； 

    相反 L2 > R1呢？ 说明 nums2 中选的 m2 元素过多， 也就是 m1 太少，将下界上移： l = m1 + 1；
   
不存在两种情况同时发生，若 L1 > R2 且 L2 > R1 , 则 L1 > R2 >= L2> R1 ==> L1 > R1,不符合升序要求。

   最后处理一下奇偶问题， 
   如果是总共奇数个元素，则取选取分隔符右端的最小值：min(R1,R2)
   如果是总共偶数个元素，则取选取分隔符左端最大值和右端最小值的均值： (max(L1,L2) + min(R1,R2))/2;
		
        例：
        nums : 12345|678910

                       l = 0,    r = 5
			 L1  R1  
			 ↓   ↓
		nums1: 1 3 | 4 5 8  m1 = （0+5）/2 = 2 (下取整)  
		nums2: 2 6 7| 9 10  m2 = (5+5)/2 - m1 = 3
		           ↑  ↑
		          L2  R2
		
		此时 L2 = 6 > R1 = 4， 上移下界 l = m1 + 1 = 3

		           l = 3,r = 5
		             L1   R1 
		             ↓   ↓
		nums1: 1 3 4 5 | 8   m1 = （3+5）/2 = 4 
		nums2: 2 | 6 7 9 10  m2 = (5+5)/2 - m1 = 1
		       ↑   ↑
		       L2  R2

		此时 L1 = 5 < R2 = 6， 且 L2 = 2 <  R1 = 8 , 满足中位数要求，
		由于总共偶数个，因此输出 
		(max(L1,L2) + min(R1,R2))/2 = (max(5,2) + min(8,6))/2 = (5+6)/2 = 5.5 
 
