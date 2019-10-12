#ifndef _PERSON_H_
#define _PERSON_H_

typedef struct person
{
	// ѧ��
	int num;
	// ����
	char name[30];
	// �Ա�
	char sex;
	// ����
	int age;
	// ��ע
	char remarks[100];
	// �ɼ�
	float score;
}Person;

// �ֹ�¼��
int person_add_manual(Person persons[]);
// �ļ�¼��
int person_add_load_file(Person persons[]);
// �ֹ�¼��(׷��)
int person_add_manual_append(Person persons[], int len);

// ѧ��������Ϣ��ʾ 
void person_print(Person persons[], int len);

// ѧ��������Ϣ���� 
void person_add_save_file(Person persons[], int len);

// ѧ��������Ϣɾ��(��ѧ��)
int person_delete_by_num(Person persons[], int len, int num);

// ѧ��������Ϣ�޸ģ�Ҫ�����������룩 
void person_update_by_num(Person persons[], int len, int num);

// ѧ��������Ϣ��ѯ 
// ��ѧ�Ų�ѯ 
void person_query_by_num(Person persons[], int len, int num);

// ��������ѯ 
void person_query_by_name(Person persons[], int len, char name[]);

// ѧ���ֳܷɼ���ѯ
// �������ѯ
void person_sort_by_score_desc(Person persons[], int len);

// �������ѯ
void person_sort_by_score_asc(Person persons[], int len);

#endif