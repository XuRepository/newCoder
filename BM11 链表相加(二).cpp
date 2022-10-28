
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
    };


class Solution {
public:
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        //考虑首先翻转俩链表，从末尾开始相加，最终再次翻转回来。
        //也可以考试使用两个stack，俩链表入栈之后，依次出栈。
        ListNode *l1 = reverse(head1);
        ListNode *l2 = reverse(head2);
        ListNode dummy = ListNode(-1);
        ListNode *cur = &dummy;
        int add = 0;

        while (l1!=nullptr || l2!=nullptr)
        {
            int val = add;
            if (l1 != nullptr)
            {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                val += l2->val;
                l2 = l2->next;
            }
            
            add = 0;
            if (val >= 10)
            {
                add = 1;
                val = val - 10;
            }

            cur->next = new ListNode(val);
            cur = cur->next;
        }

        if (add == 1)
        {
            cur->next = new ListNode(1);
            cur = cur->next;
        }

        ListNode *res = dummy.next;
        dummy.next = nullptr;

        return reverse(res);
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