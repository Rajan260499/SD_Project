#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int nb=1;
int nf=10000;
int Tprice[10];
char fruitn[5][12]={{"Mango "},{"Banana "},{"Orange "},{"Watermelon "},{"Apple "}};
char vegn[5][12]={{"Potatoes "},{"Ginger "},{"Carrots "},{"Onion "},{"Coriandar "}};

struct user
{
  int number;
  string name;
  //string addre;
  char mobile[10];
  //string aadhar;
  char userna[15];
  char pass[25];
  struct user *next;
  }*huser=NULL;

void insert()
{ int i;
   struct user *nn,*temp;
   nn=new user();
   cout<<"Enter Name               :";
   cin>>nn->name;
 //  cout<<"Enter Address            :";
 // cin>>nn->addre;
   cout<<"Enter mobile             :";
  for(i=0;i<10;i++)
   cin>>nn->mobile[i];
   if(i!=10)
   {
    cout<<"Invalid Number.Please Enter Valid Number.";
    for(i=0;i<10;i++)
    cin>>nn->mobile[i];
    
    }  
  // cout<<"Enter Your aadhar number :";
  //cin>>nn->aadhar;
   cout<<"Enter Username           :";
   cin>>nn->userna;
   cout<<"Enter Password :"<<"\n\t\t\t\tPassword Should contain atleat 8 char with one number and one special char and must be capital letter \n";
   cin>>nn->pass;
   if(huser==NULL)
   {
   huser=nn;
   nn->next=NULL; 
   }
    else
    { 
    temp=huser;
     while(temp->next!=NULL)
     temp=temp->next;
     temp->next=nn;
     nn->next=NULL;
    }  
 
}
int search(char username[],char password[])
{  int flag=0;
   struct user *temp;
   temp=huser;
   while(temp!=NULL)
{
     if(strcmp(temp->userna, username)==0 && strcmp(temp->pass, password)==0)
      
    {  
    flag=1;
    }
       
temp=temp->next; 
} 
return flag;
}
struct farmer
{
  int user_id;
  string name;
  string add;
  char mobile[10];
  char aadhar[15];
  char buyername[10][20];
  int sellf[6];
  int sellv[6];
  int veg[5];
  int fruit[5];

  struct farmer*next;
}*head1=NULL;

struct buy
{
  int user_id;
  char name[20];
  string add;
  char mobile[10];
  char aadhar[15];
  int veg[5];
  int fruit[5];

  struct buy*next;
}*head=NULL;


