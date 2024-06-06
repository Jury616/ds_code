// Implementation of ScenicAreaRecommendSearchDialog

#include "scenic_area_recommend_and_search.h"
#include "datastr_wyq/datastr_wyq/shc/Database.h"
#include"QMessageBox"
extern Database database;


ScenicAreaRecommendSearchDialog::ScenicAreaRecommendSearchDialog(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    connect(ui.go_back, &QPushButton::clicked, this, &ScenicAreaRecommendSearchDialog::onGoBackClicked);
    connect(ui.search_by_key_word, &QPushButton::clicked, this, &ScenicAreaRecommendSearchDialog::onSearchByKeyWordClicked);
    connect(ui.search_by_label, &QPushButton::clicked, this, &ScenicAreaRecommendSearchDialog::onSearchByLabelClicked);
    connect(ui.search_by_name, &QPushButton::clicked, this, &ScenicAreaRecommendSearchDialog::onSearchByNameClicked);
}

void ScenicAreaRecommendSearchDialog::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
    loadScenicAreaRecommendations();
}

void ScenicAreaRecommendSearchDialog::loadScenicAreaRecommendations()
{
    int place_num = 10;
    int* areaRecommend = database.get_recommended_toursites_index( place_num );
    for (int i = 0; i < place_num; ++i) {
        std::string ind = std::to_string((areaRecommend[i]));
        QString place_name = QString :: fromStdString(* database.get_toursite_name(areaRecommend[i])+"            序列号为："+ind);
        ui.recommend_scenic_area->append(place_name);
    }
}



void ScenicAreaRecommendSearchDialog::onGoBackClicked()
{
    accept();
}

void ScenicAreaRecommendSearchDialog::onSearchByKeyWordClicked()
{
    std::string KeyWordText = ui.key_word->text().toStdString();
    if(KeyWordText.empty())
        QMessageBox::warning(NULL,"警告！","搜索栏为空!");
    int* indices = database.get_toursites_index_by_search(KeyWordText, 10);

    ui.scenic_area_from_search->clear();
           for (int i = 0;  i < 10 ; ++i) {
               if ( indices[i] > 0){
                   std::string ind = std::to_string((indices[i]));
                   QString place_name = QString :: fromStdString(* database.get_toursite_name(indices[i]));
                   ui.scenic_area_from_search->append(place_name+"   "+QString::fromStdString(ind));
               }
               else{
                   ui.scenic_area_from_search->append("很抱歉，未找到。");
                   i += 20;
               }
           }

}

void ScenicAreaRecommendSearchDialog::onSearchByLabelClicked()
{
    std::string LabelText = ui.label->text().toStdString();
    if(LabelText.empty())
        QMessageBox::warning(NULL,"警告！","搜索栏为空!");
    int* indices = database.get_toursites_index_by_search(LabelText, 10);

    ui.scenic_area_from_search->clear();
           for (int i = 0;  i < 10 ; ++i) {
               if ( indices[i] > 0){
                   std::string ind = std::to_string((indices[i]));
                   QString place_name = QString :: fromStdString(* database.get_toursite_name(indices[i]));
                   ui.scenic_area_from_search->append(place_name+"   "+QString::fromStdString(ind));
               }
               else{
                   ui.scenic_area_from_search->append("很抱歉，未找到。");
                   i += 20;
               }
            }
}

void ScenicAreaRecommendSearchDialog::onSearchByNameClicked()
{
        std::string nameText = ui.name->text().toStdString();
        if(nameText.empty())
            QMessageBox::warning(NULL,"警告！","搜索栏为空!");
        int* indices = database.get_toursites_index_by_search(nameText, 10);

        ui.scenic_area_from_search->clear();
               for (int i = 0;  i < 10 ; ++i) {
                   if ( indices[i] > 0){
                       std::string ind = std::to_string((indices[i]));
                       QString place_name = QString :: fromStdString(* database.get_toursite_name(indices[i]));
                       ui.scenic_area_from_search->append(place_name+"   "+QString::fromStdString(ind));
                   }
                   else{
                       ui.scenic_area_from_search->append("很抱歉，未找到。");
                       i += 20;
                   }
                }

}
