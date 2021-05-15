#include "dfsalgorithm.h"

DFSAlgorithm::DFSAlgorithm(){}

QString DFSAlgorithm::search(QString currDir, QString currFile)
{
    QStack<QString>st;
    st.push(currDir);

    while(!st.empty())
    {
        QString tmp = st.top();
        st.pop();

        QDir dir(tmp);
        dir.setFilter(QDir::Dirs);

        for(auto&i: dir.entryInfoList())
        {
            if(i.isDir()) st.push(i.absolutePath());
            else if(i.isFile() && i.fileName() == currFile) return i.absoluteFilePath();
        }
    }
    return "";
}
