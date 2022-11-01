
 struct ListNode {
 	int val;
 	struct ListNode *next;
  };


class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        
        ListNode dummy = ListNode(-1);
        dummy.next = head;
        ListNode *cur = head;
        ListNode *pre = &dummy;
        bool repeat = false;
        while (cur!=nullptr)
        {
            while (cur->next!=nullptr && cur->next->val == cur->val)
            {
                repeat = true;
                cur = cur->next;
            }
            if (!repeat)
            {
                pre->next = cur;
                pre = pre->next;
            }else{
                pre->next = cur->next;
            }
            
            cur = cur->next;
            repeat = false;
        }
        return dummy.next;
        
    }
};