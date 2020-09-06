// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//     int countA=0, countB=0;
//     ListNode* curr = headA;
//     while(curr) {
//         curr = curr->next;
//         countA++;
//     }
//     curr = headB;
//     while(curr) {
//         curr = curr->next;
//         countB++;
//     }
//     int d = abs(countA - countB);
//     if (countA < countB) {
//         swap(headA, headB);
//     }
    
//     for (int i=0; i<d; i++){
//         headA = headA->next;
//     }
    
//     while(headA && headB) {
//         if (headA == headB) {
//             return headA;
//         }
//         headA = headA->next;
//         headB = headB->next;
//     }
//     return NULL;
// }