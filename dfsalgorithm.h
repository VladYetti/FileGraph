#pragma once
#ifndef DFSALGORITHM_H
#define DFSALGORITHM_H

#include "algorithm.h"

class DFSAlgorithm : public Algorithm
{
public:
    DFSAlgorithm(void);
    QString search(QString currDir, QString currFile) override;
};

#endif // DFSALGORITHM_H
