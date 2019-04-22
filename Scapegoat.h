#ifndef SCAPEGOAT_H
#define SCAPEGOAT_H

#include <iostream>
using namespace std;

#include "Node.h"

class Scapegoat
{
public:
    Scapegoat();
    int sizeofTree(Node*);
    bool IsEmpty();
    void MakeEmpty();
    void insertScapeGoat(float);
    int addwithDepth(Node*);
    int totalNodes();
    bool searchValue(float);
    void deleteNode(float);
    void printPreorder();
    void printInorder();
    void printPostorder();
    void rebuild(Node*);
    int packIntoArray(Node*,Node*[],int);
    Node* buildBalancedFromArray(Node**,int,int);



private:
    Node* root;
    int noOfNodes=0;
    int maxnode=0;



};


#endif // SCAPEGOAT_H
