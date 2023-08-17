#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    char *directory;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

ListNode *buildPathList() {
    char *path = getenv("PATH");
    
    if (path == NULL) {
        printf("PATH environment variable not found.\n");
        return NULL;
    }
    
    ListNode *head = NULL;
    ListNode *tail = NULL;
    char *token = strtok(path, ":");
    
    while (token != NULL) {
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        if (node == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
        
        node->directory = strdup(token);
        node->next = NULL;
        
        if (tail == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        
        token = strtok(NULL, ":");
    }
    
    return head;
}

void freePathList(ListNode *head) {
    while (head != NULL) {
        ListNode *temp = head;
        head = head->next;
        free(temp->directory);
        free(temp);
    }
}

int main() {
    ListNode *pathList = buildPathList();
    
    if (pathList != NULL) {
        ListNode *current = pathList;
        while (current != NULL) {
            printf("%s\n", current->directory);
            current = current->next;
        }
        
        freePathList(pathList);
    }
    
    return 0;
}

