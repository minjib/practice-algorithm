/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long n1 = 0, n2 = 0;
        
        ListNode *ans = NULL;
        
        int preVal = 0;
        ListNode *prevNode = NULL;
        
        while(l1 != NULL || l2!=NULL) {
            ListNode *node = new ListNode();
            int sum = preVal;
            if(l1 != NULL)
                sum += l1->val;
            
            if(l2 != NULL)
                sum += l2->val;
            
            preVal = sum / 10;
            
            sum %= 10;
            
            node->val = sum;
            if(prevNode == NULL)
                ans = node;
            else
                prevNode->next = node;
            
            prevNode = node;
            
            if(l1!=NULL)
                l1 = l1->next;
            
            if(l2!=NULL)
                l2 = l2->next;
        }
        
        if(preVal != 0) {
            ListNode *node = new ListNode(preVal);
            prevNode->next = node;
        }
        
        return ans;
    }
};
