#include<stdio.h>

struct smart_card
{
    char number[13];
    int amount;
};
struct Ticket
{
    char name[25];
    int age;
    char contact[11];
    int start;
    int dest;
    struct Ticket* next;
}*first_ticket=NULL;
struct smart_card sc[10];
int top_sc =-1;
void display_sc()
{
    if(top_sc==-1)
        printf("NO EXISTING CARDS STORED\n");
    else
    {
        for(int i=0;i<=top_sc;i++)
            printf("%d : %s\n",i+1,(sc+i)->number);

    }
}
void smart_card_used()
{
    int card_no,amt;
    char otp[6];
    printf("USED CARDS\n");
    display_sc();
    if(top_sc==-1)
        {
           printf("No used cards to recharge\n");
        }
    else{
    printf("Enter the card serial number you want to use\n");
    scanf("%d",&card_no);
    card_no-=1;
    if(card_no<=top_sc){
    printf("Enter the amount to recharge:\n");
    scanf("%d",&amt);
    (sc+card_no)->amount+=amt;
    printf("ENTER THE OTP: ");
    scanf("%s",otp);
    printf("Transaction Successful\n");
    }
    else{
        printf("CARD NOT VALID\n");
    }
    }
}
void smart_card_new()
{
    char otp[6];
    if(top_sc==9){
        top_sc=-1;
    }
    else
    top_sc++;
    printf("Enter the card number \nNOTE: Do not include spaces\n");
    scanf("%s",(sc+top_sc)->number);
    printf("Enter the amount to recharge:\n");
    scanf("%d",&(sc+top_sc)->amount);
    printf("ENTER THE OTP: ");
    scanf("%s",otp);
    printf("Transaction Successful\n");
}
void smart_card_check()
{
    int card_no;
    printf("SMART CARDS\n");
    display_sc();
    if(top_sc==-1){
        printf("No cards to check balance\n");
        }
    else{
    printf("Enter the card serial number you want to use\n");
    scanf("%d",&card_no);
    card_no-=1;
    if(card_no<=top_sc){
    printf("AMOUNT IN CARD %s: Rs.%d\n",(sc+card_no)->number,(sc+card_no)->amount);
    printf("Transaction Successful\n");
    }
    else 
        printf("CARD NOT VALID\n");
    }
}
void smart_card_recharge()
{
    char cho;
    printf("SMART CARD BOOKING PORTAL\n");
    do
    {
    printf("Press 'o' to recharge already used cards\n");
    printf("Press 'n' to add a new card\n");
    printf("Press 'c' to check amount in the card\n");
    printf("Press 'e' to exit\n");
    printf("Enter your choice: ");
    fflush(stdin);
    scanf(" %c",&cho);
    switch(cho)
    {
        case 'o':
            smart_card_used();
            cho='e';
            break;
        case 'n':
            smart_card_new();
            cho='e';
            break;
        case 'c':
            smart_card_check();
            cho='e';
            break;
        default:
            printf("Smart Card Portal Exiting\n");
            cho='e';
    }
    }while(cho!='e');
}
void get_data(struct Ticket * t)
{
    struct Ticket *temp;
    temp = t;
    while(temp!=NULL)
    {
        printf("Enter the name of the passenger: ");
        scanf("%s",temp->name);
        printf("Enter the contact number of the passenger: ");
        scanf("%s",temp->contact);
        printf("Enter the age of the passenger: ");
        scanf("%d",&temp->age);
        printf("Enter the starting Station: ");
        scanf("%d",&temp->start);
        printf("Enter the destination: ");
        scanf("%d",&temp->dest);
        temp=temp->next;
        printf("\n");
    }
}
void dis_tickets(struct Ticket * t)
{
    struct Ticket *temp;
    temp = t;
     while(temp!=NULL)
    {
        printf("-------------------------------------------\n");
        printf("HYDERABAD METRO TICKET\n");
        printf("PASSENGER NAME: %s",temp->name);
        printf("PASSENGER AGE: %s",temp->age);
        printf("PASSENGER contact no.: %s",temp->contact);
        // printf("STARTING STATION: %s",temp->name); print starting and destination stations using graphs
        // printf("DESTINATION STATION: %s",temp->name);
        printf("-------------------------------------------\n");
    }
}
int main()
{
    int ch;
    printf("*********************************************************\n");
    printf("HYDERABAD METRO TICKET BOOKING SERVICE\n");
     printf("*********************************************************\n");
     do
     {
    printf("1.Book Ticket\n2.Station Enquiry\n3.Cost Enquiry\n4.View Booked Tickets\n5.View Train Schedule\n6.Exit");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        //BOOK TICKET
        break;
        case 2:
        //STATIONS
        break;
        case 3:
        //COST ENQUIRY
        break;
        case 4:
        //VIEW BOOKED TICKETS
        break;
        case 5:
        //SMART CARD RECHARGE
        break;
        case 6:
        printf("\nTHANK YOU FOR USING HYDERABAD METRO SERVICE\n");
        break;
        default:
            printf("ENTER A VALID QUERY (1/2/3/4/5/6)\n");
    }
     }while(ch!=6);
    return 0;
}