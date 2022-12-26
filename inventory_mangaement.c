#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int add_product();
int delete_product();
void display_product();
void modify_product();
void inventory();

struct node
{   
    int product_no;
    char product_name[10];
    int no_of_product;
    struct node *next;
};
struct node *head;

int main()
{
    int pass;
    printf("\n\n\n*_*     '''WELCOME'''     *_*\n");
    printf("\n\n\nINVENTORY MANAGEMENT\n");
    printf("\n\nHII USER ,YOU REQUIRE A PASSWORD TO GET ACCESS TO THIS PROJECT\n");
    printf("\nGIVE A TRY *_* :");
    scanf("%d", &pass);
    if (pass == 560103)
    {
        inventory();
    }
    else
    {
        printf("clue :New horizon college of Engineering\n");
        printf("clue 2:Pincode of This Location\n");
        printf("GIVE A TRY NOW !!!!");
        printf("ENTER PASSWORD::");
        scanf("%d", &pass);
        if (pass == 560103)
        {
            inventory();
        }
        else
        {
            printf("SORRY YOUR CHANCE IS OVER ,YOU CANNOT ACCESS TO THIS PROJECT\n");
        }
    }
    return 0;
}

void inventory()
{
    char ch;
    int choice, i, get;
    do
    {
        printf("\n\n\n\t\t\t\t\t");
        printf("\nInventory Management System\n");
        printf("\n\n\t\tSELECT YOUR CHOICE.........\n\n\t\t\t\t\t1=ADD PRODUCT\n\t\t\t\t\t2=DELETE PRODUCT\n\t\t\t\t\t3=DISPLAY PRODUCT \n\t\t\t\t\t4= MODIFY PRODUCT\n\t\t\t\t\t5=Exit\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            get = add_product();
            break;
        case 2:
           get = delete_product();
            break;
        case 3:
            display_product();
            break;
        case 4:
            modify_product();
            break;
        case 5:
            break;
        default:
            printf("\nINVALID CHOICE ,PLEASE SELECT CORRECT OPTION\n");
        }

    } while (choice != 5);
    printf("\n\n\n\t\t\t*_* THANK YOU *_*\n");
    printf("\n\n\n\t\t\t\t\t\t''PROJECT DONE BY -- MANIKANTA P,USN--1NH20CS125\n");
    printf("\t\t\t\t\t\tHAVE A GOOD DAY\n");
    printf("\n\n\n\t\t\t*_* *_* *_* *_* *_* *_* *_* *_*\n");

    
    getch();
}

int add_product()
{
    struct node *temp;
    struct node *p;
    int choice;
    int pos = 0;
    int count = 0;
    char product[30];
    p = head;
    do
    {
        struct node *p, *temp;
        p = head;
        printf("\n\n\t\tSELECT YOUR CHOICE.........\n\n\t\t\t\t\t1=ADD AT FIRST\n\t\t\t\t\t2=ADD AT LAST\n\t\t\t\t\t3=ADD IN BETWEEN\n\t\t\t\t\t5=Exit\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (head == NULL)
            {   printf("LIST IS EMPTY");
                temp = (struct node *)malloc(sizeof(struct node));
                printf("\nENTER PRODUCT NUMBER:#");
                scanf("%d", &temp->product_no);
                printf("\nENTER PRODUCT NAME--");
                scanf("%s", &temp->product_name);
                printf("\nENTER NO OF PRODUCTS COUNT:#");
                scanf("%d", &temp->no_of_product);
                head = temp;
                temp->next = NULL;
                printf("\n\t\t ......INVENTORY HAS OPENED AND THE PRODUCT IS ADDED......\n");
                break;
            }
            else
            {
                temp = (struct node *)malloc(sizeof(struct node));
                printf("\nENTER PRODUCT NUMBER:#");
                scanf("%d", &temp->product_no);
                printf("\nENTER PRODUCT NAME--");
                scanf("%s", &temp->product_name);
                printf("\nENTER NO OF PRODUCTS COUNT:#");
                scanf("%d", &temp->no_of_product);
                temp->next = head;
                head = temp;
                printf("\n\t\t ......THE PRODUCT IS ADDED AT FIRST PLACE SUCCESSFULLY......\n");
                break;
            }
        case 2:
            if (head == NULL)
            {
                temp = (struct node *)malloc(sizeof(struct node));
                printf("\nENTER PRODUCT NUMBER:#");
                scanf("%d", &temp->product_no);
                printf("\nENTER PRODUCT NAME--");
                scanf("%s", &temp->product_name);
                printf("\nENTER NO OF PRODUCTS COUNT:#");
                scanf("%d", &temp->no_of_product);
                head = temp;
                temp->next = NULL;
                printf("\n\t\t ......INVENTORY HAS OPENED AND THE PRODUCT IS ADDED......\n");
                break;
            }
            else
            {
                while (p->next != NULL)
                {
                    p = p->next;
                }
                temp = (struct node *)malloc(sizeof(struct node));
                printf("\nENTER PRODUCT NUMBER:#");
                scanf("%d", &temp->product_no);
                printf("\nENTER PRODUCT NAME--");
                scanf("%s", &temp->product_name);
                printf("\nENTER NO OF PRODUCTS COUNT:#");
                scanf("%d", &temp->no_of_product);
                p->next = temp;
                temp->next = NULL;
                printf("\n\t\t ......THE PRODUCT IS ADDED AT LAST SUCCESSFULLY......\n");
            }
            break;

        case 3:
            printf("\n\tENTER THE POSITION,THAT YOU WISH TO ADD AT =");
            scanf("%d", &pos);
            while (p != NULL)
            {
                count += 1;
                if ((count + 1) == pos)
                {
                    temp = (struct node *)malloc(sizeof(struct node));
                    printf("\nENTER PRODUCT NUMBER:#");
                    scanf("%d", &temp->product_no);
                    printf("\nENTER PRODUCT NAME--");
                    scanf("%s", &temp->product_name);
                    printf("\nENTER NO OF PRODUCTS COUNT:#");
                    scanf("%d", &temp->no_of_product);
                    temp->next = p->next;
                    p->next = temp;
                    printf("\n\t\t ......PRODUCT ADDED SUCCESSFULLY......\n");
                    getch();
                }
                p = p->next;
            }
            break;
        }
    }while (choice != 5);
} 

