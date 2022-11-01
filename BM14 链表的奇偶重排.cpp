#include<deque>
using namespace std;
 struct ListNode {
 	int val;
 	struct ListNode *next;
 	ListNode(int x) : val(x), next(nullptr) {}
  };

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* oddEvenList(ListNode* head) {
        //可以考虑双指针
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *odd = head;
        ListNode *Even = head->next;

        ListNode *o = odd;
        ListNode *e = Even;

        while (o!=nullptr && e!=nullptr)
        {
            if (e->next == nullptr)//后续再无奇数
            {
                break;
            }
            o->next = e->next;
            o = o->next;
            
            e->next = o->next;
            e = e->next;
        }

        o->next = Even;
        return odd;
    }

    ListNode* oddEvenList(ListNode* head) {
        // write code here
        //使用一个queue进行额外存储。复杂度较高。可以考虑双指针
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        

        deque<ListNode *> que1;
        deque<ListNode *> que2;
        ListNode *cur = head;
        bool odd = true;
        while (cur!=nullptr)
        {
            cur->next = nullptr;//断开原有关系
            if (odd)
            {
                que1.push_back(cur);
            }else{
                que2.push_back(cur);
            }
            cur = cur->next;
            odd = !odd;
        }

        ListNode dummy = ListNode(-1);
        cur = &dummy;

        while (!que1.empty())
        {
            cur->next = que1.front();
            que1.pop_front();
            cur = cur->next;
        }
        while (!que2.empty())
        {
            cur->next = que2.front();
            que2.pop_front();
            cur = cur->next;
        }

        return dummy.next;
    }
};