#include"studentmanager.h"
//录入学生信息
void inputstudent(Node* head)
{
    Node* fresh = calloc(1, sizeof(Node));  // ✅ calloc 初始化为0
    if (fresh == NULL) {
        printf("❌ 内存不足\n");
        return;
    }
    fresh->next = NULL;

    printf("学号：");
    scanf("%d", &fresh->data.stunum);
    getchar();

    printf("姓名：");
    scanf("%49s", fresh->data.name);  // ✅ %49s 防止数组越界
    getchar();

    printf("成绩：");
    scanf("%d", &fresh->data.score);
    getchar();

    // 插入链表
    Node* move = head;
    while(move->next != NULL) move = move->next;
    move->next = fresh;
    
    savestudents(head);
    printf("✅ 录入成功！\n");

    //暂停程序
    system("pause");
    //清屏
    system("cls");
}

//打印学生信息
void printstudent(Node* head)
{
    if(head->next == NULL)
    {
        printf("当前无学生信息！\n");

        //暂停程序
        system("pause");
        //清屏
        system("cls");
        return;
    }

    Node* move = head->next;
    printf("学生信息如下：\n");
    printf("学号\t姓名\t成绩\n");
    while(move != NULL)
    {
        printf("%d\t%s\t%d\n", move->data.stunum, move->data.name, move->data.score);
        move = move->next;
    }

    //暂停程序
    system("pause");
    //清屏
    system("cls");

}

//统计学生人数
void countstudents(Node* head)
{
    int count = 0;
    Node* move = head->next;
    while(move != NULL)
    {
        count++;
        move = move->next;
    }
    printf("当前学生人数为：%d\n", count);

    //暂停程序
    system("pause");
    //清屏
    system("cls");

}

//查找学生信息
void findstudent(Node* head)
{
    printf("请输入要查找的学生学号：");
    int stunum;
    scanf("%d", &stunum);

    Node* move = head->next;
    while(move != NULL)
    {
        if(move->data.stunum == stunum)
        {
            printf("找到学生信息：\n");
            printf("学号：%d  ", move->data.stunum);
            printf("姓名：%s  ", move->data.name);
            printf("成绩：%d\n", move->data.score);

            //暂停程序
            system("pause");
            //清屏
            system("cls");
            return;
        }
        move = move->next;
    }
    printf("未找到该学生信息！\n");

    //暂停程序
    system("pause");
    //清屏
    system("cls");

}

//保存学生信息到文件
void savestudents(Node* head)
{
    FILE* fp = fopen("./students.dat", "wb");
    if(fp == NULL)
    {
        printf("无法打开文件进行保存！\n");
        return;
    }

    Node* move = head->next;
    while(move != NULL)
    {
        fwrite(&move->data, sizeof(Student), 1, fp);
        move = move->next;
    }

    fclose(fp);
}

//从文件加载学生信息
void loadstudents(Node* head)
{
    FILE* fp = fopen("./students.dat", "rb");
    if(fp == NULL)
    {
        printf("无法打开文件进行加载！\n");
        return;
    }

    Node* fresh= malloc(sizeof(Node));
    fresh->next = NULL;
    Node* move = head;
    while(fread(&fresh->data, sizeof(Student), 1, fp)==1)
    {
        move->next = fresh;
        move = fresh;
        fresh= malloc(sizeof(Node));
        fresh->next = NULL;
    }
    free(fresh);
    fclose(fp);
    printf("学生信息加载成功！\n");
}

//修改学生信息
void modifystudent(Node* head)
{
    printf("请输入要修改的学生学号：");
    int stunum;
    scanf("%d", &stunum);
    Node* move = head->next;
    while(move != NULL)
    {
        if(move->data.stunum == stunum)
        {
            printf("找到学生信息：\n");
            printf("学号：%d  ", move->data.stunum);
            printf("姓名：%s  ", move->data.name);
            printf("成绩：%d\n", move->data.score);

            printf("请输入新的姓名：");
            scanf("%s", move->data.name);
            printf("请输入新的成绩：");
            scanf("%d", &move->data.score);
            savestudents(head);
            printf("学生信息修改成功！\n");

            //保存修改后的学生信息到文件
            savestudents(head);

            //暂停程序
            system("pause");
            //清屏
            system("cls");

            return;
        }
        move = move->next;
    }
    printf("未找到该学生信息！\n");

    //暂停程序
    system("pause");
    //清屏
    system("cls");

}

//删除学生信息
void deletestudent(Node* head)
{
    printf("请输入要删除的学生学号：");
    int stunum;
    scanf("%d", &stunum);
    Node* move = head;
    while(move->next != NULL)
    {
        if(move->next->data.stunum == stunum)
        {
            Node* temp = move->next;
            move->next = move->next->next;
            free(temp);
            temp = NULL;
            //保存修改后的学生信息到文件
            savestudents(head);
            printf("学生信息删除成功！\n");
            //暂停程序
            system("pause");
            //清屏
            system("cls");

            return;
        }
        move = move->next;
    }
    printf("未找到该学生信息！\n");

    //暂停程序
    system("pause");
    //清屏
    system("cls");

}

//清空学生信息
void clearstudents(Node* head)
{
    Node* move = head->next;
    while(move != NULL)
    {
        Node* temp = move;
        move = move->next;
        free(temp);
    }
    head->next = NULL;
    //保存修改后的学生信息到文件
    savestudents(head);
    printf("所有学生信息已清空！\n");

    //暂停程序
    system("pause");
    //清屏
    system("cls");

}

//按成绩排序
void sortstudents(Node* head)
{
    if(head->next == NULL || head->next->next == NULL)
    {
        printf("学生信息不足，无法排序！\n");
        return;
    }

    //使用冒泡排序法按成绩排序
    int swapped;
    do
    {
        swapped = 0;
        Node* prev = head;
        Node* curr = head->next;
        Node* next = curr->next;

        while(next != NULL)
        {
            if(curr->data.score > next->data.score)
            {
                //交换节点
                curr->next = next->next;
                next->next = curr;
                prev->next = next;

                swapped = 1;

                //更新指针
                prev = next;
                next = curr->next;
            }
            else
            {
                //移动指针
                prev = curr;
                curr = next;
                next = next->next;
            }
        }
    } while(swapped);

    //保存排序后的学生信息到文件
    savestudents(head);
    printf("学生信息已按成绩排序！\n");
    printstudent(head);

    //暂停程序
    system("pause");
    //清屏
    system("cls");
}
