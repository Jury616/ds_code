#include"place_search.h"
#include"place_route.h"
#include"cd_comments.h"
#include "place_list.h"
#include <QApplication>

PlaceListDialog::PlaceListDialog(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    parent->setObjectName(QStringLiteral("登录"));
    connect(ui.place_route, &QPushButton::clicked, this, &PlaceListDialog::onPlaceRouteClicked);
    connect(ui.place_search, &QPushButton::clicked, this, &PlaceListDialog::onPlaceSearchClicked);
    connect(ui.cd_comments, &QPushButton::clicked, this, &PlaceListDialog::onCdCommentsClicked);
    connect(ui.go_back, &QPushButton::clicked, this, &PlaceListDialog::onGoBackClicked);
    std::vector<std::string> places_info;
    ToursiteTopo * topo = database.get_toursite_topo(scenicAreaNumber);
    std::cout<<1;
    for (int i = 0; i < database.get_toursite_place_num( scenicAreaNumber ); ++i) {
        Place * this_place = topo->places[i];
        std::string info = "场所序列号: " + std::to_string(this_place->get_index()) + "\n" +
                           "场所名称: " + *this_place->get_name() + "\n" +
                           "场所介绍: " + *this_place->get_introduction() + "\n" +
                           "场所类别: " + *this_place->get_label() + "\n" +
                           "场所获赞数: " + std::to_string(this_place->get_comments_num()) + "\n" +
                           "场所评论数: " + std::to_string(this_place->get_comments_num());
        places_info.push_back(info);
    }

    QString places_text;
    for (const auto &info : places_info) {
        places_text += QString::fromStdString(info) + "\n\n";
    }
    ui.list_of_place->setText(places_text);
}

void PlaceListDialog::onPlaceRouteClicked()
{
   // accept();
    PlaceRouteDialog dialogPlaceRoute2(this);
    dialogPlaceRoute2.exec();
}

void PlaceListDialog::onPlaceSearchClicked()
{
    // accept();
    PlaceSearchDialog dialogPlaceSearch2(this);
    dialogPlaceSearch2.exec();
}

void PlaceListDialog::onCdCommentsClicked()
{
    // accept();
    Comments_Dialog dialogComments2(this);
     dialogComments2.exec();
}

void PlaceListDialog::onGoBackClicked()
{
    accept();
}

