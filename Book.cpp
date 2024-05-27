//
// Created by 26473 on 24-5-6.
//

#include "Book.h"
// 构造函数的定义
Book::Book(const std::string& num, const std::string& t, const std::string& auth, const std::string& rat,
           const std::string& versionNum, const std::string& ISBNNum, const std::string& pageNum)
        : number(num), title(t), author(auth), rating(rat), versionNumber(versionNum),
          ISBNNumber(ISBNNum), pageNumber(pageNum) {}


// 生成 SQL 插入语句的定义
std::string Book::generateSQL() const {
    std::string sql = "INSERT INTO book_table (number, title, author, rating, version_number, ISBN_number, page_number) VALUES ('";
    sql += number + "', '" + title + "', '" + author + "', '" + rating + "', '" + versionNumber + "', '" + ISBNNumber + "', '" + pageNumber + "')";
    return sql;
}
// 在 Book 类中添加一个方法用于生成更新数据库记录的 SQL 语句
std::string Book::generateUpdateSQL() const {
    // 构建 SQL 语句
    std::string sql = "UPDATE book_table SET ";
    sql += "title = '" + title + "', ";  // 更新标题
    sql += "author = '" + author + "', ";  // 更新作者
    sql += "rating = '" + rating + "', ";  // 更新评级
    sql += "version_number = '" + versionNumber + "', ";  // 更新版本号
    sql += "ISBN_number = '" + ISBNNumber + "', ";  // 更新 ISBN 号
    sql += "page_number = '" + pageNumber + "' ";  // 更新页数
    sql += "WHERE number = '" + number + "'";  // 根据编号更新特定的记录
    return sql;
}