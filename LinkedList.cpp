#include "Practice_problem.h"

struct node
{
	int data;
	struct node* next;
	int flag;
};

void Print_LinkedList(struct node* node)
{
	while (node != NULL)
	{
		printf("(%d %d)", node->data, node->next);
		node = node->next;
	}
}

void Push_data_start(struct node** node, int data)
{
	//create a node
	struct node* NN = (struct node*)malloc(sizeof(struct node));
	NN->data = data;
	NN->flag = 0;

	NN->next = (*node);
	(*node) = NN;
}

void Push_data_end(struct node** node, int data)
{
	//create a new node
	struct node* NewNode = (struct node*)malloc(sizeof(struct node));
	NewNode->data = data;
	

	struct node* temp = (*node);

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	NewNode->next = temp->next;
	temp->next = NewNode;
}

void Insert_node_location(struct node** head, int loc, int data)
{
	//create a new node
	struct node* Newnode = (struct node*)malloc(sizeof(struct node));
	Newnode->data = data;

	int i;
	struct node* temp = (*head);
	for (i = 1; i < loc; i++)
	{
		temp = temp->next;
	}
	Newnode->next = temp->next;
	temp->next = Newnode;
}

void delete_node_location(struct node** head, int loc)
{
	struct node* temp = (*head);
	int i;

	for (i = 1; i < loc; i++)
	{
		temp = temp->next;
	}
	temp->next = temp->next->next;
}

void reverse_linkedlist(struct node** head)
{
	struct node* prev = NULL;
	struct node* next = NULL;
	struct node* current = (*head);

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	(*head) = prev;
}

bool detectLoop(struct node* h)
{
	while (h != NULL)
	{
		// If this node is already traverse
		// it means there is a cycle
		// (Because you we encountering the
		// node for the second time).
		if (h->flag == 1)
			return true;

		// If we are seeing the node for
		// the first time, mark its flag as 1
		h->flag = 1;

		h = h->next;
	}
}
void Linked_List(void)
{
	//create a head node
	struct node* head = (struct node*) malloc(sizeof(struct node));
	head = NULL;
	Push_data_start(&head, 10);
	Push_data_start(&head, 20);
	Push_data_start(&head, 30);
	Push_data_start(&head, 40);
	Push_data_start(&head, 50);
	

	Push_data_end(&head, 100);
	Push_data_end(&head, 200);
	Push_data_end(&head, 300);
	Push_data_end(&head, 400);

	Print_LinkedList(head);
	printf("\n");

	Insert_node_location(&head, 2, 500);
	Print_LinkedList(head);
	printf("\n");

	delete_node_location(&head, 4);
	Print_LinkedList(head);
	printf("\n");

	reverse_linkedlist(&head);
	Print_LinkedList(head);
	printf("\n");

#if 0
	/* Create a loop for testing */
	head->next->next->next->next = head;
	bool detect_loop = detectLoop(head);
#endif


}


