#include<vector>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 给定一个长度为n的数组nums，请你找到峰值并返回其索引。数组可能包含多个峰值，在这种情况下，返回任何一个所在位置即可。
        1.峰值元素是指其值严格大于左右相邻值的元素。严格大于即不能有等于
        2.假设 nums[-1] = nums[n] = -\infty−∞
        3.对于所有有效的 i 都有 nums[i] != nums[i + 1]
        4.你可以使用O(logN)的时间复杂度实现此问题吗？
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int findPeakElement(vector<int>& nums) {
        // write code here
        //因为边界处视为min，所以只要往高处走一定能遇到波峰。
        //二分查找，向mid位置更高的一侧搜索即可。
        if (nums.size() == 0)
        {
            return -1;
        }
        if (nums.size() == 1)
        {
            return 0;
        }
        int l = 0;
        int r = nums.size()-1;
        while (l <= r)
        {
            int mid = l + (r - l)/2;
            bool leftLess = (mid>0 && nums[mid-1]<nums[mid]) || mid == 0;//左侧更小
            bool rightLess = (mid < nums.size()-1 && nums[mid+1]<nums[mid]) || mid == nums.size()-1;//右侧更小
            if (leftLess && rightLess)
            {
                return mid;
            }else if(leftLess && !rightLess){
                //左小 右大，往大的方向走
                l = mid+1;
            }else if(!leftLess && rightLess){
                //左大 右小，往大的左侧走
                r = mid -1;
            }else{
                //左大  右大，挑一个大的走就行了
                if (nums[mid+1] > nums[mid-1])
                {
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};