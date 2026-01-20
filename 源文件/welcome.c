#include"studentmanager.h"
void welcome(Role role)
{
    printf("*********************************\n");
    printf("*\t学生信息管理系统\t*\n");
    printf("*********************************\n");
    printf("*\t请选择功能列表\t\t*\n");
    printf("*********************************\n");
    if(role == ROLE_ADMIN) 
    {
    // 管理员权限
    printf("*\t（管理员权限）\t\t*\n");

    printf("*\t1.录入学生信息\t\t*\n");
    printf("*\t2.打印学生信息\t\t*\n");
    printf("*\t3.统计学生人数\t\t*\n");
    printf("*\t4.查找学生信息\t\t*\n");
    printf("*\t5.修改学生信息\t\t*\n");
    printf("*\t6.删除学生信息\t\t*\n");
    printf("*\t7.清空学生信息\t\t*\n");
    printf("*\t8.按成绩排序\t\t*\n");
    printf("*\t9.退出系统\t\t*\n");
    }
    else
    {
    // 普通用户权限
    printf("*\t（普通用户权限）\t*\n");

    printf("*\t2.打印学生信息\t\t*\n");
    printf("*\t3.统计学生人数\t\t*\n");
    printf("*\t4.查找学生信息\t\t*\n");
    printf("*\t9.退出系统\t\t*\n");
    } 
    printf("*********************************\n");
}
