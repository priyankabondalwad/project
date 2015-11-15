project: main.o employee.o extra_func.o patient.o payment.o avail.o print.o header.h 
	cc  main.c  

main.o: main.c header.h
	cc  -c main.c

employee.o: employee.c header.h
	cc  -c employee.c
extra_func.o: extra_func.c header.h
	cc  -c extra_func.c
patient.o: patient.c header.h
	cc  -c patient.c
payment.o: payment.c header.h
	cc  -c payment.c

avail.o: avail.c header.h
	cc  -c avail.c

print.o: print.c header.h
	cc  -c print.c
