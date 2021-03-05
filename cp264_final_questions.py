1)
void transpose(int *m, int n){
	int *p = m, i, j, temp;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			temp = *(p+i*n+j);
			*(p+i*n+j) = *(p+j*n+i);
			*(p+j*n+i) = temp;
		}
	}
}

2)
int evaluate_polynomial(int a[], int n, int x){
	int i , result = 0;
	for(i=0;i<n;i++){
		if(i==(n-1))
			printf("%d * %d ^ %d" a[i], i, n-i-1);
		else
			printf("%d * %d ^ %d + " a[i], i, n-i-1);
		result = result*x + a[i];
	}
	return result;
}

3)
void reverse(char *s){
	char *end, *temp;
	int i, len=0;

	while(*end != NULL){
		len++;
		end++;
	}

	for(i=0;i<len/2;i++){
		*temp = *s;
		*s = *end
		*end=*temp
		s++;
		end--;
	}
}

4)
int str2int(char *s){
	int i , result=0;
	for(i=0;*(s+i)!='\0';i++){
		result=result * 10 + *(s+i) - '0'
	}
	return result;
}

5)
void int2binstr(int a, char s[]){
	int i, len=0;
	char *temp=NULL;

	while(a!=0){
		if((a%2)==0)
			*(temp+len) = '0';
		else
			*(temp+len) = '1';
		a=a/2;
		len++;
	}

	while(temp){
		*(s+i) = *(temp+len);
		i++;
		len--;
	}
	*(s+len) = '\0';
}

6)

node *search(node *start, char *name){
	node *temp;
	while(strcmp(start->name,name) != 0 && start!=NULL){
		temp=start;
		start = start->next;
	}
	return temp->next;
}

node *insert(node **start, char *name, int i){
	node *curr=*start;
	node *prev = NULL;
	node newnode = new_node(name);
	int n=0;
	while(n<i && curr != NULL){
		prev = curr;
		curr = curr->next;
		n++;
	}

	if(prev==NULL){
		*start=new_node;
		new_node->next = curr;
	}else{
		prev->next = new_node;
		new_node->next = curr;
	}
}


node *delete(node **start, char *name){
	node *prev=NULL;
	node *curr = *start;

	while(strcmp(curr->name, name) !=0 && curr!=NULL){
		prev=curr;
		curr=curr->next;
	}

	if(curr==NULL)
		return;
	else if(prev==NULL)
		*start= curr->next;
	else
		prev->next = curr->next;
}

7)
void display_backwards(node **start){
	Stack top = NULL;
	node *temp = *start;
	while(temp!=NULL){
		push(&top, temp->data);
		temp=temp->next;
	}
	while(top!=NULL){
		printf("%d " peek(top));
		pop(&top);
	}
}

8)
tnode *dfs(tnode *root, int val){
	tnode *temp;
	if(!root)
		return NULL;
	if(root->data==val)
		return root;

	temp=dfs(root->left,val);

	if(temp)
		return temp;
	else
		return dfs(root->right,val);
	return NULL;
}

tnode *bfs(tnode *root, int val) {
	if (!root) {
		return;
	}
	tnode *np;
	qnode *front = NULL, *rear = NULL;

	enqueue(&front, &rear, root);

	while (front) {
		if (front->tnodep) {
		   np = front->tnodep;
		   if (np->data == val) {
			  clean_queue(&front, &rear);
			  return np;
		   }
		   else {
		     enqueue(&front, &rear, np->left);
		     enqueue(&front, &rear,  np->right);
		   }
		}
		dequeue(&front,&rear);
	}
	return NULL;
}

9)
tnode *search(tnode *root, int val){
	while(root){
		if(root->data == val)
			return root;
		else if(root->data>val)
			root=root->right;
		else
			roor=root->left;
	}
	return NULL;
}

int insert(tnode **root, int val){
	if(!root)
		*root=new_node(val);
		return 1;
	else{
		tnode *curr=*root, *parent = NULL;
		while(curr!=NULL){
			parent=curr;
			if(curr->data>val)
				curr=curr->right;
			else if(curr->data<val)
				curr=curr->left;
			else
				return 0;
		}
		if(parent->data<val)
			parent->left=new_node(val);
		else
			parent->right=new_node(val);
		return 1;
		}
}

10)
struct Node *leftRotate(struct Node *x){
	srtuct Node *y = x->right;
	struct Node *temp=y->left;

	x->right = temp;
	y->left  = y;

	if(x->left->height > x->right->height)
		x->height = x->left->height +1;
	else
		x->height = x->right->height +1;
	if(y->left->height > y->right->height)
		y->height = y->left->height +1;
	else
		y->height = y->right->height +1;

	return y;
}

struct Node *rightRotate(struct Node *x){
	struct Node *y = x->left;
	struct Node *temp = y->right;

	x->left = temp;
	y->right = y;

	if(x->left->height > x->right->height)
		x->height = x->left->height +1;
	else
		x->height = x->right->height +1;
	if(y->left->height > y->right->height)
		y->height = y->left->height +1;
	else
		y->height = y->right->height +1;

	return y;
}

struct Node* insert(struct Node* node, int key){
	if(!node)
		return new_node(key);
	if(node->data > key)
		node->left = insert(node->left);
	else if(node->data < key)
		node->right = insert(node->right);
	else
		return node;

	if(node->left->height > node->right->height)
		node->height = node->left->height+1;
	else
		node->height = node->right->height+1;

	int balance = node->left->height - node->right->height;

	if(balance>1 && node->left-data > key)
		return rightRotate(node);
	if(balance<-1 && node->right->data <key)
		return leftRotate(node);
	if(balance>1 && node->left->data <key){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}if(balance<-1 && node->right->data>1){
		node->right = rightRotate(node->right)
		return leftRotate(node);
	}
	return node;
}
11)
void heapify_up(int *Heap, int index){
	int parent, val = Heap[index];
	while(index){
		parent = (index-1)/2;
		if(Heap[parent] >= val)
			break;
		else{
			Heap[index] = Heap[parent];
			index=parent;
		}
	}
	Heap[index] = val;
}

void heapify_down(int *Heap, int index, int n){
	int val = Heap[index], ci = index*2+1;
	while(ci<=n){
		if(ci < n && Heap[ci] < Heap[ci+1])
			ci++;
		if(Heap[ci] < val)
			break;
		else{
			Heap[index] = Heap[ci];
			index=ci;
			ci=index*2+1;
		}
	}
	Heap[index]=val;
}

void insert(int *Heap, int val){
	Heap[size] = val;
	heapify_up(Heap,size);
	size++;
}

void delete(int *Heap){
	Heap[0] = Heap[size-1];
	size--;
	heapify_down(Heap, 0, size-1);
}

void heap_sort_heap(int *Heap){
	int i, temp, n=size;
	for(i=0;i<n;i++){
		temp=Heap[0];
		Heap[0] = Heap[size-1];
		Heap[size-1] = temp;

		size--;
		heapify_down(Heap,0,size-1);

	}
}
12)
