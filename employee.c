

#include "header.h"
void mainmenu();
void printempmenu();
void printheader();
void printmainmenu();
int emp_info();

int readline(char *string, int n);
FILE *fa;



void new_emp(FILE *fe, FILE *fd, FILE *fa) {
	char yn, err[32];
	int flag = 0, id, op = 0, n;
	employee e;
	doc_avail a;
	
	fseek(fe, 0, SEEK_END);
	fseek(fd, 0, SEEK_END);
	fseek(fa, 0, SEEK_END);
	yn = 'Y';
	while((yn == 'Y') || (yn == 'y')) {
		op = 0;
		printf("\n--------------------------------------------------------------------------------\n");
		system("clear");		
		printheader();
		w:printf("New employee: 1]Doctor or 2]Other employee 3]Return\n");
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1 || op == 2) {
			goto w1;
		}
		else if(op == 3) {
			system("clear");
			fclose(fe);
			fclose(fd);
			fclose(fa);
			emp_info(fe, fd, fa);
		}
		else {
			printf("\n\t***Invalid entry***\n");
			goto w;
		}
		w1: printf("Enter the unique identification number:\n");
		scanf("%d", &id);
		rewind(fe);
		rewind(fd);
		while(fread(&e, SIZE2, 1, fe) == 1) {
			if(e.uid == id) {
				printf("\t UID number already exists; type another one.\n");
				flag = 1; 
				goto w1;
			}
		}
		if((flag == 0) || (fread(&e, SIZE, 1, fe) == 0)) {
			fseek(fe, 0, SEEK_END); 
			fseek(fd, 0, SEEK_END);
			fseek(fa, 0, SEEK_END);			
			e.uid = id;
			a.uid = id;
			printf("\nName of the employee:");
			readline(err, 32);
			readline(e.name, 32);
			strcpy(a.doc_name, e.name);
			printf("\nGender(M:Male/F:Female/O:Other):");
			readline(e.gender, 8);
			printf("\nAge:");
			readline(e.age, 4);
			printf("\nAddress:\n");

			printf("\n\tCity:");
			readline(e.b.city, 32);
			printf("\n\tState:");
			readline(e.b.state, 32);
			printf("\nContact no.:");
			readline(e.contact, 16);
			printf("\nE-mail id:");
			readline(e.email, 32);
			printf("\nBlood group:");
			readline(e.bg, 4);
			printf("\nSalary: Rs.");
			readline(e.salary, 8);
			printf("\nDesignation:");
			readline(e.desig, 32);
			strcpy(a.desig, e.desig);
			if(op == 1) {
				printf("\nEnter availability of the doctor:\n");
					printf("\tMonday:"); readline(e.d.mon, 32); strcpy(a.d1.mon, e.d.mon);
					printf("\tTuesday:"); readline(e.d.tue, 32); strcpy(a.d1.tue, e.d.tue);
					printf("\tWednesday:"); readline(e.d.wed, 32); strcpy(a.d1.wed, e.d.wed);
					printf("\tThursday:"); readline(e.d.thu, 32); strcpy(a.d1.thu, e.d.thu);
					printf("\tFriday:"); readline(e.d.fri, 32); strcpy(a.d1.fri, e.d.fri);
					printf("\tSaturday:"); readline(e.d.sat, 32); strcpy(a.d1.sat, e.d.sat);
					printf("\tSunday:"); readline(e.d.sun, 32); strcpy(a.d1.sun, e.d.sun);
			}		
			printf("\nDate of enrollment(mm-dd-yyyy):");
			
			printf("\n\n\t\t\t***Successfully enrolled***\n\n");
			if(op == 1) {
				fwrite(&e, SIZE2, 1, fd);
				fwrite(&a, SIZE3, 1, fa);
			}	
			fwrite(&e, SIZE2, 1, fe);
			printf("\nDo you want to make another new entry(Y/N)?\n");
			scanf("%c", &yn);
		}
	}
	
}

void edit_emp(FILE *fe, FILE *fd) {
	char yn, err[32];
	employee e;
	int id, flag = 0, flag1 = 0, op, n;
	yn = 'Y';
	while(yn == 'Y' || yn == 'y') {
		system("clear");		
		printheader();
		flag = 0, flag1 = 0;
		w:printf("\n1]Edit data\t2]Return\n");
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1) {
			printf("\n\nEnter Existing UID number:");
		}
		else if(op == 2) {
			system("clear");
			fclose(fe);
			fclose(fd);
			emp_info(fe, fd, fa);
		}
		else {
			printf("\n\t***Invalid entry***\n");
			goto w;
		}
		scanf("%d", &id);
		rewind(fe);
		rewind(fd);
		while(fread(&e, SIZE2, 1, fe) == 1) {
			if(e.uid == id) {
				flag = 1;
				break;
			}
		}
		while(fread(&e, SIZE2, 1, fd) == 1) {
			if(e.uid == id) {
				flag1 = 1;
				break;
			}
		}
		if(flag == 0) {
			printf("\t The employee is not registered\n");
			yn = 'N';
		}
		else { 
			printf("\nName of the employee:");
			readline(err, 1);
			readline(e.name, 32);
			printf("\nGender(M:Male/F:Female/O:Other):");
			readline(e.gender, 8);
			printf("\nAge:");
			readline(e.age, 4);
			printf("\nAddress:\n");
				
				printf("\nCity:");
				readline(e.b.city, 32);
				printf("\n\tState:");
				readline(e.b.state, 32);
			printf("\nContact no.:");
			readline(e.contact, 16);
			printf("\nE-mail id:");
			readline(e.email, 32);
			printf("\nBlood group:");
			readline(e.bg, 4);
			printf("\nDesignation:");
			readline(e.desig, 32);
			printf("\nSalary: Rs.");
			readline(e.salary, 8);
			;
			if(flag1 == 1) {
				fseek(fd, -SIZE2, SEEK_CUR);
				fwrite(&e, SIZE2, 1, fd);
			}				
			fseek(fe, -SIZE2, SEEK_CUR);
			fwrite(&e, SIZE2, 1, fe);
			printf("\n\n\t\t\t***Successfully edited***\n\n");	
			printf("Do you want edit any other registered entry(Y/N)?\n");
			scanf("%c", &yn);
		}
	}	
}

