#include "Scapegoat.h"

#include <iostream>
using namespace std;

#include <bits/stdc++.h>

Scapegoat::Scapegoat()
{
    root = NULL;
}

static float const log32(int n)
{
    double const log23 = 2.4663034623764317;
    return (float)(log23 * log(n));
}











int Scapegoat::totalNodes()
{

    return noOfNodes;


}



int Scapegoat::addwithDepth(Node* newNode)
{

    Node *currnode = root;
    int depth=0;

    if(currnode==NULL)
    {
        root = newNode;
        noOfNodes++;
        maxnode++;
        return 0;
    }

    else
    {
        while(currnode!=NULL)
        {
            if(newNode->value <= currnode->value)
            {

                if(currnode->left==NULL)
                {
                    currnode->left=newNode;
                    newNode->parent=currnode;
                    currnode=NULL;
                }
                else
                {
                    currnode = currnode->left;
                }
            }
            else
            {
                if(currnode->right==NULL)
                {
                    currnode->right=newNode;
                    newNode->parent=currnode;
                    currnode=NULL;
                }
                else
                {
                    currnode=currnode->right;
                }
            }


            depth++;

        }

        noOfNodes++;
        maxnode++;
        return depth;


    }





}



int Scapegoat::sizeofTree(Node* ptr)
{

    if (ptr == NULL)
    {
        return 0;
    }
    else
    {

        return 1 + sizeofTree(ptr->left) + sizeofTree(ptr->right);
    }


}



int Scapegoat::packIntoArray(Node *ptr, Node *arr[], int i)
{
    if (ptr == NULL)
    {
        return i;
    }

    i = packIntoArray(ptr->left, arr, i);
//   cout<<ptr->value<<" Index: "<<i<<endl;
    arr[i] = ptr;
    i++;

    return packIntoArray(ptr->right, arr, i);
}



void Scapegoat::rebuild(Node* u)
{


    int asize = sizeofTree(u);

    Node *p = u->parent;
    Node **a = new Node* [asize];



    packIntoArray(u,a,0);
    if (p == NULL)
    {
        root = buildBalancedFromArray(a, 0, asize);
        root->parent = NULL;
    }
    else if (p->right == u)
    {
        p->right = buildBalancedFromArray(a, 0, asize);
        p->right->parent = p;
    }
    else
    {
        p->left = buildBalancedFromArray(a, 0, asize);
        p->left->parent = p;
    }







}


Node *Scapegoat::buildBalancedFromArray(Node **a,int i, int n)
{
    if (n== 0)
        return NULL;
    int m = n / 2;


    a[i+m]->left = buildBalancedFromArray(a, i, m);


    if (a[i+m]->left != NULL)
    {
        a[i+m]->left->parent = a[i+m];
    }

    a[i+m]->right = buildBalancedFromArray(a, i+m+1, n-m-1);
    if (a[i+m]->right != NULL)
    {
        a[i+m]->right->parent = a[i+m];
    }

    return a[i+m];
}







void Scapegoat::insertScapeGoat(float newValue)
{



    Node* newNode;
    newNode = new Node;
    newNode->value = newValue;
    newNode->left=NULL;
    newNode->right=NULL;

    int d = addwithDepth(newNode);

    /*

        cout<<d<<"    ";
        cout<<log32(noOfNodes)<<endl;


    */


    if(d>log32(maxnode))
    {
        Node *p = newNode->parent;

        while (3*sizeofTree(p) <= 2*sizeofTree(p->parent))
        {



            // cout<<p->value<<"   "<<endl;

            p = p->parent;

        }

        rebuild(p->parent);


    }







}











bool Scapegoat::IsEmpty()
{

    bool found=true;

    if(root==NULL)
    {
        found = false;
    }

    return found;

}

void Scapegoat::MakeEmpty()
{
    root = NULL;
    noOfNodes = 0;
}


bool search(Node* s,float sValue)
{


    while (s != NULL)
    {
        if (s->value == sValue)
            return true;
        if (s->value < sValue)
            s = s->right;
        else
            s = s->left;
    }
    return false;
}





bool Scapegoat::searchValue(float value)
{

    bool found =  search(root,value);


    return found;



}


void DeleteNodeInBST(Node* root,float d)
{

    bool found = false;

    Node* curr;
    Node* p;
    curr = root;
    while(curr != NULL)
    {
        if(curr->value == d)
        {
            found = true;
            break;
        }
        else
        {
            p = curr;
            if(d >curr->value) curr = curr->right;
            else curr = curr->left;
        }
    }
    if(!found)
    {
        cout<<" Data not found! "<<endl;
        return;
    }

    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL
            && curr->right == NULL))
    {
        if(curr->left == NULL && curr->right != NULL)
        {
            if(p->left == curr)
            {
                p->left = curr->right;
                delete curr;
            }
            else
            {
                p->right = curr->right;
                delete curr;
            }
        }
        else
        {
            if(p->left == curr)
            {
                p->left = curr->left;
                delete curr;
            }
            else
            {
                p->right = curr->left;
                delete curr;
            }
        }
        return;
    }

    if( curr->left == NULL && curr->right == NULL)
    {
        if(p->left == curr) p->left = NULL;
        else p->right = NULL;
        delete curr;
        return;
    }


    if (curr->left != NULL && curr->right != NULL)
    {
        Node* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        }
        else
        {

            if((curr->right)->left != NULL)
            {
                Node* lcurr;
                Node* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                    lcurrp = lcurr;
                    lcurr = lcurr->left;
                }
                curr->value = lcurr->value;
                delete lcurr;
                lcurrp->left = NULL;
            }
            else
            {
                Node* tmp;
                tmp = curr->right;
                curr->value = tmp->value;
                curr->right = tmp->right;
                delete tmp;
            }
        }
        return;
    }
}





void Scapegoat::deleteNode(float deleteValue)
{

    DeleteNodeInBST(root,deleteValue);
    noOfNodes--;


    if(noOfNodes < maxnode/2)
    {
        rebuild(root);
        maxnode=noOfNodes;
    }


}


void preorder(Node *node)
{
    if (node != NULL)
    {
        cout << node->value << " ";
        preorder(node -> left);
        preorder(node -> right);
    }
}


void Scapegoat::printPreorder()
{

    preorder(root);

}






void inorder(Node *node)
{
    if (node != NULL)
    {

        inorder(node -> left);
        cout << node->value << " ";
        inorder(node -> right);
    }
}


void Scapegoat::printInorder()
{

    inorder(root);

}






void postorder(Node *node)
{
    if (node != NULL)
    {

        postorder(node -> left);
        postorder(node -> right);
        cout << node->value << " ";
    }
}


void Scapegoat::printPostorder()
{

    postorder(root);

}







