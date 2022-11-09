#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>	
#include <sys/types.h>
#include <sys/stat.h> 
#include <fcntl.h>   
#include <string.h>
#include "unistd.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
void read_data_from_file(char* fille_name, FILE* output_file);
void get_average_for_student(char* line, FILE* output_file);
void report_data_summary(int num_stud);