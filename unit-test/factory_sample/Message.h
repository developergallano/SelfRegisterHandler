#pragma once
#include <string>

#include "Registry.h"

class Message
{
public:
    Message(std::string message) : _message(message){}
    ~Message(){}
    virtual bool processMessage(std::string message){return false;}
protected:
    std::string _message;
};

class LoginMessage : public Message
{
public:
    LoginMessage(std::string message) : Message(message + " :(login-message)"){}
    virtual bool processMessage(std::string message){ return message == _message;}
};

class LogoutMessage : public Message
{
public:
    LogoutMessage(std::string message) : Message(message + " :(logout-message)"){}
    virtual bool processMessage(std::string message){ return message == _message;}
};

//messages
const char LOGINMESSAGE[] = "LOGINMESSAGE";
const char LOGOUTMESSAGE[] = "LOGOUTMESSAGE";

using MessagePtr = std::unique_ptr<Message>;

MessagePtr createLoginMessage(std::string message)
{
    return std::make_unique<LoginMessage>(message);
}

MessagePtr createLogoutMessage(std::string message)
{
    return std::make_unique<LogoutMessage>(message);
}


std::function<MessagePtr(std::string)> loginCreator = createLoginMessage;
std::function<MessagePtr(std::string)> logoutCreator = createLogoutMessage;
//using Func = std::function<MessagePtr(std::string)>;
using MessageFactory = Factory<const char*,MessagePtr>;
//using SelfRegister = SelfRegisterRegistry<const char*, Func>;
//template<>template<> bool SelfRegister::InstReg<const char*, Func>::_registered 
static bool testMessage1 = MessageFactory::registerCreator<std::string>(LOGINMESSAGE, loginCreator);
static bool testMessage2 = MessageFactory::registerCreator<std::string>(LOGOUTMESSAGE, logoutCreator);
