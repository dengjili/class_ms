#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "menu_ui.h"
#include "person.h"

/** 
ʵ��https://wenku.baidu.com/view/1c3c22124431b90d6c85c72f.html�Ŀ��У������
*/

// ����ֵ
int input();
void input_string(char str[]);
// ����������ʾ
void input_error_show();

int main()
{
	Person persons[SIZE];
	// ������������
	int choice, len = 0, working;
	char choice_name[30];

	// �����Ƿ�����(1�����У�0����ֹ)
	int is_runing = RUNNING;

	while (is_runing)
	{
		main_ui();
		
		choice = input();
		switch (choice)
		{
		case 1:
			working = TRUE;
			while (working)
			{
				person_add_ui();
				choice = input();
				switch (choice) 
				{
				case 1:
					len = person_add_manual(persons);
					break;
				case 2:
					len = person_add_load_file(persons);
					break;
				case 3:
					len = person_add_manual_append(persons, len);
					break;
				case 4:
					working = FALSE;
					break;
				default:
					input_error_show();
				}
			}
			break;
		case 2:
			person_print(persons, len);
			break;
		case 3:
			person_add_save_file(persons, len);
			break;
		case 4:
			printf("ѧ��������Ϣɾ������ѧ��ɾ����");
			choice = input();
			len = person_delete_by_num(persons, len, choice);
			break;
		case 5:
			printf("ѧ��������Ϣ�޸ģ�ѡ����Ҫ�޸ĵ�ѧ�ţ�");
			choice = input();
			person_update_by_num(persons, len, choice);
			break;
		case 6:
			working = TRUE;
			while (working)
			{
				person_info_ui();
				choice = input();
				switch (choice) 
				{
				case 1:
					printf("ѧ��������Ϣ��ѯ����ѧ�Ų�ѯ��");
					choice = input();
					person_query_by_num(persons, len, choice);
					break;
				case 2:
					printf("ѧ��������Ϣ��ѯ����ѧ�Ų�ѯ��");
					input_string(choice_name);
					person_query_by_name(persons, len, choice_name);
					break;
				case 3:
					working = FALSE;
					break;
				default:
					input_error_show();
				}
			}
			break;
		case 7:
			working = TRUE;
			while (working)
			{
				score_ui();
				choice = input();
				switch (choice) 
				{
				case 1:
					person_sort_by_score_desc(persons, len);
					break;
				case 2:
					person_sort_by_score_asc(persons, len);
					break;
				case 3:
					working = FALSE;
					break;
				default:
					input_error_show();
				}
			}
			break;
		case 8:
			is_runing = STOP;
			break;
		default:
			input_error_show();
		}
	}

	printf("\n\n���˳�...\n\n");

	return 0;
}

int input()
{
	// ������
	int num;

	printf("\n\n��ѡ��");
	scanf("%d", &num);

	return num;
}

void input_string(char str[])
{
	printf("\n\n�����룺");
	scanf("%s", str);
}

void input_error_show()
{
	printf("\n\n�������ָ��Ƿ���������ѡ�񣨰������������\n\n");
	system("pause");
}