#pragma once

/* STD */
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <map>
#include <thread>
#include <functional>
#include <algorithm>
#include <random>

/* OS */
#ifdef WIN32
#include <Windows.h>
#endif

#ifdef __APPLE__
#ifdef __OBJC__
#include <CoreFoundation/CoreFoundation.h>
#include <Cocoa/Cocoa.h>
#else
#endif
#endif

/* OSLib */
#include "OSLib.hpp"

/* Engine */
#include "Log.hpp"
#include "core/Vector.hpp"
#include "renderer/Mesh.hpp"
#include "core/Uuid.hpp"
#include "Application.hpp"
#include "Engine.hpp"

/* Renderer */
#include "renderer/Window.hpp"