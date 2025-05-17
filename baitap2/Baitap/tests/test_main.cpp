#include <gtest/gtest.h>
#include "../inc/NotificationSystem.h"

// Test fixture for NotificationSystem tests
class NotificationSystemTest : public ::testing::Test {
protected:

};

// Test Noification_Manager Singleton
TEST_F(NotificationSystemTest, NotificationManagerIsSingleton) {
    Noification_Manager* manager1 = Noification_Manager::Get_Instance();
    Noification_Manager* manager2 = Noification_Manager::Get_Instance();
    EXPECT_EQ(manager1, manager2); // Kiểm tra xem cả hai có cùng địa chỉ không
}

// Test Visitor_Logging visit
TEST_F(NotificationSystemTest, VisitorLoggingVisit) {
    Basic_Notification notification("Test log message");
    Visitor_Logging visitor;
    notification.accept(&visitor);
    // Kiểm tra thông điệp được ghi log đúng 
    EXPECT_EQ(notification.Get_Message(), "Test log message");
}

// Test Decorator Chain Get_Message
TEST_F(NotificationSystemTest, DecoratorChainGetMessage) {
    Notifcation* basic = new Basic_Notification("Decorator test");
    Notifcation* email = new Email_Notification(basic);
    Notifcation* sms = new SMS_Notification(email);
    EXPECT_EQ(sms->Get_Message(), "Decorator test");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}