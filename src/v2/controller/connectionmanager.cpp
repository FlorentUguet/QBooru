#include "connectionmanager.h"

ConnectionManager::ConnectionManager()
{

}

QList<QNetworkCookie> ConnectionManager::getLoginCookie(string url, string user, string pass){
    QString qurl = QString(url.c_str());
    QString quser = QString(user.c_str());
    QString qpass = QString(pass.c_str());

    return getLoginCookie(qurl,quser,qpass);
}

QList<QNetworkCookie> ConnectionManager::getLoginCookie(QString url, QString user, QString pass)
{
    //Getting redirection
    QUrlQuery *postData = new QUrlQuery;
    postData->addQueryItem("user", user);
    postData->addQueryItem("pass", pass);
    postData->addQueryItem("submit", "Log+in");

    QUrl qurl = QUrl(url);

    QNetworkReply* m_pReply = execPostRequest(qurl,postData);

    //qDebug() << "Loop finished";
    QVariant variantCookies = m_pReply->header(QNetworkRequest::SetCookieHeader);
    QList<QNetworkCookie> cookies = qvariant_cast<QList<QNetworkCookie> >(variantCookies);
    //qDebug() << "Cookies reply: " << cookies.toSet();

    if(m_pReply->error() != QNetworkReply::NoError)
    {
        std::string output_s = std::string("Network error while downloading ") + url.toStdString();
        outputInfo(L_ERROR,output_s);
        outputInfo(L_ERROR,m_pReply->errorString().toStdString());
        return cookies;
    }

    return cookies;
}

QNetworkReply* ConnectionManager::execPostRequest(QUrl url, QUrlQuery *data)
{
    return execRequest(url,POST,data);
}

QNetworkReply* ConnectionManager::execGetRequest(QUrl url, QUrlQuery *data)
{
    QUrl qurl = QUrl(url.toString() + data->toString());
    return execRequest(qurl,GET);
}

QNetworkReply* ConnectionManager::execRequest(QUrl url, ReqType type, QUrlQuery *data)
{
    //Synchronous download
    QNetworkAccessManager *manager = new QNetworkAccessManager;
    QNetworkRequest request;

    request.setUrl(url.toString());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    //request.setRawHeader("Referer", referer);

    QNetworkReply* m_pReply;

    switch(type){
    case GET:
        qDebug() << "Querying" << url.toString() << "with GET";
        m_pReply = manager->get(request);
        break;
    case POST:
        if(data != NULL){
            qDebug() << "Querying" << url.toString() << "with POST" << data->toString(QUrl::FullyEncoded).toUtf8();
            m_pReply = manager->post(request, data->toString(QUrl::FullyEncoded).toUtf8());
        }else{
            qDebug() << "Could not query" << url.toString() << "with POST : " << "Post data empty";
            return 0;
        }
        break;
    default:
        break;
    }

    QEventLoop loop;
    QObject::connect(m_pReply, SIGNAL(finished()),&loop, SLOT(quit()));
    loop.exec();

    return m_pReply;
}