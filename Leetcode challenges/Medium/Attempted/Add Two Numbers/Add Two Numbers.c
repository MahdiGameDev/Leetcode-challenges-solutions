#include <stdio.h>
#include <stdlib.h>



struct ListNode {
    int val;
    struct ListNode *next;
};

int set_same_size(struct ListNode* l1, struct ListNode* l2) {
    int size1 = (sizeof(l1) / sizeof(int)) + 1; int size2 = (sizeof(l2) / sizeof(int)) + 1;
    if (size1 > size2) {
        for (int i = 0; i < size2; i++) {
            l2 = l2->next;
        }
        for (int i = size2; i < size1; i++) {
            l2->val = 0;
            l2->next;
        }
        return size1;
    } else {
        for (int i = 0; i < size1; i++) {
            l1 = l1->next;
        }
        for (int i = size1; i < size2; i++) {
            l1->val = 0;
            l1->next;
        }
        for (int i = 0; i < size2; i++) {
            printf("l1.val(%d) = %d\n", i, l1->val);
        }
        return size2;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    int size = set_same_size(l1, l2);
    printf("size : %d\n", size);
    
    struct ListNode* result = calloc(size + 1, sizeof(struct ListNode));
    int temp = 0;
    
    for (int i = 0; i < size; i++) {
        temp = l1->val + l2->val;
        l1 = l1->next;
        l2 = l2->next;
        result->val = temp % 10;
        result = result->val + result->next;
        temp /= 10;
    }
    if (temp > 0) {
        result->next->val = temp;
    }

    return result;
}