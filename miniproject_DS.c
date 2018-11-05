#define CAPACITY 10
#define size1 10
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct pair{
	char tele_no[20] ;
	char tele_no_2[20];
	char occupation[50];
	char income[15];
	int age;
	char address[100];
	char name[50];
	long id;
	char pass[30];
	struct pair *next;
};
void display_all(struct pair* hash[], int size)
{
	int i;
	printf("\t Key\tValues\n");
	for(i=0;i<size;i++)
	{
		struct pair *ptr;
		printf("%d\t%ld",i,hash[i]->id);
		ptr=hash[i]->next;
		while(ptr!=NULL)
		{
		printf("-->%ld",ptr->id);
		ptr=ptr->next;
		}
	printf("\n\n");
	}
}
long generate()
{
	long x=rand()%900000+100000;
	return x;
}
void insert(struct pair* hash[], int size)
{
    int c;
  	struct pair *kvpair;
  	kvpair= (struct pair*)malloc(sizeof(struct pair));

  	kvpair->next=NULL;
	printf("\t Enter the name ::");
	scanf("%s",kvpair->name);
	//scanf("%d", &c);
	//printf("%s",kvpair->name);

	printf("\t Enter the age ::" );
	scanf("%d",&kvpair->age);
	//scanf("%d", &c);
	//printf("%d",kvpair->age);

	printf("\t Enter current address ::" );
	scanf("%s",kvpair->address);
	//scanf("%d", &c);
	//printf("%s",kvpair->address);

	printf("\t Enter tele_no ::" );
	scanf("%s",kvpair->tele_no);
	//scanf("%d", &c);
	//printf("%s",kvpair->tele_no);

	printf("\t Enter tele_no_2 ::" );
	scanf("%s",kvpair->tele_no_2);
	//scanf("%d", &c);
	//printf("%s",kvpair->tele_no_2);//printf("%d",c);

	printf("\t Enter your occupation ::" );
	scanf("%s",kvpair->occupation);
	//scanf("%d", &c);
	//printf("%s",kvpair->occupation);
	//printf("%d",c);
	printf("\t Enter your income ::" );
	scanf("%s",kvpair->income);
	//scanf("%d", &c);
	//printf("%s",kvpair->income);
	//printf("%d",c);
	printf("\t Enter your secure password ::" );
	scanf("%s",kvpair->pass);
	//scanf("%d", &c);
	//printf("%s",kvpair->pass);//printf("%d",c);


	long id=generate();
	kvpair->id = id;
	printf("\n\n\t Your unique ID is %ld\n",id);
	if(hash[id%size]==NULL)
 	hash[id%size]=kvpair;
	else
	{
  		if(hash[id%size]->next==NULL)
  		hash[id%size]->next=kvpair;
  	    else
  		{
  		struct pair *temp=(struct pair*)malloc(sizeof(struct pair *));
    	temp= hash[id%size]->next;
   		 while (temp->next!=NULL)
      		temp=temp->next;

		temp->next=kvpair;
	}
    }
}
void access_table(struct pair* hash[], int size)
{
	int f=0;
	long ID;
	char pw[100];
	printf("\t Enter ID\t" );
	scanf("%ld",&ID);
	
	//gets(pw);
  	struct pair *temp=(struct pair*)malloc(sizeof(struct pair));
  	temp=hash[ID%10];
  	//printf("%s, %s\n ", pw, temp->pass);
  	while(temp!=NULL)
  	{   //printf("sdf");
  		if((temp->id==ID))
		{	printf("\t Enter password\t");
		 scanf("%s",pw);	
			if((strcmp(pw,temp->pass)==0))
			{	
				printf("\t________________________________________________\n");
				printf("\t------------------------------------------------\n");
				printf("\t Your data has been found\n\n");
  				printf("\t Name :: %s\n",temp->name);
  				printf("\t Age :: %d\n",temp->age);
  				printf("\t Address :: %s \n",temp->address);			//print data
  				printf("\t telephone :: %s\n",temp->tele_no);
  				printf("\t telephone no 2 :: %s \n",temp->tele_no_2);
  				printf("\t occupation :: %s\n",temp->occupation);
  				printf("\t income :: %s\n",temp->income);
  				printf("\t________________________________________________\n");
				printf("\t ------------------------------------------------\n");

  			    f=1;
  			    break;
			}
			else
			{
				printf("\n\t Incorrect password. Please try again\n"); 
				f = 1;
			}
  		}
		temp=temp->next;
		
  	}
	
  	if (f==0)
  	{
  		printf("\n\t Invalid ID. Please Register Yourself first !\n");
  	}
}

void introduction()
{	
	printf("\t\t\t\t   -------------------------------------------- \n");
	printf("\t\t\t\t   -------------------------------------------- ");
	printf("\n\n\t\t\t\t   Welcome to Unique identification profiles !! \n");
	printf("\t\t\t\t   --------------------------------------------\n");
	printf("\t\t\t\t   --------------------------------------------\n\n");
	//printf("\t\t\t   Enter the operation u want to perform\n");

	printf("\t 1. Register - Enter all required details as asked in our database (Create a strong password)\n");
	printf("\t    The password you enter is the second level of security provided by our application to guard your info\n");
	printf("\t    Once your details have been entered, we provide you with your own 6 digit unique id. \n");
	printf("\t    While accessing your data, this unique code serves as the first level of security. \n");
	printf("\t    Once your details have been entered, we provide you with your own 6 digit unique id. \n\n");

	printf("\t 2. Access - Enter the unique identification id provided by our application \n");
	printf("\t    Next enter the password created by you\n");
	printf("\t    Once your details have been entered, we provide you with your details \n");

}

void credits()
{
	printf("\t ________________________________________________________________________________________\n");
	printf("\t ----------------------------------------------------------------------------------------\n\n");
	printf("\t Thank you for using our application  \n\n");

	printf("\t Data structure project\n");
	printf("\t A Hashtable has been used in this project\n");
	printf("\t Concepts of hashing and avoiding collisions have been implemented successfully\n");

	printf("\t CREATED BY\n\n");
	printf("\t -Aniruddha Das (60004170011)\n\n");
	printf("\t -Aniket Shahane (60004170010)\n\n");
	printf("\t -Arish Damania (60004170013)\n\n");
	printf("\t  ________________________________________________________________________________________\n");
	printf("\t  ----------------------------------------------------------------------------------------\n");

}

void main()
{
 int i, j=0, size, temp, pwd, val;
 struct pair* hash_table[CAPACITY];
 size=CAPACITY;
 for(int i=0;i<size;i++)
 	hash_table[i]=NULL;
 int c=-1;
 introduction();
 while(c!=3)
	 {	    printf("\n");
	 		//printf("\t --------------------------------------------------------------------------------");
	 		printf("\n\n\t 1)Register\n\t 2)Access data\n\t 3)Exit\n\t ");
			scanf("%d",&c );
	 		switch (c)
	 		{
	 				case 1: insert(hash_table,size);
							break;
					case 2: //printf("%s",hash_table[0]->pass);
			 				access_table(hash_table, size);
			 				break;
			 		case 3: break;
	 		}
	 }
//display_all(hash_table, size);
// uncomment the above lines for admin access to all the registered aadhars
credits();
}


