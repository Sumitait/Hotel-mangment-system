#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<string.h> // Added for string functions

// Function prototypes
void add();
void list();
void edit();
void delete1();
void search();
void clearScreen();
int my_getch();
void my_flush();

// Global variable to store logged-in username
char loggedInUser[20] = "";

// Clear screen function for macOS
void clearScreen() {
    system("clear");
}

// getch() implementation for macOS
int my_getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// Flush input buffer
void my_flush() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct CustomerDetails {
    char roomnumber[10];
    char name[20];
    char address[25];
    char phonenumber[15]; // Changed to char array
    char nationality[15];
    char email[20];
    char period[10];
    char arrivaldate[10];
} s;

void login() {
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10];
    char user[10] = "luvs";
    char pass[10] = "10";
    
    do {
        clearScreen();
        printf("\n  **************************  LOGIN FORM  **************************  ");
        printf(" \n                       ENTER USERNAME: ");
        scanf("%s", uname);
        printf(" \n                       ENTER PASSWORD: ");
        my_flush(); // Clear input buffer
        
        i = 0;
        while (i < 9) { // Max 9 characters for password
            c = my_getch();
            if (c == '\n' || c == '\r') break;
            else if (c == 127) { // Handle backspace
                if (i > 0) {
                    i--;
                    printf("\b \b");
                }
            }
            else {
                pword[i] = c;
                printf("*");
                i++;
            }
        }
        pword[i] = '\0';
        
        if (strcmp(uname, user) == 0 && strcmp(pword, pass) == 0) {
            strcpy(loggedInUser, uname);
            printf("  \n\n\n       WELCOME %s !!!! LOGIN IS SUCCESSFUL", uname);
            sleep(2); // Pause for 2 seconds
            break;
        }
        else {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCCESSFUL");
            a++;
            printf("\nPress any key to continue...");
            my_getch();
        }
    } while (a <= 3);
    
    if (a > 3) {
        printf("\nSorry you have entered the wrong username and password for four times!!!");
        my_getch();
        exit(0);
    }
    clearScreen();
}

int main() {
    int i = 0;
    time_t t;
    time(&t);
    char choice;
    
    clearScreen();
    printf(" -------------------------------------------------------------------------\n");
    printf("|                                                                         |\n");
    printf("|  OOOOOO   OOOOOO OOOOOO OOOOOO OOOOOO OOOOOO O      O OOOOOOO  OOOOOO   |\n");
    printf("|  O        O    O O      O        O      O    O O    O O        O        |\n");
    printf("|  O  OOOOO OOOOOO OOOOO  OOOOO    O      O    O  O   O O  OOOOO OOOOOO   |\n");
    printf("|  O    O   O  O   O      O        O      O    O   O  O O    O        O   |\n");
    printf("|  OOOOOO   O   O  OOOOOO OOOOOO   O    OOOOOO O    O O OOOOOO   OOOOOO   |\n");
    printf("|                                                                         |\n");
    printf(" -------------------------------------------------------------------------\n");
    printf("\t\t****************************************************\n");
    printf("\t\t*                                                  *\n");
    printf("\t\t*       --------------------------------           *\n");
    printf("\t\t*        WELCOME TO HOTEL FORTUNE                 *\n");
    printf("\t\t*       --------------------------------           *\n");
    printf("\t\t*                                                  *\n");
    printf("\t\t*           macOS M1 Compatible Version           *\n");
    printf("\t\t*                                                  *\n");
    printf("\t\t*     CONTACT US: +91-XXXXXXXX, 8XXXXXXXXXX       *\n");
    printf("\t\t****************************************************\n\n\n");
    
    for (i = 0; i < 80; i++) printf("-");
    printf("\nCurrent date and time : %s", ctime(&t));
    for (i = 0; i < 80; i++) printf("-");
    printf(" \nPress any key to continue: ");
    my_getch();
    
    clearScreen();
    login();
    clearScreen();
    
    while (1) {
        clearScreen();
        for (i = 0; i < 80; i++) printf("-");
        printf("\n");
        printf("   ******************************  |MAIN MENU|  ***************************** \n");
        printf("\t\t\tUser: %s\n", loggedInUser);
        for (i = 0; i < 80; i++) printf("-");
        printf("\n");
        printf("\t\t *Please enter your choice for menu*:\n\n");
        printf(" \n Enter 1 -> Book a room");
        printf("\n------------------------");
        printf(" \n Enter 2 -> View Customer Record");
        printf("\n----------------------------------");
        printf(" \n Enter 3 -> Delete Customer Record");
        printf("\n-----------------------------------");
        printf(" \n Enter 4 -> Search Customer Record");
        printf("\n-----------------------------------");
        printf(" \n Enter 5 -> Edit Record");
        printf("\n-----------------------");
        printf(" \n Enter 6 -> Exit");
        printf("\n-----------------\n");
        for (i = 0; i < 80; i++) printf("-");
        printf("\nCurrent date and time : %s", ctime(&t));
        for (i = 0; i < 80; i++) printf("-");
        printf("\n");

        choice = my_getch();
        choice = toupper(choice);
        
        switch (choice) {
            case '1': add(); break;
            case '2': list(); break;
            case '3': delete1(); break;
            case '4': search(); break;
            case '5': edit(); break;
            case '6':
                clearScreen();
                printf("\n\n\t *****THANK YOU %s*****", loggedInUser);
                printf("\n\t Visit Again \n");
                exit(0);
                break;
            default:
                clearScreen();
                printf("Incorrect Input");
                printf("\nPress any key to continue");
                my_getch();
        }
    }
}

