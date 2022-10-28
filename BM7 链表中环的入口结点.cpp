
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
          //双指针快慢追逐
     ListNode *fast = pHead;
     ListNode *slow = pHead;

    while (fast!=nullptr && fast->next!=nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            ListNode *fast = pHead;
            while (fast!=slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    }
    return nullptr;
    }
};