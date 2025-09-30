#include<iostream>
#include<stack>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;
	node(){
		left = nullptr;
		right = nullptr;

	}
};

class bstree{
	public:
	node* root;
	bstree(){
		root = NULL;
	}
	void create();
	void insert();
	void displaytree(node* temp,int level = 0);
	void inorder(node* root);
	void preorder(node* root);
	void postorder(node* root);
	node* getroot(){ return root; };
	void nonrecInorder();
	void nonrecPreorder();
	void nonrecPostorder();
	void getmin(node* temp);
	void getmax(node* temp);
	void search(node* temp,int data);
	int getheight(node* temp);
};

int bstree::getheight(node* temp){
	if(temp == NULL) return -1;
	int lh = getheight(temp->left);
	int rh = getheight(temp->right);
	return max(lh,rh)+1;
}

void bstree::nonrecPreorder(){
	node* temp = root;
	stack<node*> s;
	while(1){
		while(temp!=NULL){
			cout<<temp->data<<" ";
			s.push(temp);
			temp = temp->left;
		}
		if(s.empty()) return;
		temp = s.top();
		s.pop();
		temp = temp->right;
	}
}

void bstree::nonrecPostorder(){
	node* temp = root;
	stack<node*> s1;
	stack<node*> s2;
	s1.push(temp);
	while(!s1.empty()){
		temp = s1.top();
		s1.pop();
		s2.push(temp);
		if(temp->left){
			s1.push(temp->left);
		}
		if(temp->right){
			s1.push(temp->right);
		}
	}
	while(!s2.empty()){
		temp = s2.top();
		s2.pop();
		cout<<temp->data<<" ";
	}
}

void bstree::nonrecInorder(){
	node* temp = root;
	stack<node*> s;
	while(1){
		while(temp!=NULL){
			s.push(temp);
			temp = temp->left;
		}
		if(s.empty()) return;
		temp = s.top();
		s.pop();
		cout<<temp->data<<" ";
		temp = temp->right;
	}
}

void bstree::search(node* temp,int data){
	if(temp->data == data){
		cout<<"Element found !"<<endl;
	}
	if(temp != NULL){
		if(temp->data < data){
			search(temp->left,data);
		}
		if(temp->data > data){
			search(temp->right,data);
		}
	}
}

/*
non recursive search
void bstree::search(int data){
	node* temp = root;
	while(temp != NULL){
		if(temp->data < data){
			temp = temp->left;
		}
		else if(temp->data > data){
			temp = temp->right;
		}
		else{
			cout<<"data found"<<endl;
		}
	}
}
*/



void bstree::displaytree(node* root,int level){
    if (!root) return;
    displaytree(root->right, level + 1);
    for (int i = 0; i < level; i++) cout << "    ";
    cout << root->data << "\n";
    displaytree(root->left, level + 1);
}

void bstree::create(){
	cout<<"Creating Root: ";
	root = new node();
	root->left = root->right = NULL;
	cout<<"Enter data: ";
	cin>>root->data;
}

void bstree::insert(){
	node *temp,*p;
	if(root == NULL){ 
		create();
		return;
	}
	p = new node;
	p->left = p->right = NULL;
	cout<<"Enter data: ";
	cin>>p->data;
	
	temp = root;
	while(temp != NULL){
		if(p->data < temp->data){
			if(temp->left == NULL){
				temp->left = p;
				break;
			}
			else{
				temp = temp->left;
			}
		}
		else if(p->data > temp->data){
			if(temp->right == NULL){
				temp->right = p;
				break;
			}
			else{
				temp = temp->right;
			}
		}
		else{
			cout<<"Already Inserted"<<endl;
			break;
		}
	}
}

void bstree::inorder(node* temp){
	
	if(temp!=NULL){
		inorder(temp->left);
		cout<<" "<<temp->data;
		inorder(temp->right);
	}

}

void bstree::preorder(node* temp){
	
	if(temp!=NULL){
		cout<<" "<<temp->data;
		preorder(temp->left);
		preorder(temp->right);
	}

}

void bstree::postorder(node* temp){
	
	if(temp!=NULL){
		postorder(temp->left);
		postorder(temp->right);
		cout<<" "<<temp->data;

	}

}

void bstree::getmin(node* temp){
	if(temp == NULL){
		cout<<"Tree Empty!"<<endl;
	}
	
	while(temp->left != NULL){
		temp = temp->left;
	}
	
	cout<<"Minimum Element in Tree: "<<temp->data;
}

void bstree::getmax(node* temp){
	if(temp == NULL){
		cout<<"Tree Empty!"<<endl;
	}
	
	while(temp->right != NULL){
		temp = temp->right;
	}
	
	cout<<"Maximum Element in Tree: "<<temp->data;
}
int main(){
	bstree b;
	int c;
	do{
		cout<<"--------------------------------"<<endl;
		cout<<"\n\n1. Create Root, \n2. Insert, \n3. All Recursive Traversal, \n4. All Non Recursive Traversal, \n5. Min and Max, \n6. Display Tree, \n8. Search, \n9. Height of Tree, \n\n10. Exit\n";
		cout<<"Enter choice: ";
		cin>>c;
		switch(c){
			case 1: b.create();
				break;
			case 2: b.insert();
				break;
			case 3: cout<<"inorder Traversal: ";
				b.inorder(b.getroot());
				cout<<endl;
				cout<<"preorder Traversal: ";
				b.preorder(b.getroot());
				cout<<endl;
				cout<<"postorder Traversal: ";
				b.postorder(b.getroot());
				cout<<endl;
				break;
			case 4: cout<<"inorder Traversal: ";
				b.nonrecInorder();
				cout<<endl;
				cout<<"preorder Traversal: ";
				b.nonrecPreorder();
				cout<<endl;
				cout<<"postorder Traversal: ";
				b.nonrecPostorder();
				cout<<endl;
				break;
			case 5: b.getmin(b.getroot());
					b.getmax(b.getroot());
				break;
			case 6: b.displaytree(b.getroot());
				break;
			case 8: int d;
				cout<<"Enter Search element: ";
				cin>>d;
				b.search(b.getroot(),d);
				break;
			case 9:
				cout<<"Height of Tree: "<< b.getheight(b.root)<<endl;
				break;
			case 10: cout<<"Exiting...."<<endl;
				break;
			default: cout<<"Invalid choice!"<<endl;
		}
	}while(c!=10);
}
