# class_ms
原题目要求是对一个有N个学生的班级，通过该系统实现对该班级学生的基本信息进行录入、
显示、修改、删除、保存等操作的管理。

    项目改造为指针使用版本

**主要掌握点包括**

* 结构体的使用
* 数组的使用
* 增删改查的基本概念
* 基本的比较、排序、查找算法
* 文件的读取、写入
  
## 功能点列表

1. 本系统采用一个包含N个数据的结构体数组，每个数据的结构应当包括：学
号、姓名、性别、年龄、备注。
2. 本系统显示这样的菜单：
	* 学生基本信息录入
		1. 手工录入
		2. 文件录入
		3. 手工录入(追加)
	* 学生基本信息显示
	* 学生基本信息保存
	* 学生基本信息删除
	* 学生基本信息修改 ~~（要求先输入密码）~~
	* 学生基本信息查询
		1. 按学号查询
		2. 按姓名查询
	* 学生总分成绩查询
		1. 按降序查询
		2. 按升序查询
	* 退出系统
3. 执行一个具体的功能之后，程序将重新显示菜单。
4. 将学生基本信息保存到文件中。
5. ~~进入系统之前要先输入密码。~~

`其中删除线功能未实现，如果有兴趣实现可以向我Pull requests，功能实现不负责，有一点需要注意，输入密码需要使用****等覆盖，不能显示明文`


## 使用

* 压缩包下载： [Download Zip](https://github.com/dengjili/class_ms/archive/master.zip)
* 或者git命令下载： 
  ```git clone git@github.com:dengjili/class_ms.git```

* 直接运行项目
![新建项目](https://raw.githubusercontent.com/dengjili/class_ms/master/picture/import_1.png "新建项目")

![运行界面](https://raw.githubusercontent.com/dengjili/class_ms/master/picture/run_1.png "运行界面")


## 功能演示



