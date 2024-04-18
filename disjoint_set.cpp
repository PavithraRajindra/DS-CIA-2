#include <stdio.h>
#include <stdlib.h>

class tree{
	private:
		struct node {
		int data;
		struct node* parent;
		int rank;
		};
				
		struct node* root;	

	public:
		struct node* nodes[100];
		tree(){
			root = NULL;
			for (int i = 0; i < 100; i++) {
            nodes[i] = nullptr;
        	}
		}

		struct node* create(int);
		struct node* find(int);
		bool merge(int, int);
		void display(int);
};

// Function to create a new node with a given data value
tree :: node* tree :: create(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode==nullptr){
		printf("Memory Allocation failed!\n");
		return nullptr;
	}
    newnode->data = data;
    newnode->parent = newnode; 
    newnode->rank = 0; 
	nodes[data]=newnode;
    return newnode;
}

// Function to find the root of the tree containing the given node
tree::node* tree::find(int ele) {
    if (nodes[ele] == nullptr) {
        printf("Error: Element not found!\n");
        return nullptr;
    }

    struct node* temp = nodes[ele];
    if (temp != temp->parent) {
        temp->parent = find(temp->parent->data);
    }
    return temp->parent;
}


// Function to merge two sets (by rank)
bool tree :: merge(int ele_1, int ele_2) {
    struct node* root_1 = find(ele_1);
    struct node* root_2 = find(ele_2);

    if (root_1 == root_2){
		printf("Sets are not disjoint!\n");
		return false; 
	}

    if (root_1->rank < root_2->rank) {
        root_1->parent = root_2;
    } 
	else if (root_1->rank > root_2->rank) {
        root_2->parent = root_1;
    } 
	else {
        root_2->parent = root_1;
        root_1->rank++;
    }
	return true;
}

int main() {
	tree t;
	int choice, num_1, num_2;

	while(true){
		printf("\nMENU\n1. Insert\n2. Find\n3. Union\n4. Exit\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice){
			
			case 1:
				printf("Enter element to be inserted: ");
				scanf("%d", &num_1);

				if(t.create(num_1)){
					printf("Set created successfully!");
				}
				else{
					printf("Failed to create set!");
				}
				break;
			
			case 2:
				printf("Enter element to be searched: ");
				scanf("%d", &num_1);

				if(t.find(num_1)){
					printf("Element found!");
				}
				else{
					printf("Element not found!");
				}
				break;
			
			case 3:
				printf("Enter elements of the sets to be merged: ");
				scanf("%d %d",&num_1, &num_2);

				if(t.merge(num_1, num_2)){
					printf("Merge successful!\n");
				}
				else{
					printf("Merge failed!");
				}
				break;
			
			case 4:
				exit(0);
			
			default:
				printf("Invalid Choice!");
				break;
		}
	}

    return 0;
}
