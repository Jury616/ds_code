#ifndef DIARYMANAGER_H
#define DIARYMANAGER_H

#include "diaryentry.h"
#include <QString>
#include <QVector>
#include <QMap>

class DiaryManager
{
public:
    DiaryManager(const QString &storagePath);

    void addEntry(const DiaryEntry &entry);
    QVector<DiaryEntry> getEntries() const;
    QVector<DiaryEntry> searchByDestination(const QString &destination) const;
    QVector<DiaryEntry> searchByTitle(const QString &title) const;
    QVector<DiaryEntry> searchByContent(const QString &keyword) const;
    void loadEntries();
    void saveEntries() const;

private:
    QVector<DiaryEntry> entries;
    QString storagePath;

    void saveEntry(const DiaryEntry &entry) const;
    DiaryEntry loadEntry(const QString &filePath) const;
};

#endif // DIARYMANAGER_H
