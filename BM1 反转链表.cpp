 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
    };

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