void insertf()
{ 
int ch,ch1,ch2,ch3,user,n1,n2,n3,n4,n5,m1,m2,m3,m4,m5,i;
   struct farmer *nn,*temp;

   nn=new farmer;
   nn->user_id=nf;
    nf++;
   cout<<"Enter Name              :"<<endl;
   cin>>nn->name;
   cout<<"Enter Address           :"<<endl;
   cin>>nn->add;
   cout<<"Enter mobile            :"<<endl;
  for(i=0;i<10;i++)
  { 
   cin>>nn->mobile[i];
  }
  if(i!=10)
  {
    cout<<"\nInvalid Number.Please Enter Valid Number\n";
    cout<<"Enter mobile            :"<<endl;
  for(i=0;i<10;i++)
  { 
   cin>>nn->mobile[i];
  }
  } 
   cout<<"Enter Your aadhar number:"<<endl;
  for(i=0;i<15;i++)
  {
   cin>>nn->aadhar[i];
  }
   if(i!=15)
   {
   cout<<"Invalid Number.";
   cout<<"Enter Your Valid aadhar number:"<<endl;
  for(i=0;i<15;i++)
  {
   cin>>nn->aadhar[i];
  }
   }
   for(i=0;i<5;i++) 
{
   nn->veg[i]=0;
   nn->fruit[i]=0;
}
do
{
     cout<<"\n\t\t\t 1.Vegetable \n\t\t\t 2.Fruit \n\t\t\t 3.Exit\n"<<endl;
	   cout<<"Enter Your Choice"<<endl;
		cin>>ch1;
		switch(ch1)
		{
			case 1:cout<<"1.Potatoes\n2.Ginger\n3.Carrots\n4.Onion\n5.Coriandar\n"<<endl;
				cout<<"Enter Your Choice"<<endl;
				cin>>ch2;
				switch(ch2)
				{
					case 1:cout<<"Enter the amount of Potatoes available in kg"<<endl;								
						cin>>n1;
						nn->veg[0]=n1;
						break;
					case 2:cout<<"Enter the amount of Ginger available in gm"<<endl;								
						cin>>n2;
						nn->veg[1]=n2;
						break;
					case 3:cout<<"Enter the amount of Carrots available in Kg"<<endl;								
						cin>>n3;
						nn->veg[2]=n3;	
						break;
					case 4:cout<<"Enter the amount of Onion available in Kg"<<endl;								
						cin>>n4;
						nn->veg[3]=n4;
						break;
					case 5:cout<<"Enter the amount of Coriandar available in bunches"<<endl;								
						cin>>n5;
						nn->veg[4]=n5;
						break;		
				}
                                     break;
		         case 2:cout<<"1.Mango\n2.Banana\n3.Orange\n4.Watermelon\n5.Apples\n"<<endl;
				cout<<"Enter your choice"<<endl;
				cin>>ch3;
				switch(ch3)
				{
					case 1:cout<<"Enter the amount of Mango available in dozen"<<endl;								
						cin>>m1;
						nn->fruit[0]=m1;
						break;
					case 2:cout<<"Enter the amount of Banana available in dozen"<<endl;								
						cin>>m2;
						nn->fruit[1]=m2;
						break;
					case 3:cout<<"Enter the amount of Orange available in dozen"<<endl;								
						cin>>m3;
						nn->fruit[2]=m3;	
						break;
					case 4:cout<<"Enter the amount of Watermelon available in Unit"<<endl;								
						cin>>m4;
						nn->fruit[3]=m4;
						break;
					case 5:cout<<"Enter the amount of Apples available in dozen"<<endl;								
						cin>>m5;
						nn->fruit[4]=m5;
						break;		
				}
                      break;

		}
    }while(ch1!=3);
   if(head1==NULL)
   {
   head1=nn;
   nn->next=NULL; 
   }
    else
   { 
     temp=head1;
     while(temp->next!=NULL)
     temp=temp->next;
     temp->next=nn;
     nn->next=NULL;
   }  
}

void displayf()
{
int i;
struct farmer*nn;
nn=head1;
while(nn!=NULL)
{
cout<<"Information about farmer is = "<<endl<<endl;
  cout<<"\n\tUser Id \tName    \t\tAddress    \t\tMoblie NO.    \t\t\tAdhar No.\t\n";
   cout<<"\n\t"<<nn->user_id<<" \t"<<nn->name<<"    \t\t"<<nn->add<<"    \t\t"<<nn->mobile<<"    \t\t"<<nn->aadhar<<"\t\n";
   cout<<"GOODS AVAILABLE OF FARMERS   :"<<endl<<endl;
  
 cout<<"\n\tFruit"<<endl<<endl;
   for(i=0;i<5;i++)
{
if(i==0)
      cout<<"Mango      ="<<nn->fruit[i]<<endl;
else if(i==1)
      cout<<"Banana     ="<<nn->fruit[i]<<endl;
else if(i==2)
      cout<<"Orange     ="<<nn->fruit[i]<<endl;
else if(i==3)
      cout<<"Watermelon ="<<nn->fruit[i]<<endl;
else if(i==4)
      cout<<"Apples     ="<<nn->fruit[i]<<endl;
 //cout<<"\t"<<nn->fruit[i]<<endl;
} 
  cout<<"\n\tVegetable"<<endl<<endl;
    for(i=0;i<5;i++)
{
 
if(i==0)
      cout<<"\n\tPotatoes  ="<<nn->veg[i]<<endl;
else if(i==1)
      cout<<"\n\tGingers   ="<<nn->veg[i]<<endl;
else if(i==2)
      cout<<"\n\tCarrots   ="<<nn->veg[i]<<endl;
else if(i==3)
      cout<<"\n\tOnion     ="<<nn->veg[i]<<endl;
else if(i==4)
      cout<<"\n\tCoriander ="<<"\t"<<nn->veg[i]<<endl;
// cout<<"\t"<<nn->veg[i]<<endl;
 }
     nn=nn->next;
     cout<<endl;
}
}


