#include "stdio.h"
#include "stdlib.h"

typedef struct node {
        int value;
        struct node* prev;
        struct node* left;
        struct node* right;
}node;

typedef struct tree {
        struct node* root;
        int count;
}tree;

void init(tree *t) {
        t->count = 0;
        t->root = NULL;
}

int find(tree *t, int value, node *n) {
        node *nodeptr = t->root;
        if (!nodeptr) {
                return 1;
        }
        else {
                while (nodeptr != NULL) {
                        if (value > nodeptr->value) {
                                nodeptr = nodeptr->right;
                                continue;
                        }
                        if (value < nodeptr->value) {
                                nodeptr = nodeptr->left;
                                continue;
                        }
                        if (value == nodeptr->value) {
                                if (n == NULL) {
                                        return 0;
                                }
                                else {
                                        printf("there");
                                        n = nodeptr;
                                        printf("in function find %p\n", n);
                                        return 0;
                                }
                        }
                }
        }
        return 1;
}

int insert(tree *t, int value) {
        if (!t->root) {
                node *temp = malloc(sizeof(node));
                if (!temp) {
                    return 2;
                }
                temp->value = value;
                temp->right = NULL;
                temp->left = NULL;
                temp->prev = NULL;
                t->root = temp;
                (t->count)++;
                return 0;
        }

        if (!find(t, value, NULL)) {
                return 1;
        }
        else {
                node *prevptr;
                node *ptr = t->root;
                while (ptr) {
                        prevptr = ptr;

                        if (value < ptr->value) {
                                if (!ptr->left) {
                                        node *temp = malloc(sizeof(node));
                                        if (!temp) {
                                                return 2;
                                        }
                                        temp->value = value;
                                        temp->left = NULL;
                                        temp->right = NULL;
                                        temp->prev = prevptr;
                                        prevptr->left = temp;

                                        t->count++;
                                        return 0;
                                }
                                else {
                                        ptr = ptr->left;
                                        continue;
                                }
                        }
                        else {
                                if (!ptr->right) {
                                        node *temp = malloc(sizeof(node));
                                        temp->value = value;
                                        temp->left = NULL;
                                        temp->right = NULL;
                                        temp->prev = prevptr;
                                        prevptr->right = temp;
                                        t->count++;
                                        return 0;
                                }
                                else {
                                        ptr = ptr->right;
                                        continue;
                                }
                        }
                }

        }
        return 1;
}

void print(node* root,tree *t) {
    int flag;
    if (root) {
        if(root->left){
            print(root->left,t);

        }
        if(root->right){
            print(root->right,t);
        }
        flag++;
        printf("%d", root->value);
        if(root->prev!=NULL){
            printf(" ");
        }
        else{
            printf("\n");
        }
    }
}


int main() {
        tree *t = malloc(sizeof(tree));

        init(t);

        for (int i = 0; i < 7; ++i) {
                int a;
                scanf("%d", &a);
                insert(t, a);
        }
        print(t->root, t);
}
