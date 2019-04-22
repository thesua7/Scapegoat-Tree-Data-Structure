#ifndef NODE_H
#define NODE_H


class Node
{
public:
    Node()
    {

        parent = left = right = NULL;

    };
    Node *parent,*left,*right;
    float value;

private:



};

#endif // NODE_H


