#ifndef DIARYDIALOG_H
#define DIARYDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>
#include "diarymanager.h"

class DiaryDialog : public QDialog
{
    Q_OBJECT
#ifndef DIARYDIALOG_H
#define DIARYDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>
#include "diarymanager.h"

class DiaryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DiaryDialog(QWidget *parent = nullptr);

private slots:
    void addEntry();
    void displayEntry();
    void searchEntries();
    void likeEntry();

private:
    QLineEdit *titleEdit;
    QTextEdit *contentEdit;
    QLineEdit *destinationEdit;
    QLineEdit *searchEdit;
    QPushButton *saveButton;
    QPushButton *searchButton;
    QListWidget *entryList;
    QLabel *likeCountLabel;
    QPushButton *likeButton;
    DiaryManager diaryManager;

    void updateEntryList(const QVector<DiaryEntry> &entries);
};

#endif // DIARYDIALOG_H

public:
    explicit DiaryDialog(QWidget *parent = nullptr);

private slots:
    void addEntry();
    void displayEntry();
    void searchEntries();
    void likeEntry();

private:
    QLineEdit *titleEdit;
    QTextEdit *contentEdit;
    QLineEdit *destinationEdit;
    QLineEdit *searchEdit;
    QPushButton *saveButton;
    QPushButton *searchButton;
    QListWidget *entryList;
    QLabel *likeCountLabel;
    QPushButton *likeButton;
    DiaryManager diaryManager;

    void updateEntryList(const QVector<DiaryEntry> &entries);
};

#endif // DIARYDIALOG_H
