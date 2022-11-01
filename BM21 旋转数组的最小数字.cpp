#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
int minNumberInRotateArray(vector<int> rotateArray) {
                int left = 0;
        int right = rotateArray.size()-1;
        while (left < right)
        {
            int mid = left + (right - left)/2;
            if (rotateArray[mid] > rotateArray[right])
            {
                left = mid + 1;
            }else if(rotateArray[mid] == rotateArray[right]){
                right--;
            }else{
                right = mid;
            }
        }
        return rotateArray[left];
        
    }
};