void display_product()                                                                                //function to view the data
{
  struct node *p;
  p = head;
  if (p == NULL)
  {
    printf("\n\t\t.... INVENTORY IS EMPTY....\n\t\t....ADD PRODUCT TO SEE THE INVENTORY....\n");
    return;
  }
  printf("\t\t\t******************INVENTORY MANAGEMENT SYSTEM*********************");
  printf("\n---------------------------------------------------------------\n");
  printf("Product Number | Product Name | Product count");
  printf("\n---------------------------------------------------------------\n");
  while (p != NULL)
  {
    printf("%d",p->product_no);
    printf("\t\t%s",p->product_name);
    printf("\t       %d",p->no_of_product);
    printf("\n");
    
    p = p->next;
  }
}

int delete_product() // funtion to delete the data
{
    int choice = 0, count = 0;
    char product[30];
    do
    {
        struct node *p, *temp;

        if (head == NULL)
        {
            printf("\n\t\t.... INVENTORY IS EMPTY....\n\t\t....ADD PRODUCT TO DELETE THE PRODUCTS IN INVENTORY....\n");
            return 0;
        }
        p = head;
        printf("\n\n\t\tSELECT YOUR CHOICE.........\n\n\t\t\t\t\t1=DELETE AT FIRST\n\t\t\t\t\t 2=DELETE AT LAST\n\t\t\t\t\t 3=DELETE IN BETWEEN\n\t\t\t\t\t 5=Exit\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:temp = head;
            head = temp->next;
            free(temp);
            printf("\n\t\t....FIRST PRODUCT INFO DELETED....\n");
            break;
        case 2:
            if (head->next == NULL)
            {
            temp = head;
            head = temp->next;
            free(temp);
            printf("\n\t\t....FIRST PRODUCT INFO DELETED....\n");
            break;
            }
            while (p->next->next != NULL)
               {
                    p = p->next;
               }
            temp = p->next;
            p->next = NULL;
            free(temp);
            printf("\n\t\t....PRODUCT INFO DELETED...\n");
            break;
        case 3:
            printf("\nENTER THE PRODUCT TO BE DELETED=");
            scanf("%s", product);
            if (strcmp(head->product_name, product) == 0)
            {
            temp = head;
            head = temp->next;
            free(temp);
            printf("\n\t\t....FIRST PRODUCT INFO DELETED....\n");
            break;
            }
            while (p->next != NULL)
            {
                if (strcmp(p->next->product_name, product) == 0)
                {
                    count = 1;
                    temp = p->next;
                    p->next = temp->next;
                    free(temp);
                    printf("\n\t\t....PRODUCT %s IS REMOVED FROM INVENTORY....\n", product);
                    break;
                }
                p = p->next;
            }
            if (count == 0)
                printf("\n\t\t.....NOT FOUND....\n");
            break;
        }
    } while (choice != 5);
    return 0;
}
void modify_product()                                                                                           //function to modify the data
{ struct node *p, *temp;
  int count=0, choice;
  char ch[20];
  p=head;
  if(head==NULL)
   { printf("\n\t\t.... INVENTORY IS EMPTY....\n\t\t....ADD PRODUCT TO MODIFY....\n");
     getch();
     return;
   }
  printf("\n\t\t\tENTER THE PRODUCT NAME ,THAT YOU WISH TO EDIT\n");
  scanf("%s",&ch);
  while(p!=NULL)
   {  if(strcmp(p->product_name,ch)==0)
      { count=1;
        printf("\n\t\t\t\t1.EDIT PRODUCT NAME\n\t\t\t\t2.EDIT PRODUCT NUMBER\n\t\t\t\t3.EDIT PRODUCT COUNT\n\t\t\t\t4.EDIT ALL PRODUCT DETAILS\n\t\t\t\t5.EXIT");
        scanf("%d",&choice);
        switch(choice)
        {case 1:printf("\n ENTER NEW PRODUCT NAME:");
                scanf("%s",&p->product_name);
                break;
         case 2:printf("\nENTER NEW PRODUCT NO#:");
                scanf("%d",&p->product_no);
                break;
        case 3:printf("\nENTER NEW NO OF PRODUCTS COUNT#:");
                scanf("%d",&p->no_of_product);
                break;
        
        case 4: printf("\n ENTER NEW PRODUCT NAME:");
                scanf("%s",&p->product_name);
                printf("\nENTER NEW PRODUCT NO:#");
                scanf("%d",&p->product_no);
                printf("\nENTER NEW NO OF PRODUCTS COUNT#:");
                scanf("%d",&p->no_of_product);
                
               
                break;  
         case 5:break;
         default:printf("\n\nINVALID CHOICE !!!!!"); 
        } 
        printf("\n\t\t\t\t...SUCCESSFULLY MODIFIED...\n");     
      }  
    p=p->next;
    }
  getch();
  if(count==0)
  { printf("\t\t.....NOT FOUND.....\n");
    getch();
  }
} 