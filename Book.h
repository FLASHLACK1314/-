//
// Created by 26473 on 24-5-6.
//

#ifndef MEDIA_LIBRARY_MANAGEMENTV1_0_BOOK_H
#define MEDIA_LIBRARY_MANAGEMENTV1_0_BOOK_H
#include <string>

class Book {
private:
    std::string number;
    std::string title;
    std::string author;
    std::string rating;
    std::string versionNumber;
    std::string ISBNNumber;
    std::string pageNumber;

public:
    // 构造函数
    Book(const std::string& num, const std::string& t, const std::string& auth, const std::string& rat,
         const std::string& versionNum, const std::string& ISBNNum, const std::string& pageNum);

    // 生成 SQL 插入语句
    std::string generateSQL() const;

    // 生成 SQL 更新语句的方法
    std::string generateUpdateSQL() const;
};

#endif //MEDIA_LIBRARY_MANAGEMENTV1_0_BOOK_H
