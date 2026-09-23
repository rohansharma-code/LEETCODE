class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // Min-heap: stores the smallest current node
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            compare
        > pq;

        // Put the first node of every list into the heap
        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }

        // Dummy node to build the answer
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            
            // Get the smallest node
            ListNode* smallest = pq.top();
            pq.pop();

            // Add it to the result
            tail->next = smallest;
            tail = tail->next;

            // Add the next node from the same list
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        return dummy->next;
    }

private:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
};