
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct person
{
    char code[20];
	char name[20];
	char date[20];
	int cost;
};

void addrecord();
void listrecord();
void deleterecord();
void searchrecord();
void deleterecord();
void bookticket();

int main()
{
    int choice;

        printf("\n\n\n\t\t**********WELCOME TO online movie ticket*************");

        getch();

        while(1)
        {
            system("cls");
            printf("\n\n\t\t\t  MENU\t\t\n\n");
            printf("\t1.Insert Movie Details.   \n\t2.View All Movie    \n\t3.Find Movie   \n\t4.Booking Movie Ticket   \n\t5.Delete Movie  \n\t6.Exit");
            printf("\n\nEnter your choice:");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1:addrecord();
                break;
                case 2: listrecord();
                break;
                case 3: searchrecord();
                break;
                case 4: bookticket();
                break;
                case 5: deleterecord();
                break;
                case 6: exit(0);
                break;
                default:
                            system("cls");
                            printf("\nEnter 1 to 6 only");
                            printf("\n Enter any key");
                    getch();
            }
        }

    return 0;
}

void addrecord()
{
        system("cls");
        FILE *f;
        struct person p;
        f=fopen("marjuk.pori","ab+");
        printf("\n Enter Code: ");
        fflush(stdin);
        gets(p.code);
        printf("\nEnter Name: ");
        fflush(stdin);
        gets(p.name);
        printf("\nEnter date: ");
        fflush(stdin);
        gets(p.date);
        printf("\nEnter cost:");
        scanf("%d",&p.cost);

        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);
        printf("\nrecord saved");

fclose(f);

    printf("\n\nEnter any key");

	 getch();
    system("cls");
}

void listrecord()
{
    system("cls");
    struct person p;
    FILE *f;
    f=fopen("marjuk.pori","rb");
    if(f==NULL)
    {
        printf("\nfile opening error in listing :");
        exit(1);
    }
    printf("\n\n\n YOUR RECORD IS\n\n ");
    while(fread(&p,sizeof(p),1,f)==1)
    {
         printf("\nCode=%s\nName=%s\nMovie Date=%s\nCost =%ld\n\n",p.code,p.name,p.date,p.cost);
    }
    fclose(f);
    printf("\n Enter any key");
    getch();
    system("cls");

}


void searchrecord()
{
    system("cls");
    struct person p;
FILE *f;
char code[100];

f=fopen("marjuk.pori","rb");
if(f==NULL)
{
    printf("\n error in opening\a\a\a\a");
    exit(1);

}
printf("\nEnter name of person to search\n");
fflush(stdin);
gets(code);
while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.code,code)==0)
    {
        printf("\n\tDetail Information About %s\n",code);
        printf("\nCode=%s\nName=%s\nMovie Date=%s\nCost =%ld\n\n",p.code,p.name,p.date,p.cost);
        break;
    }
        else
        {
            printf("file not found");
            system("cls");
        }

}
 fclose(f);
  printf("\n Enter any key");

	 getch();
    system("cls");
}

void deleterecord()
{
    struct person p;
	FILE *f,*t;
	char code[20];
	system("cls");
	f=fopen("marjuk.pori","rb");
	t=fopen("marjuk1.pori","wb");
	do{
	rewind(f);
	printf("Enter the phone number to be deleted from the Database:\n");
	fflush(stdin);
	gets(code);
	while(fread(&p,sizeof(p),1,f)==1)
	{
		if(strcmp(p.code,code)!=0)
		{
		    fwrite(&p,sizeof(p),1,t);
		}
		else
		printf("Record deleted successfully.");
	}

	fclose(f);
	fclose(t);
	remove("marjuk.pori");
	rename("marjuk1.pori","marjuk.pori");

	f=fopen("marjuk.pori","rb");
	t=fopen("marjuk1.pori","wb");
    printf("\nDo you want to delete another record (y/n):");
	fflush(stdin);
	  }
    	while(getche()=='y'||getche()=='Y');
		fclose(f);
	getch();
}


void bookticket()
{
	system("cls");
    struct person p;
	FILE *f;

	int total_seat,mobile,total_amount;
	char name[20];

	char ch;
	char code[20];



	printf("\n For Book ticket Choise Movie(Enter Movie Code) ::\n");
	printf("\n Enter movie code :");
	fflush(stdin);
	gets(code);
	system("cls");

	f = fopen("marjuk.pori","rb");
	if(f == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		while(fread(&p,sizeof(p),1,f)==1)
    {
        if(strcmp(p.code,code)==0)
        {
            printf("\n\tDetail Information About %s\n",code);
            printf("\nCode=%s\nName=%s\nMovie Date=%s\nCost =%ld\n\n",p.code,p.name,p.date,p.cost);
            break;
        }
            else
            {
                printf("file not found");
                system("cls");
            }

    }

	}

	printf("\n* Fill Deatails  *");
	printf("\nEnter Your name :");
    fflush(stdin);
	gets(name);
	printf("\n Mobile number :");
	scanf("%d",&mobile);
	printf("\n Total number of tickets :");
	scanf("%d",&total_seat);

	system("cls");

	total_amount = p.cost * total_seat;

	printf("\n ***** ENJOY MOVIE ****\n");
	printf("\n\t\tName : %s",name);
	printf("\n\t\tMobile Number : %d",mobile);
	printf("\n\t\tMovie name : %s",p.name);
	printf("\n\t\tTotal seats : %d",total_seat);
	printf("\n\t\tCost per ticket : %d",p.cost);
	printf("\n\t\tTotal Amount : %d",total_amount);



		printf("\n");

	fclose(f);
getch();
}
