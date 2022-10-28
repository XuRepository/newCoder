#include<vector>
#include<queue>
using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
//时间复杂度 O(nlogn)O(nlogn),考虑二路归并；对于归并，可以考虑分治
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeList(lists,0,lists.size()-1);
    }

    ListNode *mergeList(vector<ListNode *> &lists,int L,int R) {
        if (L ==R)
        {
            return lists.at(L);
        }
        if (L > R)
        {
            return nullptr;
        }
        int mid = L+(R-L)/2;
        return Merge(mergeList(lists,L,mid),mergeList(lists,mid+1,R));
    }

    //方法2，考虑使用小顶堆
    struct cmp
    {
        bool operator()(ListNode *A,ListNode *B){
            return A->val > B->val;
        }
    };
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *,vector<ListNode *>,cmp> pq;
        for (size_t i = 0; i < lists.size(); i++)
        {
            if(lists[i] != NULL)
                pq.push(lists[i]);//所有链表的首元素全部进来
        }

        //小顶堆依次弹出堆顶元素，并且把堆顶元素的next添加进来。
        ListNode dummy = ListNode(-1);
        ListNode *cur = &dummy;
        while(!pq.empty()){
            ListNode *temp = pq.top();
            pq.pop();
            cur->next = temp;
            cur = cur->next;
            if (temp->next!=nullptr)
            {
                pq.push(temp->next);
            }
        }
        return dummy.next;
        
    }



//每次归并两个
    ListNode *mergeKLists1(vector<ListNode *> &lists) {
        //递归出口
        int len = lists.size();
        if (len == 0)
        {
            return nullptr;
        }
        if (len == 1)
        {
            return lists.at(0);
        }
        
        
        vector<ListNode *> vec;
        for (size_t i = 0; i < len/2; i++)
        {
            vec.push_back(Merge(lists.at(i),lists.at(i+1)));
        }
        if (len%2==1)//有多余的一条
        {
            vec.push_back(lists.at(len-1));
        }

        return mergeKLists(vec);
    }
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode dummy = ListNode(-1);
        ListNode *cur = &dummy;
        ListNode *cur1 = pHead1;
        ListNode *cur2 = pHead2;

        while (cur1!=nullptr && cur2!=nullptr)
        {
            if (cur1->val < cur2->val)
            {
                cur->next = cur1;
                cur1 = cur1->next;
            }else{
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }

        if (cur1 != nullptr)
        {
            cur->next = cur1;
        }
        if (cur2!=nullptr)
        {
            cur->next = cur2;
        }

        return dummy.next;
    }
};