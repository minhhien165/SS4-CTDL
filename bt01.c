#include<stdio.h>
#include<stdlib.h>

//Dinh nghia cau truc node
typedef struct Node{
	int data;
	struct Node*next;
}Node;

//Ham tao node moi
Node * createNode(int value){
	Node * newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = value;
	newNode->next = NULL;
	
	return newNode;
}

//Ham tao danh sach lien ket tu n phan tu
Node * listNode(int n){
	Node*head = NULL;
	Node*tail = NULL;
	
	for(int i=0; i<n; i++){
		int value;
		printf("nhap gia tri cho phan tu thu %d: ", i+1);
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

// Ham duyet va in danh sach lien ket
void printLinkedList(Node* head) {
    Node* temp = head;
    printf("Danh sach lien ket: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

//Ham giai phong bo nho
void freeLinkedList(Node*head){
	Node*temp;
	
	while(head != NULL){
		temp = head;
		head = head->next;
		free(temp);
	}
	
	printf("Bo nho da giai phong");
}

int main(){
	int n;

    printf("Nhap so luong phan tu cua danh sach: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong phan tu phai lon hon 0.\n");
        return 0;
    }
    
    Node*head = listNode(n);
    
    printLinkedList(head);
    
    freeLinkedList(head);
    
	
	return 0;
}
