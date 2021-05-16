#include "dfsalgorithm.h"

DFSAlgorithm::DFSAlgorithm(){}

QString DFSAlgorithm::search(QString currDir, QString currFile)
{
    std::stack<QString>st;
    st.push(currDir);
    while(!st.empty())
    {
        QString tmp = st.top();
        st.pop();
        QDir dir(tmp);
        for(auto&i: dir.entryInfoList())
        {
            qDebug() << i.fileName();
            if(i.isDir() && i.fileName() != "." && i.fileName() != "..") st.push(i.absoluteFilePath());
            else if(i.isFile() && i.fileName() == currFile) return i.absoluteFilePath();
        }
    }
    return "";
}
