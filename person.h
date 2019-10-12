#ifndef _PERSON_H_
#define _PERSON_H_

typedef struct person
{
	// 学号
	int num;
	// 姓名
	char name[30];
	// 性别
	char sex;
	// 年龄
	int age;
	// 备注
	char remarks[100];
	// 成绩
	float score;
}Person;

// 手工录入
int person_add_manual(Person persons[]);
// 文件录入
int person_add_load_file(Person persons[]);
// 手工录入(追加)
int person_add_manual_append(Person persons[], int len);

// 学生基本信息显示 
void person_print(Person persons[], int len);

// 学生基本信息保存 
void person_add_save_file(Person persons[], int len);

// 学生基本信息删除(按学号)
int person_delete_by_num(Person persons[], int len, int num);

// 学生基本信息修改（要求先输入密码） 
void person_update_by_num(Person persons[], int len, int num);

// 学生基本信息查询 
// 按学号查询 
void person_query_by_num(Person persons[], int len, int num);

// 按姓名查询 
void person_query_by_name(Person persons[], int len, char name[]);

// 学生总分成绩查询
// 按降序查询
void person_sort_by_score_desc(Person persons[], int len);

// 按升序查询
void person_sort_by_score_asc(Person persons[], int len);

#endif