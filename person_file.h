#include "person.h"

#ifndef _PERSON_FILE_H_
#define _PERSON_FILE_H_

// 从文件中读取数据
int load(Person persons[]);
// 保存数据到文件
void save(Person persons[], int len);

#endif