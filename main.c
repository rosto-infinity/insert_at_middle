#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} list;

// Fonction pour insérer un nœud au milieu de la liste
list *insert_at_middle(list *head, int value, int position) {
    list *new_node = (list *)malloc(sizeof(list));
    new_node->data = value;

    if (position == 0 || head == NULL) {
        // Insertion au début si la position est 0 ou si la liste est vide
        new_node->next = head;
        return new_node;
    }

    list *current = head;
    int index = 0;

    // Trouver le nœud avant la position souhaitée
    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    if (current == NULL) {
        // Si la position est plus grande que la taille de la liste, on ajoute à la fin
        new_node->next = NULL;
        return head; // Retourne la tête inchangée
    }

    // Insérer le nouveau nœud
    new_node->next = current->next;
    current->next = new_node;

    return head; // Retourne la tête de la liste
}

// Fonction pour créer la liste
list *create_list() {
    list *head = NULL;
    int value, position;

    printf("Entrez -1 pour terminer \n");
    printf("Entrez les données : \n");
    scanf("%d", &value);

    while (value != -1) {
        printf("Entrez la position pour insérer (0 pour début) : ");
        scanf("%d", &position);
        head = insert_at_middle(head, value, position); // Insertion au milieu
        printf("Entrez les données : \n");
        scanf("%d", &value);
    }
    return head;
}

// Fonction pour afficher la liste
void display_list(list *head) {
    list *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    list *my_list = NULL;
    my_list = create_list();
    display_list(my_list);

    // Libération de la mémoire
    list *temp;
    while (my_list != NULL) {
        temp = my_list;
        my_list = my_list->next;
        free(temp);
    }

    return 0;
}
