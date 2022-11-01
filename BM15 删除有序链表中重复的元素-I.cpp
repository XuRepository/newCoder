
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
        
        ListNode *pre = head;
        ListNode *cur = head->next;

        while (cur != nullptr)
        {
            if (pre->val == cur->val)
            {
                pre->next = cur->next;
                cur = cur->next;
            }else{
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};