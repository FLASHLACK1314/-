#include <iostream>

#include <string>
#include "MysqlServer.h"
#include "Help.h"
#include "Book.h"
#include "Video.h"
#include "Picture.h"

// 主函数
int main() {
    //循环开始状态
    bool running = true;
    while (running) {
        cout << "***************************************" << endl;
        cout << "媒体库管理系统设计" << endl;
        cout << "1. 添加物品" << endl;
        cout << "2. 查询物品" << endl;
        cout << "3. 显示物品" << endl;
        cout << "4. 修改物品" << endl;
        cout << "5. 删除物品" << endl;
        cout << "6. 帮助" << endl;
        cout << "9. 重新开始" << endl;
        cout << "0. 退出程序" << endl;
        if(ConnectMysql()){
            cout << "已连接上数据库可以进行操作" << endl;
        }else{
            cout << "连接数据库失败请重新打开此程序或者输入9重试" << endl;
        }
        cout << "请输入: ";
        int choice;
        cin >> choice;
        //进行匹配
        switch (choice) {
            case 1: {
                cout << "您选择了添加物品" << endl;
                cout << "请选择物品的类别" << endl;
                cout << "1. 添加图书类" << endl;
                cout << "2. 添加视频光盘类" << endl;
                cout << "3. 添加图画类" << endl;
                cout << "4. 回到主界面" << endl;
                cout << "请输入: " << endl;
                int choice2;
                cin >> choice2;
                switch (choice2) {
                    case 1: {
                        int choice3;
                        string number, title, author, rating, versionNumber, ISBNNumber, pageNumber;
                        cout << "您选择添加图书类" << endl;
                        cout << "注意按下回车后不可以修改信息" << endl;
                        cout << "请输入编号（不可以0为开头）: " << endl;
                        cin >> number;
                        // 消除一行以防空格传入数据库
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "请输入标题: " << endl;
                        // 整行传入
                        getline(cin, title);
                        cout << "请输入作者: " << endl;
                        getline(cin, author);
                        cout << "请输入评级: " << endl;
                        cin >> rating;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "请输入版号: " << endl;
                        cin >> versionNumber;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "请输入ISBN码: " << endl;
                        cin >> ISBNNumber;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "请输入页数: " << endl;
                        cin >> pageNumber;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        //再次确定
                        cout << "是否要添加？不添加输入0，添加任意输入" << endl;
                        cin >> choice3;
                        switch (choice3) {
                            case 1: {
                                //连接数据库
                                //进行数据库插入
                                if (updateData(
                                        "INSERT INTO number_table (number, category) VALUES ('" + number +
                                        "', 'book')")) {
                                    //实例化book
                                    Book book(number, title, author, rating, versionNumber, ISBNNumber, pageNumber);
                                    //生成数据库语言
                                    string sql = book.generateSQL();
                                    //插入数据库
                                    if (updateData(sql)) {
                                        cout << "图书类添加成功" << endl;
                                    } else {
                                        cout << "图书类添加失败" << endl;
                                        updateData("DELETE FROM number_table WHERE number ='" + number + "'");
                                    }
                                    cin.get();
                                    cout << "按下回车回到主界面" << endl;
                                    cin.get();
                                    break;
                                } else {
                                    cin.get();
                                    cout << "编号重复" << endl;
                                    cout << "按下回车回到主界面" << endl;
                                    cin.get();
                                    break;
                                }
                            }
                            case 0: {
                                cin.get();
                                cout << "按下回车回到主界面" << endl;
                                cin.get();
                                break;
                            }
                            default: {
                                cout << "无效输入！按下回车回到主界面!" << endl;
                                cin.get();
                                cin.get();
                                break;
                            }
                        }
                        break;
                    }
                    case 2 : {
                        int choice3;
                        string number, title, author, rating, tasterName, productionYear, videoTime;
                        cout << "您选择添加视频光盘类" << endl;
                        cout << "注意按下回车后不可以修改信息" << endl;
                        cout << "请输入编号（不可以0为开头）: " << endl;
                        cin >> number;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "请输入标题: " << endl;
                        getline(cin, title);
                        cout << "请输入作者" << endl;
                        getline(cin, author);
                        cout << "请输入评级" << endl;
                        cin >> rating;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "输入品者名字" << endl;
                        getline(cin, tasterName);
                        cout << "输入出品年份" << endl;
                        cin >> productionYear;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "输入时长" << endl;
                        cin >> videoTime;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "是否要添加？添加输入1，不添加输入0" << endl;
                        cin >> choice3;
                        switch (choice3) {
                            case 1: {
                                if (updateData("INSERT INTO number_table(number,category) VALUES('" + number +
                                               "', 'video')")) {
                                    Video video(number, title, author, rating, tasterName, productionYear, videoTime);
                                    string sql = video.generateSQL();
                                    if (updateData(sql)) {
                                        cout << "视频光盘类添加成功" << endl;
                                    } else {
                                        cout << "视频光盘类添加失败" << endl;
                                        updateData("DELETE FROM number_table WHERE number ='" + number + "'");
                                    }
                                    cin.get();
                                    cout << "按下回车回到主界面" << endl;
                                    cin.get();
                                    break;
                                } else {
                                    cout << "编号重复" << endl;
                                    cin.get();
                                    cout << "按下回车回到主界面" << endl;
                                    cin.get();
                                    break;
                                }
                            }
                            case 0: {
                                cin.get();
                                cout << "按下回车回到主界面" << endl;
                                cin.get();
                                break;
                            }
                            default: {
                                cout << "无效输入！按下回车回到主界面" << endl;
                                cin.get();
                                cin.get();
                                break;
                            }
                        }
                        break;
                    }
                    case 3 : {
                        int choice3;
                        string number, title, author, rating, internation, length, width;
                        cout << "您选择了图画类" << endl;
                        cout << "注意按下回车后的消息不可更改" << endl;
                        cout << "请输入编号(不可以0为开头)" << endl;
                        cin >> number;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "请输入标题" << endl;
                        getline(cin, title);
                        cout << "请输入作者" << endl;
                        getline(cin, author);
                        cout << "请输入评级" << endl;
                        cin >> rating;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "请输入作者国籍" << endl;
                        getline(cin, internation);
                        cout << "请输入长（单位为cm）" << endl;
                        cin >> length;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "请输入宽（单位为cm）" << endl;
                        cin >> width;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "是否要添加？添加输入1，不添加输入0" << endl;
                        cin >> choice3;
                        switch (choice3) {
                            case 1: {
                                if (updateData("INSERT INTO number_table(number,category) VALUES('" + number +
                                               "', 'picture')")) {
                                    Picture picture(number, title, author, rating, internation, length, width);
                                    string sql = picture.generateSQL();
                                    if (updateData(sql)) {
                                        cout << "图画类添加成功" << endl;
                                    } else {
                                        cout << "图画类添加失败" << endl;
                                        updateData("DELETE FROM number_table WHERE number ='" + number + "'");
                                    }
                                    cin.get();
                                    cout << "按下回车回到主界面" << endl;
                                    cin.get();
                                    break;
                                } else {
                                    cout << "编号重复" << endl;
                                    cin.get();
                                    cout << "按下回车回到主界面" << endl;
                                    cin.get();
                                    break;
                                }
                            }
                            case 0: {
                                cin.get();
                                cout << "按下回车回到主界面" << endl;
                                cin.get();
                                break;
                            }
                            default: {
                                cout << "无效输入！按下回车回到主界面！" << endl;
                                cin.get();
                                cin.get();
                                break;
                            }
                        }
                        break;
                    }
                    case 4 : {
                        cout << "按下回车回到主界面" << endl;
                        cin.get();
                        cin.get();
                        break;
                    }
                    default:
                        cout << "无效输入！按下回车回到主界面" << endl;
                        cin.get();
                        cin.get();
                        break;
                }
                break;
            }
            case 2: {
                cout << "您选择了查询物品" << endl;
                cout << "请输入您的需求" << endl;
                cout << "1.查询图书类" << endl;
                cout << "2.查询视频光盘类" << endl;
                cout << "3.查询图画类" << endl;
                cout << "4.回到主界面" << endl;
                cout << "请输入:" << endl;
                int choice3;
                cin >> choice3;
                switch (choice3) {
                    case 1: {
                        cout << "您选择了查询图书类" << endl;
                        cout << "如何查询？" << endl;
                        cout << "1.按标题查询" << endl;
                        cout << "2.按编号查询" << endl;
                        int choice4;
                        cin >> choice4;
                        switch (choice4) {
                            case 1: {
                                string title;
                                cout << "您选择了标题查询" << endl;
                                cout << "请输入标题" << endl;
                                cin >> title;
                                QueryDatabase("SELECT * FROM book_table WHERE title = '" + title + "'");
                                cin.get();
                                cout << "按下回车回到主界面" << endl;
                                cin.get();
                                break;
                            }
                            case 2: {
                                string number;
                                cout << "您选择了编号查询" << endl;
                                cout << "请输入编号" << endl;
                                cin >> number;
                                QueryDatabase("SELECT * FROM book_table WHERE number = '" + number + "'");
                                cin.get();
                                cout << "按下回车回到主界面" << endl;
                                cin.get();
                                break;
                            }
                            default: {
                                cout << "输入无效！按下回车回到主界面！" << endl;
                                cin.get();
                                cin.get();
                                break;
                            }
                        }
                        break;
                    }
                    case 2: {
                        cout << "您选择视频光盘类查询" << endl;
                        cout << "如何查询？" << endl;
                        cout << "1.按标题查询" << endl;
                        cout << "2.按编号查询" << endl;
                        cout << "请输入:" << endl;
                        int choice5;
                        cin >> choice5;
                        switch (choice5) {
                            case 1: {
                                string title;
                                cout << "您选择了标题查询" << endl;
                                cout << "请输入标题" << endl;
                                cin >> title;
                                QueryDatabase("SELECT * FROM video_table WHERE title = '" + title + "'");
                                cin.get();
                                cout << "按下回车回到主界面" << endl;
                                cin.get();
                                break;
                            }
                            case 2: {
                                string number;
                                cout << "您选择了编号查询" << endl;
                                cout << "请输入编号" << endl;
                                cin >> number;
                                QueryDatabase("SELECT * FROM video_table WHERE number = '" + number + "'");
                                cin.get();
                                cout << "按下回车回到主界面" << endl;
                                cin.get();
                                break;
                            }
                            default: {
                                cout << "输入无效！按下回车回到主界面！" << endl;
                                cin.get();
                                cin.get();
                                break;
                            }
                        }
                        break;
                    }
                    case 3: {
                        cout << "您选择了图画类查询" << endl;
                        cout << "如何查询？" << endl;
                        cout << "1.按标题查询" << endl;
                        cout << "2.按编号查询" << endl;
                        cout << "请输入:" << endl;
                        int choice6;
                        cin >> choice6;
                        switch (choice6) {
                            case 1: {
                                string title;
                                cout << "您选择了标题查询" << endl;
                                cout << "请输入标题" << endl;
                                cin >> title;
                                QueryDatabase("SELECT * FROM picture_table WHERE title = '" + title + "'");
                                cin.get();
                                cout << "按下回车回到主界面" << endl;
                                cin.get();
                                break;
                            }
                            case 2: {
                                string number;
                                cout << "您选择了编号查询" << endl;
                                cout << "请输入编号" << endl;
                                cin >> number;
                                QueryDatabase("SELECT * FROM picture_table WHERE number = '" + number + "'");
                                cin.get();
                                cout << "按下回车回到主界面" << endl;
                                cin.get();
                                break;
                            }
                            default: {
                                cout << "无效输入！按下回车回到主界面" << endl;
                                cin.get();
                                cin.get();
                                break;
                            }
                        }
                        break;
                    }
                    case 4: {
                        cout << "按下回车回到主界面" << endl;
                        cin.get();
                        cin.get();
                        break;
                    }
                    default: {
                        cout << "无效输入！按下回车回到主界面" << endl;
                        cin.get();
                        cin.get();
                        break;
                    }
                }
                break;
            }
            case 3: {
                cout << "您选择了显示物品库" << endl;
                cout << "该显示哪个物品库" << endl;
                cout << "1.图书类" << endl;
                cout << "2.视频光盘类" << endl;
                cout << "3.图画类" << endl;
                cout << "4.回到主界面" << endl;
                cout << "请输入:" << endl;
                int choice7;
                cin >> choice7;
                switch (choice7) {
                    case 1 : {
                        cout << "显示图书类物品库" << endl;
                        if (QueryDatabase("SELECT * FROM book_table ")) {
                            cout << "以上为图书类物品库" << endl;
                        } else {
                            cout << "显示失败" << endl;
                        }
                        cin.get();
                        cout << "按下回车回到主界面" << endl;
                        cin.get();
                        break;
                    }
                    case 2: {
                        cout << "显示视频光盘类物品库" << endl;
                        if (QueryDatabase("SELECT * FROM video_table ")) {
                            cout << "以上为视频光盘类物品库" << endl;
                        } else {
                            cout << "显示失败" << endl;
                        }
                        cin.get();
                        cout << "按下回车回到主界面" << endl;
                        cin.get();
                        break;
                    }
                    case 3 : {
                        cout << "显示图画类物品库" << endl;
                        if (QueryDatabase("SELECT * FROM picture_table ")) {
                            cout << "以上为图画类物品库" << endl;
                        } else {
                            cout << "显示失败" << endl;
                        }
                        cin.get();
                        cout << "按下回车回到主界面" << endl;
                        cin.get();
                        break;
                    }
                    case 4 : {
                        cout << "按下回车回到主界面" << endl;
                        cin.get();
                        cin.get();
                        break;
                    }
                    default: {
                        cout << "无效输入！按下回车回到主界面！" << endl;
                        cin.get();
                        cin.get();
                        break;
                    }
                }
                break;
            }
            case 4: {
                int choice8;
                cout << "您选择了修改物品" << endl;
                cout << "1.选择修改物品的类别" << endl;
                cout << "2.回到主界面" << endl;
                cout << "请输入:" << endl;
                cin >> choice8;
                switch (choice8) {
                    case 1: {
                        int choice9;
                        cout << "请选择修改物品类别" << endl;
                        cout << "1.图书类" << endl;
                        cout << "2.视频光盘类" << endl;
                        cout << "3.图画类" << endl;
                        cout << "请输入:" << endl;
                        cin >> choice9;
                        switch (choice9) {
                            case 1: {
                                string number;
                                cout << "请输入要修改的图书类的编号" << endl;
                                cin >> number;
                                if (QueryDatabase("SELECT * FROM book_table WHERE number = '" + number + "'")) {
                                    cout << "查询到可修改的图书类数据(上图)" << endl;
                                    cout << "进行图书表数据修改" << endl;
                                    string title, author, rating, versionNumber, ISBNNumber, pageNumber;
                                    // 消除一行以防空格传入数据库
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "请输入修改后的标题: " << endl;
                                    // 整行传入
                                    getline(cin, title);
                                    cout << "请输入修改后的作者: " << endl;
                                    getline(cin, author);
                                    cout << "请输入修改后的评级: " << endl;
                                    cin >> rating;
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "请输入修改后的版号: " << endl;
                                    cin >> versionNumber;
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "请输入修改后的ISBN码: " << endl;
                                    cin >> ISBNNumber;
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "请输入修改后的页数: " << endl;
                                    cin >> pageNumber;
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    //再次确定
                                    cout << "是否要修改？修改输入1，不修改输入0" << endl;
                                    int choice3;
                                    cin >> choice3;
                                    switch (choice3) {
                                        case 1: {
                                            //实例化book
                                            Book book(number, title, author, rating, versionNumber, ISBNNumber,
                                                      pageNumber);
                                            //生成数据库语言
                                            string sql = book.generateUpdateSQL();
                                            if (updateData(sql)) {
                                                cout << "更新成功" << endl;
                                            } else {
                                                cout << "更新失败" << endl;
                                            }
                                            cin.get();
                                            cout << "按下回车回到主界面" << endl;
                                            cin.get();
                                            break;
                                        }
                                        case 0: {
                                            cin.get();
                                            cout << "按下回车回到主界面" << endl;
                                            cin.get();
                                            break;
                                        }
                                        default: {
                                            cout << "无效输入！按下回车回到主界面!" << endl;
                                            cin.get();
                                            cin.get();
                                            break;
                                        }
                                    }
                                } else {
                                    cout << "抱歉，图书表内没有此编号" << endl;
                                    cin.get();
                                    cout << "按下回车回到主界面" << endl;
                                    cin.get();
                                    break;
                                }
                                break;
                            }
                            case 2: {
                                string number;
                                cout << "请输入要修改的视频光盘类的编号" << endl;
                                cin >> number;
                                if (QueryDatabase("SELECT * FROM video_table WHERE number = '" + number + "'")) {
                                    string title, author, rating, tasterName, productionYear, videoTime;
                                    cout << "查询到可修改的视频光盘类数据(上图)" << endl;
                                    cout << "进行视频光盘类表数据修改" << endl;
                                    cout << "您选择添加视频光盘类" << endl;
                                    cout << "注意按下回车后不可以修改信息" << endl;
                                    cout << "请输入修改后的标题: " << endl;
                                    getline(cin, title);
                                    cout << "请输入修改后的作者" << endl;
                                    getline(cin, author);
                                    cout << "请输入修改后的评级" << endl;
                                    cin >> rating;
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "输入修改后的品者名字" << endl;
                                    getline(cin, tasterName);
                                    cout << "输入修改后的出品年份" << endl;
                                    cin >> productionYear;
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "输入修改后的时长" << endl;
                                    cin >> videoTime;
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "是否要添加？添加输入1，不添加输入0" << endl;
                                    int choice3;
                                    cin >> choice3;
                                    switch (choice3) {
                                        case 1: {
                                            //实例化
                                            Video video(number, title, author, rating, tasterName, productionYear,
                                                        videoTime);
                                            //生成数据库语言
                                            string sql = video.generateUpdateSQL();
                                            if (updateData(sql)) {
                                                cout << "更新成功" << endl;
                                            } else {
                                                cout << "更新失败" << endl;
                                            }
                                            cin.get();
                                            cout << "按下回车回到主界面" << endl;
                                            cin.get();
                                            break;
                                        }
                                        case 0: {
                                            cin.get();
                                            cout << "按下回车回到主界面" << endl;
                                            cin.get();
                                            break;
                                        }
                                        default: {
                                            cout << "无效输入！按下回车回到主界面!" << endl;
                                            cin.get();
                                            cin.get();
                                            break;
                                        }
                                    }
                                } else {
                                    cout << "抱歉，视频光盘表内没有此编号" << endl;
                                    cin.get();
                                    cout << "按下回车回到主界面" << endl;
                                    cin.get();
                                    break;
                                }
                                break;
                            }
                            case 3: {
                                string number;
                                cout << "请输入要修改的图画类的编号" << endl;
                                cin >> number;
                                if (QueryDatabase("SELECT * FROM picture_table WHERE number = '" + number + "'")) {
                                    string title, author, rating, internation, length, width;
                                    cout << "查询到可修改的视频光盘类数据(上图)" << endl;
                                    cout << "注意按下回车后的消息不可更改" << endl;
                                    cout << "请输入修改后的标题" << endl;
                                    getline(cin, title);
                                    cout << "请输入修改后的作者" << endl;
                                    getline(cin, author);
                                    cout << "请输入修改后的评级" << endl;
                                    cin >> rating;
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "请输入修改后的作者国籍" << endl;
                                    getline(cin, internation);
                                    cout << "请输入修改后的长（单位为cm）" << endl;
                                    cin >> length;
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "请输入修改后的宽（单位为cm）" << endl;
                                    cin >> width;
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "是否要添加？添加输入1，不添加输入0" << endl;
                                    int choice3;
                                    cin >> choice3;
                                    switch (choice3) {
                                        case 1: {
                                            //实例化
                                            Picture picture(number, title, author, rating, internation, length, width);
                                            //生成数据库语言
                                            string sql = picture.generateUpdateSQL();
                                            if (updateData(sql)) {
                                                cout << "更新成功" << endl;
                                            } else {
                                                cout << "更新失败" << endl;
                                            }
                                            cin.get();
                                            cout << "按下回车回到主界面" << endl;
                                            cin.get();
                                            break;
                                        }
                                        case 0: {
                                            cin.get();
                                            cout << "按下回车回到主界面" << endl;
                                            cin.get();
                                            break;
                                        }
                                        default: {
                                            cout << "无效输入！按下回车回到主界面!" << endl;
                                            cin.get();
                                            cin.get();
                                            break;
                                        }
                                    }
                                } else {
                                    cout << "抱歉，图画类表内没有此编号" << endl;
                                    cin.get();
                                    cout << "按下回车回到主界面" << endl;
                                    cin.get();
                                    break;
                                }

                                break;
                            }
                            default: {
                                cout << "无效输入！按下回车回到主界面!" << endl;
                                cin.get();
                                cin.get();
                                break;
                            }
                        }
                        break;
                    }
                    case 2: {
                        cout << "按下回车回到主界面" << endl;
                        cin.get();
                        cin.get();
                        break;
                    }
                    default: {
                        cout << "无效输入！按回车重新回到主界面" << endl;
                        cin.get();
                        cin.get();
                        break;
                    }
                }
                break;
            }
            case 5: {
                int choice2;
                cout << "您选择了删除物品" << endl;
                cout << "请删除哪一种物品" << endl;
                cout << "1.图书类" << endl;
                cout << "2.视频光盘类" << endl;
                cout << "3.图画类" << endl;
                cout << "4.回到主界面" << endl;
                cin >> choice2;
                switch (choice2) {
                    case 1: {
                        string number;
                        cout << "您选择了删除图书类的物品" << endl;
                        cout << "请输入要删除的图书类的编号" << endl;
                        cin >> number;
                        //首先进行查询查看是否存在
                        if (QueryDatabase("SELECT * FROM book_table WHERE number = '" + number + "'")) {
                            cout << "查询到数据(如上图)可以进行删除" << endl;
                            cout << "正在进行删除操作" << endl;
                            if (updateData("DELETE FROM number_table WHERE number ='" + number + "'")) {
                                cout << "删除成功" << endl;
                                cin.get();
                                cout << "按下回车回到主界面" << endl;
                                cin.get();
                                break;
                            } else {
                                cout << "删除失败" << endl;
                                cin.get();
                                cout << "按下回车回到主界面" << endl;
                                cin.get();
                                break;
                            }
                        } else {
                            cout << "抱歉您输入的编号在图书类中并不存在" << endl;
                            cin.get();
                            cout << "按下回车回到主界面" << endl;
                            cin.get();
                            break;
                        }
                    }
                    case 2: {
                        string number;
                        cout << "您选择了删除视频光盘类的物品" << endl;
                        cout << "请输入要删除的视频光盘类的编号" << endl;
                        cin >> number;
                        //首先进行查询查看是否存在
                        if (QueryDatabase("SELECT * FROM video_table WHERE number = '" + number + "'")) {
                            cout << "查询到数据(如上图)可以进行删除" << endl;
                            cout << "正在进行删除操作" << endl;
                            if (updateData("DELETE FROM number_table WHERE number ='" + number + "'")) {
                                cout << "删除成功" << endl;
                                cin.get();
                                cout << "按下回车回到主界面" << endl;
                                cin.get();
                                break;
                            } else {
                                cout << "删除失败" << endl;
                                cin.get();
                                cout << "按下回车回到主界面" << endl;
                                cin.get();
                                break;
                            }
                        } else {
                            cout << "抱歉您输入的编号在视频光盘类中并不存在" << endl;
                            cin.get();
                            cout << "按下回车回到主界面" << endl;
                            cin.get();
                            break;
                        }
                    }
                    case 3: {
                        string number;
                        cout << "您选择了删除图画类的物品" << endl;
                        cout << "请输入要删除的图画类的编号:" << endl;
                        cin >> number;
                        //首先进行查询查看是否存在
                        if (QueryDatabase("SELECT * FROM picture_table WHERE number = '" + number + "'")) {
                            cout << "查询到数据(如上图)可以进行删除" << endl;
                            cout << "正在进行删除操作" << endl;
                            if (updateData("DELETE FROM number_table WHERE number ='" + number + "'")) {
                                cout << "删除成功" << endl;
                                cin.get();
                                cout << "按下回车回到主界面" << endl;
                                cin.get();
                                break;
                            } else {
                                cout << "删除失败" << endl;
                                cin.get();
                                cout << "按下回车回到主界面" << endl;
                                cin.get();
                                break;
                            }
                        } else {
                            cout << "抱歉您输入的编号在视频光盘类中并不存在" << endl;
                            cin.get();
                            cout << "按下回车回到主界面" << endl;
                            cin.get();
                            break;
                        }
                    }
                    case 4: {
                        cout << "按下回车回到主界面" << endl;
                        cin.get();
                        cin.get();
                        break;
                    }
                    default: {
                        cout << "无效输入！按回车重新回到主界面" << endl;
                        cin.get();
                        cin.get();
                        break;
                    }
                }
                break;
            }
            case 6: {
                //调用帮助类
                Help::displayHelp();
                cin.get();
                cin.get();
                break;
            }
            case 9: {
                cout << "重新开始主程序" << endl;
                break;
            }
            case 0: {
                cout << "退出系统!" << endl;
                running = false;
                break;
            }
            default: {
                cout << "无效输入！按回车重新回到主界面" << endl;
                cin.get();
                cin.get();
                break;
            }
        }
    }

}