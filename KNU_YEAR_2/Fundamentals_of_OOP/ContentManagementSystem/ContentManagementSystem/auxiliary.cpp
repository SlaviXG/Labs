#include <QString>


bool isCorrectName(QString name)
{
    if(name.size() == 0) return false;

    QString prohibited = "\\/<>:*?\"|";
    bool notSpaceSym = false;

    for(int i = 0; i < name.size(); i++)
    {
        if(name[i]!=' ') notSpaceSym = true;
        for(int j = 0; j < prohibited.size(); j++)
        {
            if(name[i]==prohibited[j]) return false;
        }
    }

    if(name.size()!=0 and notSpaceSym==false) return false;

    return true;
}


void trimStr(QString &str)
{
    int initialLen = str.size();

    if(!initialLen) return;

    int l = 0; int r = initialLen - 1;

    if(str[0] == ' ')
        while(l + 1 < initialLen)
        {
            if(str[l + 1] != ' ') break;
            l++;
        }
        //now l - index of the last space in preffix
    else l = -1;

    if(str[r] == ' ')
        while(r > l + 1)
        {
            if(str[r-1]!=' ') break;
            r--;
        }
        //now r - index of the first space in suffix
    else r = initialLen;

    str = str.mid(l + 1, r - (l + 1));
}


QString getFileNameFromPath(QString path)
{
    QString fileName = "";

    for(int i = path.size() - 1; i >= 0; i--)
    {
        if(path[i] == '/') break;

        fileName = path[i] + fileName;
    }

    return fileName;
}


QString getFileExtension(QString fileNameOrPath)
{
    QString fileName = getFileNameFromPath(fileNameOrPath);
    QString extension = "";
    bool dot = false;

    for(int i = fileName.size() - 1; i >= 0; i--)
    {
        if(fileName[i] == '.') dot = true;
        if(dot) break;

        extension = fileName[i] + extension;
    }

    return (dot ? (extension) : QString());
}
