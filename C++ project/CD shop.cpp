#include <iostream>
#include<string>
#include<conio.h>

using namespace std;
struct movie
{
	int    m_id;
	string mname;
	string production_history;
	string production_company;
	string director_name;
	int    copies_number;
	movie  *next;
};

struct movie_customer{
		int copies_number;
		string mcname;
		movie_customer *mcnext;
	};
struct customers
{
	movie_customer t;
	int id;
	string cname;
	int copies_number;
	string movie_name;
	customers *cnext;	
};


movie *mhead=NULL;
customers *chead=NULL;
movie_customer *mchead=NULL;


void insertinformation_movie(string mname,string production_history,string production_company,string director_name,int copies_number);
void insertinformation_customers(string cname);
void insertsales_customers();
void insertmovie_customers(int copies_number,string mname);
void addinformation_movie();
void addinformation_customers();
void showinformation_customers();
void showinformation_movie();
void inputinformation_movie();
void inputinformation_customers();
void formateinformation_movies();
void formateinformation_customers();
void delete_movie();
void delete_customer();
void search_in_movies();
void search_in_customers();
void oprations();
void opration_movies();
void opration_customers();
int main(int argc, char *argv[])
{
	addinformation_customers();
	addinformation_movie();

	oprations();
	//system("CLS");
	//delete_movie();
	//showinformation_movie();
	//delete_customer();
	//showinformation_customers();
	//formateinformation_customers();
	//showinformation_customers();
	return 0;
	
}

void insertinformation_movie(string mname,string production_history,string production_company,string director_name,int copies_number)
{
	static int i=0;
	movie *new_movie,*mlast;
	new_movie=new movie;
	new_movie->m_id=++i;
	new_movie->mname=mname;
	new_movie->production_history=production_history;
	new_movie->production_company=production_company;
	new_movie->director_name=director_name;
	new_movie->copies_number=copies_number;
	if(mhead==NULL)
	{
		mhead=new_movie;
		new_movie->next=NULL;
	}
	else
	{
		mlast=mhead;
		while(mlast->next!=NULL)
		mlast=mlast->next;
		mlast->next=new_movie;
		new_movie->next=NULL;
	}
}

void insertinformation_customers(string cname)
{
	static int i=0;
	customers *new_customer,*clast;
	new_customer=new customers;
	new_customer->id=++i;
	new_customer->cname=cname;
	new_customer->copies_number=0;
	
	
		if(chead==NULL)
	{
		chead=new_customer;
		new_customer->cnext=NULL;
	}
	else
	{
		clast=chead;
		while(clast->cnext!=NULL)
		clast=clast->cnext;
		clast->cnext=new_customer;
		new_customer->cnext=NULL;
	} 
	
}
void insertsales_customers()
{
		cout<<"                         *******************\n";
	cout<<"                         SALES OPRATIONS \n";
	cout<<"                         *******************\n";
	
	showinformation_customers();
	
	customers *movie_customers;
	movie_customers=chead;
	cout<<" Enter id customer  : ";
	int s;
	cin>>s;
	while(s!=movie_customers->id && movie_customers->cnext!=NULL )
	{
		movie_customers=movie_customers->cnext;
	}
	if (s==movie_customers->id)
	{
		showinformation_movie();
		cout<<mhead->m_id;
		cout<<"Enter id_movie : ";
		int x;
		cin>>x;
		movie *search_movie;
		search_movie=mhead;
		while(x!=search_movie->m_id && search_movie->next!=NULL)
		{
			search_movie=search_movie->next;
		}
		if(x==search_movie->m_id)
		{
			movie_customers->movie_name=search_movie->mname;
			while(1)
			{
				cout<<"\nEnter copies number do you want : ";
				int y;
				cin>>y;
				if(y<=search_movie->copies_number && y>0)
				{
					movie_customers->copies_number=y;
					search_movie->copies_number-=y;
					search_movie=mhead;
					break;
					
				}
				else
				cout<<"There are only "<<search_movie->copies_number<<" for this film enter copies number agine \n";
			}
		}
		
	}
	else
	{
		cout<<"This person is a new customer or the that you enter is rong";
	}
	
	
}

