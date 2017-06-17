/*
   Name: Gabriel Kling
   CEFET-RJ/Campus Petrópolis
   Hashing - Separate Chaining with Linked Lists
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{

  int id;
  struct node* next;

};

typedef struct node Node;

int hash(int k){

  int indice = k % 30;
  return indice;
}

void empty(Node *vet[30]){
  int i;

  for(i = 0; i < 30; i++){

    vet[i] = NULL;

  }
}

//Insere se não houver colisão OK

Node *add_no_colision(int k){

  Node *new = malloc(sizeof(Node*));

  if(!new){
    printf("Allocation Error!\n");
  }

  new->id = k;

  new->next = NULL;

  return new;

}

//Insere se houver colisão OK

void add(int k, Node *tab[30]){

  Node *p = tab[hash(k)];

  while(p->next != NULL){
    p = p->next;
  }

  Node* new = (Node*)malloc(sizeof(Node*));

  if(!new){
    printf("Allocation Error!\n");
  }

  p->next = new;

  new->next = NULL;

  new->id = k;

}

//Print the Hash Table OK

void print(Node *vet[30]){

  int i;
  Node *p;

  for(i = 0;  i < 30; i++){
    if(vet[i] != NULL){
      p = vet[i];

      printf("Colision on index %i:\nElements: %i\t", i, p->id);

      while(p->next != NULL){

        p = p->next;
        printf("%i\t", p->id);

      }

      printf("\n\n");
    }
  }
}

int delete(int k, Node *vet[30]){

    Node *p = vet[hash(k)];

    if(p->next == NULL){

      free(p);
      vet[hash(k)] == NULL;
      return 0;

    }

    if(p->id = k){
      vet[hash(k)] = p->next;
      free(p);
      return 0;
    }

    while(p->next->id != k){
      p = p->next;
    }

    Node* at = p->next;

    Node* prox = at->next;

    free(at);

    p->next = prox;

    return 0;
}

void busca(int k, Node *vet[30]){

  Node* p;

  if(vet[hash(k)] != NULL){
    p = vet[hash(k)];
  }

  else{
    printf("Key not found!\n");
    return;
  }

  while(p->next != NULL && p->id != k){
    p = p->next;
  }

  if(p->id = k){
    printf("Key found in the list! Index: %i\n", hash(k));
  }

  if(p->next == NULL){
    printf("Key not found!");
  }



}

int main(void){

  Node *vet[30];

  int i, c, k, indice;

  empty(vet);

  while(1){

    printf("1 - Add.\n2 - Delete\n3 - Print Hash Table.\n4 - Search.\n5 - Exit.\n");
    scanf("%i", &c);

    switch(c){

      case 1:

      printf("Type the number that you want to add:\n");
      scanf("%d", &k);

      indice = hash(k);

      printf("Hash Index: %i\n", indice);

      if(vet[hash(k)] == NULL){
        vet[hash(k)] = add_no_colision(k);
      }
      else{
        add(k, vet);
      }

      break;

      case 2:

      printf("Digite o elemento que deseja deletar:\n\n");
      scanf("%i", &k);

      delete(k, vet);

      break;

      case 3:

      system("clear");
      print(vet);

      break;

      case 4:

      printf("Digite o elemento que deseja buscar:\n");
      scanf("%d", &k);

      busca(k, vet);
      break;

      case 5:

      exit(1);
    }
  }
}
