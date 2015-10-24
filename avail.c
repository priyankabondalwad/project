


#include "header.h"

FILE *fa;


void new_avail(FILE *fa) {
	char yn, err[32], dat[16], tim[16];
	int flag = 0, id, op, n;
	doc_avail a;
	fseek(fa, 0, SEEK_END);
	yn = 'Y';
	while((yn == 'Y') || (yn == 'y')) {
		printf("\n--------------------------------------------------------------------------------\n");
		system("clear");		
		printheader();
		w1:printf("1]Add availability\t2]Return\n");
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1) {
			goto w;
		}
		else if(op == 2) {
			system("clear");
			fclose(fa);
			avail_info(fa);
		}
		else {
			printf("\n\t***Invalid entry***\n");
			goto w1;
		}

		w: printf("Enter the UID number:\n");
		scanf("%d", &id);
		rewind(fa);
		while(fread(&a, SIZE3, 1, fa) == 1) {
			if(a.uid == id) {
				printf("\tERROR: UID number already exists; type another one.\n");
				flag = 1; 
				goto w;
			}
		}
		if((flag == 0) || (fread(&a, SIZE3, 1, fa) == 0)) {
			fseek(fa, 0, SEEK_END);
			a.uid = id;
			printf("\nName of the doctor:");
			readline(err, 32);
			readline(a.doc_name, 32);
			printf("\nDesignation:");
			readline(a.desig, 32);
			printf("\nEnter availability of the doctor:\n");
			printf("\n\tMonday"); readline(a.d1.mon, 16);
			printf("\n\tTuesday:"); readline(a.d1.tue, 32);
			printf("\n\tWednesday:"); readline(a.d1.wed, 32);
			printf("\n\tThursday:"); readline(a.d1.thu, 32);
			printf("\n\tFriday:"); readline(a.d1.fri, 32);				
			printf("\n\tSaturday:"); readline(a.d1.sat, 32);
			printf("\n\tSunday:"); readline(a.d1.sun, 32);

			
			printf("\n\n\t\t\t***Successfully enrolled***\n\n");
			fwrite(&a, SIZE3, 1, fa);
			printf("Do you want to make another new entry(Y/N)?\n");
			scanf("%c", &yn);
		}
	}
	
}


		
void search_avail(FILE *fa) {
	char n[32], yn = 'Y', err[32];
	int id, op, f1 = 0, n1;
	doc_avail a;
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
			readline(err, 32);			
			readline(n, 32);
			rewind(fa);
			while(fread(&a, SIZE3, 1, fa) == 1) {
				if(strcmp(a.doc_name, n) == 0) {
					f1 = 1;
					break;
				}
			}
		}
		else if(op == 2) {
			printf("Enter the UID number:\n");
			scanf("%d", &id);
			rewind(fa); 
			while(fread(&a, SIZE3, 1, fa) == 1) {
				if(a.uid == id) {
					f1 = 1;
					break;
				}
			}
		}
		else if(op == 3) {
			fclose(fa);
			avail_info(fa);
		}
		else {
			printf("\n\t***Invalid entry***\n");
			goto w;
		}
		if(f1 == 1) {
			system("clear");
			printf("\n\t\t<<------------- AVAILABILITY OF DOCTOR ------------>>\n\n");
			printf("=> UID number of the doctor:""\t%d\n\n", a.uid); 
			printf("=> Name of the doctor:""\t%s\n\n", a.doc_name);
			printf("=> Designation:""\t%s\n\n", a.desig);
			printf("=> Availability:\n\n");
			printf("\t\t=> Monday:""    %s\n\n", a.d1.mon);
			printf("\t\t=> Tuesday:""   %s\n\n", a.d1.tue);
			printf("\t\t=> Wednesday:"" %s\n\n", a.d1.wed);
			printf("\t\t=> Thursday:""  %s\n\n", a.d1.thu);
			printf("\t\t=> Friday:""    %s\n\n", a.d1.fri);
			printf("\t\t=> Saturday:""  %s\n\n", a.d1.sat);
			printf("\t\t=> Sunday:""    %s\n\n", a.d1.sun);
			printf("--------------------------------------------------------------\n");
		}
		else
			printf("\tERROR: Entry not found\n");
		printf("\nDo you want to search any other registered entry(Y/N)?\n");
		scanf(" %c", &yn);
	}
		 
}

	
void edit_avail(FILE *fa) {
	char yn, err[32];
	doc_avail a;
	doc_avail a1;
	int id, flag = 0, op, n;
	yn = 'Y';
	while(yn == 'Y' || yn == 'y') {
		system("clear");		
		printheader();
		flag = 0;
		w:printf("\n1]Edit availability\t2]Return\n");
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
			fclose(fa);
			avail_info(fa);
		}
		else {
			printf("\n\t***Invalid entry***\n");
			goto w;
		}
		scanf("%d", &id);
		rewind(fa);
		while(fread(&a, SIZE3, 1, fa) == 1) {
			if(a.uid == id) {
				flag = 1;
				break;
			}
		}
		if(flag == 0) {
			printf("\t The doctor  is not present\n");
			yn = 'N';
		}
		else { 
			strcpy(a1.doc_name, a.doc_name);
			strcpy(a1.desig, a.desig);
			a1.uid = a.uid;
			printf("Edit availability of the doctor:\n");
				printf("\tMonday:"); readline(err, 32); readline(a1.d1.mon, 16);
				printf("\n\tTuesday:"); readline(a1.d1.tue, 32);
				printf("\n\tWednesday:"); readline(a1.d1.wed, 32);
				printf("\n\tThursday:"); readline(a1.d1.thu, 32);
				printf("\n\tFriday:"); readline(a1.d1.fri, 32);
				printf("\n\tSaturday:"); readline(a1.d1.sat, 32);
				printf("\n\tSunday:"); readline(a1.d1.sun, 32);
			fseek(fa, -SIZE3, SEEK_CUR);
			fwrite(&a1, SIZE3, 1, fa);
			printf("\n\t\t\t***Successfully edited***\n\n");	
			printf("Do you want edit any other registered entry(Y/N)?\n");
			scanf("%c", &yn);
		}
	}	
}



