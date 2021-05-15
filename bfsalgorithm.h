#pragma once
#ifndef BFSALGORITHM_H
#define BFSALGORITHM_H

#include "algorithm.h"

class BFSAlgorithm : public Algorithm
{
public:
    BFSAlgorithm(void);
    QString search(QString currDir, QString currFile) override;
};

#endif // BFSALGORITHM_H
