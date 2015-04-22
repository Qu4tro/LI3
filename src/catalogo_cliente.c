#include "catalogo_cliente.h"

int heightC(client_node N) {
    return N == NULL ? 0 : N -> height;
}


int balanceC(client_node N) {
    if (N == NULL) {
        return 0;
    }

    return heightC(N -> left) - heightC(N -> right);
}


client_node newCNode(char* key) {

    client_node node = malloc(sizeof(struct cnode));
    node -> codigo_cliente = dupstr(key);
    node -> left = NULL;
    node -> right = NULL;
    node -> compras = NULL;
    node -> height = 1;
    return node;

}

client_node rightRotateC(client_node y) {

    client_node x = y -> left;
    client_node T2 = x -> right;

    x -> right = y;
    y -> left = T2;

    y -> height = max(heightC(y -> left), heightC(y -> right)) + 1;
    x -> height = max(heightC(x -> left), heightC(x -> right)) + 1;

    return x;
}

client_node leftRotateC(client_node x) {
    client_node y = x -> right;
    client_node T2 = y -> left;

    y -> left = x;
    x -> right = T2;

    x -> height = max(heightC(x -> left), heightC(x -> right)) + 1;
    y -> height = max(heightC(y -> left), heightC(y -> right)) + 1;

    return y;
}

client_node insere_cliente(client_node node, char* key) {

    int balance;

    if (node == NULL) {
        return (newCNode(key));
    }

    if (strcmp(key, node -> codigo_cliente) == 0){
        return node;
    }

    if (strcmp(key, node -> codigo_cliente) < 0){
        node -> left  = insere_cliente(node -> left, key);
    } else if (strcmp(key, node -> codigo_cliente) > 0){
        node -> right = insere_cliente(node -> right, key);
    }

    node -> height = max(heightC(node -> left), heightC(node -> right)) + 1;

    balance = balanceC(node);

    if (balance > 1 && strcmp(key, node -> left -> codigo_cliente) < 0) {
        return rightRotateC(node);
    }

    if (balance < -1 && strcmp(key, node -> right -> codigo_cliente) > 0) {
        return leftRotateC(node);
    }

    if (balance > 1 && strcmp(key, node -> left -> codigo_cliente) > 0) {
        node -> left = leftRotateC(node -> left);
        return rightRotateC(node);
    }

    if (balance < -1 && strcmp(key, node -> right -> codigo_cliente) < 0) {
        node -> right = rightRotateC(node -> right);
        return leftRotateC(node);
    }

    return node;
}

client_node procura_cliente(client_node root, char* element) {

    if (root == NULL) {
        return NULL;
    }

    if (strcmp(element, root -> codigo_cliente) == 0){
        return root;
    }

    if        (strcmp(element, root -> codigo_cliente) < 0){
        return procura_cliente(root -> left, element);
    } else if (strcmp(element, root -> codigo_cliente) > 0){
        return procura_cliente(root -> right, element);
    }

    return 0;
}



int existe_cliente(client_node root, char* element) {

    if (root == NULL) {
        return 0;
    }

    if (strcmp(element, root -> codigo_cliente) == 0){
        return 1;
    }

    if (strcmp(element, root -> codigo_cliente) < 0){
        return existe_cliente(root -> left, element);
    } else if (strcmp(element, root -> codigo_cliente) > 0){
        return existe_cliente(root -> right, element);
    }

    return 0;
}


int get_clientes_por_letra(client_node root, char letra){

        int clientes_totais = 0;

        if (root == NULL){
            return 0;
        }
     
        if (root -> codigo_cliente[0] >= letra){
            clientes_totais += get_clientes_por_letra(root -> left, letra);
        }
     
        if (root -> codigo_cliente[0] == letra){
            printf("%s\n", root -> codigo_cliente);
            clientes_totais++;
        }
     
        if (root -> codigo_cliente[0] <= letra){
            clientes_totais += get_clientes_por_letra(root->right, letra);
        }

        return clientes_totais;

}


void inOrder(client_node root) {
    if (root != NULL) {
        inOrder(root -> left);
        printf("%s ", root -> codigo_cliente);
        inOrder(root -> right);
    }
}

/* int main() { */

/*     struct node* root = NULL; */

/*     root = insert_client(root, "DD1234"); */
/*     root = insert_client(root, "DD1234"); */
/*     root = insert_client(root, "EE1234"); */
/*     root = insert_client(root, "FF1234"); */
/*     root = insert_client(root, "AA1234"); */
/*     root = insert_client(root, "BB1234"); */
/*     root = insert_client(root, "CC1234"); */

/*     printf("In order traversal of the constructed AVL tree is \n"); */
/*     inOrder(root); */

/*     return 0; */
/* } */