void list_avail(FILE *fa) {
	char err[1];	
	doc_avail a;
	system("clear");
	printf("\n\t<<------------- AVAILABILITY OF ALL DOCTORS ------------>>\n\n");
	rewind(fa);
	printf("--------------------------------------------------------------\n");
	while(fread(&a, SIZE3, 1, fa) == 1) {
		printf("=> UID number of the doctor:""\t%d\n", a.uid); 
		printf("=> Name of the doctor:""\t%s\n", a.doc_name);
		printf("=> Designation:""\t%s\n", a.desig);
		printf("=> Availability:\n");
			printf("\t\t=> Monday:""    %s\n", a.d1.mon);
			printf("\t\t=> Tuesday:""   %s\n", a.d1.tue);
			printf("\t\t=> Wednesday:"" %s\n", a.d1.wed);
			printf("\t\t=> Thursday:""  %s\n", a.d1.thu);
			printf("\t\t=> Friday:""    %s\n", a.d1.fri);
			printf("\t\t=> Saturday:""  %s\n", a.d1.sat);
			printf("\t\t=> Sunday:""    %s\n", a.d1.sun);
		printf("--------------------------------------------------------------\n");
	}
	printf("\nPress enter key to continue\n");
	readline(err, 1);
	readline(err, 1);
}


		
	

int avail_info(FILE *fa){
	fa = fopen("availability.txt", "rb+");
	if(fa == NULL) {
		perror("Sorry, file cannot be accessed:");
		return errno;
	}

	int op, n;
	char err[32];
	while(1) {
		printavailmenu();
		d:printf("\n\n\n\tEnter the option number:");
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		switch(op) {
			case 1:system("clear");
				printheader();
				new_avail(fa);
				break;
			case 2:system("clear");
				printheader();
				search_avail(fa);
				break;
			case 3:system("clear");
				printheader();
				edit_avail(fa);
				break;
			
			case 4:system("clear");
				printheader();
				list_avail(fa);
				break;
			case 5:fclose(fa);
				system("clear");
				printheader();
				printmainmenu();
				break;
			default:printf("\n\n\t***Invalid entry***");
				goto d;		
				break;		
		}
	}
	return 0;
}

