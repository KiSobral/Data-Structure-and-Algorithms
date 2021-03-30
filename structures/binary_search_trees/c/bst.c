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

link search(link root, item x){
    if (root == NULL)   return NULL;
    if (root->val == x) return root;
    if (x < root->val)  return search(root->left, x);
    if (x > root->val)  return search(root->right, x);
}

link aux_search(link root, item x, link *father){
    link current = root;
    *father = NULL;

    while (current){
        if (current->val == x) return current;
        *father = current;

        if (x < current->val) current = current->left;
        else                  current = current->right;
    }

    return NULL;
}

link remove_node(link root, item x){
    link father, node, sub_father, substitute;
    node = aux_search(root, x, &father);
    if (node == NULL) return root;
    
    if (!node->left || !node->right){
        if (!node->left) substitute = node->right;
        else             substitute = node->left;
    } else {
        sub_father = node;
        substitute = node->left;
        while (substitute->right){
            sub_father = substitute;
            substitute = substitute->right;
        }

        if (sub_father != node){
            sub_father->right = substitute->left;
            substitute->left  = node->left;
        }

        substitute->right = node->right;

        if (!father) {
            free(node);
            return substitute;
        }

        if (x < father->val) father->left = substitute;
        else                 father->right = substitute;

        free(node);
        return(root);
    }
}

void pre_order(link root){
    if (root==NULL) return;
    printf("%d ", root->val);
    pre_order(root->left);
    pre_order(root->right);
}
void in_order(link root){
    if (root==NULL) return;
    in_order(root->left);
    printf("%d ", root->val);
    in_order(root->right);
}
void post_order(link root){
    if (root==NULL) return;
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->val);
}

int main(){
    link root = initialize();
    root = insert(root, 18);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 14);
    root = insert(root, 10);
    root = insert(root, 16);
    root = insert(root, 9);
    root = insert(root, 12);
    root = insert(root, 11);

    in_order(root);
    printf("\n");

    root = remove_node(root, 14);

    in_order(root);
    printf("\n");

    return 0;
}