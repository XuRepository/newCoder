
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

class Solution {
public:
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