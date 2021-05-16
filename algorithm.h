#pragma once
#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QFileInfo>
#include <QString>
#include <stack>
#include <queue>
#include <QDir>
#include <QDebug>

class Algorithm
{
public:
    virtual QString search(QString currDir, QString currFile) = 0;
    virtual ~Algorithm(void);
};

#endif // ALGORITHM_H