void insertmovie_customers(int copies_number,string mname)
{
	movie_customer *new_movie_customer,*mclast;
	new_movie_customer=new movie_customer;
	new_movie_customer->copies_number=copies_number;
	new_movie_customer->mcname;
		if(mchead==NULL)
	{
		mchead=new_movie_customer;
		new_movie_customer->mcnext=NULL;
	}
	else
	{
		mclast=mchead;
		while(mclast->mcnext!=NULL)
		mclast=mclast->mcnext;
		mclast->mcnext=new_movie_customer;
		new_movie_customer->mcnext=NULL;
	}
	
}

void addinformation_movie()
{
	insertinformation_movie("Al-loabah","2016-6-14","Al_Harm Company","Ahmed Alsokee",10);
	insertinformation_movie("Kalmt Al_ser","2019-8-14","Al_Neel Company","Ahmed Alsokee",15);
	insertinformation_movie("Tetanic","2008-1-6","Moon Company","Tomas",5);
}

void showinformation_movie()
{
	system("CLS");
	movie *show;
	show=mhead;
	cout<<"                           MOVIE DETAILS          \n";
        cout<<"\n_________________________________________________________________________________________________________\n";
		cout<<"id "<<"| Movie name "<<"| Movie production_history "<<"| Movie production_company "<<"| Movie director_name "<<"| Movie copies_number "<<endl;
		cout<<"_________________________________________________________________________________________________________\n";
	while(1)
	{
			if(show->copies_number!=0)
	{
    	cout<<show->m_id;
    	cout<<"  |  "<<show->mname;
		cout<<" |      "<<show->production_history;
		cout<<" |      "<<show->production_company;
		cout<<" |      "<<show->director_name;
		cout<<" |      "<<show->copies_number<<endl;
		cout<<"_________________________________________________________________________________________________________\n";
		
		
	}
		if(show->next==NULL)
		break;
		show=show->next;
    }
    
}

void addinformation_customers()
{
	
	insertinformation_customers("omar");
	insertinformation_customers("ali");
	insertinformation_customers("mohammed");
}	

void showinformation_customers()
{
	system("CLS");
	customers *show;
	show=chead;
	cout<<"                           customers DETAILS          \n";
	cout<<"\n_________________________________________________________________________________________________________\n";
	cout<<"id "<<"| customers name "<<"| Movie name "<<"| Movie copies_number "<<endl;
	cout<<"_________________________________________________________________________________________________________\n";
	while(1)
	{
		
    	cout<<show->id;
    	cout<<"  |  "<<show->cname;
    	if(show->copies_number!=0)
    	{
	    	cout<<"    |   "<<show->movie_name;
		    cout<<" |   "<<show->copies_number<<endl;
	    }
	    else
	    cout<<"\n";
		
		
		if(show->cnext==NULL)
		break;
		show=show->cnext;
		
	}
	
	
}

void inputinformation_movie()
{
	system("CLS");
		cout<<"                         ******************\n";
	cout<<"                         INPUT A NEW MOVIE \n";
	cout<<"                         ******************\n";
	string mname,production_history,production_company,director_name;
	int copies_number;
	cout<<"Enter Movie name : ";
	cin>>mname;
	cout<<"Enter Movie production_history : ";
	cin>>production_history;
	cout<<"Enter Movie production_company : ";
	cin>>production_company;
	cout<<"Enter Movie director_name : ";
	cin>>director_name;
	cout<<"Enter Movie copies_number : ";
	cin>>copies_number;
	insertinformation_movie( mname, production_history, production_company, director_name, copies_number);	
}

void inputinformation_customers()
{
		cout<<"                         *******************\n";
	cout<<"                         INPUT A NEW CUSTOMER \n";
	cout<<"                         *******************\n";
	system("CLS");
	string cname;
	cout<<"Enter customers name : ";
	cin>>cname;
	insertinformation_customers(cname);
	char x;
	cout<<"press y for sales movie or any thing for done : ";
	cin>>x;
	if(x=='y' or x=='Y')
	insertsales_customers();
	
	
}

