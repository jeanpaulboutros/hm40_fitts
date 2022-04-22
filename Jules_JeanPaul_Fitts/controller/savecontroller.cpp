#include "savecontroller.h"
#include <iostream>
#include <string>
#include <sstream>

SaveController::SaveController()
{
}

void SaveController::saveContent(const SavedData& data) {
    // Chargement de l'ancien fichier et parsing
    QList<SavedData> newData = this->loadFile();
    // Ajout nouvelle donnée
    newData.append(data);

    //  Serialization
    QJsonArray mainArray;
    for (auto data : newData) {
        mainArray.append(data.toJson());
    }
    QJsonDocument jsonDoc(mainArray);

    QFile file("data.json");
    if(!file.open(QIODevice::ReadWrite)) {
        qDebug() << "File open error";
    } else {
        qDebug() <<"JSON File open!";
    }

    file.write(jsonDoc.toJson());
    file.close();
}

QList<SavedData> SaveController::loadFile() {
    QFile file("data.json");
    QList<SavedData> fileData;
    if(!file.open(QIODevice::ReadWrite  )) {
        qDebug() << "File open error";
    } else {
        qDebug() << "JSON File open!";
    }

    QString val = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    QJsonArray jsonArr = doc.array();
    QJsonObject jsonObject = doc.object();




    for (auto v : jsonArr) {
        QJsonObject element = v.toObject();
        QList<QPoint> clickedPoints;
        QList<QPoint> cercleCenter;
        QList<int> cercleSize;
        QList<qint64> times;

        QJsonArray cercleSizeArr = element["cercleSize"].toArray();
        QJsonArray clickedPointsArr = element["clickedPoints"].toArray();
        QJsonArray timesArr = element["times"].toArray();
        QJsonArray cercleCenterArr = element["cercleCenter"].toArray();
        for (int i = 0; i < cercleSizeArr.count(); i++) {
             cercleCenter.append(QPoint(cercleCenterArr.at(i*2).toInt(), cercleCenterArr.at(i*2+1).toInt()));
            clickedPoints.append(QPoint(clickedPointsArr.at(i*2).toInt(), clickedPointsArr.at(i*2+1).toInt()));
            cercleSize.append(cercleSizeArr.at(i).toInt());
            times.append(timesArr.at(i).toDouble());
        }

        SavedData tempData ;

        tempData.cercleCenter = cercleCenter;
        tempData.clickedPoints = clickedPoints;
        tempData.cercleSize = cercleSize;
        tempData.times = times;



        fileData.append(tempData);
    }


    return fileData;
}



void SaveController::test(){
    SavedData data = {};
    QList<QPoint> points;
    points.append(QPoint(1, 1));
    points.append(QPoint(12, 31));
    points.append(QPoint(2, 6));
    data.clickedPoints = points;

    QList<QPoint> points2;
    points2.append(QPoint(4, 4));
    points2.append(QPoint(2, 3));
    points2.append(QPoint(5, 6));
    data.cercleCenter = points2;

    QList<int> size;
    size.append(4);
    size.append(5);
    size.append(6);
    data.cercleSize = size;

    QList<qint64> time;
    time.append(Q_INT64_C(932838457459459));
    time.append(Q_INT64_C(932838232459459));
    time.append(Q_INT64_C(132838457459459));
    data.times = time;

    QJsonDocument doc( data.toJson());
    QString jsonString = doc.toJson(QJsonDocument::Indented);
    qDebug() << jsonString.toStdString().c_str();

    this->saveContent(data);
}
