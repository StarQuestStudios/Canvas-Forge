#include "CFpch.hpp"
#include "Log.hpp"
#include "Engine.hpp"

namespace CanvasForge
{
  std::string Log::currentLogFile;
  std::fstream Log::logStream;
  std::string Log::logString;
  std::function<void(std::string _message)> Log::customLogFunc;

  void Log::Init()
  {
    if (!std::filesystem::exists("./Logs/"))
    {
      std::filesystem::create_directory("./Logs");
    }

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%y %H-%M-%S");
    currentLogFile = oss.str();

    std::ofstream tmpStream("./Logs/" + currentLogFile);
    tmpStream.close();

#ifndef ACE_DIST
    logStream.open("./Logs/" + currentLogFile);
#endif
  }

  void Log::ShutDown()
  {
#ifndef ACE_PLATFORM_ANDROID
    logStream.close();
#endif
  }

  void Log::Message(std::string _message)
  {
    SendMessage("Message", _message, 7);
  }

  void Log::Warning(std::string _message)
  {
    SendMessage("Warning", _message, 14);
  }

  void Log::Error(std::string _message)
  {
    SendMessage("Error", _message, 12);
  }

  void Log::Throw(std::string _message)
  {
    // TODO: Implement a way to throw exceptions
    // Engine::os->Throw(_message);
#ifdef ACE_PLATFORM_WIN
#elif __EMSCRIPTEN__
    std::string warnjs = "alert('ERROR: " + Utils::Wstr2str(_message) + "')";
    emscripten_run_script(warnjs.c_str());
#endif
    Engine::Quit();
  }

  void Log::SendMessage(std::string _prefix, std::string _message, int _color)
  {
#ifndef ACE_DIST
    std::time_t t = std::time(nullptr);
    std::tm timestamp = *std::localtime(&t);
    _message = "[%T][" + _prefix + "] " + _message;
#ifdef __WIN32__
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, _color);
    std::cout << std::put_time(&timestamp, _message.c_str()) << std::endl;
    logStream << std::put_time(&timestamp, _message.c_str()) << std::endl;
#else
    std::string ColorCode = "\033[0m";

    if (_color == 12)
    {
      ColorCode = "\033[31m";
    }
    else if (_color == 14)
    {
      ColorCode = "\033[33m";
    }

    if (Engine::os != nullptr)
    {
      Engine::os->LogMessage(_message);
    }
    std::wcout << ColorCode << std::put_time(&timestamp, _message.c_str()) << std::endl;
#endif

#ifndef ACE_PLATFORM_ANDROID
    logStream << std::put_time(&timestamp, _message.c_str()) << std::endl;
#endif

#endif
    if (customLogFunc != NULL)
    {
      _message.replace(_message.find("[%T]"), 4, "");
      customLogFunc(_message);
    }
  }
}