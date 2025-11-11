#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Holder {
    char name[50];
    struct Date dob;    // date of birth
    char address[100];
    char nationality[30];
};


struct Passport {
    char passportNumber[20];
    struct Date issueDate;
    struct Date expiryDate;
    char issuingCountry[30];
    struct Holder holder;   // nested structure
};

int main() {
    struct Passport p;


    printf("Enter Passport Number: ");
    scanf("%s", p.passportNumber);

    printf("Enter Issuing Country: ");
    scanf("%s", p.issuingCountry);

    printf("Enter Issue Date (day month year): ");
    scanf("%d %d %d", &p.issueDate.day, &p.issueDate.month, &p.issueDate.year);

    printf("Enter Expiry Date (day month year): ");
    scanf("%d %d %d", &p.expiryDate.day, &p.expiryDate.month, &p.expiryDate.year);

    printf("Enter Holder Name: ");
    scanf(" %[^\n]", p.holder.name); // space before %[ to read full line

    printf("Enter Date of Birth (day month year): ");
    scanf("%d %d %d", &p.holder.dob.day, &p.holder.dob.month, &p.holder.dob.year);

    printf("Enter Address: ");
    scanf(" %[^\n]", p.holder.address);

    printf("Enter Nationality: ");
    scanf("%s", p.holder.nationality);

    printf("\n---- Passport Details ----\n");
    printf("Passport No: %s\n", p.passportNumber);
    printf("Issuing Country: %s\n", p.issuingCountry);
    printf("Issue Date: %d-%d-%d\n", p.issueDate.day, p.issueDate.month, p.issueDate.year);
    printf("Expiry Date: %d-%d-%d\n", p.expiryDate.day, p.expiryDate.month, p.expiryDate.year);

    printf("\n---- Holder Details ----\n");
    printf("Name: %s\n", p.holder.name);
    printf("Date of Birth: %d-%d-%d\n", p.holder.dob.day, p.holder.dob.month, p.holder.dob.year);
    printf("Address: %s\n", p.holder.address);
    printf("Nationality: %s\n", p.holder.nationality);

    return 0;
}