void add() {
    FILE *f;
    char test;
    f = fopen("add.txt", "a+");
    if (f == NULL) {
        f = fopen("add.txt", "w+");
        clearScreen();
        printf("Please hold on while we set our database in your computer!!");
        printf("\nProcess completed press any key to continue!! ");
        my_getch();
    }
    
    while (1) {
        clearScreen();
        printf("\n Enter Customer Details:");
        printf("\n**************************\n");
        printf("Enter Room number: ");
        scanf("%s", s.roomnumber);
        my_flush();
        
        printf("Enter Name: ");
        scanf("%s", s.name);
        my_flush();
        
        printf("Enter Address: ");
        scanf("%s", s.address);
        my_flush();
        
        printf("Enter Phone Number: ");
        scanf("%s", s.phonenumber);
        my_flush();
        
        printf("Enter Nationality: ");
        scanf("%s", s.nationality);
        my_flush();
        
        printf("Enter Email: ");
        scanf("%s", s.email);
        my_flush();
        
        printf("Enter Period ('x' days): ");
        scanf("%s", s.period);
        my_flush();
        
        printf("Enter Arrival date (dd/mm/yyyy): ");
        scanf("%s", s.arrivaldate);
        my_flush();
        
        fwrite(&s, sizeof(s), 1, f);
        printf("\n\n1 Room is successfully booked!!");
        printf("\nPress esc key to exit, any other key to add another customer detail: ");
        test = my_getch();
        if (test == 27) // ESC key
            break;
    }
    fclose(f);
}

void list() {
    FILE *f;
    int i;
    if ((f = fopen("add.txt", "r")) == NULL) {
        printf("No records found!");
        my_getch();
        return;
    }
    
    clearScreen();
    printf("ROOM    ");
    printf("NAME\t ");
    printf("\tADDRESS ");
    printf("\tPHONENUMBER ");
    printf("\tNATIONALITY ");
    printf("\tEMAIL ");
    printf("\t\t  PERIOD ");
    printf("\t ARRIVALDATE \n");
    
    for (i = 0; i < 118; i++) printf("-");
    printf("\n");
    
    while (fread(&s, sizeof(s), 1, f) == 1) {
        printf("%-8s %-15s %-15s %-15s %-10s %-20s %-10s %-12s\n", 
               s.roomnumber, s.name, s.address, s.phonenumber, 
               s.nationality, s.email, s.period, s.arrivaldate);
    }
    
    for (i = 0; i < 118; i++) printf("-");
    printf("\n");
    
    fclose(f);
    printf("\nPress any key to continue...");
    my_getch();
}

