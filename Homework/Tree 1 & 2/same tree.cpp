#include<bits/stdc++.h>
using namespace std;
bool isSameTree(Node* p , Node * q){
    if(p==NULL && q==NULL){
        return true;
    }
    if(p!=NULL && q!=NULL) {
        return ((p->data==q->data) && (isSameTree(p->left,q->left)) && (isSameTree(p->right,q->right)));
    }
    
    return false;
}
