//
// Created by 26473 on 24-5-6.
//

#ifndef MEDIA_LIBRARY_MANAGEMENTV1_0_MYSQLSERVER_H
#define MEDIA_LIBRARY_MANAGEMENTV1_0_MYSQLSERVER_H

#include <mysql.h>
#include <bits/stdc++.h>
using namespace std;

bool ConnectMysql();//连接数据库
bool QueryDatabase(string sql);//查询并输出结果
void outMysql();//输出查询结果
bool updateData(string sql);//插入删除修改操作
void FreeConnect();//释放资源


#endif //MEDIA_LIBRARY_MANAGEMENTV1_0_MYSQLSERVER_H
