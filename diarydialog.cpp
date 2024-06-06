#include "diarydialog.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include"datastr_wyq/datastr_wyq/DatabaseIF.h"
#include"datastr_wyq/datastr_wyq/shc/Database.h"
extern Database database;
extern int scenicAreaNumber;
DiaryDialog::DiaryDialog(QWidget *parent)
    : QDialog(parent), diaryManager("./diary_contents")
{
    setWindowTitle("游学日记");

    titleEdit = new QLineEdit(this);
    titleEdit->setPlaceholderText("请输入日记的标题");

    contentEdit = new QTextEdit(this);
    contentEdit->setPlaceholderText("请输入日记内容");

    destinationEdit = new QLineEdit(this);
    destinationEdit->setPlaceholderText("请输入日记的地点");

    saveButton = new QPushButton("提交", this);
    connect(saveButton, &QPushButton::clicked, this, &DiaryDialog::addEntry);

    searchEdit = new QLineEdit(this);
    searchEdit->setPlaceholderText("请输入要搜索的内容");

    searchButton = new QPushButton("搜索", this);
    connect(searchButton, &QPushButton::clicked, this, &DiaryDialog::searchEntries);

    entryList = new QListWidget(this);
    connect(entryList, &QListWidget::itemClicked, this, &DiaryDialog::displayEntry);

    likeCountLabel = new QLabel("点赞: 0", this);
    likeButton = new QPushButton("点赞", this);
    connect(likeButton, &QPushButton::clicked, this, &DiaryDialog::likeEntry);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("标题:", this));
    layout->addWidget(titleEdit);
    layout->addWidget(new QLabel("内容:", this));
    layout->addWidget(contentEdit);
    layout->addWidget(new QLabel("地点:", this));
    layout->addWidget(destinationEdit);
    layout->addWidget(saveButton);
    layout->addWidget(new QLabel("搜索:", this));
    layout->addWidget(searchEdit);
    layout->addWidget(searchButton);
    layout->addWidget(entryList);
    layout->addWidget(likeCountLabel);
    layout->addWidget(likeButton);

    setLayout(layout);

    diaryManager.loadEntries();
    updateEntryList(diaryManager.getEntries());
}

void DiaryDialog::addEntry()
{
    QString title = titleEdit->text();
    QString content = contentEdit->toPlainText();
    QString destination = destinationEdit->text();

    if (!title.isEmpty() && !content.isEmpty() && !destination.isEmpty())
    {
        DiaryEntry entry(title, content + "\n地点: " + destination, "Author");
        diaryManager.addEntry(entry);

        updateEntryList(diaryManager.getEntries());
        titleEdit->clear();
        contentEdit->clear();
        destinationEdit->clear();
    }
    else
    {
        QMessageBox::warning(this, "警告！", "日记信息存在缺失！");
    }
}

void DiaryDialog::displayEntry()
{

    QListWidgetItem *item = entryList->currentItem();
    if (item)
    {
        QString title = item->text();
        for (const DiaryEntry &entry : diaryManager.getEntries())
        {
            if (entry.getTitle() == title)
            {
                titleEdit->setText(entry.getTitle());
                contentEdit->setText(entry.getContent());
                likeCountLabel->setText(QString("点赞数: %1").arg(entry.getLikes()));
                break;
            }
        }
    }

}

void DiaryDialog::searchEntries()
{
    QString keyword = searchEdit->text();
    if (!keyword.isEmpty())
    {
        QVector<DiaryEntry> results = diaryManager.searchByContent(keyword);
        updateEntryList(results);
    }
}

void DiaryDialog::likeEntry()
{
    QListWidgetItem *item = entryList->currentItem();
    if (item)
    {
        QString title = item->text();
        for (DiaryEntry &entry : diaryManager.getEntries())
        {
            if (entry.getTitle() == title)
            {
                entry.addLike();
                likeCountLabel->setText(QString("点赞数: %1").arg(entry.getLikes()));
                diaryManager.saveEntries();
                break;
            }
        }
    }
}

void DiaryDialog::updateEntryList(const QVector<DiaryEntry> &entries)
{
    entryList->clear();
    for (const DiaryEntry &entry : entries)
    {
        entryList->addItem(entry.getTitle());
    }
}
