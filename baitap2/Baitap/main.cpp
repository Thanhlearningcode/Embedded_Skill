#include "inc/NotificationSystem.h"
#include <iostream>

int main() {
    Notifcation* basicNotification = new Basic_Notification("Hello, this is a test notification!");
    Notifcation* emailNotification = new Email_Notification(basicNotification);
    Notifcation* smsNotification = new SMS_Notification(emailNotification);

    Notifcation_Visitor* loggingVisitor = new Visitor_Logging();
    Noification_Manager* manager = Noification_Manager::Get_Instance();

    manager->Send_Notification(smsNotification, loggingVisitor);

    // Không cần delete thủ công vì NotificationDecorator đã tự động xóa wrapped_notification_
    // delete smsNotification; 
    delete loggingVisitor;

    return 0;
}