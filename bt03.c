#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node*next;
}Node;

Node*createdNode(int value){
	Node*newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = value;
	newNode->next = NULL;
	
	return newNode;
}

Node*listNode(int n){
	Node*head = NULL;
	Node*tail = NULL;
	
	for(int i=0; i<n; i++){
		int value;
		printf("Phan tu thu %d: ", i + 1);
		scanf("%d", &value);
		
		Node*newNode = createdNode(value);
		
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
	}
	
	return head;
}

void printList(Node*head){
	Node*temp = head;
	
	printf("Mang lien ket:\n");
	while(temp != NULL){
		printf("%d->", temp->data);
		temp = temp->next;
	}
	
	printf("NULL\n");
}

void deleteHeadNode(Node**head){
	Node*temp = *head;
	*head = (*head)->next;
	free(temp);
}

int main(){
	int n;
	
	do{
		printf("Nhap so luong phan tu voi 0<n<=1000: ");
		scanf("%d", &n);
	}while(n<0 || n>1000);
	
	Node*head = listNode(n);
	
	printf("Mang chua xoa:\n");
	printList(head);
	printf("\nMang sau khi xoa:\n");
	deleteHeadNode(&head);
	printList(head);
	
	return 0;
}
