
struct ListNode {
 	int val;
 	struct ListNode *next;
};


class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }
        
        // write code here
        //考虑把链表的后半部分倒序，然后对比
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next!=nullptr )
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *r = reverse(slow);
        ListNode *l = head;

        while (l!=slow)
        {
            if (l->val != r->val)
            {
                return false;
            }
            l = l->next;
            r = r->next;
        }
        return true;
    }
    ListNode *reverse(ListNode *head){
        if (head == nullptr)
        {
            return head;
        }

        ListNode *cur = head;
        ListNode* pre = nullptr;

        while (cur!=nullptr)
        {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};