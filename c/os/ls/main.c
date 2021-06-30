//--------------------------------------------
// NAME: Ivan Dimitrov
// CLASS: XIb
// NUMBER: 13
// PROBLEM: #1
// FILE NAME: main.c (unix file name)
// FILE PURPOSE:
// Implements basic ls functionality
//---------------------------------------------
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <getopt.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

/*
 * Gets the full path of a given file
 * @param s1 - directory
 * @param s2 - file
 * @return Returns string with the full path of a file
 */
char* get_dir(char *s1, char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 2);
    strcpy(result, s1);
    strcat(result, "/");
    strcat(result, s2);
    return result;
}

/*
 * Gets the type of a given file
 * @param mode - stat mode of the file
 * @return Returns char with the type of the file
 */
char get_type(mode_t mode){
    if(S_ISREG(mode)){
        return '-';
    } else if(S_ISDIR(mode)) {
        return 'd';
    } else if(S_ISBLK(mode)) {
        return 'b';
    } else if(S_ISCHR(mode)) {
        return 'c';
    } else if(S_ISFIFO(mode)) {
        return 'p';
    } else if(S_ISLNK(mode)) {
        return 'l';
    } else if(S_ISSOCK(mode)) {
        return 's';
    }
}

/*
 * Gets the permissions of a given file
 * @param mode - stat mode of the file
 * @return Returns string with the permissions of the file
 */
char* get_permissions(mode_t mode){
    char* permissions = malloc(10);
    permissions[0] = (mode & S_IRUSR) ? 'r' : '-';
    permissions[1] = (mode & S_IWUSR) ? 'w' : '-';
    permissions[2] = (mode & S_IXUSR) ? 'x' : '-';
    permissions[3] = (mode & S_IRGRP) ? 'r' : '-';
    permissions[4] = (mode & S_IWGRP) ? 'w' : '-';
    permissions[5] = (mode & S_IXGRP) ? 'x' : '-';
    permissions[6] = (mode & S_IROTH) ? 'r' : '-';
    permissions[7] = (mode & S_IWOTH) ? 'w' : '-';
    permissions[8] = (mode & S_IXOTH) ? 'x' : '-';
    permissions[9] = '\0';
    return permissions;
}

/*
 * Gets the age of a given file
 * @param file_time - modification time of the file
 * @return Returns 1 if the file is older than 6 months
 *         Return 0 otherwise
 */
int is_old(time_t file_time){
    time_t sys_time;
    time(&sys_time);
    if(sys_time - file_time > 15778463){
        return 1;
    }
    return 0;
}

/*
 * Implements the main ls logic
 * @param argc - number of the arguments of the program
 * @param arg - name of the given file
 * @param l - is 1 if the program is started with -l flag
 * @param A - is 1 if the program is started with -A flag
 * @param R - is 1 if the program is started with -R flag
 * @param new_line - is 0 if \n can't be printed before the get_files func
 * @return Returns 0 on success and -1 on error
 */
