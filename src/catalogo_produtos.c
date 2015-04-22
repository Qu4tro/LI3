#include "catalogo_produtos.h"

int height(prod_node N) {
    return N == NULL ? 0 : N -> height;
}


int getBalance(prod_node N) {
    if (N == NULL) {
        return 0;
    }

    return height(N -> left) - height(N -> right);
}


prod_node newNode(char* key) {

    prod_node node = malloc(sizeof(struct pnode));
    node -> codigo_produto = dupstr(key);
    node -> left = NULL;
    node -> right = NULL;
    node -> compras = NULL;
    node -> height = 1;
    return node;

}

prod_node rightRotate(prod_node y) {

    prod_node x = y -> left;
    prod_node T2 = x -> right;

    x -> right = y;
    y -> left = T2;

    y -> height = max(height(y -> left), height(y -> right)) + 1;
    x -> height = max(height(x -> left), height(x -> right)) + 1;

    return x;
}

prod_node leftRotate(prod_node x) {
    prod_node y = x -> right;
    prod_node T2 = y -> left;

    y -> left = x;
    x -> right = T2;

    x -> height = max(height(x -> left), height(x -> right)) + 1;
    y -> height = max(height(y -> left), height(y -> right)) + 1;

    return y;
}

prod_node insert_produto(prod_node node, char* key) {

    int balance;

    if (node == NULL) {
        return (newNode(key));
    }

    if (strcmp(key, node -> codigo_produto) == 0){
        return node;
    }

    if (strcmp(key, node -> codigo_produto) < 0){
        node -> left  = insert_produto(node -> left, key);
    } else if (strcmp(key, node -> codigo_produto) > 0){
        node -> right = insert_produto(node -> right, key);
    }

    node -> height = max(height(node -> left), height(node -> right)) + 1;

    balance = getBalance(node);

    if (balance > 1 && strcmp(key, node -> left -> codigo_produto) < 0) {
        return rightRotate(node);
    }

    if (balance < -1 && strcmp(key, node -> right -> codigo_produto) > 0) {
        return leftRotate(node);
    }

    if (balance > 1 && strcmp(key, node -> left -> codigo_produto) > 0) {
        node -> left = leftRotate(node -> left);
        return rightRotate(node);
    }

    if (balance < -1 && strcmp(key, node -> right -> codigo_produto) < 0) {
        node -> right = rightRotate(node -> right);
        return leftRotate(node);
    }

    return node;
}

prod_node procura_produto(prod_node root, char* element) {

    if (root == NULL) {
        return NULL;
    }

    if (strcmp(element, root -> codigo_produto) == 0){
        return root;
    }

    if (strcmp(element, root -> codigo_produto) < 0){
        return procura_produto(root -> left, element);
    } else if (strcmp(element, root -> codigo_produto) > 0){
        return procura_produto(root -> right, element);
    }

    return 0;
}



int existe_produto(prod_node root, char* element) {

    if (root == NULL) {
        return 0;
    }

    if (strcmp(element, root -> codigo_produto) == 0){
        return 1;;
    }

    if (strcmp(element, root -> codigo_produto) < 0){
        return existe_produto(root -> left, element);
    } else if (strcmp(element, root -> codigo_produto) > 0){
        return existe_produto(root -> right, element);
    }

    return 0;
}

int get_produtos_por_letra(prod_node root, char letra){

        int produtos_totais = 0;

        if (root == NULL){
            return 0;
        }
     
        if (root -> codigo_produto[0] >= letra){
            produtos_totais += get_produtos_por_letra(root -> left, letra);
        }
     
        if (root -> codigo_produto[0] == letra){
            printf("%s\n", root -> codigo_produto);
            produtos_totais++;
        }
     
        if (root -> codigo_produto[0] <= letra){
            produtos_totais += get_produtos_por_letra(root->right, letra);
        }

        return produtos_totais;

}


/* void inOrder(prod_node root) { */
    /* if (root != NULL) { */
    /*     inOrder(root -> left); */
    /*     printf("%s ", root -> codigo_produto); */
    /*     inOrder(root -> right); */
    /* } */
/* } */

/* int main() { */

/*     struct node* root = NULL; */

/*     root = insert(root, "DD1234"); */
/*     root = insert(root, "DD1234"); */
/*     root = insert(root, "EE1234"); */
/*     root = insert(root, "FF1234"); */
/*     root = insert(root, "AA1234"); */
/*     root = insert(root, "BB1234"); */
/*     root = insert(root, "CC1234"); */

/*     printf("In order traversal of the constructed AVL tree is \n"); */
/*     inOrder(root); */

/*     return 0; */
/* } */