void search_emp(FILE *fe, FILE *fd) {
	char n[32], yn = 'Y', err[32];
	int id, op, f1 = 0, n1;
	employee e;
	while(yn == 'Y' || yn == 'y') {
		system("clear");		
		printheader();
		f1 = 0;
		w:printf("\nSearch by 1]Name 2]UID number 3]Return:\n\n");
		n1 = scanf("%d", &op);
		if(n1 == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1) {
			printf("Enter the name of employee:\n");
			readline(err, 1);			
			readline(n, 32);
			rewind(fe);
			while(fread(&e, SIZE2, 1, fe) == 1) {
				if(strcmp(e.name, n) == 0) {
					f1 = 1;
					break;
				}
			}
		}
		else if(op == 2) {
			printf("Enter the UID number:\n");
			scanf("%d", &id);
			rewind(fe); 
			while(fread(&e, SIZE2, 1, fe) == 1) {
				if(e.uid == id) {
					f1 = 1;
					break;
				}
			}
		}
		else if(op == 3) {
			fclose(fe);
			emp_info(fe);
		}
		else {
			printf("\n\t***Invalid entry***\n");
			goto w;
		}
		if(f1 == 1) {
			system("clear");
			printf("\n\t\t<<------------- DATA OF EMPLOYEE ------------>>\n\n");
			printf("=> UID number of the employee:""\t%d\n\n", e.uid); 
			printf("=> Name of the employee:""\t%s\n\n", e.name);
			printf("=> Designation:""\t%s\n\n", e.desig);
			printf("=> Gender:""\t%s\n\n", e.gender);
			printf("=> Age:""\t%s years\n\n", e.age);
			printf("=> Address:\n\n");
			printf("\t> City:       ""\t%s\n", e.b.city);
			printf("\t> State:      ""\t%s\n\n", e.b.state);
			printf("=> Contact no.:""\t%s\n\n", e.contact);
			printf("=> E-mail id:""\t%s\n\n", e.email);
			printf("=> Blood group:""\t%s\n\n", e.bg);
			printf("=> Salary:\t""Rs.%s\n\n", e.salary);
			
			printf("--------------------------------------------------------------\n");
		}
		else
			printf("\t Entry not found\n");
		printf("\nDo you want to search any other registered entry(Y/N)?\n");
		scanf(" %c", &yn);
	}
		 
}

void list_emp(FILE *fe, FILE *fd) {
	char err[1];
	employee e;
	rewind(fe);
	printf("--------------------------------------------\n");
	printf("Registered employee:\n");
	printf("--------------------------------------------\n\n\n");
	while(fread(&e, SIZE2, 1, fe) == 1) {
		printf("=> UID number of the employee:""\t%d\n", e.uid); 
		printf("=> Name of the employee:""\t%s\n", e.name);
		printf("=> Designation:""\t%s\n", e.desig);
		printf("--------------------------------------------\n\n");
	}
	printf("Press enter key to continue");
	readline(err, 1);
	readline(err, 1);
}


	
		

int emp_info() {
	FILE *fe, *fd;
	fe = fopen("employee.txt", "rb+");
	fd = fopen("doctor.txt",  "rb+");
	fa = fopen("availability.txt", "rb+");
	if(fe == NULL) {
		perror(" file cannot be accessed:");
		return errno;
	}
	if(fd == NULL) {
		perror(" file cannot be accessed:");
		return errno;
	}
	if(fa == NULL) {
		perror(" file cannot be accessed:");
		return errno;
	}

	int op, n;
	char err[32];
	while(1) {
		printempmenu();
		c:printf("\n\n\n\tEnter the option number:");
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}

		switch(op) {
			case 1:system("clear");
				printheader();
				new_emp(fe, fd, fa);
				break;
			case 2:system("clear");
				printheader();
				edit_emp(fe, fd);
				break;
			case 3:system("clear");
				printheader();
				search_emp(fe, fd);
				break;
			case 4:system("clear");
				printheader();
				list_emp(fe, fd);
				break;
			
			case 5:fclose(fa);
				fclose(fd);
				fclose(fe);
				system("clear");
				printheader();
				printmainmenu();
				break;
			default:printf("\n\n\t***Invalid entry***");
				goto c;		
				break;		
		}
	}
	return 0;
}

