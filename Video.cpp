//
// Created by 26473 on 24-5-6.
//

#include "Video.h"

// 构造函数的定义
Video::Video(const std::string& num, const std::string& t, const std::string& auth, const std::string& rat,
             const std::string& tasterNam, const std::string& productionYea, const std::string& videoTim)
        : number(num), title(t), author(auth), rating(rat), tasterName(tasterNam),
          productionYear(productionYea), videoTime(videoTim) {}

// 生成 SQL 插入语句的定义
std::string Video::generateSQL() const {
    std::string sql = "INSERT INTO video_table(number, title, author, rating, taster_name, production_year, video_time) VALUES ('";
    sql += number + "', '" + title + "', '" + author + "', '" + rating + "', '" + tasterName + "', '" + productionYear + "', '" + videoTime + "')";
    return sql;
}
// 生成SQL 更新语句的定义
std::string Video::generateUpdateSQL() const {
    std::string sql = "UPDATE video_table SET ";
    sql += "title = '" + title + "', ";
    sql += "author = '" + author + "', ";
    sql += "rating = '" + rating + "', ";
    sql += "taster_name = '" + tasterName + "', ";
    sql += "production_year = '" + productionYear + "', ";
    sql += "video_time = '" + videoTime + "' ";
    sql += "WHERE number = '" + number + "'";
    return sql;
}
