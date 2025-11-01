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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(head->next == NULL) return head;
        set<long long int> s;
        for(int i=0; i<nums.size(); i++) s.insert(nums[i]);
        while(s.find(head->val) != s.end()) 
        {
            ListNode* curr = head->next;
            head->next = NULL;
            head = curr;
        } 
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr != NULL)
        {
            ListNode* nextprev = curr;
            ListNode* nextcurr = curr->next;
            if(s.find(curr->val) != s.end())
            {
                prev->next = curr->next;
                curr->next = NULL;
            }
            prev = nextprev;
            curr = nextcurr;
        }
        return head;
    }
};