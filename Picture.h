//
// Created by 26473 on 24-5-6.
//

#ifndef MEDIA_LIBRARY_MANAGEMENTV1_0_PICTURE_H
#define MEDIA_LIBRARY_MANAGEMENTV1_0_PICTURE_H

#include <string>

class Picture {
private:
    std::string number;
    std::string title;
    std::string author;
    std::string rating;
    std::string international;
    std::string length;
    std::string width;

public:
    // 构造函数
    Picture(const std::string &num, const std::string &t, const std::string &auth, const std::string &rat,
            const std::string &internat, const std::string &leng, const std::string &wid);

    // 生成 SQL 插入语句
    std::string generateSQL() const;

    // 生成 SQL 更新语句
    std::string generateUpdateSQL() const;
};


#endif //MEDIA_LIBRARY_MANAGEMENTV1_0_PICTURE_H
