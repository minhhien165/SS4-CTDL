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
		printf("Gia tri cua phan tu thu %d: ", i+1);
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

void deleteNode(int index, Node**head){
	if (*head == NULL) {
        printf("Danh sach rong, khong the xoa.\n");
        return;
    }
	
	int currentIndex = 0;
	Node*temp = *head;
	Node* prev = NULL;
	
	while (temp != NULL && currentIndex < index) {
        prev = temp;
        temp = temp->next;
        currentIndex++;
    }
    
    if (temp == NULL) {
        printf("Vi tri %d khong ton tai trong danh sach.\n", index);
        return;
    }

    prev->next = temp->next;
    free(temp);
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
	int index;
	
	do{
		printf("Vui long nhap so luong phan tu 0<n<100: ");
		scanf("%d", &n);
	}while(n<0 || n>100);
	
	Node*head = listNode(n);
	
	printf("\n mang ban dau");
	printListNode(head);
	
	printf("\nNhap vi tri muon xoa: ");
	scanf("%d", &index);
	
	deleteNode(index, &head);
	printf("\n mang sau khi xoa:\n");
	printListNode(head);
	
	return 0;
}
