#pragma once
#include <string>

class HandlerResult
{
public:
   enum Result
   {
      Success,
      Fail,
   };
   HandlerResult(Result result, std::string msg);

   const Result& getResult() const;
   const std::string& getMsg() const;
private:
   Result _result;
   std::string _msg;
};