//functions for buyer login

void insertb()
{ 
int ch,ch1,ch2,ch3,user,n1,n2,n3,n4,n5,m1,m2,m3,m4,m5,i;

   struct buy *nn,*temp;
   nn=new buy;
   nn->user_id=nb;
    nb++;
   cout<<"Enter Name               :"<<endl;
   cin>>nn->name;
   cout<<"Enter Address            :"<<endl;
   cin>>nn->add;
   cout<<"Enter mobile            :"<<endl;
  for(i=0;i<10;i++)
  { 
   cin>>nn->mobile[i];
  }
  if(i!=10)
  {
    cout<<"\nInvalid Number.Please Enter Valid Number\n";
    cout<<"Enter mobile            :"<<endl;
  for(i=0;i<10;i++)
  { 
   cin>>nn->mobile[i];
  }
  } 
   cout<<"Enter Your aadhar number:"<<endl;
  for(i=0;i<15;i++)
  {
   cin>>nn->aadhar[i];
  }
   if(i!=15)
   {
   cout<<"Invalid Number.";
   cout<<"Enter Your aadhar number:"<<endl;
  for(i=0;i<15;i++)
  {
   cin>>nn->aadhar[i];
  }
   }
   for(i=0;i<5;i++) 
{
   nn->veg[i]=0;
   nn->fruit[i]=0;
}
do{
 cout<<"\n\t\t\t 1.Vegetable \n\t\t\t 2.Fruit \n\t\t\t 3.Exit\n"<<endl;
	   cout<<"Enter Your Choice"<<endl;
		cin>>ch1;
		switch(ch1)
		{
			case 1:cout<<"\n1.Potatoes\n2.Ginger\n3.Carrots\n4.Onion\n5.Coriander\n"<<endl;
				cout<<"Enter Your Choice"<<endl;
				cin>>ch2;
				switch(ch2)
				{
					case 1:cout<<"Enter the amount of Potatoes in Kg"<<endl;								
						cin>>n1;
						nn->veg[0]=n1;
						break;
					case 2:cout<<"Enter the amount of Ginger in Kg"<<endl;								
						cin>>n2;
						nn->veg[1]=n2;
						break;
					case 3:cout<<"Enter the amount of Carrots in Kg"<<endl;								
						cin>>n3;
						nn->veg[2]=n3;	
						break;
					case 4:cout<<"Enter the amount of Onion in Kg"<<endl;								
						cin>>n4;
						nn->veg[3]=n4;
						break;
					case 5:cout<<"Enter the amount of Coriander in Bunches"<<endl;								
						cin>>n5;
						nn->veg[4]=n5;
						break;		
				}
                                     break;
		         case 2:cout<<"\n1.Mango\n2.Banana\n3.Orange\n4.Watermelon\n5.Apples\n"<<endl;
				cout<<"Enter your choice"<<endl;
				cin>>ch3;
				switch(ch3)
				{
					case 1:cout<<"Enter the amount of Mango in Dozen"<<endl;								
						cin>>m1;
						nn->fruit[0]=m1;
						break;
					case 2:cout<<"Enter the amount of Banana in Dozen"<<endl;								
						cin>>m2;
						nn->fruit[1]=m2;
						break;
					case 3:cout<<"Enter the amount of Orange in Kg"<<endl;								
						cin>>m3;
						nn->fruit[2]=m3;	
						break;
					case 4:cout<<"Enter the amount of Watermelon in piece"<<endl;								
						cin>>m4;
						nn->fruit[3]=m4;
						break;
					case 5:cout<<"Enter the amount of Apples in Kg"<<endl;								
						cin>>m5;
						nn->fruit[4]=m5;
						break;		
				}
                      break;

		}
    }while(ch1!=3);
   if(head==NULL)
   {
   head=nn;
   nn->next=NULL; 
   }
    else
   { 
     temp=head;
     while(temp->next!=NULL)
     temp=temp->next;
     temp->next=nn;
     nn->next=NULL;
   }  
}
void displayb()
{
int i;
struct buy*nn;
nn=head;
while(nn!=NULL)
{
cout<<"Information of the Buyer is  "<<endl<<endl;

  cout<<"\n\tUser Id  Name    \t\tAddress    \t\tMoblie NO.    \t\t\tAdhar No.\t\n";
  cout<<"\n\t"<<nn->user_id<<"   "<<nn->name<<"    \t\t"<<nn->add<<"    \t\t"<<nn->mobile<<"    \t\t"<<nn->aadhar<<"\t\n";
   cout<<"GOODS AVAILABLE OF FARMERS   :"<<endl<<endl;
   cout<<"Requirment Of The Buyer's Are"<<endl<<endl;

   cout<<"\n\tFruit"<<endl<<endl;
   for(i=0;i<5;i++)
{
if(i==0)
      cout<<"\n\tMango      ="<<nn->fruit[i];
else if(i==1)
      cout<<"\n\tBanana     ="<<nn->fruit[i];
else if(i==2)
      cout<<"\n\tOrange     ="<<nn->fruit[i];
else if(i==3)
      cout<<"\n\tWatermelon ="<<nn->fruit[i];
else if(i==4)
      cout<<"\n\tApples     ="<<nn->fruit[i];

 //cout<<"\t"<<nn->fruit[i]<<endl;
} 
  cout<<"\n\tVegetable"<<endl<<endl;
    for(i=0;i<5;i++)
 {
if(i==0)
      cout<<"\n\tPotatoes  ="<<nn->veg[i];
else if(i==1)
      cout<<"\n\tGinger    ="<<nn->veg[i];
else if(i==2)
      cout<<"\n\tCarrots   ="<<nn->veg[i];
else if(i==3)
      cout<<"\n\tOnion     ="<<nn->veg[i];
else if(i==4)
      cout<<"\n\tCoriander ="<<nn->veg[i];
 //cout<<"\t"<<nn->veg[i]<<endl;
 }
     nn=nn->next;
     cout<<endl;
}
} 
void logic()
{
struct farmer *temp;
temp=head1;
int sv[5][4]={{18000,19000,25000,22000},{1500,1600,2000,1200},{4400,5400,3500,4500},{10000,15000,20000,18000},{2000,3500,4500,3400}};
int dv[5][4]={{4000,5000,7000,4000},{1500,1500,1800,1500},{4200,5300,4000,4500},{12000,13000,16000,18000},{1800,3000,4400,3200}};
int rsv[5][4];
int pv[5][4]={{15,15,14,18},{250,245,230,250},{32,31,32,35},{34,35,36,34},{10,12,11,12}};
int totalprice[10];
int stock[10];

int sf[5][4]={{8500,7900,9000,6500},{1800,1700,2000,1500},{4400,5400,3500,4500},{1000,1500,2000,1800},{8000,7500,9500,8400}};
int df[5][4]={{8500,8000,9100,6500},{1800,1500,1800,1500},{4200,5300,4000,4500},{1200,1300,1600,1800},{7800,7500,9400,8500}};
int pf[5][4]={{450,460,470,475},{25,26,23,22},{45,42,42,47},{80,85,81,75},{100,95,96,95}};
int key,i,j,k;
int rsf[5][4];

int demand[10];
int T[10];
for(i=0;i<10;i++)
{
  Tprice[i]=0;
  demand[i]=0;
  totalprice[i]=0;
  T[i]=0;
}

for(i=0;i<5;i++)
{
 for(j=0;j<4;j++)
{  
   rsv[i][j]=sv[i][j]-dv[i][j];
   demand[i]=dv[i][j]+demand[i];
   totalprice[i]=pv[i][j]+totalprice[i];//vegetable price calculation
}
}
for(i=5,j=0;i<10,j<5;i++,j++)
 {
 for(k=0;k<4;k++)
{
   rsf[j][k]=sf[j][k]-df[j][k];
   demand[i]=df[j][k]+demand[i];
   totalprice[i]=pf[j][k]+totalprice[i];//fruit price calculation
}
}
for(i=0;i<10;i++)
{
demand[i]=demand[i]/4;
totalprice[i]=totalprice[i]/4;
}
for(i=0;i<5;i++)
{
cout<<"Enter Todays Stock of "<<vegn[i]<<"  :";
cin>>stock[i];
}
for(i=5,j=0;i<10,j<5;i++,j++)
{

cout<<"Enter Todays Stock of "<<fruitn[j]<<"  :";
cin>>stock[i];

}

 for(i=0;i<10;i++)
{

T[i]=demand[i]-stock[i];


}

for(i=0;i<10;i++)
{
Tprice[i]=totalprice[i];
if(-1000<=T[i]<=1000)
{
Tprice[i]=totalprice[i];

}
 if(1000<=T[i]<=2000)
{
Tprice[i]=Tprice[i]+1;
}
 if(2000<=T[i]<=3000)
{
Tprice[i]=Tprice[i]+2;

}
 if(3000<=T[i]<=4000)
{ 
Tprice[i]=Tprice[i]+3;
}
if(4000<=T[i]<=5000)
{
Tprice[i]=Tprice[i]+5;
}
 if(5000<=T[i]<=6000)
{
Tprice[i]=Tprice[i]+6;
}
 if(6000<=T[i]<=7000)
{
Tprice[i]=Tprice[i]+7;
}
 if(7000<=T[i]<=8000)
{
Tprice[i]=Tprice[i]+9;
}
 if(8000<=T[i])
{
Tprice[i]=Tprice[i]+10;
}
if((-2000)<=T[i]<=(-1000))
{
Tprice[i]=Tprice[i]-1;
}
 if((-3000)<=T[i]<=(-2000))
{
Tprice[i]=Tprice[i]-2;
} if((-4000)<=T[i]<=(-3000))
{
Tprice[i]=Tprice[i]-3;
}
 if((-5000)<=T[i]<=(-4000))
{
Tprice[i]=Tprice[i]-4;
}
 if((-6000)<=T[i]<=(-5000))
{
Tprice[i]=Tprice[i]-5;
}
 if((-7000)<=T[i]<=(-6000))
{
Tprice[i]=Tprice[i]-7;
}
 if((-8000)<=T[i]<=(-7000))
{
Tprice[i]=Tprice[i]-8;
}
 if(T[i]<=(-8000))
{
Tprice[i]=Tprice[i]-9;
}


}
cout<<"\n";
cout<<"Today's Price \n";
cout<<"\tGoods            Price\n";
for(i=0;i<5;i++)
{
cout<<"\n\t"<<vegn[i]<<"   \t "<<Tprice[i]<<"\n\n";
} 
for(i=5,j=0;i<10,j<5;i++,j++)
{
cout<<"\n\t"<<fruitn[j]<<"   \t "<<Tprice[i]<<"\n\n";
} 
}

           
/*void middleman()
{

int i,j,k,l=0;
struct farmer *temp;
struct buy *t;
temp=head1;
t=head;

 while(temp!=NULL)
 {
  while(t!=NULL)
   {
    
    for(i=0;i<5;i++)
      {
    
       if(temp->veg[i]==t->veg[i])
         {
          temp->sellv[i]=t->veg[i];
           strcpy(temp->buyername[i],t->name); 
         }
      if(temp->veg[i]>=t->veg[i])
 	{  
       	  temp->veg[i]=temp->veg[i]-t->veg[i];
          temp->sellv[i]=t->veg[i];
           strcpy(temp->buyername[i],t->name);
         }
         if(temp->veg[i]<=t->veg[i])
         {
           t->veg[i]=t->veg[i]-temp->veg[i];
           temp->sellv[i]=t->veg[i];
            strcpy(temp->buyername[i],t->name);
         }
       }
   t=t->next; 
    }
for(i=0;i<5;i++)
//cout<<"SELL"<<temp->sellv[i]<<"\n";
  temp=temp->next;
 }
temp=head1;
while(temp!=NULL)
{
for(i=0;i<5;i++)
{
cout<<"\n\tSell  :"<<temp->sellv[i];
cout<<"\n\t";
cout<<"Buyername :"<<temp->buyername[i];
cout<<"\n\n";
 }
temp=temp->next;
}
}*/

