#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
using namespace std;

int i,n;
ifstream fin;
ofstream fout;
fstream fio;
void disp();

class stock
{
	char name[20],pass[10];
	float pr; int quant;

public:
	void get();
	void get2();
	void show();
    int stchk(char nm[30]);    
    void withd(int qty);
    void refil(int qty);
}st;

void stock::withd(int qty)
{
	if(quant>=qty)
	{
		quant-=qty;
		cout<<"\n\nStock updated.\n";
		cout<<"\n\nTotal price to be paid:"<<pr*qty;
    }
	else 
	   cout<<"\n\nInsufficient stock";
	    getch();
		
	
}

void stock::refil(int qty)
{
	
		quant+=qty;
		cout<<"\n\nStock updated.";
	    getch();
		
	
}

int stock::stchk(char nm[30])
{
	if(strcmp(nm,name)==0)
	 return 0;
	else 
	return 1;
}
void stock::get()
{
	cin>>name>>pr>>quant;
}

void stock::get2()
{
	cin>>name>>quant;
}

void stock::show()
{
	
	cout<<"\n"<<name<<"\t\t\t"<<quant<<"\t\t\t"<<pr;
}

void addnew()
{
 

    system("cls");
		
	disp();
	getch();
	system("cls");
	
	cout<<"\nEnter the No. of Products that you wish to add: ";
    cin>>n;
	
    
    if (n!=0)
    {
	
	int j,l,sum=0;
	fout.open("shop.dat",ios::binary|ios::app);
	for(i=0;i<n;i++)
	
	{
		cout<<"\n\nInput the name, price and the quantity of item respectively\n\n";
	    st.get();
	    fout.write((char*)&st,sizeof(st));
        cout<<"\n\nitem updated";
		cin.get();

    }
    
    cout<<"\n\nStock Updated!!";

    fout.close();
    cin.get();
    system("cls");
    disp();
  }

	else
  {

	fout.close();
	cin.get();
	system("cls");
	cout<<"\n\nNo items to be added";
  }
  
}

void withdraw()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	disp();
	cout<<"\n\nEnter the product's name \n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    {
		  
		  st.withd(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     
    
     if(i!=1)
       cout<<"\n\n!!Record not found!!";
     fio.close();
    cin.get();
    system("cls");
	 disp(); 
	getch();
}

void disp()
{
	int i=1;
	cout<<"\n==================================================================";
	cout<<"\n\n=================\tTHE STOCK ITEMS ARE\t==================";
	cout<<"\n\n==================================================================\n";
	cout<<"\n\nPARTICULARS\tSTOCK AVAILABLE\t\t\t PRICE";
	cout<<"\n\n============================================================\n";	
	 fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)
	     {	i=0; break;}
	     st.show();
	  }
     }
     if(i==0)
     {	cout<<"\n\n\t\t\t!!Empty record room!!";
	getch();
     }
     fin.close();
}

void refill()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	disp();
	cout<<"\n\nEnter the products name \n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    {
		  
		  st.refil(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     if(i!=1)
       cout<<"\n\n!!Record not found!!";
     fio.close();
    system("cls");
    cin.get();
	 disp(); cin.get();	
}

void remove()
{
	system("cls");	
	 int i=0;
     char temp[30];
     cout<<"\n\t\t\t\tDelete Record";
     cout<<"\n\nEnter the name of the product:";
     cin>>temp;
     fout.open("temp.dat",ios::binary);
     fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	    if(st.stchk(temp)==0)
	    {
		  st.show();
		  cout<<"\n\n\t\tRecord deleted";
		  i++;
	    }
	    else
		  fout.write((char*)&st,sizeof(st));
     }
     if(i==0)
       cout<<"\n\n!!Record not found!!";
     fin.close();
     fout.close();
     remove("shop.dat");
     rename("temp.dat","shop.dat");
}

// car

class Cars {
    public:
    	
    string mark [10] = {"Hyundai","BMW","Mercedes","Audi","Tesla","Skoda","Volkswagun","Toyota","Ford"};

