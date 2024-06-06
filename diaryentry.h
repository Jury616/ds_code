#ifndef DIARYENTRY_H
#define DIARYENTRY_H

#include <QString>
#include <QByteArray>
#include <QDataStream>

class DiaryEntry
{
public:
    DiaryEntry() : views(0), totalRating(0.0), ratingCount(0), likes(0) {}
    DiaryEntry(const QString &title, const QString &content, const QString &author)
        : title(title), content(content), author(author), views(0), totalRating(0.0), ratingCount(0), likes(0) {}

    QString getTitle() const { return title; }
    QString getContent() const { return content; }
    QString getAuthor() const { return author; }
    int getViews() const { return views; }
    double getRating() const { return ratingCount > 0 ? totalRating / ratingCount : 0; }
    int getRatingCount() const { return ratingCount; }
    int getLikes() const { return this->likes; }

    void incrementViews() { views++; }
    void addRating(double rating) { totalRating += rating; ratingCount++; }
    void addLike() { this->likes++; }
    QByteArray compressContent() const;
    QString decompressContent(const QByteArray &compressedContent) const;

private:
    QString title;
    QString content;
    QString author;
    int views;
    double totalRating;
    int ratingCount;
    int likes;
};

QDataStream &operator<<(QDataStream &out, const DiaryEntry &entry);
QDataStream &operator>>(QDataStream &in, DiaryEntry &entry);

#endif // DIARYENTRY_H
