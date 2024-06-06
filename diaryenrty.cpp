#include "diaryentry.h"
#include <QDataStream>
#include <zlib.h>

QByteArray DiaryEntry::compressContent() const
{
    QByteArray uncompressedData = content.toUtf8();
    uLongf compressedSize = compressBound(uncompressedData.size());
    QByteArray compressedData(compressedSize, 0);

    if (compress((Bytef*)compressedData.data(), &compressedSize, (const Bytef*)uncompressedData.data(), uncompressedData.size()) != Z_OK)
    {
        return QByteArray();
    }

    compressedData.resize(compressedSize);
    return compressedData;
}

QString DiaryEntry::decompressContent(const QByteArray &compressedContent) const
{
    uLongf uncompressedSize = compressedContent.size() * 4; // 预估解压后大小
    QByteArray uncompressedData(uncompressedSize, 0);

    if (uncompress((Bytef*)uncompressedData.data(), &uncompressedSize, (const Bytef*)compressedContent.data(), compressedContent.size()) != Z_OK)
    {
        return QString();
    }

    uncompressedData.resize(uncompressedSize);
    return QString::fromUtf8(uncompressedData);
}

QDataStream &operator<<(QDataStream &out, const DiaryEntry &entry)
{
    out << entry.getTitle() << entry.getAuthor() << entry.getViews() << entry.getRating() << entry.getRatingCount() << entry.getLikes() << entry.compressContent();
    return out;
}

QDataStream &operator>>(QDataStream &in, DiaryEntry &entry)
{
    QString title, author;
    int views, ratingCount, likes;
    double rating;
    QByteArray compressedContent;

    in >> title >> author >> views >> rating >> ratingCount >> likes >> compressedContent;

    entry = DiaryEntry(title, DiaryEntry().decompressContent(compressedContent), author);
    entry.incrementViews(); // restore views
    for (int i = 0; i < ratingCount; ++i) { entry.addRating(rating); } // restore ratings
    for (int i = 0; i < likes; ++i) { entry.addLike(); } // restore likes
    return in;
}
