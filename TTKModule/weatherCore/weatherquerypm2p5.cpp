#include "weatherquerypm2p5.h"

WeatherQuerPM2P5::WeatherQuerPM2P5(QObject *parent)
    : WeatherQuery(parent)
{

}

void WeatherQuerPM2P5::startToQuery(const QString &id)
{
    if(m_reply)
    {
        m_reply->deleteLater();
        m_reply = NULL;
    }

    m_reply = m_manager->get(QNetworkRequest( QUrl(WeatherCryptographicHash::decryptData(PM2P5_QUERY_URL, URL_KEY).arg(id)) ));
    connect(m_reply, SIGNAL(finished()), SLOT(searchFinshed()) );
    connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)),this,
                     SLOT(replyError(QNetworkReply::NetworkError)) );
}

void WeatherQuerPM2P5::searchFinshed()
{
    if(m_reply == NULL)
    {
        return;
    }

    WeatherObject::WeatherPM2P5 pm2p5List;
    if(m_reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = m_reply->readAll();///Get all the data obtained by request
#ifdef WEATHER_QT_5
        QJsonParseError jsonError;
        QJsonDocument parseDoucment = QJsonDocument::fromJson(bytes, &jsonError);
        ///Put the data into Json
        if(jsonError.error != QJsonParseError::NoError ||
           !parseDoucment.isObject())
        {
            emit repliedPM2P5Finished(pm2p5List);
            return ;
        }

        QJsonObject jsonObject = parseDoucment.object();
        if(jsonObject.contains("success") &&
           jsonObject.take("success").toString() == "1")
        {
            jsonObject = jsonObject.value("result").toObject();

            pm2p5List.m_weaidP = jsonObject.value("weaid").toString();
            pm2p5List.m_aqi = jsonObject.value("aqi").toString();
            pm2p5List.m_aqiLevid = jsonObject.value("aqi_levid").toString();
            pm2p5List.m_aqiLevnm = jsonObject.value("aqi_levnm").toString();
            pm2p5List.m_aqiScope = jsonObject.value("aqi_scope").toString();
            pm2p5List.m_aqiRemark = jsonObject.value("aqi_remark").toString();
        }
        else
        {
            M_LOGGER_ERROR(QString("Error: %1").arg(jsonObject.take("msg").toString()));
            emit repliedPM2P5Finished(pm2p5List);
            return;
        }
#else
        QScriptEngine engine;
        QScriptValue sc = engine.evaluate("value=" + QString(bytes));
        if(sc.property("success").isValid() &&
           sc.property("success").toString() == "1")
        {

            if(sc.property("result").isValid())
            {
                sc = sc.property("result");
                pm2p5List.m_weaidP = sc.property("weaid").toString();
                pm2p5List.m_aqi = sc.property("aqi").toString();
                pm2p5List.m_aqiLevid = sc.property("aqi_levid").toString();
                pm2p5List.m_aqiLevnm = sc.property("aqi_levnm").toString();
                pm2p5List.m_aqiScope = sc.property("aqi_scope").toString();
                pm2p5List.m_aqiRemark = sc.property("aqi_remark").toString();
            }
        }
        else
        {
            M_LOGGER_ERROR(QString("Error: %1").arg(sc.property("msg").toString()));
            emit repliedPM2P5Finished(pm2p5List);
            return;
        }
#endif
    }

    emit repliedPM2P5Finished(pm2p5List);
    deleteLater();
}
