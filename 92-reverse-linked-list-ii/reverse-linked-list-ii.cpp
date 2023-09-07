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

        ListNode* reverseBetween(ListNode *head, int left, int right)
        {
            ListNode *lenfinder = head;
            int len = 0;
            if (head == NULL || head->next == NULL || left == right)
            {
                return head;
            }
            while (lenfinder != NULL)
            {
                len++;
                lenfinder = lenfinder->next;
            }

            ListNode *temp1 = head;
            ListNode *temp2 = head;
            ListNode *temp3 = head;
            if (left == 1)
            {
                temp1 = NULL;
            }
            for (int i = 0; i < left - 2; i++)
            {
                temp1 = temp1->next;
            }
            if (right == len)
            {
                temp3 = NULL;
            }
            else
            {
                for (int i = 0; i < right; i++)
                {
                    temp3 = temp3->next;
                }
            }
            if (temp1 != NULL)
            {
                temp2 = temp1->next;
            }
            else
            {
                temp2 = head;
            }
            ListNode *prev = NULL;
            ListNode *curr = temp2;
            ListNode *forward = NULL;
            int count = 1;
            while (count <= right - left + 1)
            {
                forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
                count++;
            }
            if (temp1 != NULL)
            {
                temp1->next = prev;
            }

            temp2->next = temp3;
            if (temp1 == NULL)
            {
                return prev;
            }
            return head;
        }
};