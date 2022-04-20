#ifndef SAVECONTROLLER_H
#define SAVECONTROLLER_H
#include "view/view.h"
#include <QtCore>
#include <cstdio>
#include <QJsonObject>
#include <sstream>
#include <string>
struct SavedData
{
    QList<QPoint> clickedPoints;
    QList<QPoint> cercleCenter;
    QList<int> cercleSize;
    QList<qint64> times;


    QJsonObject toJson() const {
       QJsonObject mainObject;
       QJsonArray clickedPointsArr;
       QJsonArray cercleCenterArr;
       QJsonArray cercleSizeArr;
       QJsonArray timesArr;


       foreach(QPoint item, clickedPoints)
       {
            clickedPointsArr.push_back(item.x());
           clickedPointsArr.push_back(item.y());
       }
       foreach(QPoint item, cercleCenter)
       {
           cercleCenterArr.push_back(item.x());
           cercleCenterArr.push_back(item.y());
       }

       foreach(int item, cercleSize)
       {
           std::stringstream ss;
           cercleSizeArr.push_back(item);
       }

       foreach(qint64 item, times)
       {
           std::stringstream ss;
           timesArr.push_back(item);
       }


        mainObject.insert("clickedPoints", clickedPointsArr);
        mainObject.insert("cercleCenter", cercleCenterArr);
        mainObject.insert("cercleSize", cercleSizeArr);
        mainObject.insert("times", timesArr);

        return mainObject;
    }
//    SavedData(QList<QPoint> clickedPoints, QList<QPoint> cercleCenter, QList<int> cercleSize, QList<qint64> times)
//    {
//      this->clickedPoints = clickedPoints;
//      this->cercleCenter = cercleCenter;
//      this->cercleSize = cercleSize;
//      this->times = times;
//    }
};


class SaveController
{

private:

public:
    SaveController();
    void saveContent(const SavedData& data);
    void test();
    QList<SavedData> loadFile();

};

#endif // SAVECONTROLLER_H
