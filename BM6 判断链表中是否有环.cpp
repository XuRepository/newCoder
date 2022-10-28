
 struct ListNode {
 	int val;
 	struct ListNode *next;
 };


/**
 * 
 * @param head ListNode类 
 * @return bool布尔型
 */
bool hasCycle(ListNode* head ) {
    // write code here
  //双指针快慢追逐
     ListNode *fast = head;
     ListNode *slow = head;

    while (fast!=nullptr && fast->next!=nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
        
    }
    return false;
}