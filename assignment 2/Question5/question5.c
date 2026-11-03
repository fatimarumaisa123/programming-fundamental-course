/**
 * Programmer: Rumaisa fatima
 * Program: library management system
 */
#include <stdio.h>
#include <string.h>   
void displayMenu()//displays menu
{
    printf("1. register member\n");
    printf("2. display available books\n");
    printf("3. borrow a book\n");
    printf("4. return a book\n");
    printf("5. display member record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}


void registerMember(char name[], int *studentID, int *memberType)//takes members details
{
    printf("Enter name: ");
    scanf(" %49[^\n]", name); 
    printf("Enter studentid: ");
    scanf("%d", studentID);
    do//validity check for membership type
    {
        printf("Membership type (1 = Student, 2 = Faculty): ");
        scanf("%d", memberType);
        if (*memberType != 1 && *memberType != 2)
        {
            printf("Invalid membership type try again\n");
        }
    } while (*memberType !=1 && *memberType !=2);//end loop

    printf("Registration successful.\n");
}

void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks)//print boks in the table
{
    int i;
    printf("id .    title           .      copies\n");
    for (i=0; i<totalBooks; i++)//for to print book details
    {
        printf("%-6d %-25s %-6d\n", bookIDs[i], bookTitles[i], availableCopies[i]);
    }//end for
}
void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks,
                int borrowedBookIDs[], int *borrowedCount, int memberType)//to borrow a bok
{
    int id, days, i;
    int index = -1;//if book is not found basically a bogus or garbage value
    int allowedDays;
    if (*borrowedCount >= 3)//checking the limit of 3 
    {
        printf("You already have 3 books. Return one before borrowing another.\n");
        return;//get out of the function as max limit reached for book borrowing
    }

    printf("Enter book id: ");
    scanf("%d", &id);
    for (i = 0; i < totalBooks; i++)//searching for the book id
    {
        if (bookIDs[i] == id) //if book id found
            index = i;
    }

    if (index == -1)//if book id not found
    {
        printf("Invalid book ID.\n");
        return;//get out of the function as book not found
    }

    if (availableCopies[index] == 0)//if o copies are left
    {
        printf("Sorry, no copies of %s are available.\n", bookTitles[index]);
        return;//get out of the function as no copies left to borrow
    }

    printf("Number of days you want to keep the book: ");
    scanf("%d", &days);

    if (days<=0)//days input validity check
    {
        printf("Number of days must be positive.\n");
        return;
    }
    if (memberType == 1)
    {
        allowedDays = 14; //students allowed to borrow for 14 days
    }
    else
    {
        allowedDays = 30; // faculty allowed to borrow for 30 days
    }

    if (days>allowedDays)
    {
        printf("Note: your limit is %d days. A fine applies after that.\n", allowedDays);
    }
    borrowedBookIDs[*borrowedCount] = id;
    (*borrowedCount)++;
    availableCopies[index]--;

    printf("You borrowed \"%s\".\n", bookTitles[index]);
}


