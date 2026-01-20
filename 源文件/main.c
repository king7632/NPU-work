#include"studentmanager.h"

/* 菜单指令处理函数
 * 返回值：
 *   0  -> 继续运行
 *  -1  -> 请求退出系统
 */
int handle_command(Node* head, User* user)
{
    welcome(user->role);
    printf("\n请输入指令：");

    int c;
    if (scanf("%d", &c) != 1) {
        printf("请输入数字指令！\n");
        while (getchar() != '\n');  // 清空输入缓冲区
        return 0;
    }
    getchar();  // 吸收回车

    switch (c)
    {
        case 1:
            if (user->role != ROLE_ADMIN) 
            {
              printf("权限不足\n");
              //  记录未授权录入尝试
              log_action(user->username, "unauthorized input attempt");
              //暂停程序
              system("pause");
              //清屏
              system("cls");
              break;
            }
            printf("录入学生信息\n");
            // 记录录入操作
            log_action(user->username, "input student");
            inputstudent(head);
            break;
        case 2:
            printf("打印学生信息\n");
            // 记录打印操作
            log_action(user->username, "print students");
            printstudent(head);
            break;
        case 3:
            printf("统计学生人数\n");
            // 记录统计操作
            log_action(user->username, "count students");
            countstudents(head);
            break;
        case 4:
            printf("查找学生信息\n");
            // 记录查找操作
            log_action(user->username, "find student");
            findstudent(head);
            break;
        case 5:
            if (user->role != ROLE_ADMIN) 
            {
              printf("权限不足\n");
                // 记录未授权修改尝试
                log_action(user->username, "unauthorized modify attempt");
              //暂停程序
              system("pause");
              //清屏
            system("cls");
              break;
            }
            printf("修改学生信息\n");
            // 记录修改操作
            log_action(user->username, "modify student");
            modifystudent(head);
            break;
        case 6:
            if (user->role != ROLE_ADMIN) 
            {
              printf("权限不足\n");
              // 记录未授权删除尝试
              log_action(user->username, "unauthorized delete attempt");
              //暂停程序
              system("pause");
              //清屏
              system("cls");
              break;
            }
            printf("删除学生信息\n");
            // 记录删除操作
            log_action(user->username, "delete student");
            deletestudent(head);
            break;
        case 7:
            if (user->role != ROLE_ADMIN) 
            {
              printf("权限不足\n");
              // 记录未授权清空尝试
              log_action(user->username, "unauthorized clear attempt");
              //暂停程序
              system("pause");
              //清屏
              system("cls");
              break;
            }
            printf("清空学生信息\n");
            // 记录清空操作
            log_action(user->username, "clear all students");
            clearstudents(head);
            break;
        case 8:
            if (user->role != ROLE_ADMIN) 
            {
              printf("权限不足\n");
              // 记录未授权排序尝试
              log_action(user->username, "unauthorized sort attempt");
              //暂停程序
              system("pause");
              //清屏
              system("cls");
              break;
            }
            printf("按成绩排序\n");
            // 记录排序操作
            log_action(user->username, "sort students by score");
            sortstudents(head);
            break;
        case 9:
            printf("退出系统\n");
            return -1;   // 通知主程序退出
        default:
            printf("无效指令，请重新输入！\n");

            //暂停程序
            system("pause");
            //清屏
            system("cls");
            break;
    }
    return 0;
}

User current_user;

int main(void)
{
    /* 设置控制台编码（Windows） */
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    /* 系统状态 */
    SystemState state = SYS_INIT;

    /* 创建头结点 */
    Node* head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        printf("内存分配失败，程序退出。\n");
        return -1;
    }
    head->next = NULL;

    /* 主状态机循环 */
    while (state != SYS_EXIT)
    {
        switch (state)
        {
            case SYS_INIT:
                /* 系统初始化阶段 */
                loadstudents(head);
                if (login(&current_user) == 0)
                {
                  printf("欢迎，%s！\n", current_user.username);
                  state = SYS_RUNNING;
                }
                else
                {
                  state = SYS_EXIT;
                }
                break;

            case SYS_RUNNING:
                /* 系统运行阶段 */
                if (handle_command(head, &current_user) < 0) {
                    state = SYS_EXIT;
                }
                break;

            default:
                state = SYS_EXIT;
                break;
        }
    }

    /* 系统退出清理 */
    free(head);            // 释放头结点

    printf("系统已安全退出。\n");
    return 0;
}