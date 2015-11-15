
#include "header.h"
void pat_info();
void emp_info();
void avail_info();

int readline(char *string, int n);
FILE *fa;

void printheader() {
	
	system("clear");
	
	
	printf("*********************GLOBAL HOSPITAL-------- SHIVAJI NAGAR,NANDED.************************\n");
	
}



void printmainmenu() {
	printf("\n\t\t\t\t\t\t\t\t-------------\n"
		"\t\t\t\t\t\t\t\t| MAIN MENU |\n"
		"\t\t\t\t\t\t\t\t-------------\n\n\n"
		"\t\t\t\t\t\t\t\t1] PATIENT\n\n"
	        "\t\t\t\t\t\t\t\t2] EMPLOYEE/DOCTOR\n\n"
	        "\t\t\t\t\t\t\t\t3] PAYMENT\n\n"
		"\t\t\t\t\t\t\t\t4] AVAILABILITY OF DOCTOR\n\n"
		"\t\t\t\t\t\t\t\t5] EXIT\n\n\n");
	int c, n;
	char err[32];
	a:printf("\n\n\n\tEnter the option number:");
	n = scanf("%d", &c);
	if(n == 0) {
		c = 7;
		readline(err, 32);
	}
	
	
	switch(c) {
		case 1:pat_info();
			break;
		case 2:emp_info(fa);
			break;
		
		case 3:avail_info(fa);
			break;
		
			
		case 4:system("clear");
			exit(1);
			break;
		default:printf("\n\t***Invalid entry***\n");
			goto a;
			break;
	}
}


void printpatmenu() {
	system("clear");
	printheader();
	printf("\n\t\t-----------\n"
		"\t\t| PATIENT |:\n"
		"\t\t-----------\n\n\n"
		"\t\t\t1] Enroll a new patient\n\n"
		"\t\t\t2] Edit existing entry\n\n"
		"\t\t\t3] Display record of particular patient\n\n"
		"\t\t\t4] List of all registered patients\n\n"
		"\t\t\t5] Close the enrollment of patient\n\n"
		"\t\t\t6] Return to main menu\n\n");
}


void printempmenu() {
	system("clear");
	printheader();
	printf("\n\t\t------------\n"
		"\t\t| EMPLOYEE |:\n"
		"\t\t------------\n\n"
		"\t\t\t1] Enroll a new employee/doctor\n\n"
		"\t\t\t2] Edit existing entry\n\n"
		"\t\t\t3] Display profile of particular employee/doctor\n\n"
		"\t\t\t4] List of all registered employee\n\n"
		"\t\t\t5] Close the enrollment of employee\n\n"
		"\t\t\t6] Return to main menu\n");
}


void printavailmenu() {
	system("clear");
	printheader();
	printf("\n\t\t----------------\n"
		"\t\t| AVAILABILITY |:\n"
		"\t\t----------------\n\n\n"
		"\t\t\t1] Add availability of doctor\n\n"
		"\t\t\t2] Search availability of particular doctor\n\n"
		"\t\t\t3] Edit availablity\n\n"
		"\t\t\t4] List availability of all doctors\n\n"
		"\t\t\t5] Return to main menu\n");
}
	

