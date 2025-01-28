#pragma once 
#include "CFpch.hpp"

namespace CanvasForge {
  class Log {
  public:
    static void Init();
    static void ShutDown();
    
    static void Message(std::wstring _message);
    static void Warning(std::wstring _message);
    static void Error(std::wstring _message);

    static void Throw(std::wstring _message);

    static std::function<void(std::wstring _message)> customLogFunc;
  private:
    static void SendMessage(std::wstring _prefix, std::wstring _message, int _color);

    static std::string currentLogFile;
    static std::wfstream logStream;
    static std::wstring logString;

  };
}