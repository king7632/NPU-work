#include "studentmanager.h"
#include <string.h>
#include <stdio.h>

int login(User *user)
{
    char name[32];

    printf("请输入用户名：admin / user ：");
    scanf("%31s", name);

    if (strcmp(name, "admin") == 0) {
        strcpy(user->username, "admin");
        user->role = ROLE_ADMIN;
        return 0;
    }
    else if (strcmp(name, "user") == 0) {
        strcpy(user->username, "user");
        user->role = ROLE_USER;
        return 0;
    }

    printf("登录失败\n");
    return -1;
}
