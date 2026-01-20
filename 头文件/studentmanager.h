#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
//学生信息结构体
typedef struct _Student
{
    int stunum;
    char name[20];
    int score;
} Student;

//结点信息
typedef struct _Node
{
    Student data;
    struct _Node* next;
} Node;

//系统状态枚举
typedef enum {
    SYS_INIT,      // 系统初始化
    SYS_RUNNING,   // 正常运行
    SYS_EXIT       // 退出系统
} SystemState;

//用户权限枚举
typedef enum {
    ROLE_ADMIN,
    ROLE_USER
} Role;

//用户信息结构体
typedef struct {
    char username[32];
    Role role;
} User;

//日志记录函数
void log_action(const char *username, const char *action);
void welcome(Role role);
void inputstudent(Node* head);
void printstudent(Node* head);
void countstudents(Node* head);
void findstudent(Node* head);
void savestudents(Node* head);
void loadstudents(Node* head);
void modifystudent(Node* head);
void deletestudent(Node* head);
void clearstudents(Node* head);
void sortstudents(Node* head);
int login(User *user);
#endif