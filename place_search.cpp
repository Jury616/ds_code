#include "place_search.h"
#include <QApplication>

#include "datastr_wyq\datastr_wyq./PlaceRecom.h"

extern int scenicAreaNumber;

PlaceSearchDialog::PlaceSearchDialog(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    connect(ui.go_back, &QPushButton::clicked, this, &PlaceSearchDialog::onGoBackClicked);
    connect(ui.submit_1, &QPushButton::clicked, this, &PlaceSearchDialog::onSubmit1Clicked);
    connect(ui.submit_2, &QPushButton::clicked, this, &PlaceSearchDialog::onSubmit2Clicked);
    connect(ui.submit_3, &QPushButton::clicked, this, &PlaceSearchDialog::onSubmit3Clicked);

    // 初始更新场所数量显示
        updateNumberOfPlaces();

    // 连接信号槽，确保在scenicAreaNumber改变时更新显示
     //   connect(this, SIGNAL(scenicAreaNumberChanged()), this, SLOT(onScenicAreaNumberChanged()));
}

void PlaceSearchDialog::onGoBackClicked()
{
    accept();
}

void PlaceSearchDialog::onSubmit1Clicked()
{
    bool ok;
    int index = ui.place_index->text().toInt(&ok);
    if (ok)
    {
        struct placeInfo info = placeRecom->get_nearby_places(index);
        QString infoText;
        infoText.append(QString("查询到的场所数量: %1\n").arg(info.number));
        for (int i = 0; i < info.number; ++i)
        {
            infoText.append(QString("第 %1个场所:\n").arg(i + 1));
            infoText.append(QString("   场所名称: %1\n").arg(QString::fromStdString(*info.names[i])));
            infoText.append(QString("   场所类别: %1\n").arg(QString::fromStdString(*info.labels[i])));
            infoText.append(QString("   场所介绍: %1\n").arg(QString::fromStdString(*info.introductions[i])));
            infoText.append(QString("   相对距离: %1\n").arg(info.distance[i]));
        }
        ui.place_information->setPlainText(infoText);
    }
    else
    {
        ui.place_information->setPlainText("很抱歉，未找到。");
    }
}

void PlaceSearchDialog::onSubmit2Clicked()
{
        QString label = ui.place_label->text();
        struct placeInfo info = placeRecom->filter_nearby_places(label.toStdString());
        QString infoText;
        infoText.append(QString("过滤后的场所数量: %1\n").arg(info.number));
        for (int i = 0; i < info.number; ++i)
        {
            infoText.append(QString("第 %1个场所:\n").arg(i + 1));
            infoText.append(QString("   场所名称: %1\n").arg(QString::fromStdString(*info.names[i])));
            infoText.append(QString("   场所类别: %1\n").arg(QString::fromStdString(*info.labels[i])));
            infoText.append(QString("   场所介绍: %1\n").arg(QString::fromStdString(*info.introductions[i])));
            infoText.append(QString("   相对距离: %1\n").arg(info.distance[i]));
        }
        ui.place_information->setPlainText(infoText);
}

void PlaceSearchDialog::onSubmit3Clicked()
{
    bool okIndex;
        int index = ui.place_index_1->text().toInt(&okIndex);
        if (okIndex)
        {
            QString label = ui.place_label_1->text();
            struct placeInfo info = placeRecom->get_nearby_places_by_label(index, label.toStdString());
            QString infoText;
            infoText.append(QString("查询到的场所数量: %1\n").arg(info.number));
            for (int i = 0; i < info.number; ++i)
            {
                infoText.append(QString("第 %1个场所:\n").arg(i + 1));
                infoText.append(QString("   场所名称: %1\n").arg(QString::fromStdString(*info.names[i])));
                infoText.append(QString("   场所类别: %1\n").arg(QString::fromStdString(*info.labels[i])));
                infoText.append(QString("   场所介绍: %1\n").arg(QString::fromStdString(*info.introductions[i])));
                infoText.append(QString("   相对距离: %1\n").arg(info.distance[i]));
            }
            ui.place_information->setPlainText(infoText);
        }
        else
        {
            ui.place_information->setPlainText("请输入有效的场所索引。");
        }
}

void PlaceSearchDialog::updateNumberOfPlaces()
{
    // 调用get_number_of_places函数，并更新文本框内容
    int numberOfPlaces = placeRecom->get_number_of_places(scenicAreaNumber);
    ui.number_of_place->setHtml(QString("<p style=\" font-family:'SimSun'; font-size:16pt;\">%1</p>").arg(numberOfPlaces));
}

void PlaceSearchDialog::onScenicAreaNumberChanged()
{
    // 更新场所数量显示
    updateNumberOfPlaces();
}