void delete1() {
    FILE *f, *t;
    int found = 0;
    char roomnumber[20];
    
    if ((t = fopen("temp.txt", "w")) == NULL) {
        printf("Error opening temporary file!");
        my_getch();
        return;
    }
    
    if ((f = fopen("add.txt", "r")) == NULL) {
        printf("No records found!");
        my_getch();
        return;
    }
    
    clearScreen();
    printf("Enter the Room Number of the customer to be deleted: ");
    scanf("%s", roomnumber);
    my_flush();
    
    while (fread(&s, sizeof(s), 1, f) == 1) {
        if (strcmp(s.roomnumber, roomnumber) == 0) {
            found = 1;
        } else {
            fwrite(&s, sizeof(s), 1, t);
        }
    }
    
    fclose(f);
    fclose(t);
    
    if (!found) {
        printf("\n\nRecords of Customer with Room number %s not found!!", roomnumber);
        remove("temp.txt");
    } else {
        remove("add.txt");
        rename("temp.txt", "add.txt");
        printf("\n\nThe Customer is successfully removed....");
    }
    
    my_getch();
}

void search() {
    FILE *f;
    char roomnumber[20];
    int found = 0;
    
    if ((f = fopen("add.txt", "r")) == NULL) {
        printf("No records found!");
        my_getch();
        return;
    }
    
    clearScreen();
    printf("Enter Room number of the customer to search: ");
    scanf("%s", roomnumber);
    my_flush();
    
    while (fread(&s, sizeof(s), 1, f) == 1) {
        if (strcmp(s.roomnumber, roomnumber) == 0) {
            found = 1;
            printf("\n\tRecord Found\n ");
            printf("\nRoom Number:\t%s", s.roomnumber);
            printf("\nName:\t%s", s.name);
            printf("\nAddress:\t%s", s.address);
            printf("\nPhone number:\t%s", s.phonenumber);
            printf("\nNationality:\t%s", s.nationality);
            printf("\nEmail:\t%s", s.email);
            printf("\nPeriod:\t%s", s.period);
            printf("\nArrival date:\t%s", s.arrivaldate);
            break;
        }
    }
    
    if (!found) {
        printf("\n\tRequested Customer could not be found!");
    }
    
    fclose(f);
    printf("\n\nPress any key to continue...");
    my_getch();
}

void edit() {
    FILE *f;
    char roomnumber[20];
    long pos;
    int found = 0;
    
    if ((f = fopen("add.txt", "r+")) == NULL) {
        printf("No records found!");
        my_getch();
        return;
    }
    
    clearScreen();
    printf("Enter Room number of the customer to edit: ");
    scanf("%s", roomnumber);
    my_flush();
    
    while (fread(&s, sizeof(s), 1, f) == 1) {
        if (strcmp(s.roomnumber, roomnumber) == 0) {
            found = 1;
            printf("\nEnter new details for room %s:\n", roomnumber);
            printf("-------------------------------\n");
            
            printf("Name [%s]: ", s.name);
            scanf("%s", s.name);
            my_flush();
            
            printf("Address [%s]: ", s.address);
            scanf("%s", s.address);
            my_flush();
            
            printf("Phone Number [%s]: ", s.phonenumber);
            scanf("%s", s.phonenumber);
            my_flush();
            
            printf("Nationality [%s]: ", s.nationality);
            scanf("%s", s.nationality);
            my_flush();
            
            printf("Email [%s]: ", s.email);
            scanf("%s", s.email);
            my_flush();
            
            printf("Period [%s]: ", s.period);
            scanf("%s", s.period);
            my_flush();
            
            printf("Arrival Date [%s]: ", s.arrivaldate);
            scanf("%s", s.arrivaldate);
            my_flush();
            
            // Move back to the beginning of the record
            fseek(f, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, f);
            break;
        }
    }
    
    fclose(f);
    
    if (found) {
        printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
    } else {
        printf("\n\n\tTHE RECORD DOESN'T EXIST!!!!");
    }
    
    my_getch();
}