void bill()
{ int i,j,topri=0,topri1=0,pt=0;
  struct farmer *temp;
  struct buy *t;
   temp=head1;
    t=head;
while(temp!=NULL)
{
   cout<<"\n-----------------User Id  "<<temp->user_id<<" Farmer Name :"<<temp->name<<"--------------------\n";
   cout<<"\n\tProduct Name   \t\t\tQuntity  \t\tPrice  \t\tTotal Price  ";
   for(i=0;i<5;i++)
{  topri=topri+(temp->veg[i]*Tprice[i]);
   pt=temp->veg[i]*Tprice[i];
   cout<<"\n\t"<<vegn[i]<<"  \t\t\t"<<temp->veg[i]<<"  \t\t"<<Tprice[i]<<"  \t\t"<<pt;
} 
  for(i=0,j=5;i<5,j<10;i++,j++)
 {
    topri=topri+(temp->fruit[i]*Tprice[j]);
    pt=temp->veg[i]*Tprice[j];
    cout<<"\n\t"<<fruitn[i]<<"  \t\t\t"<<temp->fruit[i]<<"  \t\t"<<Tprice[j]<<"  \t\t"<<pt;
}
  cout<<"\n\n\tTotal Price\t\t\t\t\t\t\t        "<<topri<<"\n";
temp=temp->next;
}


while(t!=NULL)
{
   cout<<"\n-----------------User Id "<<t->user_id<<" Buyer Name :"<<t->name<<"--------------------\n";
   cout<<"\n\tProduct Name    \t\t\tQuntity  \t\tPrice  \t\tTotal Price  ";
   for(i=0;i<5;i++)
{  topri1=topri1+(t->veg[i]*Tprice[i]);
   pt=t->veg[i]*Tprice[i];
   cout<<"\n\t"<<vegn[i]<<"    \t\t\t"<<t->veg[i]<<"  \t\t"<<Tprice[i]<<"  \t\t"<<pt;
} 
  for(i=0,j=5;i<5,j<10;i++,j++)
 {
    topri1=topri1+(t->fruit[i]*Tprice[j]);
    pt=t->veg[i]*Tprice[j];
  cout<<"\n\t"<<fruitn[i]<<"    \t\t\t"<<t->fruit[i]<<"  \t\t"<<Tprice[j]<<" \t\t"<<pt;
}
cout<<"\n\n\tTotal Price\t\t\t\t\t\t\t        "<<topri1;
cout<<"\n\n";  
t=t->next;
}

}


 int main()
 {
int ch,flag;
  char username[15];
  char password[25];
do {
  cout<<"1.Sign In\n";
  cout<<"2.Log  In\n";
  cout<<"Enter Choice :";
  cin>>ch;
 switch(ch)
 {
    case 1 : insert();
             break;
    case 2 :system("clear");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t USERNAME :";
            cin>>username;
            cout<<"\n\t\t\t\t\t\t\t PASSWORD :";
            cin>>password;
            flag=search(username,password);
        system("clear");
 if(flag==1)
   {
       cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO THE DAILY\n";
       cout<<"  \t\t\t\t\t\t   MARKET SYSTEM\n";           
      
   
   
             

           int chi,ch1,ch2,ch3,user,n1,n2,n3,n4,n5,m1,m2,m3,m4,m5;
  
do
{ 
  cout<<"\n1.Buyer login\n2.Farmer Login\n3.Display\n4.Middleman\n";
  cout<<"5.Exit \n";
  cout<<"Enter Choice :"<<endl;
  cin>>chi;
 switch(chi)
   {
    case 1 : cout<<"\n\tWelcome to Buyer Login "<<endl<<endl;    
		insertb();
		//displayb();
            break;
    
    case 2 : cout<<"\n\tWelcome to Farmer Login"<<endl<<endl;
		insertf();
		//displayf(); 
                break;
    case 3 :cout<<"\n\tBuyer Information   = "<<endl;
		displayb();
		cout<<endl<<endl;
            cout<<"\n\tFarmer Information  = "<<endl;
		displayf();
		cout<<endl<<endl;
                  break;  
    case 4: logic();
           // middleman();
            bill();
             break;
   }
}while(chi!=5);
return 0;
}
    else
       {
           cout<<"Invalid Username and Password Entered.\n";
           cout<<"Please Enter Valid Username and Password.\n";
             
        }
}
}while(ch!=3);
return  0;
}






 

