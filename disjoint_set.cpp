//Program to implement Disjoint Set ADT using Union-Find Data Structure
#include <stdio.h>
#include <stdlib.h>

class tree
{
	private:
		struct node
		{
			int data;
			struct node* parent;
			int rank;
		};

		struct node** nodes;
		int capacity;

	public:
		tree(){
			capacity = 100;
			nodes = (struct node**) malloc(capacity * sizeof(struct node*));
			if(nodes==nullptr){
				printf("Memory  allocation failed!\n");
				exit(0);
			}
			for (int i = 0; i < capacity; i++){
				nodes[i] = nullptr;
			}
		}

		~tree(){
			for( int i = 0; i < capacity; i++){
				free(nodes[i]);
			}
			free(nodes);
		}

		struct node* create(int);
		int find(int);
		bool merge(int, int);
};

// Function to create a new node with a given data value
tree :: node* tree :: create(int data){
  struct node* newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode==nullptr){
		printf("Memory Allocation failed!\n");
		exit(0);
	}
	if (capacity <= data) {
        int new_capacity = capacity*2;
        struct node** new_nodes = (struct node**)malloc(new_capacity* sizeof(struct node*));
        if (new_nodes == nullptr) {
            printf("Memory Allocation failed!");
            free(newnode);
            exit(0);
        }
        for (int i = 0; i < capacity; i++) {
            new_nodes[i] = nodes[i];
        }
        for (int i = capacity; i < new_capacity; i++) {
            new_nodes[i] = nullptr;
        }
        free(nodes);
        nodes = new_nodes;
        capacity = new_capacity;
    }
    newnode->data = data;
    newnode->parent = newnode; 
    newnode->rank = 0; 
	nodes[data]=newnode;
    return newnode;
}

// Function to find the root of the tree containing the given node
int tree::find(int ele){
    if (ele < 0 || ele >= capacity || nodes[ele] == nullptr){
        return -1;
    }

    struct node* temp = nodes[ele];
    if (temp != temp->parent){
        int root_data = find(temp->parent->data);
		temp->parent=nodes[root_data];
    }
    return temp->parent->data;
}


// Function to merge two sets (by rank)
bool tree :: merge(int ele_1, int ele_2){
    int root_1 = find(ele_1);
    int root_2 = find(ele_2);

	if(root_1 == -1 && root_2 == -1){
		printf("Error: Elements %d and %d not found!\n",ele_1,ele_2);
		return false;
	}
	else if(root_1==-1)
	{
		printf("Error: Element %d not found!\n",ele_1);
		return false;
	}
	else if(root_2==-1)
	{
		printf("Error: Element %d not found!\n",ele_2);
		return false;
	}

    if (root_1 == root_2){
		printf("Both elements are in the same set!\n");
		return false; 
	}

    if (nodes[root_1]->rank < nodes[root_2]->rank){
        nodes[root_1]->parent = nodes[root_2];
    } 
	else if (nodes[root_1]->rank > nodes[root_2]->rank){
        nodes[root_2] -> parent = nodes[root_1];
    } 
	else{
        nodes[root_2] -> parent = nodes[root_1];
        nodes[root_1]->rank++;
    }
	return true;
}

int main() {
	tree t;
	int choice, num_1, num_2, par;
	char extra;

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

                par = t.find(num_1);
				if(par!=1){
					printf("%d is in the set whose parent is %d", num_1, par);
				}
				else{
					printf("Error: Element %d not found!\n",num_1);
				}
				break;

			case 3:
				printf("Enter elements of the sets to be merged: ");
				scanf("%d %d", &num_1, &num_2);

				if(t.merge(num_1, num_2)){
					printf("Merge successful!");
				}
				else{
					printf("Merge failed!");
				}
				break;

			case 4:
				printf("Exiting...\n");
				exit(0);

			default:
				printf("Invalid Choice!\n");
				break;
		}
	}

    return 0;
}
