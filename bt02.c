#include<stdio.h>

typedef struct Node{
	int data;
	struct Node*next;
}Node;

Node* createNode(int value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = value;
	newNode->next = NULL;
	
	return newNode;
}

Node* listNode(int n){
	Node*head = NULL;
	Node*tail = NULL;
	
	for(int i=0; i<n; i++){
		int value;
		printf("gia tri cua phan tu %d: ", i+1);
		scanf("%d", &value);
		
		Node*newNode = createNode(value);
		
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
	
	printf("Danh sach lien ket\n");
	while(head != NULL){
		printf("%d", temp->data);
		temp = temp->next;
	}
	
	printf("NULL");
}

void addAtHead(Node**head,int value){
	Node*newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = value;
	newNode->next = *head;
	*head = newNode;
}

int main(){
	int n;
	int number;
	
	do{
		printf("Vui long nhap gia tri 0>n>=1000: ");
		scanf("%d", &n);
	}while(n<0 || n>1000);
	
	Node*head = listNode(n);
	
	printf("/nNhap phan tu muon them: ");
	scanf("%d", &number);
	
	addAtHead(&head, number);
	
	printListNode(head);
}
