#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "person_file.h"

// 从文件中读取数据
int load(Person persons[])
{
	FILE * fp;
	int len = 0;
	Person temp_person;

	fp = fopen("person.dat", "rb");
	if (fp == NULL)
	{
		printf("读取文件person.dat失败，退出当前程序\n");
		exit(-1);
	}

	// 单个读取
	while (fread(&temp_person, sizeof(Person), 1, fp) == TRUE)
	{
		persons[len++] = temp_person;
	}

	fclose(fp);

	printf("\n\n成功从文件中读取数据, 当前录入人数：%d\n\n", len);

	return len;
}

// 保存数据到文件
void save(Person persons[], int len)
{
	FILE * fp;
	int i = 0;

	fp = fopen("person.dat", "wb");
	if (fp == NULL)
	{
		printf("文件person.dat创建失败，退出当前程序\n");
		exit(-1);
	}

	// 单个写入
	for (; i < len; i++)
	{
		fwrite(&persons[i], sizeof(Person), 1, fp);
	}

	fclose(fp);

	printf("成功保存数据到文件\n");
}
