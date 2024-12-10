#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node*next;
}Node;

Node*createNode(int value){
	Node*newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = value;
	newNode->next = NULL;
	
	return newNode;
};

Node*listNode(int n){
	Node*head = NULL;
	Node*tail = NULL;
	
	for(int i=0; i<n; i++){
		int temp;
		printf("Phan tu thu %d: ", i+1);
		scanf("%d", &temp);
		
		Node*newNode = createNode(temp);
		
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

void printListNode(Node*head){
	Node*temp = head;
	
	while(temp !=NULL){
		printf("%d->", temp->data);
		temp = temp->next;
	}
	
	printf("NULL\n");
}

void searchNode(Node*head, int value){
	Node*temp = head;
	int position = 0;
	int found = 0;
	
	while(temp != NULL){
		if(temp->data == value){
			printf("vi tri cua gia tri can tim la: %d", position);
			found = 1;
		}
		temp = temp->next;
		position++;
	}
	if(!found){
		printf("-1");
	}
}

int main(){
	int n;
	int value;
	
	do{
		printf("vui long nhap gia tri cua n voi 0<n=<1000; ");
		scanf("%d", &n);
	}while(n<0 || n>1000);
	
	Node*head = listNode(n);
	
	printf("\nDanh sach lien ket: \n");
	printListNode(head);
	
	printf("Vui long nhap gia tri can tim kiem: ");
	scanf("%d", &value);
	printf("\n");
	
	searchNode(head, value);
	
	return 0;
}
