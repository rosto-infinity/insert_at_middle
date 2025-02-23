#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} list;

// Fonction pour ins�rer un n�ud au milieu de la liste
list *insert_at_middle(list *head, int value, int position) {
    list *new_node = (list *)malloc(sizeof(list));
    new_node->data = value;

    if (position == 0 || head == NULL) {
        // Insertion au d�but si la position est 0 ou si la liste est vide
        new_node->next = head;
        return new_node;
    }

    list *current = head;
    int index = 0;

    // Trouver le n�ud avant la position souhait�e
    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    if (current == NULL) {
        // Si la position est plus grande que la taille de la liste, on ajoute � la fin
        new_node->next = NULL;
        return head; // Retourne la t�te inchang�e
    }

    // Ins�rer le nouveau n�ud
    new_node->next = current->next;
    current->next = new_node;

    return head; // Retourne la t�te de la liste
}

// Fonction pour cr�er la liste
list *create_list() {
    list *head = NULL;
    int value, position;

    printf("Entrez -1 pour terminer \n");
    printf("Entrez les donn�es : \n");
    scanf("%d", &value);

    while (value != -1) {
        printf("Entrez la position pour ins�rer (0 pour d�but) : ");
        scanf("%d", &position);
        head = insert_at_middle(head, value, position); // Insertion au milieu
        printf("Entrez les donn�es : \n");
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

    // Lib�ration de la m�moire
    list *temp;
    while (my_list != NULL) {
        temp = my_list;
        my_list = my_list->next;
        free(temp);
    }

    return 0;
}
