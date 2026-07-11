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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        else{
            int n=0;
            ListNode* temp=head;
            ListNode* tail=NULL;
            while(temp){
                if(!temp->next) tail=temp;
                temp=temp->next;
                n++;
            }
            k%=n;
            temp=head;
            if(k==0) return head;
            else{
                for(int i=1;i<n-k;i++){
                    temp=temp->next;
                }
                tail->next=head;
                head=temp->next;
                temp->next=NULL;
                return head;
            }
        }
    }
};