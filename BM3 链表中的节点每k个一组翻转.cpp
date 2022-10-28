 struct ListNode {
 	int val;
 	struct ListNode *next;
  };

class Solution {
public:
    //递归
    ListNode* reverseKGroup(ListNode* head, int k) {
        //翻转前K个节点，然后递归后续剩下的链表
        if (head == nullptr)
        {
            return head;
        }
        
        
        //递归出口
        ListNode *tail = head;

//注意 ，使用递归的时候寻找第K个元素，for循环的次数是K 还是K-1。
//应该是K，因为要对前K个元素每个元素都进行==null的判断，一共k个元素，需要进行K次
        for (size_t i = 0; i < k; i++)
        {
            if (tail == nullptr)
            {
                return head;//不足K个，就结束。
            }
            tail = tail->next;
        }  

        // ListNode *next = tail->next;
        ListNode *cur = head;
        ListNode *pre = nullptr;
        //翻转前K个
        while (cur!=tail)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        head->next = reverseKGroup(tail,k);
        return pre;
    }
    

    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup1(ListNode* head, int k) {
        if (head == nullptr)
        {
            return head;
        }
        
        // write code here
        ListNode dNode = ListNode(-1);
        ListNode *dummy = &dNode;
        dummy->next = head;

        ListNode *leftNode = dummy;
        ListNode *pre = dummy;
        ListNode *cur = head;

        //首先搜索K个元素，进行翻转，如果不足K个 不做处理
        bool flag = true;
        while (flag)
        {
            for (size_t i = 1; i < k; i++)
            {
                if (cur == nullptr)
                {
                    flag = false;
                    break;
                }
                
                pre = cur;
                cur = cur->next;
            }
            if (flag)
            {
                //翻转leftNode.next  到  cur
                ListNode *rightNode = cur->next;
                ListNode *begin = leftNode->next;

                cur->next = nullptr;
                leftNode->next = nullptr;
                
                //恢复连接
                leftNode->next = ReverseList(begin);
                begin->next = rightNode;

                leftNode = begin;
                pre = leftNode;
                cur = rightNode;
            }
        }
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
};