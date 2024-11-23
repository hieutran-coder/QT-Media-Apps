#ifndef VIDEOINTERFACEDBUS_H
#define VIDEOINTERFACEDBUS_H

#include "VideoInterfaceDbus_global.h"

class VIDEOINTERFACEDBUS_EXPORT VideoInterfaceDbus
{
public:
    VideoInterfaceDbus();
    virtual void onVideoChanged(QString videoPath) = 0;
    virtual void onShowRequested() = 0;
    virtual void onRequestPause() = 0;
};

class VIDEOINTERFACEDBUS_EXPORT VideoDbusService
{
    public:
        void setListeners(QString serviceName, QString path, QString interfaceName);
        //singleton
        static VideoDbusService *getInstance();
    private:
        VideoDbusService();
};


#endif // VIDEOINTERFACEDBUS_H
