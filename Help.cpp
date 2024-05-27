//
// Created by FLASHLACK on 24-5-6.
//
#include "Help.h"
#include <iostream>
using namespace std;
//定义Help类
void Help::displayHelp() {
    cout << "帮助信息：" << endl;
    cout << "1. 添加物品: 添加新的物品到库存中。" << endl;
    cout << "2. 查询物品: 根据物品编号查询物品信息。" << endl;
    cout << "3. 显示物品: 显示库存中所有物品信息。" << endl;
    cout << "4. 编辑物品: 编辑已有物品的信息。" << endl;
    cout << "5. 删除物品: 从库存中删除指定物品。" << endl;
    cout << "6. 帮助信息: 显示此帮助信息。" << endl;
    cout << "9. 重启系统 ：重启系统回到主界面" << endl;
    cout << "0. 退出系统: 退出程序。" << endl;
    cout << "再按一下回车回到主界面" << endl;
}
