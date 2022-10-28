
 struct ListNode {
	int val;
	struct ListNode *next;
 };


class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        if(head == nullptr){
            return head;
        }
        ListNode node = ListNode(-1);
        ListNode *dummy = &node;
        dummy->next = head;
        ListNode *cur = head;
        ListNode *pre = dummy;

        for(int i = 1; i < m;i++){
            pre = cur;
            cur = cur->next;
        }
        ListNode *left = pre;
        ListNode *start = cur;
        for(int i = m;i < n;i++){
            pre = cur;
            cur = cur->next;
        }
        ListNode *right = cur->next;
        ListNode *end = cur;

        left->next = nullptr;
        end->next = nullptr;

        //翻转指定区间 start-end
        ReverseList(start);
        left->next = end;
        start->next = right;
        return dummy->next;

    }

    ListNode* ReverseList(ListNode* pHead) {
		if(pHead == nullptr){
			return pHead;
		}
		ListNode *pre = nullptr;
		ListNode *cur = pHead;
		ListNode *next = pHead->next;
		while(cur!=nullptr){
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
    }

    ListNode* reverseBetween2(ListNode* head, int m, int n) {
        if(head == nullptr){
            return head;
        }
        ListNode node = ListNode(-1);
        ListNode *dummy = &node;
        dummy->next = head;
        ListNode *cur = head;
        ListNode *pre = dummy;

        for(int i = 1; i < m;i++){
            pre = cur;
            cur = cur->next;
        }

        for(int i = m;i < n;i++){
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = cur;
            pre->next  = tmp;
            cur = tmp;
        }

        return dummy->next;
    }
};