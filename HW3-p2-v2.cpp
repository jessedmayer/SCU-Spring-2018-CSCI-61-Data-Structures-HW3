#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
        c == '*' || c == '/' ||
        c == '^')
        return true;
    return false;
}

struct node{
    char data;
    node* left_ptr;
    node* right_ptr;
};

void recursive_step(string s, int i, node* &root_ptr){
    if(i<s.length()){
        if(isOperator(s[i])&&!isOperator(s[i+1])){
            root_ptr->data = s[i];
            recursive_step(s,i+1,root_ptr->left_ptr);
            recursive_step(s,i+2,root_ptr->right_ptr);
        }
        else if(isOperator(s[i])&&isOperator(s[i+1])){
            root_ptr->data = s[i];
            root_ptr->left_ptr->data = s[i+1];
            recursive_step(s,i+2,root_ptr->left_ptr->left_ptr);
            recursive_step(s,i+3,root_ptr->left_ptr->right_ptr);
            recursive_step(s,i+4,root_ptr->right_ptr);
        }
        else{
            root_ptr->data = s[i];
        }
    }
}

void print_tree(node* root_ptr){
    cout << root_ptr->data;
    if(isOperator(root_ptr->left_ptr->data)&&isOperator(root_ptr->right_ptr->data)){
        print_tree(root_ptr->left_ptr);
        print_tree(root_ptr->right_ptr);
    }
    if(!isOperator(root_ptr->left_ptr->data)&&!isOperator(root_ptr->right_ptr->data)){
        cout << root_ptr->left_ptr->data;
        cout << root_ptr->right_ptr->data;
    }
}

node* preorder_to_Tree(string s) {
    node* root_ptr;
    recursive_step(s,0,root_ptr);
    return root_ptr;
}




int main(){
    string case_1 = "+*26/38";
    string case_2 = "*37";
    string case_3 = "/+284";

    node* root_1 = preorder_to_Tree(case_1);
    print_tree(root_1);

    node* root;
    root->data = '+';
    root->left_ptr->data = '3';
    root->right_ptr->data = '5';
    print_tree(root);
    return 0;
}

