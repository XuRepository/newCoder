 struct ListNode {
 	int val;
 	struct ListNode *next;
  };


        //链表排序的两种思路
        //1，分治，归并
        //2，辅助数组，快排
class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        if (head== nullptr || head->next == nullptr)
        {
            return head;
        }
        
        // write code here
        //使用分治，链表如何找中点？快慢指针
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *pre = nullptr;

        while (fast!=nullptr && fast->next!= nullptr)
        {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next == nullptr;//切断
        return Merge(sortInList(head),sortInList(slow));
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