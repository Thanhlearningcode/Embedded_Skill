#include "inc/NotificationSystem.h"
#include <iostream>

int main() {
   


    auto basic = std::make_shared<Basic_Notification>("Hello, this is a test notification!");
    auto email = std::make_shared<Email_Notification>(basic);
    auto sms   = std::make_shared<SMS_Notification>(email);


    Notifcation_Visitor* loggingVisitor = new Visitor_Logging();
    Noification_Manager* manager = Noification_Manager::Get_Instance();

    manager->Send_Notification(sms.get(), loggingVisitor);

    // Không cần delete thủ công vì NotificationDecorator đã tự động xóa wrapped_notification_
    // delete smsNotification; 
    delete loggingVisitor;

    return 0;
}