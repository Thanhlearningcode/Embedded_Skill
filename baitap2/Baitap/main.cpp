#include "inc/NotificationSystem.h"
#include <iostream>

int main() {
    Notifcation* basicNotification = new Basic_Notification("Hello, this is a test notification!");
    Notifcation* emailNotification = new Email_Notification(basicNotification);
    Notifcation* smsNotification = new SMS_Notification(emailNotification);

    Notifcation_Visitor* loggingVisitor = new Visitor_Logging();
    Noification_Manager* manager = Noification_Manager::Get_Instance();

    manager->Send_Notification(smsNotification, loggingVisitor);

    delete loggingVisitor;

    return 0;
}
