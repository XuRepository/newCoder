#include<vector>
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        if (row == 0)
        {
            return false;
        }
        int col = array.at(0).size();
        if (col == 0)
        {
            return false;
        }
        //从右上角向左下角搜索
        int i = 0;
        int j = col-1;
        while (i < row && j >=0)
        {
            if (array[i][j] > target)
            {
                j--;
            }else if(array[i][j] < target){
                i++;
            }else{
                return true;
            }
        }
        return false;
    }
};



