//
//  main.cpp
//  Binary Tree
//
//  Created by Zach Reda on 8/24/21.
//

#include <iostream>
#include <vector>
using namespace std;

struct node{

string data;
node *left, *right;


node (string s){
data = s;
left = NULL;
right=NULL;
}
};

class Tree{
protected:
    node *root;
public:
    Tree() {root = NULL;}
    void add(node *&p, string s){
        if (p==NULL) {
            p = new node(s);
        }
        else if (s<p->data) {
            add(p->left,s);
            
        }
        else
            add(p->right,s);
        
    }
    void add(string s){
        add(root, s);
    }
    
    void remove(node *&p, string s){
        if (p==NULL) {
            cout<<"Was not present"<<endl;
        }
        if (s<p->data) {
            remove(p->left, s);
        }
        else if (s>p->data)
            remove(p->right, s);
        else if (p->left == NULL && p->right ==NULL){
            delete p;
            p = NULL;
        }
        else if (p->right == NULL){
            delete p;
            p = p->left; //copy of p bc deleted
        }
        else if(p->left==NULL){
            //same as above but mirrored
        }
        else{
            //find and delete rightmost in the left subtree take the data value that was there and use it to replace with p value
           // p->data = the data value that was just removed
            
            //function very similar to remove but would return value instead
            //findAndDelete_biggest
            //move to right until node doesnt have a right
            //procedure to delete
            //return piece of data that was there 
        }
        
            
            
    }
};

tree_to_vec(t,v){
    //calls tree_tovec(t.root,v)
    
}

tree_to_vec(node *p, vector<string> &v){
    if (p!=NULL) {
        tree_to_vec(p->left,v);
        v.push_back(p->data);
        tree_to_vec(p->right,v);
    }
}

Tree::empty(){
    //calls on empty(t.root)
}
empty(node *p){
    if (p!=NULL) {
        empty(p->left);
        empty(p->right);
        delete p;
    }
}

vec_to_tree(vector<string> v, Tree t, int first, int last){
    //v = {a b c d e f g}
    int middle = (first+last)/2;
    t.add(v[middle]);
    vec_to_tree(v, t, first, middle-1); //works with a b c
    vec_to_tree(v, t, middle+1, last); //works with e f g
}

int main(int argc, const char * argv[]) {
    Tree t;
    t.add("s");
    vector<string> v;
    tree_to_vec(t,v); //in alpha order
    t.empty();
    vec_to_tree(v,t,0,v.size()-1);
    //t is now balanced
}

