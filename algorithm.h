#pragma once
#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QFileInfo>
#include <QString>
#include <QStack>
#include <QQueue>
#include <QDir>

class Algorithm
{
public:
    virtual QString search(QString currDir, QString currFile) = 0;
    virtual ~Algorithm(void);
};

#endif // ALGORITHM_H
