#include<iostream>
#include<conio.h>
using namespace std;
class Node
{
    public: 	
      int roll_no;
      string name;
      float marks,per;
      Node *next;	
};
class Linked_List
{
	public:
		Node *head = NULL;
		void Insert()
		{
			int r;
			string n;
			float m;
			cout<<"\n\n Enter Roll NO. :";
			cin>>r;
			cout<<"\n\n Enter Name :";
			cin>>n;
			cout<<"\n\n Enter Marks:";
			cin>>m;
			
			Node *new_node=new Node();        //create new node all pu all the dataset
			new_node-> roll_no=r;
			new_node->name=n;
			new_node->marks=m;
			new_node->per=m/100*100;
			new_node->next = NULL;        // Put NULL on next address of new_node
			
			if(head==NULL)                   // means this new_node is first node
			{
				head=new_node;
				
			}
			else{                          //if not NULL means new_node is not first node, list already consist node
			    Node *ptr = head;
				while(ptr->next != NULL)   //ptr pointer var traverse and reach on last node 
				{
					ptr=ptr->next;
				}
				ptr->next=new_node;       //Now insert new_node in last of list	
			}
			cout<<"\n\n\n New Node Inserted Successfully...";
			
		}
		// after insert , Now start search
		void Search()
		{
		  if(head==NULL)	                 // Search whether list has node or not 
		  {
		  	cout<<"\n\n Linked list is Empty...";
		  }
		  else
		  {
		  	int r , found=0;
		  	cout<<"\n\n Enetr Roll NO. For Search:";      //take user input , Search on the basis of roll no.
		  	cin>>r;
		  	Node *ptr = head;            //Searching from first node
		  	while(ptr != NULL)
		  	{
		  		if(r == ptr->roll_no)      //roll no check with user input(r)
		  		{
		  			cout<<"\n\n Roll No. :"<<ptr->roll_no;
		  			cout<<"\n\n Name :" <<ptr->name;
		  			cout<<"\n\n Marks :"<<ptr->marks;
		  			cout<<"\n\n Per % :"<<ptr->per;
		  			found++;
				  }
				  ptr=ptr->next;
			  }
			  if(found == 0)
			  {
			  	cout<<"\n\n\n Search Roll. "<<r<<"Can't found....";
			  }
		  }
		}
		void Count()
		{
			if(head == NULL)
			{
				cout<<"\n\n Linked List is Empty...";
				
			}
			else
			{
				int c=0;
				Node *ptr = head;
				while(ptr != NULL)
				{
					c++;
					ptr=ptr->next;
				}
				cout<<"\n\n Total No. of Nodes: "<<c;
				
			}
		}
		
		void Update(){
			if(head == NULL){
				cout<<"\n\n Linked List is Empty...";
			}
			else
			{
				int r, found=0;
				cout<<"\n\n Enter Roll No. For Updation :";                  //users enter roll no.
				cin>>r;
				Node *ptr = head;
				while(ptr != NULL)
				{
					if(r == ptr->roll_no)                                   // if found that user's roll no. == any nodes's roll no.
					{
						cout<<"\n\n Enter New Roll No. :";                  //then user enter new roll no. for updation
						cin>>ptr->roll_no;                                  //update with new roll no.
						cout<<"\n\n Enter New Name :";
						cin>>ptr->name;
						cout<<"\n\n Enter New Marks :";
						cin>>ptr->marks;
						ptr->per = ptr->marks/100*100;                  //ptr k marks me jaa k per find kro fir ptr k next me stored kro      
						cout<<"\n\n\n Record Updated Successfully...";
						found++;
						
					}
					ptr=ptr->next;
				}
				if(found == 0)
				{
					cout<<"\n\n Update Roll No."<<r;        ///
				}
			}
		}                                                    /////
		
		
		void Delete()
		{
			if(head== NULL)
			{
				cout<<"\n\n Linked List is Empty...";
				
			}
			else
			{
				int r , found=0;
				cout<<"\n\n Enter Roll No. For Deletion :";
				cin>>r;
				if(r == head->roll_no)             // if user input(r) is first Node
				{
					Node *ptr = head;                //delete node considered as ptr
					head = head->next;       
					cout<<"\n\n Record Deleted Successfully...";
					found++;                                     //means deleted node found
					delete ptr;                                  // built in keyword delete 
				}
				else                               // if user's input(r) is not first Node
				{
					Node *ptr=head;
					
					while(ptr != NULL)
					{
						if(r == ptr->roll_no)
						{
							ptr->next=ptr->next->next;
							cout<<"\n\n Record Delete Successfully...";
							found++;
							delete ptr;
							break;
						}
						ptr=ptr->next;
					}
				}
				if(found==0)
				{
					cout<<"\n\n Delete Roll No."<<r;
				}
			}
		}
		void show()
		{
			if(head== NULL)
			{
				cout<<"\n\n Linked List is Empty... :";
			}
			else
			{
				Node *ptr = head;
				while(ptr != NULL)
				{
					cout<<"\n\n Roll No. :"<<ptr->roll_no;
					cout<<"\n\n Name :"<<ptr->name;
					cout<<"\n\n Marks :"<<ptr->marks;
					cout<<"\n\n Per % :"<<ptr->per;
					ptr = ptr->next;
				}
			}
		}
};

main()
{
	Linked_List obj;
	p:
    system("cls");
    int choice;
	cout<<"\n\n 1. Insert Record";
	cout<<"\n\n 2. Search Record";
	cout<<"\n\n 3. Count Nodes";
	cout<<"\n\n 4. Update Record";
	cout<<"\n\n 5. Delete Record";
	cout<<"\n\n 6. Show All Record";
	cout<<"\n\n 7. Exit";
	cout<<"\n\n\n Your Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			system("cls");
			obj.Insert();
			break;
	    case 2:
			system("cls");
			obj.Search();
			break;
	    case 3:
			system("cls");
			obj.Count();
			break;
	    case 4:
			system("cls");
			obj.Update();
			break;
        case 5:
			system("cls");
			obj.Delete();
			break;
	    case 6:
			system("cls");
			obj.show();
			break;
        case 7:
			exit(0);
        default:
		    cout<<"\n\n\n Invalid Choice....Please Try Again.";																							
			
	}
	getch();
	goto p;
	
}
