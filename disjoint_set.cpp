#include <stdio.h>
#include <stdlib.h>

class tree {
private:
    struct node {
        int data;
        struct node* parent;
        int rank;
    };

    struct node* root;
    struct node** nodes; // Dynamic array of pointers to nodes
    int capacity;

public:
    tree() {
        root = nullptr;
        capacity = 100;
        nodes = new struct node*[capacity];
        for (int i = 0; i < capacity; ++i) {
            nodes[i] = nullptr;
        }
    }

	struct node* create(int);
	int fin(int);
	struct node* find(int);
	bool merge(int, int);
};

// Function to create a new node with a given data value
tree :: node* tree :: create(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode==nullptr){
		printf("Memory Allocation failed!\n");
		return nullptr;
	}
	if (capacity <= data) {
        int new_capacity = data + 1;
        struct node** new_nodes = (struct node**)malloc(new_capacity* sizeof(struct node*));
        if (new_nodes == nullptr) {
            printf("Memory Allocation failed!");
            delete newnode;
            return nullptr;
        }
        for (int i = 0; i < capacity; ++i) {
            new_nodes[i] = nodes[i];
        }
        for (int i = capacity; i < new_capacity; ++i) {
            new_nodes[i] = nullptr;
        }
        delete[] nodes;
        nodes = new_nodes;
        capacity = new_capacity;
    }
    newnode->data = data;
    newnode->parent = newnode; 
    newnode->rank = 0; 
	nodes[data]=newnode;
    return newnode;
}

int tree::fin(int ele)
{
    if(find(ele)){
		return find(ele)->data;
	}
	else{
		return 0;
	}
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

	if(root_1 == nullptr || root_2 == nullptr){
		return false;
	}

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
	int choice, num_1, num_2, par;

	while(true){
		printf("\n\nMENU\n1. Insert\n2. Find\n3. Union\n4. Exit\nEnter your choice: ");
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
				printf("Enter element whose parent is to be found: ");
				scanf("%d", &num_1);
                par = t.fin(num_1);
				if(par){
					printf("Root of %d is %d", num_1, par);
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
