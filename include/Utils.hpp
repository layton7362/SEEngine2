#pragma once

#define isSubclass(base, class) dynamic_cast<base*>(class) != nullptr

#define ToSubclass(base, class) dynamic_cast<base*>(class)