    string model [10]= {"2016MD","2018AS","2018DS","2017LA","2018OW","2005Ps","2008PW","2010QW","2016SA"};

    string color [10]={"Red","black","yellow","Blue","Red","Brown","Silver","Black","grey"};

    string maxs_peed [10]={"100 Km/h ","150 Km/h","150 Km/h","170 Km/h","130 Km/h","140 Km/h","130 Km/h","120 Km/h","150 Km/h"};

    int price [ 10 ] ={100,200,300,500,200,250,400,600,900} ;

    int date [10] = {2010,2012,2013,2017,2018,2005,2008,2010,2014};



   };

   class Lessee {
    public:
    	
   string Name [10];
   string Natio_ID [10] ;
   int payment_acc [ 10] ;
   };


 Cars car ;
 Lessee lessee ;


   void Minu ()
 {
 	
   
   int num=1;
 for(int i=0 ;i<9;++i)
 {
 	cout<<"\t\t\t";
    cout<<"Enter " <<num<<"\t- To Select  "<<car.mark[i]<<endl;
    num++ ;
 }

 }


 void Details (int theChoice)
  {
  	system("CLS");
  	 cout<<"\n\n\n\t\t\t-----------------------------\n";
     cout<<"\t\t\tYou Have Selected - "<<car.mark[theChoice-1]<<endl;
     cout<<"\t\t\t-----------------------------\n\n\n";
     cout<<"\t\t\tModel : "<<car.model[theChoice-1]<<endl;
     cout<<"\t\t\tColor : "<<car.color[theChoice-1]<<endl;
     cout<<"\t\t\tMaximum Speed : "<<car.maxs_peed[theChoice-1]<<endl;
     cout<<"\t\t\tPrice : "<<car.price[theChoice-1]<<"K"<<endl;


  }


   void check (int j )
  {
      if(lessee.payment_acc[j]  >= car.price[j])
           cout<<"\n\n\n\t\t\tProcess has been done successfully!! " <<endl;
           else
              cout<<"\n\n\n\t\t\tNot Available " <<endl;

  }

  void user_input (int theChoice)
   {
   	system("CLS");
        int j=theChoice-1 ;
       cout<<"\t\t\t----------------------------------------\n";
       cout<<"\t\t\tPlease Provide Your Personal Details  : \n";
       cout<<"\t\t\t----------------------------------------\n\n";
       cout<<"\n\tNOTE: PROVIDE FIRST NAME ONLY, DONOT ENTER SPACE WHILE PROVIDING NAME,\n\tPAYMENT WON'T PROCEED IF THE GIVEN AMOUNT IS LESS THEN THE RATE OF CAR\n\n\n\n";
       cout<<"\t\t\tEnter Your Name : ";
       cin>>lessee.Name[j];
       cout<<"\t\t\tEnter Your National ID : ";
       cin>>lessee.Natio_ID[j] ;
       cout<<"\t\t\tPayment Amount: " ;
       cin>>lessee.payment_acc[j] ;


     check( j ) ;
   }


