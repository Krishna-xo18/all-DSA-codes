/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        vector<ListNode*> splitListToParts(ListNode *head, int k)
        {
            int len = 0;
            ListNode *temp = head;
            while (temp != NULL)
            {
                temp = temp->next;
                len++;
            }

            vector<ListNode*> ans;
            ListNode *temp1 = head;
            if (k > len)
            {
                for (int i = 0; i < len; i++)
                {
                    ListNode *list3 = new ListNode(temp1->val);
                    temp1 = temp1->next;
                    ans.push_back(list3);
                }
                int y = k - ans.size();
                for (int i = 0; i < y; i++)
                {
                    ans.push_back(NULL);
                }
                return ans;
            }
            int remainder = len % k;
            int size = len / k;
            for (int i = 0; i < remainder; i++)
            {
                ListNode *temp2 = new ListNode(temp1->val);
                ListNode *list1 = temp2;
                for (int j = 0; j < size; j++)
                {
                    temp1 = temp1->next;
                    ListNode *new1 = new ListNode(temp1->val);
                    temp2->next = new1;
                    temp2 = temp2->next;
                }
                ans.push_back(list1);
                temp1 = temp1->next;
            }
            int x = k - ans.size();

            for (int i = 0; i < x; i++)
            {
                ListNode *temp3 = new ListNode(temp1->val);
                ListNode *list2 = temp3;
                for (int j = 0; j < size - 1; j++)
                {
                    temp1 = temp1->next;
                    ListNode *new2 = new ListNode(temp1->val);\
                    temp3->next = new2;
                    temp3 = temp3->next;
                }
                temp1 = temp1->next;
                ans.push_back(list2);
            }
            return ans;
        }
};