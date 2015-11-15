
#include "header.h"
void printpatmenu();
void printmainmenu();
void printheader();
int readline(char *string, int n);
int pat_info();

void new_pat(FILE *fp) {
	char yn, err[32];
	int flag = 0, reg, op, n;
	patient p;
	fseek(fp, 0, SEEK_END);
	yn = 'Y';
	while((yn == 'Y') || (yn == 'y')) {
		printf("\n--------------------------------------------------------------------------------\n");
		system("clear");		
		printheader();
		w: printf("1]Add record\t 2]Return\n");
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1) {
			printf("\n\nEnter Registration number:");
		}
		else if(op == 2) {
			system("clear");
			fclose(fp);
			pat_info(fp);
		}
		else {
			printf("\n\t***Invalid entry***\n");
			goto w;
		}
		scanf("%d", &reg);
		rewind(fp);
		while(fread(&p, SIZE, 1, fp) == 1) {
			if(p.regn == reg) {
				printf("\t Registration number already exists; type another one.\n\n");
				flag = 1; 
				goto w;
			}
		}
		if((flag == 0) || (fread(&p, SIZE, 1, fp) == 0)) {
			fseek(fp, 0, SEEK_END);
			p.regn = reg;
			printf("\nName of the patient:");
			readline(err, 32);
			readline(p.name, 32);
			printf("\nGender(M:Male/F:Female/O:Other):");
			readline(p.gender, 8);
			printf("\nAge:");
			readline(p.age, 4);
			printf("\nAddress:\n");
				
			printf("\n\tCity:");
			readline(p.a.city, 32);
			printf("\n\tState:");
			readline(p.a.state, 32);
			printf("\nContact no.:");
			readline(p.contact, 16);
			printf("\nE-mail id:");
			readline(p.email, 32);
			printf("\nType of patient:\n\tGovernment servant(G)\n\tOther(O)\n");
			readline(p.type, 16);
			printf("\nBlood group:");
			readline(p.bg, 4);
			printf("\nDisease/problem:");
			readline(p.disease, 64);
			printf("\nName of the doctor to being referred:");
			readline(p.doc_name, 32);
			printf("\nHistory of patient if any:");
			readline(p.history, 256);
			
			
			
			
			
			
			printf("\n\n\t\t\t***Successfully enrolled***\n\n");
				
			fwrite(&p, SIZE, 1, fp);
			printf("Do you want to make another new entry(Y/N)?\n");
			scanf("%c", &yn);
		}
	}
	
}


void edit_pat(FILE *fp) {
	char yn, err[32];
	patient p;
	int reg, flag = 0, op, n;
	yn = 'Y';
	while(yn == 'Y' || yn == 'y') {
		system("clear");		
		printheader();
		flag = 0;
		w:printf("\n1]Edit record\t 2]Return\n");
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1) {
			printf("\n\nEnter Registration number:");
		}
		else if(op == 2) {
			system("clear");
			fclose(fp);
			pat_info(fp);
		}
		else {
			printf("\n\t***Invalid entry***\n");
			goto w;
		}
		scanf("%d", &reg);
		rewind(fp);
		while(fread(&p, SIZE, 1, fp) == 1) {
			if(p.regn == reg) {
				flag = 1;
				break;
			}
		}
		if(flag == 0) {
			printf("\t The patient is not registered\n");
			yn = 'N';
		}
		else { 
			printf("\nName of the patient:");
			readline(err, 32);
			readline(p.name, 32);
			printf("\nGender(M:Male/F:Female/O:Other):");
			readline(p.gender, 8);
			printf("\nAge:");
			readline(p.age, 4);
			printf("\nAddress:\n");
				
			printf("\n\tCity:");
			readline(p.a.city, 32);
			printf("\n\tState:");
			readline(p.a.state, 32);
			printf("\nContact no.:");
			readline(p.contact, 16);
			printf("\nE-mail id:");
			readline(p.email, 32);
			printf("\nType of patient:\n\tGovernment servant(G)\n\tOther(O)");
			readline(p.type, 16);
			printf("\nBlood group:");
			readline(p.bg, 4);
			printf("\nDisease/problem:");
			readline(p.disease, 64);
			printf("\nName of the doctor to being referred:");
			readline(p.doc_name, 32);
			printf("\nHistory of patient if any:");
			readline(p.history, 256);
			
			printf("\nTreatment done:");
			readline(p.treatment, 32);
			printf("\nMedicines suggested:");
			readline(p.med, 32);
			fseek(fp, -SIZE, SEEK_CUR);
			fwrite(&p, SIZE, 1, fp);
			printf("\n\n\t\t\t***Successfully edited***\n\n");	
			printf("Do you want edit any other registered entry(Y/N)?\n");
			scanf("%c", &yn);
		}
	}	
}


