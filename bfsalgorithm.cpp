#include "bfsalgorithm.h"

BFSAlgorithm::BFSAlgorithm(void) {}

QString BFSAlgorithm::search(QString currDir, QString currFile)
{
    QQueue<QString>q;
    q.push_back(currDir);

    while(!q.empty())
    {
        QString tmp = q.front();
        q.pop_front();

        QDir dir(tmp);
        dir.setFilter(QDir::Dirs);

        for(auto&i: dir.entryInfoList())
        {
            if(i.isDir()) q.push_back(i.absolutePath());
            else if(i.isFile() && i.fileName() == currFile) return i.absoluteFilePath();
        }
    }
    return "";
}
