#pragma once 
#include "CFpch.hpp"

namespace CanvasForge {
  class Log {
  public:
    static void Init();
    static void ShutDown();
    
    static void Message(std::string _message);
    static void Warning(std::string _message);
    static void Error(std::string _message);

    static void Throw(std::string _message);

    static std::function<void(std::string _message)> customLogFunc;
  private:
    static void SendMessage(std::string _prefix, std::string _message, int _color);

    static std::string currentLogFile;
    static std::fstream logStream;
    static std::string logString;

  };
}