/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** l_flag.c
*/

#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <time.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <time.h>
#include "ls.h"
#include "my.h"

void mydir(struct stat sb)
{
    (S_ISDIR(sb.st_mode) != 0) ? my_putstr("d") :
    (S_ISSOCK(sb.st_mode) != 0) ? my_putstr("s") :
    (S_ISBLK(sb.st_mode) != 0) ? my_putstr("b") :
    (S_ISCHR(sb.st_mode) != 0) ? my_putstr("c") :
    (S_ISLNK(sb.st_mode)!= 0) ? my_putstr("l") :
    (S_ISFIFO(sb.st_mode) != 0) ? my_putstr("p") : my_putstr("-");
}

void my_rights(struct stat sb)
{
    ((sb.st_mode & S_IRUSR) != 0) ? my_putstr("r") : my_putstr("-");
    ((sb.st_mode & S_IWUSR) != 0) ? my_putstr("w") : my_putstr("-");
    ((sb.st_mode & S_IXUSR) != 0) ? my_putstr("x") : my_putstr("-");
    ((sb.st_mode & S_IRGRP) != 0) ? my_putstr("r") : my_putstr("-");
    ((sb.st_mode & S_IWGRP) != 0) ? my_putstr("w") : my_putstr("-");
    ((sb.st_mode & S_IXGRP) != 0) ? my_putstr("x") : my_putstr("-");
    ((sb.st_mode & S_IROTH) != 0) ? my_putstr("r") : my_putstr("-");
    ((sb.st_mode & S_IWOTH) != 0) ? my_putstr("w") : my_putstr("-");
    ((sb.st_mode & S_IXOTH) != 0) ? my_putstr("x ") : my_putstr("- ");
}

char *mytime(char *str)
{
    char *str2;
    int j = 0;
    int i = 4;

    str2 = malloc(my_strlen(str) * sizeof(*str));
    while (i <= 15) {
        if (i == 7)
              str2[j++] = '.';
        str2[j++] = str[i++];
    }
    str2[j] = '\0';
    return (str2);
}

void my_aff_data(struct stat sb, struct passwd *pass, struct group *group)
{
    pass = getpwuid(sb.st_uid);
    group = getgrgid(pass->pw_gid);
    mydir(sb);
    my_rights(sb);
    my_put_nbr(sb.st_nlink);
    my_putchar(' ');
    my_putstr(pass->pw_name);
    my_putchar(' ');
    my_putstr(group->gr_name);
    my_putchar(' ');
    my_put_nbr(sb.st_size);
    my_putchar(' ');
    my_putstr(mytime(ctime(&sb.st_mtime)));
    my_putchar(' ');
}

void l_flag(char *name)
{
    DIR    *dirp = opendir(name);
    struct stat    sb;
    struct passwd    *pass;
    struct group    *group;
    struct dirent    *list;
    char path[2048];

    while ((list = readdir(dirp)) != NULL) {
          if (my_strcmp(list->d_name, ".") && my_strcmp(list->d_name, "..")) {
              my_strcpy(path, name);
              my_strcat(path, "/");
              my_strcat(path, list->d_name);
              lstat(path, &sb);
              my_aff_data(sb, pass,  group);
              my_putstr(list->d_name);
            my_putchar('\n');
          }
      }
    closedir(dirp);
}
