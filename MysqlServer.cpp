//
// Created by 26473 on 24-5-6.
//

#include "MysqlServer.h"
#include <iomanip>

MYSQL mysql;
MYSQL_RES *res;


//连接数据库
bool ConnectMysql() {
    mysql_init(&mysql);//初始化mysql
    if (!(mysql_real_connect(&mysql,
                             "localhost",//主机 如果是远程就改成服务器的ip地址
                             "root",//用户名
                             "123456",//密码
                             "media_library_management",//数据库名 必须是已经存在的 我的mysql大小写不敏感
                             3306,//端口号 默认的0或者3306
                             NULL, 0//最后两个参数的常用写法 几乎都是这两个
    ))) {
        cout << "Error connecting to database:" + (string) mysql_error(&mysql) << endl;
        return false;
    } else {
        cout << "Connected..." << endl;
        return true;
    }
}

//创建数据库或表 增删改查方法
bool updateData(string sql) {
    mysql_query(&mysql, "set names utf8");//设置编码格式 否则mysql里中文乱码
    // 执行SQL语句
    // 0 执行成功
    // 1 执行失败
    if (mysql_query(&mysql, sql.c_str())) {//mysql_query第二个参数只接受const cahr* 需要将string类型转化
        cout << "数据库报错 ( " + (string) mysql_error(&mysql) + " )" << endl;
        return false;
    } else {
        cout << "数据库操作成功" << endl;
        return true;
    }
}

//查询并输出
bool QueryDatabase(string sql) {
    mysql_query(&mysql, "set names utf8");//设置编码格式 否则cmd下中文乱码
    // 执行SQL语句
    // 0 执行成功
    // 1 执行失败
    // 所以相反
    cout << sql << endl;
    if (mysql_query(&mysql, sql.c_str())) {//mysql_query第二个参数只接受const cahr* 需要将string类型转化
        cout << "数据库报错 ( " + (string) mysql_error(&mysql) + " )" << endl;
        return false;
    } else {
        cout << "数据库操作成功" << endl;
    }

    //获得结果集 MYSQL_RES *res，没有则失败
    if (!(res = mysql_store_result(&mysql))) {
        cout << "无法从数据库中获得信息 " + (string) mysql_error(&mysql) << endl;
        return false;
    }
    // 获取数据行数
    int num_rows = mysql_num_rows(res);

    // 如果没有结果，则输出提示，有则进行打印
    if (num_rows < 1) {
        cout << "没有查询到此数据" << endl;
        return false;
    } else {
        outMysql();//打印结果
    }
    return true;
}

void outMysql() {
    // 打印数据行数
    cout << "查到数据行为: " << mysql_affected_rows(&mysql) << endl;
    cout << "以下为输出结果" << endl;

    char *field[32];//字段名
    int num = mysql_num_fields(res);//获取列数
    vector<int> fieldWidths(num, 0); // 保存每个字段的最大宽度

    // 获取字段名，并计算每个字段的最大宽度
    for (int i = 0; i < num; ++i) {
        field[i] = mysql_fetch_field(res)->name;
        fieldWidths[i] = max(fieldWidths[i], static_cast<int>(strlen(field[i])));
    }

    // 输出表头
    cout << left;
    for (int i = 0; i < num; ++i) {
        cout << setw(fieldWidths[i] + 2) << field[i] << " | ";
    }
    cout << endl;

    // 输出分隔线
    for (int i = 0; i < num; ++i) {
        cout << setw(fieldWidths[i] + 2) << setfill('-') << "" << "+";
    }
    cout << setfill(' ') << endl;

    // 获取每行数据，并更新字段的最大宽度
    MYSQL_ROW column;
    while (column = mysql_fetch_row(res)) {
        for (int i = 0; i < num; ++i) {
            fieldWidths[i] = max(fieldWidths[i], static_cast<int>(strlen(column[i])));
        }
    }

    // 输出数据
    mysql_data_seek(res, 0); // 重新定位到结果集开头
    while (column = mysql_fetch_row(res)) {//获取一行数据
        for (int i = 0; i < num; ++i) {
            // 输出数据并填充空格以保证对齐
            cout << setw(fieldWidths[i] + 2) << left << column[i] << " | ";
        }
        cout << endl;
    }
}

//释放资源
void FreeConnect() {
    mysql_free_result(res);
    mysql_close(&mysql);
}