float returnBook(int bookIDs[], int availableCopies[], int totalBooks,
                 int borrowedBookIDs[], int *borrowedCount, int memberType, float *totalFine)//to return a book
{
    int id, days, i;
    int bookIndex = -1;//position of the book in the inventory 
    int borrowPos = -1;//position of the book in the borrowed list 
    int allowedDays, extraDays, rate;
    float fine = 0;
    char code[20];

    printf("Enter book ID to return: ");
    scanf("%d", &id);

    /* Check that the member really borrowed this book */
    for (i = 0; i < *borrowedCount; i++) // Checking if the member borrowed the book
    {
        if (borrowedBookIDs[i] == id)
        {
            borrowPos = i;
        }
    }
    if (borrowPos == -1)
    {
        printf("You have not borrowed this book.\n");
        return 0;
    }

    printf("Number of days the book was kept: ");
    scanf("%d", &days);

    if (days <= 0)//days validity check
    {
        printf("Number of days must be positive.\n");
        return 0;
    }
    for (i = 0; i < totalBooks; i++)//checking and adding the book back in the inventory
    {
        if (bookIDs[i] == id)
        {
            bookIndex = i;
        }
    }
    availableCopies[bookIndex]++;
    if (memberType == 1)
    {
        allowedDays = 14;
        rate = 20;//20 fine for each extra day
    }
    else
    {
        allowedDays = 30;
        rate = 10;// 10 for each extra day
    }
    if (days > allowedDays)//calculating late fine
    {
        extraDays = days - allowedDays;
        fine = extraDays * rate;
        printf("Late return! %d extra days. Fine: Rs. %.2f\n", extraDays, fine);
       *totalFine = *totalFine + fine;
        printf("Enter membership code (or any text to skip): ");
        scanf("%19s", code);

        if (strcmp(code, "LIB2026") == 0) //if code is same
        {
            fine = fine / 2; // 50 % off on the fine
            printf("Correct code! 50%% waiver applied. Fine payable: Rs. %.2f\n", fine);
        }
        else
        {
            printf("Wrong code. No waiver. Fine payable: Rs. %.2f\n", fine);
        }
    }
    else
    {
        printf("Returned on time. No fine.\n");
    }
    for (i = borrowPos; i < *borrowedCount - 1; i++) // Remove the book from the borrowed list by shifting the rest to the left 
    {
        borrowedBookIDs[i] = borrowedBookIDs[i+1];
    }
    (*borrowedCount)--;

    return fine;
}

void displayMemberRecord(char name[], int studentID, int memberType,
                         int borrowedBookIDs[], int borrowedCount,
                         float totalFine, float fineAfterWaiver)//to show member record
{
    int i;

    printf("\n===== MEMBER RECORD =====\n");
    printf("Name: %s\n", name);
    printf("Student ID: %d\n", studentID);

    if (memberType == 1)
    {
        printf("Member type: Student\n");
    }
    else
    {
        printf("Member type: Faculty\n");
    }

    printf("Currently borrowed books: ");
    if (borrowedCount == 0)
    {
        printf("None");
    }
    for (i = 0; i < borrowedCount; i++)
    {
        printf("%d ", borrowedBookIDs[i]);
    }
    printf("\n");

    printf("Total fine before waiver: Rs. %.2f\n", totalFine);
    printf("Final fine payable: Rs. %.2f\n", fineAfterWaiver);
}

int main()
{
    int bookIDs[4] = {101, 102, 103, 104};
    char bookTitles[4][50] = {"Programming in C", "Data Structures",
                              "Database Systems", "Computer Networks"};
    int availableCopies[4] = {5, 3, 0, 4};
    int totalBooks = 4;

    //Member record variables 
    char name[50] = "";
    int studentID = 0;
    int memberType = 0;
    int borrowedBookIDs[3];
    int borrowedCount = 0;
    float totalFine = 0; // total fine before waiver 
    float fineAfterWaiver = 0;//total payable fine with waiver
    int registered = 0;// 0 = not registered, 1 = registered 

    int choice;

    do//until the user exits
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (registered == 1)
                    printf("A member is already registered\n");
                else
                {
                    registerMember(name, &studentID, &memberType);
                    registered = 1;
                }
                break;

            case 2:
                displayBooks(bookIDs, bookTitles, availableCopies, totalBooks);
                break;

            case 3:
                if (registered == 0)
                    printf("Please register first\n");
                else
                    borrowBook(bookIDs, bookTitles, availableCopies, totalBooks, borrowedBookIDs, &borrowedCount, memberType);
                
                break;

            case 4:
                if (registered == 0)
                    printf("Please register first\n");
                
                else
                {
                    fineAfterWaiver = fineAfterWaiver +
                        returnBook(bookIDs, availableCopies, totalBooks,
                                   borrowedBookIDs, &borrowedCount, memberType, &totalFine);
                }
                break;

            case 5:
                if (registered == 0)
                    printf("Please register first\n");
                else
                    displayMemberRecord(name, studentID, memberType,
                                        borrowedBookIDs, borrowedCount,totalFine, fineAfterWaiver);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter 1 to 6.\n");
            }
    } while (choice != 6);

    return 0;
}