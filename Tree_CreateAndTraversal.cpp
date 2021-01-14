#include<iostream>
using namespace std;

template<class T>
class TreeNode{
    private:
        int object;
        TreeNode *left, *right; 
    
    public:
		// Default Constructor
            TreeNode()
            {   left  = NULL;
                right = NULL; }
            
        // Overloaded Constructor 
            TreeNode(T object){
                this->object = object;
                left  = NULL;
                right = NULL; }
            
        // SETTERS
            void setObject(T obj){  this->object = obj; }
            void setLeft(TreeNode *left){  this->left = left; }
            void setRight(TreeNode *right){  this->right = right; }
            
        // GETTERS
            int getObject(){ return this->object; }
            TreeNode *getLeft(){ return this->left; }
            TreeNode *getRight(){ return this->right; }
		
		//============= M E M B E R   F U N C T I O N S =============
		
		// isLeaf() function [to check if there is no right/left child]
            int isLeaf(){   
                if(this->left==NULL && this->right==NULL) return 1;
                else return 0;	}
		
		// Visit() function [return node object]
            int Visit(){ return this->object; }
};   

class BinaryTree{
    private:
        TreeNode<int> *root;

    public:
    // Default Constructor
        BinaryTree(){ root = NULL; }
    
    // Destructor
        ~BinaryTree(){ };

    /* ============= Member Functions ============= */

    // Add new node to tree
        void add(int data){
            TreeNode<int> *node = new TreeNode<int>(data);
            TreeNode<int> *p, *q;
            p = q = root;

            if( root != NULL ){
                while(q != NULL ){
                    p = q;
                    if(data < p->getObject()) q = p->getLeft();
				        else if(data >= p->getObject()) q = p->getRight();   }   
            if(data < p->getObject()) p->setLeft(node);
			    else if(data >= p->getObject()) p->setRight(node);	}

			else{ root = node; }    }

    // PreOrder Traversal
		void preOrder(){	preOrder(root);	}
		void preOrder(TreeNode<int> *t){
			if(t){
                cout<<t->Visit()<<"  ";
				preOrder(t->getLeft());
				preOrder(t->getRight());  } }
    // PostOrder Traversal
        void postOrder(){	postOrder(root);	}
		void postOrder(TreeNode<int> *t){
			if(t){
				postOrder(t->getLeft());
				postOrder(t->getRight());
                cout<<t->Visit()<<"  ";  } }
    
    // InOrder Traversal
        void inOrder(){	inOrder(root);	}
		void inOrder(TreeNode<int> *t){
			if(t){
				inOrder(t->getLeft());
                cout<<t->Visit()<<"  ";
			    inOrder(t->getRight());  } }

};

int main(){

    // BT is the object of class BinaryTree
        BinaryTree BT;

        BT.add(10); BT.add(20); BT.add(54); BT.add(13); BT.add(67); BT.add(7); BT.add(1);

        cout<<"PreOrder Traversal: ";    BT.preOrder();
        cout<<"\n\nPostOrder Traversal: ";   BT.postOrder();
        cout<<"\n\nInOrder Traversal: ";     BT.inOrder();

        return 0;   }