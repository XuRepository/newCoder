struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        //数学法，沿着两条链表走两边
        ListNode *l1 = pHead1;
        ListNode *l2 = pHead2;

        while (l1!=l2)
        {
            if(l1 == nullptr){
                l1 = pHead2;
            }else{
                l1 = l1->next;
            }
            if (l2 == nullptr)
            {
                l2 = pHead1;
            }else{
                l2 = l2->next;
            }
        }
        return l1;
    }
};
