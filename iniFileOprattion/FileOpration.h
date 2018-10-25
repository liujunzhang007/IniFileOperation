#ifndef FILEOPRATION_H
#define FILEOPRATION_H
#include <QObject>

class FileOpration : public QObject
{
public:
    FileOpration();
    void fileCreate();
    void fileRead();
    void fileWrite();
};

#endif // FILEOPRATION_H