void search_pat(FILE *fp) {
	char n[32], yn = 'Y', err[32];
	int reg, op, f1 = 0, n1;
	patient p;
	while(yn == 'Y' || yn == 'y') {
		system("clear");		
		printheader();
		f1 = 0;
		w:printf("\nSearch by 1]Name 2]Registration number 3]Return:\n\n");
		n1 = scanf("%d", &op);
		if(n1 == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1) {
			printf("Enter the name of patient:\n");
			readline(err, 32);			
			readline(n, 32);
			rewind(fp);
			while(fread(&p, SIZE, 1, fp) == 1) {
				if(strcmp(p.name, n) == 0) {
					f1 = 1;
					break;
				}
			}
		}
		else if(op == 2) {
			printf("Enter the registration number:\n");
			scanf("%d", &reg);
			rewind(fp); 
			while(fread(&p, SIZE, 1, fp) == 1) {
				if(p.regn == reg) {
					f1 = 1;
					break;
				}
			}
		}
		else if(op == 3) {
			fclose(fp);
			pat_info(fp);
		}
		else {
			printf("\t***Invalid entry***\n");
			goto w;
		}
		if(f1 == 1) {
			system("clear");
			printf("\n\t\t<<------------- DATA OF PATIENT ------------>>\n\n");
			printf("=> Registration number of the patient:""\t%d\n\n", p.regn); 
			printf("=> Name of the patient:""\t%s\n\n", p.name);
			printf("=> Gender:""\t%s\n\n", p.gender);
			printf("=> Age:""\t%s years\n\n", p.age);
			printf("=> Address:\n\n");
			
			printf("\t> City:""       \t%s\n", p.a.city);
			printf("\t> State:""      \t%s\n\n", p.a.state);
			printf("=> Contact no.:""\t%s\n\n", p.contact);
			printf("=> E-mail id:""\t%s\n\n", p.email);
			printf("=> Type of patient:\t");
			if(strcmp(p.type, "G") == 0 || strcmp(p.type, "g") == 0)
				printf("Government servant\n\n");
			
			else
				printf("Other\n\n");
		
			printf("=> Blood group:""\t%s\n\n", p.bg);
			printf("=> Disease/problem:""\t%s\n\n", p.disease);
			printf("=> Name of the doctor to being referred:""\t%s\n\n", p.doc_name);
			printf("=> History of patient:""\t%s\n\n", p.history);
			
			printf("=> Treatment done:""\t%s\n\n", p.treatment);
			printf("=> Medicines suggested:""\t%s\n\n", p.med);
			printf("--------------------------------------------------------------\n");
		}
		else
			printf("\t Entry not found\n");
		printf("\nDo you want to search any other registered entry(Y/N)?\n");
		scanf(" %c", &yn);
	}
		 
}

void list_pat(FILE *fp) {
	char err[1];
	patient p;
	rewind(fp);
	printf("--------------------------------------------\n");
	printf("Registered patients:\n");
	printf("--------------------------------------------\n\n\n");
	while(fread(&p, SIZE, 1, fp) == 1) {
		printf("=> Registration number of the patient:""\t%d\n", p.regn); 
		printf("=> Name of the patient:""\t%s\n", p.name);
		
		printf("--------------------------------------------\n\n");
	}
	printf("Press enter key to continue");
	readline(err, 1);
	readline(err, 1);
}

void close_pat(FILE *fp) {
	patient p;
	char yn = 'Y', err[32];
	int reg, flag = 0, op, n;
	FILE *tmp;
	while(yn == 'Y' || yn == 'y') {
		system("clear");		
		printheader();
		flag = 0;
		rewind(fp);
		tmp = fopen("temporary.txt", "wb+");		
		w:printf("\n1]Close record\t 2]Return\n");
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		if(op == 1) {
			printf("\n\nEnter Registration number:");
		}
		else if(op == 2) {
			system("clear");
			fclose(fp);
			pat_info(fp);
		}
		else {
			printf("\n\t***Invalid entry***\n");
			goto w;
		}
		scanf("%d", &reg);
		while(fread(&p, SIZE, 1, fp) == 1) {
			if(p.regn != reg) {
				fseek(tmp, 0, SEEK_END);
				fwrite(&p, SIZE, 1, tmp);
			}
			else
				flag = 1;
		}
		if(flag == 1) {
		fclose(tmp);
		fclose(fp);
		fp = fopen("patient.txt", "wb+");
		tmp = fopen("temporary.txt", "rb+");
		while(fread(&p, SIZE, 1, tmp) == 1) {
				fseek(fp, 0, SEEK_END);
				fwrite(&p, SIZE, 1, fp);
		}
		fclose(tmp);	
		fclose(fp);
		fp = fopen("patient.txt", "rb+");
		printf("\n\t\t\t***Successfully closed***\n\n");
		}
		else
			printf("\t Registration number does not exis\n");	
		printf("\nDo you want to close any other record(Y/N):\n");
		scanf(" %c", &yn);
		
	}
}

int pat_info() {
	FILE *fp;
	fp = fopen("patient.txt", "rb+");
	if(fp == NULL) {
		perror(" file cannot be accessed:");
		return errno;
	}
	int op, n;
	char err[32];
	while(1) {
		printpatmenu();
		b:printf("\n\n\n\tEnter the option number:");
		n = scanf("%d", &op);
		if(n == 0) {
			op = 7;
			readline(err, 32);
		}
		switch(op) {
			case 1:system("clear");
				printheader();
				new_pat(fp);
				break;
			case 2:system("clear");
				printheader();
				edit_pat(fp);
				break;
			case 3:system("clear");
				printheader();
				search_pat(fp);
				break;
			case 4:system("clear");
				printheader();
				list_pat(fp);
				break;
			case 5:system("clear");
				printheader();
				close_pat(fp);
				break;
			case 6:system("clear");
				fclose(fp);
				printheader();
				printmainmenu();
				break;
			default:printf("\n\n\t***Invalid entry***");
				goto b;		
				break;		
		}
	}
	return 0;
}
