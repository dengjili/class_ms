#include <stdio.h>
#include <string.h>
#include "global.h"
#include "person_file.h"
#include "person.h"

int person_add_manual(Person persons[])
{
	return person_add_manual_append(persons, 0);
}

int person_add_manual_append(Person persons[], int len)
{
	Person temp_person;

	printf("请录入学号 姓名 性别 年龄 备注 成绩(学号小于0终止)\n");
	while (len < SIZE)
	{
		printf("请录入第%d个信息：", len + 1);
		scanf("%d %s %c %d %s %f", &temp_person.num, temp_person.name, &temp_person.sex, &temp_person.age, temp_person.remarks, &temp_person.score);
	
		if (temp_person.num <= 0)
		{
			break;
		}
		persons[len++] = temp_person;
	}
	printf("\n\n录入成功, 当前录入人数：%d\n\n", len);
	return len;
}

int person_add_load_file(Person persons[])
{
	return load(persons);
}

void person_print(Person persons[], int len)
{
	int i = 0;
	printf("%-10s%-10s%-10s%-10s%-20s%-10s\n", "学号", "姓名", "性别", "年龄", "备注", "成绩");
	for (; i < len; i++)
	{
		printf("%-10d%-10s%-10c%-10d%-20s%-10.1f\n", persons[i].num, persons[i].name, persons[i].sex, persons[i].age, persons[i].remarks, persons[i].score);
	}
}

void person_add_save_file(Person persons[], int len)
{
	save(persons, len);
}

int person_delete_by_num(Person persons[], int len, int num)
{
	// 寻找输入是否有对应的学号
	int i = 0;
	for (; i < len; i++)
	{
		if (persons[i].num == num)
		{
			break;
		}
	}

	// 如果未找到
	if (i == len)
	{
		printf("\n\n当前数据中，没有学号：%d，请核对\n\n", num);
		return len;
	}

	// 如果找到，那么数组移动位置，从找到处开始：i + 1 = i
	for (; i < len; i++)
	{
		persons[i] = persons[i + 1];
	}

	printf("\n\n成功删除学号：%d\n\n", num);
	return len - 1;
}

void person_update_by_num(Person persons[], int len, int num)
{
	// 寻找输入是否有对应的学号
	int i = 0;
	for (; i < len; i++)
	{
		if (persons[i].num == num)
		{
			break;
		}
	}

	// 如果未找到
	if (i == len)
	{
		printf("\n\n当前数据中，没有学号：%d，请核对\n\n", num);
		return;
	}

	// 如果找到，那么数组移动位置，从找到处开始：i + 1 = i
	printf("请重新录入 姓名 性别 年龄 备注 成绩：");
	scanf("%s %c %d %s %f", persons[i].name, &persons[i].sex, &persons[i].age, persons[i].remarks, &persons[i].score);

	printf("\n\n成功修改学号：%d\n\n", num);
}


void person_query_by_num(Person persons[], int len, int num)
{
	// 寻找输入是否有对应的学号
	int i = 0;
	for (; i < len; i++)
	{
		if (persons[i].num == num)
		{
			break;
		}
	}

	// 如果未找到
	if (i == len)
	{
		printf("\n\n当前数据中，没有学号：%d，请核对\n\n", num);
		return;
	}

	// 如果找到，输出
	printf("%-10s%-10s%-10s%-10s%-20s%-10s\n", "学号", "姓名", "性别", "年龄", "备注", "成绩");
	printf("%-10d%-10s%-10c%-10d%-20s%-10.1f\n", persons[i].num, persons[i].name, persons[i].sex, persons[i].age, persons[i].remarks, persons[i].score);
}

void person_query_by_name(Person persons[], int len, char name[])
{
	// 寻找输入是否有对应的姓名
	int i = 0;
	for (; i < len; i++)
	{
		if (strcmp(persons[i].name, name) == 0)
		{
			break;
		}
	}

	// 如果未找到
	if (i == len)
	{
		printf("\n\n当前数据中，没有姓名：%s，请核对\n\n", name);
		return;
	}

	// 如果找到，输出
	printf("%-10s%-10s%-10s%-10s%-20s%-10s\n", "学号", "姓名", "性别", "年龄", "备注", "成绩");
	printf("%-10d%-10s%-10c%-10d%-20s%-10.1f\n", persons[i].num, persons[i].name, persons[i].sex, persons[i].age, persons[i].remarks, persons[i].score);
}

void person_sort_by_score_desc(Person persons[], int len)
{
	Person persons_sort[SIZE];
	int i = 0, j = 0;

	// 1. 拷贝
	for (i = 0; i < len; i++)
	{
		persons_sort[i] = persons[i];
	}

	// 2. 排序（选择排序）
	for (i = 0; i < len - 1; i++)
	{
		// 第i个是需要与最小的min交换的
		int max = i;
		for (j = i + 1; j < len; j++)
		{
			if (persons_sort[max].score < persons_sort[j].score)
			{
				max = j;
			}
		}

		if (max != i)
		{
			Person temp = persons_sort[i];
			persons_sort[i] = persons_sort[max];
			persons_sort[max] = temp;
		}
	}

	// 3. 输出
	printf("%-10s%-10s%-10s%-10s%-20s%-10s\n", "学号", "姓名", "性别", "年龄", "备注", "成绩");
	for (i = 0; i < len; i++)
	{
		printf("%-10d%-10s%-10c%-10d%-20s%-10.1f\n", persons_sort[i].num, persons_sort[i].name, persons_sort[i].sex, persons_sort[i].age, persons_sort[i].remarks, persons_sort[i].score);
	}
}

// 升序
void person_sort_by_score_asc(Person persons[], int len)
{
	Person persons_sort[SIZE];
	int i = 0, j = 0;

	// 1. 拷贝
	for (i = 0; i < len; i++)
	{
		persons_sort[i] = persons[i];
	}

	// 2. 排序（选择排序）
	for (i = 0; i < len - 1; i++)
	{
		// 第i个是需要与最小的min交换的
		int min = i;
		for (j = i + 1; j < len; j++)
		{
			if (persons_sort[min].score > persons_sort[j].score)
			{
				min = j;
			}
		}

		if (min != i)
		{
			Person temp = persons_sort[i];
			persons_sort[i] = persons_sort[min];
			persons_sort[min] = temp;
		}
	}

	// 3. 输出
	printf("%-10s%-10s%-10s%-10s%-20s%-10s\n", "学号", "姓名", "性别", "年龄", "备注", "成绩");
	for (i = 0; i < len; i++)
	{
		printf("%-10d%-10s%-10c%-10d%-20s%-10.1f\n", persons_sort[i].num, persons_sort[i].name, persons_sort[i].sex, persons_sort[i].age, persons_sort[i].remarks, persons_sort[i].score);
	}
}