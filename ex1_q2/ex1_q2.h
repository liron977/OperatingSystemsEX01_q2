#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdbool.h>
#include <fcntl.h>   
#include<unistd.h>
#include <sys/wait.h>
#include <time.h>
void read_data_from_file(char* fille_name, FILE* output_file);
void get_student_average(char* line, FILE* output_file);
void report_data_summary(int num_stud);
int grade_calculation(FILE* output_file, int agrc, char* argv[]);
FILE* open_output_file(char* open_mode);