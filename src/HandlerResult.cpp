#include "HandlerResult.h"

HandlerResult::HandlerResult(Result result, std::string msg)
: _result(result)
, _msg(msg)
{
}

const HandlerResult::Result& HandlerResult::getResult() const
{
   return _result;
}

const std::string& HandlerResult::getMsg() const
{
   return _msg;
}
