#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "person_file.h"

// ���ļ��ж�ȡ����
int load(Person persons[])
{
	FILE * fp;
	int len = 0;
	Person temp_person;

	fp = fopen("person.dat", "rb");
	if (fp == NULL)
	{
		printf("��ȡ�ļ�person.datʧ�ܣ��˳���ǰ����\n");
		exit(-1);
	}

	// ������ȡ
	while (fread(&temp_person, sizeof(Person), 1, fp) == TRUE)
	{
		persons[len++] = temp_person;
	}

	fclose(fp);

	printf("\n\n�ɹ����ļ��ж�ȡ����, ��ǰ¼��������%d\n\n", len);

	return len;
}

// �������ݵ��ļ�
void save(Person persons[], int len)
{
	FILE * fp;
	int i = 0;

	fp = fopen("person.dat", "wb");
	if (fp == NULL)
	{
		printf("�ļ�person.dat����ʧ�ܣ��˳���ǰ����\n");
		exit(-1);
	}

	// ����д��
	for (; i < len; i++)
	{
		fwrite(&persons[i], sizeof(Person), 1, fp);
	}

	fclose(fp);

	printf("�ɹ��������ݵ��ļ�\n");
}
