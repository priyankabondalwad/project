
#include "header.h"


int readline(char *string, int n) {	
	int i = 0;
	char ch, err[16];
	ch = getchar();
	while(i < n && ch != '\n') {
		string[i] = ch;
		ch = getchar();
		i++;	
	}
	if(i == n) { 	
		readline(err, 16);
		return 0;
	}
	string[i] = '\0';
	return 1;
}


 
void dt(char *dat, char *tim) {	
	time_t t;
        struct tm *tmp;
	t = time(NULL);
        tmp = localtime(&t);
	strftime(dat, 16, "%x", tmp);
	strftime(tim, 16, "%X", tmp);
}


