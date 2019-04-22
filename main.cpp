#include <iostream>

using namespace std;
#include "Scapegoat.h"



int main()
{
    Scapegoat Sg;

    if(!Sg.IsEmpty())
    {
        cout<<"Tree is empty"<<endl;
    }
    else
    {
        cout<<"Tree is not empty"<<endl;
    }

    cout<<endl;

    Sg.insertScapeGoat(7);
    Sg.insertScapeGoat(8);
    Sg.insertScapeGoat(6);
    Sg.insertScapeGoat(9);
    Sg.insertScapeGoat(5);
    Sg.insertScapeGoat(2);
    Sg.insertScapeGoat(4);
    Sg.insertScapeGoat(1);
    Sg.insertScapeGoat(0);
    Sg.insertScapeGoat(3);
    Sg.insertScapeGoat(3.5);




    cout<<"After inserting the total number of nodes is: "<<Sg.totalNodes()<<endl;
    cout<<endl;
    cout<<endl;


    cout<<"Preorder: ";
    Sg.printPreorder();
    cout<<endl;

    cout<<"Inorder: ";
    Sg.printInorder();
    cout<<endl;

    cout<<"Postorder: ";
    Sg.printPostorder();
    cout<<endl;

    cout<<endl;
    cout<<"Search value 8: ";

    if(Sg.searchValue(8)==true)
    {
        cout<<"Found"<<endl;
    }

    else
    {
        cout<<"Not Found"<<endl;
    }
    cout<<endl;


    cout<<"Search value 10: ";

    if(Sg.searchValue(10)==true)
    {
        cout<<"Found"<<endl;
    }

    else
    {
        cout<<"Not Found"<<endl;
    }
    cout<<endl;







    cout<<endl;
    cout<<"Deleting 3.5 value from the node"<<endl;

    Sg.deleteNode(3.5);
    cout<<"\n\n"<<endl;


    cout<<"Preorder: ";
    Sg.printPreorder();
    cout<<endl;

    cout<<"Inorder: ";
    Sg.printInorder();
    cout<<endl;

    cout<<"Postorder: ";
    Sg.printPostorder();
    cout<<endl;


    Sg.MakeEmpty();



    return 0;
}
