#include "bfsalgorithm.h"

BFSAlgorithm::BFSAlgorithm(void) {}

QString BFSAlgorithm::search(QString currDir, QString currFile)
{
    std::queue<QString>q;
    q.push(currDir);
    while(!q.empty())
    {
        QString tmp = q.front();
        q.pop();
        QDir dir(tmp);
        for(auto&i: dir.entryInfoList())
        {
            qDebug() << i.fileName();
            if(i.isDir() && i.fileName() != "." && i.fileName() != "..") q.push(i.absoluteFilePath());
            else if(i.isFile() && i.fileName() == currFile) return i.absoluteFilePath();
        }
    }
    return "";
}