int get_files(int argc, char *arg, int l, int A, int R, int new_line){
    char **sub_dirs = NULL;
    int sub_dirs_count = 0;
    struct stat st;
    if(stat(arg, &st) != 0){
        char error[] = "ls: cannot access '";
        strcat(error, arg);
        strcat(error, "'");
        perror(error);
        free(arg);
        return -1;
    }
    int total_blocks = 0;
    struct passwd *u_pwd;
    struct group *g_grp;
    struct tm *time;
    char buffer[80];
    if(S_ISDIR(st.st_mode)){
        DIR *dir;
        if((dir = opendir(arg)) == NULL){
            char error[] = "ls: cannot open directory '";
            strcat(error, arg);
            strcat(error, "'");
            perror(error);
            free(arg);
            return -1;
        }
        if(argc > optind + 1 || R){
            printf(new_line ? "\n" : "");
            printf("%s:\n", arg);
        }
        struct dirent *entry;
        errno = 0;
        while(entry = readdir(dir)) {
            if(A ? (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) : entry->d_name[0] != '.'){
                int can_free = 1;
                char *full_dir = get_dir(arg, entry->d_name);
                if(stat(full_dir, &st) != 0){
                    char error[] = "ls: cannot access '";
                    strcat(error, full_dir);
                    strcat(error, "'");
                    perror(error);
                    free(full_dir);
                    continue;
                }
                if(l){
                    time = localtime(&st.st_mtime);
                    char user_id[10];
                    char group_id[10];
                    if((u_pwd = getpwuid(st.st_uid)) == NULL){
                        sprintf(user_id, "%d", st.st_uid);
                    }
                    if((g_grp = getgrgid(st.st_gid)) == NULL){
                        sprintf(group_id, "%d", st.st_gid);                        
                    }
                    char* permissions = get_permissions(st.st_mode);
                    if(is_old(st.st_mtime)){
                        strftime(buffer, sizeof(buffer), "%b %e %Y", time);
                    } else {
                        strftime(buffer, sizeof(buffer), "%b %e %H:%M", time);
                    }
                    printf("%c%s %d %s %s %d %s %s\n", get_type(st.st_mode), permissions, 
                            st.st_nlink, (u_pwd ? u_pwd->pw_name : user_id), (g_grp ? g_grp->gr_name : group_id), 
                            st.st_size, buffer, entry->d_name);
                    if(R && (get_type(st.st_mode) == 'd')){
                        can_free = 0;
                        sub_dirs = realloc(sub_dirs, sizeof(char*) * (sub_dirs_count + 1));
                        sub_dirs[sub_dirs_count++] = full_dir;
                    }
                    free(permissions);
                    total_blocks += st.st_blocks;
                } else {
                    printf("%c %s\n", get_type(st.st_mode), entry->d_name);
                    if(R && (get_type(st.st_mode) == 'd')){
                        can_free = 0;
                        sub_dirs = realloc(sub_dirs, sizeof(char*) * (sub_dirs_count + 1));
                        sub_dirs[sub_dirs_count++] = full_dir;
                    }
                }
                if(can_free){
                    free(full_dir);
                }
            }
        }
        if(errno){
            char error[] = "ls: cannot read directory '";
            strcat(error, arg);
            strcat(error, "'");
            perror(error);
            if(closedir(dir) != 0){
                char error[] = "ls: cannot close directory '";
                strcat(error, arg);
                strcat(error, "'");
                perror(error);
                return -1;
            }
            return -1;
        }
        if(closedir(dir) != 0){
            char error[] = "ls: cannot close directory '";
            strcat(error, arg);
            strcat(error, "'");
            perror(error);
            free(arg);
            return -1;
        }
        if(l){
            printf("total %d\n", total_blocks/2);
        }
    } else {
        printf(new_line ? "\n" : "");
        if(l){
            time = localtime(&st.st_mtime);
            char user_id[10];
            char group_id[10];
            if((u_pwd = getpwuid(st.st_uid)) == NULL){
                sprintf(user_id, "%d", st.st_uid);
            }
            if((g_grp = getgrgid(st.st_gid)) == NULL){
                sprintf(group_id, "%d", st.st_gid);                        
            }
            char* permissions = get_permissions(st.st_mode);
            if(is_old(st.st_mtime)){
                strftime(buffer, sizeof(buffer), "%b %e %Y", time);
            } else {
                strftime(buffer, sizeof(buffer), "%b %e %H:%M", time);
            }
            printf("%c%s %d %s %s %d %s %s\n", get_type(st.st_mode), permissions, 
                    st.st_nlink, (u_pwd ? u_pwd->pw_name : user_id), (g_grp ? g_grp->gr_name : group_id), 
                    st.st_size, buffer, arg);
            free(permissions);
            total_blocks += st.st_blocks;
        } else {
            printf("%c %s\n", get_type(st.st_mode), arg);
        }
    }
    free(arg);
    for(int i = 0; i < sub_dirs_count; i++){
        get_files(argc, sub_dirs[i], l, A, R, 1);
    }
    if(sub_dirs != NULL){
        free(sub_dirs);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int option;
    int A = 0, l = 0, R = 0;
    while((option = getopt(argc, argv, "lAR")) != -1){
        switch(option){
            case 'l':
                l = 1;
                break;

            case 'A':
                A = 1;
                break;

            case 'R':
                R = 1;
                break;
        }
    }
    char *arg;
    for(int i = optind; i <= argc; i++){
        if(argv[i] == NULL){
            if(i != optind){
                break;
            }
            arg = malloc(3);
            strcpy(arg, ".");
        } else {
            arg = malloc(strlen(argv[i]) + 1);
            strcpy(arg, argv[i]);
        }
        get_files(argc, arg, l, A, R, (i != optind));        
    }
    return 0;
}