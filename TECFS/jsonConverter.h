#ifndef JSONCONVERTER_H
#define JSONCONVERTER_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QObject>

class jsonConverter
{
public:
    jsonConverter();
    /**
     * @brief convierte la entrada en un arreglo
     * @param obj objeto a convertir
     * @return arreglo de la entrada
     */
    QByteArray convert(QJsonObject);
    /**
     * @brief Convierte un string en un json
     * @param jsonString string a convertir
     * @return json de la entrada
     */
    QJsonObject getJsonObjectFromString(const QString);
    /**
     * @brief Convierte un objeto json en un arreglo
     * @param jsonName json a convertir
     * @return arreglo de la entrada
     */
    QJsonArray readResultsJson(QJsonObject);
private:
    QString fileName;
};

#endif // JSONCONVERTER_H
