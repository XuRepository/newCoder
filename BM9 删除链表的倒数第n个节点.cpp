 struct ListNode {
 	int val;
 	struct ListNode *next;
  };

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // write code here
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode dummy = ListNode(-1);
        dummy.next = head;
        ListNode *pre = &dummy;

        for (size_t i = 0; i < n; i++)
        {
            if (fast == nullptr)//达不到倒数n个
            {
                return nullptr;
            }
            
            fast = fast->next;
        }
        while (fast!=nullptr)
        {
            fast = fast->next;
            slow = slow->next;
            pre = pre->next;
        }

        //找到目标slow
        pre->next = slow->next;
        return dummy.next;
        
    }
};