#include "diarymanager.h"
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDataStream>
#include "datastr_wyq/datastr_wyq/shc/Database.h"
extern Database database;

DiaryManager::DiaryManager(const QString &storagePath)
    : storagePath(storagePath)
{
    loadEntries();
}

void DiaryManager::addEntry(const DiaryEntry &entry)
{
    entries.append(entry);
    saveEntry(entry);
}

QVector<DiaryEntry> DiaryManager::getEntries() const
{
    return entries;
}

QVector<DiaryEntry> DiaryManager::searchByDestination(const QString &destination) const
{
    QVector<DiaryEntry> result;
    for (const DiaryEntry &entry : entries)
    {
        if (entry.getContent().contains(destination, Qt::CaseInsensitive))
        {
            result.append(entry);
        }
    }
    return result;
}

QVector<DiaryEntry> DiaryManager::searchByTitle(const QString &title) const
{
    QVector<DiaryEntry> result;
    for (const DiaryEntry &entry : entries)
    {
        if (entry.getTitle().contains(title, Qt::CaseInsensitive))
        {
            result.append(entry);
        }
    }
    return result;
}

QVector<DiaryEntry> DiaryManager::searchByContent(const QString &keyword) const
{
    QVector<DiaryEntry> result;
    for (const DiaryEntry &entry : entries)
    {
        if (entry.getContent().contains(keyword, Qt::CaseInsensitive))
        {
            result.append(entry);
        }
    }
    return result;
}

void DiaryManager::loadEntries()
{
    QDir dir(storagePath);
    if (!dir.exists())
    {
        dir.mkpath(".");
    }

    QStringList files = dir.entryList(QDir::Files);
    for (const QString &fileName : files)
    {
        QString filePath = dir.filePath(fileName);
        DiaryEntry entry = loadEntry(filePath);
        entries.append(entry);
    }
}

void DiaryManager::saveEntries() const
{
    for (const DiaryEntry &entry : entries)
    {
        saveEntry(entry);
    }
}

void DiaryManager::saveEntry(const DiaryEntry &entry) const
{
    QDir dir(storagePath);
    if (!dir.exists())
    {
        dir.mkpath(".");
    }

    QFile file(dir.filePath(entry.getTitle()));
    if (file.open(QIODevice::WriteOnly))
    {
        QDataStream out(&file);
        out << entry;
    }
}

DiaryEntry DiaryManager::loadEntry(const QString &filePath) const
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly))
    {
        QDataStream in(&file);
        DiaryEntry entry;
        in >> entry;
        return entry;
    }
    return DiaryEntry();
}
