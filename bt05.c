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
}

Node*listNode(int n){
	Node*head = NULL;
	Node*tail = NULL;
	
	for(int i=0; i<n; i++){
		int temp;
		printf("Gia tri cua nut %d: ", i+1);
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

void insertAtPosition(Node**head, int value, int index){
	Node*newNode = createNode(value);
	
	if(index ==0){
		newNode->next = *head;
        *head = newNode;
        return;
	}
	
	int currentIndex = 0;
	Node*temp = *head;
	
	while(temp != NULL && currentIndex < index - 1){
		temp = temp->next;
		currentIndex++;
	}
	
	if (temp == NULL) {
        printf("Vi tri %d nam ngoai pham vi danh sach.\n", index);
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
	
}

void printListNode(Node*head){
	Node*temp = head;
	
	while(temp != NULL){
		printf("%d ->", temp->data);
		temp = temp->next;
	}
	
	printf("NULL");
}

int main(){
	int n;
	int value;
	int index;
	
	do{
		printf("vui long nhap gia tri cua 0<n<100: ");
		scanf("%d",&n);
	}while(n<0 || n>100);
	
	Node*head = listNode(n);
	
	printf("\n mang ban dau");
	printListNode(head);
	
	printf("\n nhap gia tri muon them: ");
	scanf("%d", &value);
	
	printf("\n nhap vi tri muon them: ");
	scanf("%d", &index);
	
	insertAtPosition(&head, value, index);
	printf("\n mang sau khi them:\n");
	printListNode(head);
	
	return 0;
}
