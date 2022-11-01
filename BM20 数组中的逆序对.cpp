#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int count = 0;
    //使用归并排序的修改版，在merge的时候计算逆序对
    int InversePairs(vector<int> data) {
        if (data.size()<2)
        {
            return 0;
        }
        
        mergeSort(data,0,data.size()-1);
        return count;
    }

    void mergeSort(vector<int> &data,int l,int r){
        if (l < r)
        {
            int mid = l + (r - l)/2;
            mergeSort(data,l,mid);
            mergeSort(data,mid+1,r);
            merge(data,l,mid,r);
        }
    }

    //返回值是当前两段归并产生的逆序对
    void merge(vector<int> &data,int left,int mid,int right){
        vector<int> temp(right - left + 1);
        int l = left;
        int r = mid+1;
        int start = left;
        int cur = 0;
         while (l <= mid && r <=right)
         {
            if(data[l] <= data[r]){
                temp[cur] = data[l];
                cur++;
                l++;
            }else{
                //产生逆序对
                count += mid - l + 1;
                count%=1000000007;
                temp[cur] = data[r];
                r++;
                cur++;
            }
         }
         //剩余的也给加上
         while (l <= mid)
         {
            temp[cur] = data[l];
            cur++;
            l++;
         }
          while (r <= right)
         {
            temp[cur] = data[r];
            cur++;
            r++;
         }
         //把temp替换进data位置
         for(const int &i : temp){
            data[start++] = i;
         }
    }



    int InversePairs1(vector<int> data) {
        //考虑使用额外空间保存所有的值，然后遍历data，遍历一个删一个
        vector<int> temp =  vector<int>(data);
        sort(temp.begin(),temp.end());

        long count = 0;
        long l = 0L;
        for(const int &i : data){
            auto iter = find(temp.begin(),temp.end(),i);
            l = iter - temp.begin();
            count += l;
            temp.erase(iter);//前面的元素搜索过了，要移除。因为排序后的集合不知道原始的元素位置。
        }

        return count%1000000007;
    }
};