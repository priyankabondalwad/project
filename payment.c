
#include "header.h"
void printheader();
int readline(char *string, int n);
void printmainmenu();


int concession(float total) {	
	float con;	
	con = total * 20 / 100;
	total = total - con;
	return total;
}


int pay_info() {
	payment pay;
	patient p;
	char n[32],  err[32], yn, f, f1 = 0;
	int reg, op, n1;
	FILE *fp1, *fp;
	fp = fopen("patient.txt", "rb+");
	if(fp == NULL) {
		perror("Sorry, file cannot be accessed:");
		return errno;
	}
	fp1 = fopen("payment.txt", "rb+");
	if(fp1 == NULL) {
		perror("Sorry, file cannot be accessed:");
		return errno;
	}
	rewind(fp);
	rewind(fp1);
	system("clear");
	printheader();
	w:printf("Search by 1]registration number or 2]name of the patient  3]Return\n");
	n1 = scanf("%d", &op);
	if(n1 == 0) {
		op = 7;
		readline(err, 32);
	}
	f = 0;
	if(op == 1) {
		printf("\nEnter registration number of the patient:\n");
		scanf("%d", &reg);
		f = 1;
	}
	else if(op == 2) {
		printf("\nEnter name of the patient:\n");
		readline(err, 1);
		readline(n, 32);
		f = 1;
	}
	else if(op == 3) {
		fclose(fp);
		fclose(fp1);
		system("clear");
		printheader();
		printmainmenu();
	}
	else {
		printf("\n\t***Invalid Entry***\n\n");
		goto w;
	}
	if(f == 1) {
		while(fread(&p, SIZE, 1, fp) == 1) {
			f1 = 0;
			if(strcmp(p.name, n) == 0 || p.regn == reg) {
				f1 = 1;
				break;
			}
		}
		if(f1 == 1) {
			pay.reg = p.regn;
			strcpy(pay.name, p.name);
			strcpy(pay.type, p.type);	
			
			
			printf("Enter registration fee: Rs.");
			scanf("%f", &pay.reg_fee);
			printf("Enter doctor fee: Rs.");
			scanf("%f", &pay.doc_fee);
			printf("Enter medicine fee: Rs.");
			scanf("%f", &pay.med_fee);
			pay.tot_fee = pay.reg_fee + pay.doc_fee + pay.med_fee;
			if((strcmp(p.type, "G") == 0 || strcmp(p.type, "g") == 0) || (strcmp(p.type, "M") == 0 || strcmp(p.type,"m") == 0)) {
				pay.tot_fee = concession(pay.tot_fee);
			} 
			printf("Total payment amount:\tRs.%f\n", pay.tot_fee); 
			printf("Payment received(Y/N)\n");
			scanf(" %c", &yn);
			if(yn = 'y' || yn == 'Y') 
				strcpy(pay.status, "Payment done\n");
			else
				strcpy(pay.status, "Payment not done\n");
			fseek(fp1, 0, SEEK_END);
			fwrite(&pay, SIZE1, 1, fp1);
		}
		else {
			printf("\tERROR: Entry not found\n");
			goto g;
		}	
		system("clear");
		printheader();
		printf("\t\t<<------------ PAYMENT RECCEIPT ------------>>\n\n");
		
		printf("\tPatient Name:" "\t%s\n\n", p.name);
		printf("\tRegistration number:" "\t%d\n\n", p.regn);
		printf("\tType of patient:\t");
			if(strcmp(p.type, "G") == 0 || strcmp(p.type, "g") == 0)
				printf("Government Servant\n\n");
			else if(strcmp(p.type, "M") == 0 || strcmp(p.type, "m") == 0)
				printf("Mediclaim Holder\n\n");
			else
				printf("Other\n\n");
		printf("\tPayment details:\n\n");
		printf("\t\tRegistration fee:" "\tRs.%f\n\n", pay.reg_fee);
		printf("\t\tDoctor fee:" "      \tRs.%f\n\n", pay.doc_fee);
		printf("\t\tMedical fee:" "     \tRs.%f\n\n", pay.med_fee);
		printf("\t\t----------------------------------------\n");
		printf("\t\tTotal fee:" "      \tRs.%f\n", pay.tot_fee);
		printf("\t\t----------------------------------------\n\n");
		printf("\tStatus:" "\t%s\n\n", pay.status);
		printf("\t(20 percent concession for Government Servant and Mediclaim Holder)\n");
	}
	g:printf("\nPress enter key to continue\n");
	readline(err, 1);	
	readline(err, 1);
	fclose(fp);
	fclose(fp1);
}

