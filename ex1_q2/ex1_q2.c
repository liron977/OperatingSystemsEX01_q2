#include "ex1_q2.h"
#define GRADES_FILE "all_std.txt" 

void read_data_from_file(char* fille_name, FILE* output_file) {
    FILE* file = fopen(fille_name, "r");
    char line[80];
    int num_stud = 0;
    while (fgets(line, sizeof(line), file)) {
        get_average_for_student(line, output_file);
        num_stud++;
    }
    fclose(file);
    exit(num_stud);
}
void get_average_for_student(char* line, FILE* output_file) {
    int sum_of_grades = 0;
    char* token = strtok(line, " ");
    int index = 0;
    char* student_name = token;
    int grade = 0;
    while (token != NULL) {
        token = strtok(NULL, " ");
        if (token != NULL) {
            index++;
            sscanf(token, "%d", &grade);
            sum_of_grades += grade;
        }
    }
    double avg = (double)sum_of_grades / (index);
    fprintf(output_file, "%s", student_name);
    fprintf(output_file, " %.2f\n", avg);
}
int main(int agrc, char* argv[]) {
    int num_stud = 0;
    FILE* output_file = NULL;
    char* input_file_name;
    int exit_value;
    int status;
    if (strcmp(argv[1], "-t") == 0) {
        output_file = fopen(GRADES_FILE, "w");
        fseek(output_file, 0, SEEK_SET);
    }
    else  if (strcmp(argv[1], "-a") == 0) {
        output_file = fopen(GRADES_FILE, "a");
    }
    for (int i = 2; i < agrc; i++) {
        input_file_name = argv[i];
        int pid = fork();
        if (pid == -1) {
            printf("The fork failed");
        }
        if (pid == 0) {
          read_data_from_file(input_file_name, output_file);
        }
        else{
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)){
                 exit_value = WEXITSTATUS(status);
                 fprintf(stderr, "process: %d file: %s number of students: %d\n",
                     pid, input_file_name, exit_value);

                // printf("exit_value %d,%d \n", exit_value,pid);
                 num_stud += exit_value;
            }
        }
    }
    fclose(output_file);
    report_data_summary(num_stud);
}
void report_data_summary(int num_stud) {
    fprintf(stderr, "grade calculation for %d students is done\n", num_stud);
}
//int main() {
//    int num_stud = 0;
//    char* input_file_name;
//    FILE* output_file = NULL;
//    char* argv[] = {"ex1_q2","-t","gr_1.txt","gr_2.txt" };
//    FILE* outputFile = NULL;
//    int amountOfFilles = sizeof(argv)/(sizeof(char*));
//    char* inputFileName;
//    int exit_value;
//    int status;
//    if (strcmp(argv[1], "-t") == 0) {
//        output_file = fopen("all_std.txt", "w");
//        fseek(output_file, 0, SEEK_SET);
//    }
//    else  if (strcmp(argv[1], "-a") == 0) {
//        output_file = fopen("all_std.txt", "a");
//        fseek(output_file, 0,SEEK_END);
//    }
//    for (int i = 2; i < amountOfFilles; i++) {
//        input_file_name = argv[i];
//        fprintf(fork(),"vf");
//       /* if (pid == 0) {
//            read_data_from_file(input_file_name, output_file);
//        }
//        else {
//            waitpid(pid, &status, 0);
//            if (WIFEXITED(status)) {
//                exit_value = WEXITSTATUS(status);
//                num_stud += exit_value;
//            }
//        }*/
//    }
//    fclose(output_file);
//}