int main()
{
	char pass[10];
	int i,j,k;
	
	cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ WELCOME TO SALES SYSTEM ============|";
	getch();
	system("cls");
	
	cout<<"\n\n\t\t   1. Gadget Store\n\n\t\t   2. Car DealerShip ";
	cout<<"\n\n=============================================================\n";
	cout<<"\n\nEnter Your Choice:";
	cin>>k;
	if(k==1)
	{
      system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ WELCOME TO STORE MANAGEMENT ============|";
	getch();
	system("cls");
	cout<<"\n\t\t   STORE MANAGEMENT SYSTEM\n";	
	cout<<"=============================================================";
	cout<<"\n\n\t\t   1. Dealer Menu\n\n\t\t   2. Customer Menu\n\n\t\t   3. Employee Menu\n\n\t\t  ";
	cout<<"\n\n=============================================================\n";
	cout<<"\n\nEnter Your Choice:";
	cin>>j;
	if(j==1)
	{
	
	system("cls");
    system("cls");
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
	
	for(int z=0;z<6;z++)
	{
		pass[z]=getch();
		system("cls");
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
		for(i=1;i<=(z+1);i++)
		{
			cout<<"*";
		}
	}
	if(strcmp(pass,"dealer")==0)
	{
    system("cls");
	dealermenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    DEALER MENU\n1. Add new product\n2. Display stock\n3. Refill\n4. Remove an item\n5. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	if(i==1)
	{
		addnew();getch();
	goto dealermenu;
	}

	else if(i==2)
	{
		system("cls");
	disp();getch();goto dealermenu;
	}
	else if(i==3)
	{
		refill();goto dealermenu;
	}
	else if(i==4)
	{
		remove();getch();goto dealermenu;
	}
	else 
	{
		system("cls");
	cout<<"\n\n\n\t\t\t";
	getch();
	exit(0);
}
}
else
{
	cout<<"\n\n\nAuthorised Personnel Only\n\n";
	getch();
	getch();
	getch();
	getch();
	getch();
	getch();
	exit(0);
}
	}
	if(j==2)
	{
		custmenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    CUSTOMER MENU\n1. Purchase\n2. Display stock\n3. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	
	
	
	if (i==1)
	{
	withdraw();getch();goto custmenu;
	}
	else if(i==2)
	{
		system("cls");
	disp();getch();goto custmenu;
	}
	
	else 
	{
		system("cls");
	cout<<"\n\n\n\t\t\t";
	getch();
	exit(0);
}
	
}
if(j==3)
{
	system("cls");
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
	
	for(int z=0;z<3;z++)
	{
		pass[z]=getch();
		system("cls");
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
		for(i=1;i<=(z+1);i++)
		{
			cout<<"*";
		}
	}
	
	
	if(strcmp(pass,"emp")==0)
	{
	empmenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\tEMPLOYEE MENU\n1. Display stock\n2. Refill\n3. Exit";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	if(i==1)
	{
		system("cls");
	disp();getch();goto empmenu;
	}
	else if(i==2)
	{
		refill();goto empmenu;
	}
	else 
	{
		system("cls");
	cout<<"\n\n\n\t\t\tThank You!!";
	getch();
	exit(0);
}
}
else
{
	cout<<"\n\nSorry!! Access Denied..\n\n";
	getch();
	getch();
	getch();
	getch();
	getch();
	
	exit(0);
}

}	}

if(k==2)
{   
  system("CLS");
  int login();
    login();
    
	string decide ="yes" ;
     cout<<"\t\t\t----------------------------------------------\n";    
     cout<<"\t\t\t\tSIMPLE CAR RENTAL SYSTEM \n";
     cout<<"\t\t\tWelcome to Our Company ,Choose from the menu : "<<endl;
     cout<<"\t\t\t----------------------------------------------\n";
     while(decide!="exit")
     {
         Minu();
     cout<<"\n\n\n\t\t\tYour Choice: ";
     int theChoice ;
     cin>>theChoice ;
     Details(theChoice);
     cout<<"\n\n\n\t\t\tAre You Sure, you want to rent this Car? (yes /no /exit ) : ";
     cin>>decide ;
     if(decide=="yes") {
        user_input(theChoice);
        cout<<"\n\n\t\t\tDo you want to continue ?(yes/no) ";
        cin>>decide;
        if (decide=="no") break ;
system("CLS");
     }

   else {
      if(decide=="no")
      {
      	system("CLS");
          continue ;
      }
     else if  (decide=="exit")
     {
     	system("CLS");
     	cout<<"\n\n\n\t\t\t";

         break ;
     }

   }
     }
}
	
	getch();
}


int login(){
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\n\n\n\t\t\t\t\t  Simple Car Rental System Login";
   cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13){
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass"){
      cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
      system("PAUSE");
      system("CLS");
      
   }else{
      cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
      system("PAUSE");
      system("CLS");
      login();
   }
}
