#Makefile for ex1-q2 winter 2022A
CFLAGS = -Wall
LDFLAGS = -lm # not really needed for this exercise
CC = gcc -std=c99
ECHO = echo "going to compile for target $@"
PROG = ex1_q2

OBJFILES = ex1_q2.o 

all: $(PROG) test

$(PROG): $(OBJFILES) $(FACTORS)	
	$(CC) $(CFLAGS) $(OBJFILES) -o $(PROG)

$(FACTORS): $(FACTORS_DEPENDECY)
	$(CC) $(CFLAGS) $(FACTORS_DEPENDECY) -o $(FACTORS)
		
#OBJFILES
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@
	
test: $(PROG)
	./$(PROG) -a gr_1.txt gr_2.txt gr_3.txt
	
clean: 
	rm -vf *.o ${PROG} *.log
	