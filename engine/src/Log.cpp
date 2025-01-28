#include "CFpch.hpp"
#include "Log.hpp"
#include "Engine.hpp"

namespace CanvasForge
{
  std::string Log::currentLogFile;
  std::wfstream Log::logStream;
  std::wstring Log::logString;
  std::function<void(std::wstring _message)> Log::customLogFunc;

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

  void Log::Message(std::wstring _message)
  {
    SendMessage(L"Message", _message, 7);
  }

  void Log::Warning(std::wstring _message)
  {
    SendMessage(L"Warning", _message, 14);
  }

  void Log::Error(std::wstring _message)
  {
    SendMessage(L"Error", _message, 12);
  }

  void Log::Throw(std::wstring _message)
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

  void Log::SendMessage(std::wstring _prefix, std::wstring _message, int _color)
  {
#ifndef ACE_DIST
    std::time_t t = std::time(nullptr);
    std::tm timestamp = *std::localtime(&t);
    _message = L"[%T][" + _prefix + L"] " + _message;
#ifdef __WIN32__
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, _color);
    std::wcout << std::put_time(&timestamp, _message.c_str()) << std::endl;
    logStream << std::put_time(&timestamp, _message.c_str()) << std::endl;
#else
    std::wstring ColorCode = L"\033[0m";

    if (_color == 12)
    {
      ColorCode = L"\033[31m";
    }
    else if (_color == 14)
    {
      ColorCode = L"\033[33m";
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
      _message.replace(_message.find(L"[%T]"), 4, L"");
      customLogFunc(_message);
    }
  }
}