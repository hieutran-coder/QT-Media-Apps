#include "videointerfacedbus.h"
#include<QMetaClassInfo>
#include<QDBusReply>
#include<QDBusConnection>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonValue>
#include<QMetaObject>
#include<QDebug>

VideoInterfaceDbus::VideoInterfaceDbus() {}

// 2 lần call
void VideoDbusService::setListeners(QString serviceName, QString path, QString interfaceName)
{
    // Những ai muốn đưa video thành listerner  của nó thì sẽ gọi hàm này (
    QDBusMessage message = QDBusMessage::createMethodCall(
        "Video.Service",
        "/VideoService",
        "com.fpt.VideoServiceInterface",
        "onMessageReceived"
        );

    // Mục đích thông tin này gửi đi là gì?
    QJsonObject jsonObj;
    jsonObj.insert("msg", "addNewListener"); // Tại sao lại có hàm bên trong

    // Gửi thông tin
    QJsonObject jsonSubObj;
    jsonSubObj.insert("ServiceName", serviceName);
    jsonSubObj.insert("Path", path);
    jsonSubObj.insert("ServiceInterface", interfaceName);

    jsonObj.insert("data", jsonSubObj);

    message << QString(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact));

    QDBusReply<void> reply = QDBusConnection::sessionBus().call(message);

    // Kiểm tra kết quả trả về
    if (!reply.isValid()) {
        qDebug() << "Error:" << reply.error().message();
    }
}

VideoDbusService *VideoDbusService::getInstance()
{
    static VideoDbusService* tmp = new VideoDbusService();
    return tmp;
}

VideoDbusService::VideoDbusService()
{

}
