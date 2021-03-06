#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include "algorithm.h"

class Client : public QObject
{
public:
    Client(QObject* parent = nullptr);
    Client(Algorithm* algorithm, QObject* parent =nullptr);
    void setAlgorithm(Algorithm* algorithm);
    QString executeAlgorithm(QString currDir, QString currFile);
    ~Client(void);
private:
    Algorithm* algorithm;
};

#endif // CLIENT_H
