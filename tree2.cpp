#include<iostream>
#include<Queue>
using namespace std;

class node{
    public:
    node *left;
    int data;
    node *right;
};

class Queue{
 private:
 int front;
 int rear;
 int size;
 node **Q;

 public:
 Queue(){front=rear=-1;size=10;Q=new node*[size];}
 Queue(int size){front=rear=-1;this->size=size;Q=new node*[this->size];}

 void enqueue(node *x){
    if(rear==size-1)
        cout<<"Queue is full\n";
    else{
        rear++;
        Q[rear]=x;
    }
 }

 node* dequeue(){
    node* x=nullptr;
    if(front==rear)
        cout<<"Queue is Empty\n";
    else{
        x=Q[front+1];
        front++;
    }
    return x;
 }

 void display(){
    for(int i=front+1;i<=rear;i++)
        cout<<Q[i]<<" ";
    cout<<"\n";
 }

 int isEmpty(){
    return front==rear;
 }
};

class tree{
    public:
    node *root;
    tree(){root=nullptr;}
    void createTree(){
        node *p,*t;
        int x;
        Queue q(100);

        cout<<"Enter root value ";
        cin>>x;
        root=new node;
        root->data=x;
        root->left=root->right=nullptr;
        q.enqueue(root);

        while(!q.isEmpty()){
            p=q.dequeue();
            cout<<"Enter left child of "<<p->data<<" ";
            cin>>x;
            if(x!=-1){
                t=new node;
                t->data=x;
                t->left=t->right=nullptr;
                p->left=t;
                q.enqueue(t);
            }
            cout<<"Enter the right child "<<p->data<<" ";
            cin>>x;
            if(x!=-1){
                t=new node;
                t->data=x;
                t->left=t->right=nullptr;
                p->right=t;
                q.enqueue(t);
            }
        }
        
    }


    void preorder(node* p){
        if(p){
            cout<<p->data<<" ";
            preorder(p->left);
            preorder(p->right);
        }
    }
    void postorder(node* p){
        if(p){
            postorder(p->left);
            postorder(p->right);
            cout<<p->data<<" ";
        }
    }
    void inorder(node *p){
        if(p){
            inorder(p->left);
            cout<<p->data<<" ";
            inorder(p->right);
        }
    }
    void levelorder(node* p){
        Queue q(100);
        cout<<root->data<<" ";
        q.enqueue(root);

        while(!q.isEmpty()){
            root=q.dequeue();
            if(root->left){
                cout<<root->left->data<<" ";
                q.enqueue(root->left);
            }
            if(root->right){
                cout<<root->right->data<<" ";
                q.enqueue(root->right);
            }
        }

    }


    int height(node *root){
        int x=0,y=0;
        if(root==0)
            return 0;
        x=height(root->left);
        y=height(root->right);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
};
int main()
{
    tree t;
    t.createTree();
    t.preorder(t.root);
    t.inorder(t.root);
    
    return 0;
}