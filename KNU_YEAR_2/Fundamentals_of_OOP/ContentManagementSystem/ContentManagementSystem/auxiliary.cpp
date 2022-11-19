#include <QString>
#include <QDir>
#include <QDirIterator>


bool isCorrectName(const QString name)
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


QString getFileNameFromPath(const QString path)
{
    QString fileName = "";

    for(int i = path.size() - 1; i >= 0; i--)
    {
        if(path[i] == '/') break;

        fileName = path[i] + fileName;
    }

    return fileName;
}


QString getFileExtension(const QString fileNameOrPath)
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

QString getParentPath(const QString path)
{
    QString parentPath = "";

    bool slashMet = false;

    for(int i = path.size() - 1; i >= 0; i--)
    {
        if(slashMet)
        {
            parentPath = path[i] + parentPath;
        }

        if(path[i] == '/') slashMet = true;
    }

    return parentPath;
}


void copyAndReplaceFolderContents(const QString &fromDir, const QString &toDir, bool copyAndRemove = false) {
    QDirIterator it(fromDir, QDirIterator::Subdirectories);
    QDir dir(fromDir);
    const int absSourcePathLength = dir.absoluteFilePath(fromDir).length();

    while (it.hasNext()){
        it.next();
        const auto fileInfo = it.fileInfo();
        if(!fileInfo.isHidden()) { //filters dot and dotdot
            const QString subPathStructure = fileInfo.absoluteFilePath().mid(absSourcePathLength);
            const QString constructedAbsolutePath = toDir + subPathStructure;

            if(fileInfo.isDir()){
                //Create directory in target folder
                dir.mkpath(constructedAbsolutePath);
            } else if(fileInfo.isFile()) {
                //Copy File to target directory

                //Remove file at target location, if it exists, or QFile::copy will fail
                QFile::remove(constructedAbsolutePath);
                QFile::copy(fileInfo.absoluteFilePath(), constructedAbsolutePath);
            }
        }
    }

    if(copyAndRemove)
        dir.removeRecursively();
}

bool folderNamesAreUniqueInPath(QString path)
{
    QStringList dirs = path.split('/');
    int dirsSz = dirs.size();
    QSet <QString> dirSet;
    for(int i = 0; i < dirsSz; i++)
        dirSet.insert(dirs[i]);
    return (dirSet.size() == dirsSz);
}