void formateinformation_movies()
{
	if(mhead==NULL)
	cout<<"/N**THERE IS NO MOVIES**/N";
	else
	{
		movie *formate;
    	while(mhead!=NULL)
    	{
	    	formate=mhead;
	    	mhead=mhead->next;
	    	delete formate;
	    }
	    cout<<"/n                    ************************/n";
	    cout<<"                      FORMATE END SUCCESSFULLY";
	    cout<<"/n                    ************************/n";
	}

	
	
}

void formateinformation_customers()
{
	if(chead==NULL)
	cout<<"/N**THERE IS NO customers**/N";
	else
	{
		customers *formate;
    	while(chead!=NULL)
    	{
	    	formate=chead;
	    	chead=chead->cnext;
	    	delete formate;
	    }
	    cout<<"/n                    ************************/n";
	    cout<<"                      FORMATE END SUCCESSFULLY";
	    cout<<"/n                    ************************/n";
	    system("puase");
	}
}

void delete_movie()
{
	
	if(mhead==NULL)
	cout<<"\n**THERE IS NO MOVIES**\n";
	else
	{
		k:
	movie *old=mhead;
	cout<<"Enter movie ID you want to delete :";
	int del;
	cin>>del;
	while(old->m_id<del && old!=NULL)
	old=old->next;
	if(old->m_id!=del)
	{
		cout<<"!!!  MOVIE ID IS RONG ENTER AGINE !!!\n";
		goto k;
	}
	else
	{
		movie *temp=old;
		temp->next=old->next->next;
		delete old;
	}
	}
}
void delete_customer()
{
		int del;
	if(chead==NULL)
	cout<<"\n**THERE IS NO MOVIES**\n";
	else
	{
		k:
	cout<<"Enter customer ID you want to delete :";
	std::cin>>del;
	customers *old=chead;
	while(old->id<del && old->cnext!=NULL)
	old=old->cnext;
	if(old->id!=del)
	{
    	cout<<"!!!  cusomer ID IS RONG ENTER AGINE !!!\n";
		goto k;
	}

	else
	{
		delete old->cnext;
	}
	}
}

void search_in_movies();
void search_in_customers();

void oprations()
{
	char ch;
	while(1)
	{
		//system("CLS");
			cout<<"                         *******************\n";
	cout<<"                         WELCOME IN CD SHOPE \n";
	cout<<"                         *******************\n";
		cout<<"\n  To movies opration press m ";
	    cout<<"\n  To customers opration press c ";
	    cout<<"\n  or any key to exite \n";
	    cout<<"\n  your choise please : ";
	    cin>>ch;
	    if(ch=='m')
	    opration_movies();
    	else if(ch=='c')
	    opration_customers();
	    else
	    break;
	}
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"                         **************************\n";
	cout<<"                         THANKS FOR VISIT OUR SHOPE \n";
	cout<<"                         **************************\n";
}
void opration_movies()
{system("CLS");
	
	while(1)
	{
			cout<<"                         ***************\n";
	cout<<"                         MOVIE OPRATION \n";
	cout<<"                         ***************\n";
		char ch;
	cout<<"\n  To add new movies press 1 ";
	cout<<"\n  To  show movies detials press 2 ";
	cout<<"\n  or any key for back to main opration \n";
	cout<<"\n  your choise please : ";
	cin>>ch;
	if(ch=='1')
	inputinformation_movie();
	else if(ch=='2')
	showinformation_movie();
	else
	oprations();
	}
}
void opration_customers()
{
	system("CLS");
	while(1)
	{
	cout<<"                         *******************\n";
	cout<<"                         CUSTOMER OPRATION\n";
	cout<<"                         *******************\n";
		char ch;
	cout<<"\n  To add new customer press 1 ";
	cout<<"\n  To  show customer detials press 2 ";
	cout<<"\n  To  sales movie press 3 ";
	cout<<"\n  or any key for back to main opration \n";
	cout<<"\n  your choise please : ";
	cin>>ch;
	if(ch=='1')
	inputinformation_customers();
	else if(ch=='2')
	showinformation_customers();
	else if(ch=='3')
	insertsales_customers();
	else
	oprations();
		
	}
	
} 




















































































































































































































































































































































































































































