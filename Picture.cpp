//
// Created by 26473 on 24-5-6.
//

#include "Picture.h"
// 构造函数的定义
Picture::Picture(const std::string& num, const std::string& t, const std::string& auth, const std::string& rat,
                 const std::string& internat, const std::string& leng, const std::string& wid)
        : number(num), title(t), author(auth), rating(rat), international(internat),
          length(leng), width(wid) {}

// 生成 SQL 插入语句的定义
std::string Picture::generateSQL() const {
    std::string sql = "INSERT INTO picture_table (number, title, author, rating, international, length, width) VALUES ('";
    sql += number + "', '" + title + "', '" + author + "', '" + rating + "', '" + international + "', '" + length + "', '" + width + "')";
    return sql;
}
// 生成 SQL 更新语句
std::string Picture::generateUpdateSQL() const {
    std::string sql = "UPDATE picture_table SET ";
    sql += "title = '" + title + "', ";
    sql += "author = '" + author + "', ";
    sql += "rating = '" + rating + "', ";
    sql += "international = '" + international + "', ";
    sql += "length = '" + length + "', ";
    sql += "width = '" + width + "' ";
    sql += "WHERE number = '" + number + "'";
    return sql;
}