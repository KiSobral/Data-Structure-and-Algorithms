#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int item;

typedef struct node {
    item val;
    struct node* left;
    struct node* right;
} node;

typedef struct node* link;

link initialize(){
    return NULL;
}

link create_node(item x){
    link new_node    = (link)malloc(sizeof(node));
    new_node->val   = x;
    new_node->left  = NULL;
    new_node->right = NULL;
    return new_node;
}

link insert(link root, item x) {
    if (root==NULL) {
        link new_node = create_node(x);
        return new_node;
    }

    if (x < root->val) root->left = insert(root->left, x);
    if (x > root->val) root->right = insert(root->right, x);
    return root;
}

void pre_order(link root){
    if (root==NULL) return;
    printf("%d ", root->val);
    pre_order(root->left);
    pre_order(root->right);
}
void in_order(link root){
    if (root==NULL) return;
    pre_order(root->left);
    printf("%d ", root->val);
    pre_order(root->right);
}
void post_order(link root){
    if (root==NULL) return;
    pre_order(root->left);
    pre_order(root->right);
    printf("%d ", root->val);
}

int main(){
    link root = initialize();
    root = insert(root, 23);
    root = insert(root, 24);
    root = insert(root, 22);

    post_order(root);
    printf("\n");
}