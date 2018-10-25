#include "FileOpration.h"
#include<QSettings>
#include <QGuiApplication>
#include<QFile>
#include<QDebug>

FileOpration::FileOpration()
{

}
void FileOpration::fileCreate(){

    QString appPath = QCoreApplication::applicationDirPath() + "/languages.ini";
    qDebug()<<"QFile.exists()----Ture-------"<<appPath;
    //QSettings构造函数的第一个参数是ini文件的路径,第二个参数表示针对ini文件,第三个参数可以缺省
    QSettings *configIniWrite = new QSettings(appPath, QSettings::IniFormat);
    //向ini文件中写入内容,setValue函数的两个参数是键值对
    //向ini文件的第一个节写入内容,ip节下的第一个参数
    configIniWrite->setValue("/ip/first", "192.168.0.1");
    //向ini文件的第一个节写入内容,ip节下的第二个参数
    configIniWrite->setValue("ip/second", "127.0.0.1");
    //向ini文件的第二个节写入内容,port节下的第一个参数
    configIniWrite->setValue("port/open", "2222");
    //写入完成后删除指针
    delete configIniWrite;

}
void FileOpration::fileRead(){

    QSettings *pIni = new QSettings(QCoreApplication::applicationDirPath()+"/languages.ini", QSettings::IniFormat);
    QString sArg = "";
    sArg = pIni->value("/ip/first").toString();
    qDebug("arg1 = %s\n", sArg.toStdString().data());

    sArg = "";
    sArg = pIni->value("ip/second").toString();
    qDebug("arg2 = %s\n", sArg.toStdString().data());

    sArg = "";
    sArg = pIni->value("port/open").toString();
    qDebug("arg3 = %s\n", sArg.toStdString().data());

    delete pIni;

}
void FileOpration::fileWrite(){
    QSettings *pIni = new QSettings(QCoreApplication::applicationDirPath()+"/languages.ini", QSettings::IniFormat);
    if(!pIni->contains("Data/Language")){
        pIni->setValue("Data/Language","alreadySave");
        qDebug()<<"Data/Language already writed! ===   "<<pIni->value("Data/Language").toString().toStdString().data();

    }else {
        qDebug()<<"Data/Language already exisited! ===   "<<pIni->value("Data/Language").toString().toStdString().data();
    }
    delete pIni;

}
