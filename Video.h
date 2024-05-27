//
// Created by 26473 on 24-5-6.
//

#ifndef MEDIA_LIBRARY_MANAGEMENTV1_0_VIDEO_H
#define MEDIA_LIBRARY_MANAGEMENTV1_0_VIDEO_H
#include <string>

class Video {
private:
    std::string number;
    std::string title;
    std::string author;
    std::string rating;
    std::string tasterName;
    std::string productionYear;
    std::string videoTime;

public:
    // 构造函数
    Video(const std::string& num, const std::string& t, const std::string& auth, const std::string& rat,
         const std::string& tasterNam, const std::string& productionYea, const std::string& videoTim);

    // 生成 SQL 插入语句
    std::string generateSQL() const;
    // 生成 SQL 更新语句
    std::string generateUpdateSQL() const;
};


#endif //MEDIA_LIBRARY_MANAGEMENTV1_0_VIDEO_H
