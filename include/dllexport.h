#pragma once

/**
 * @file dllexport.h
 * @brief All about DLL export.
 */

namespace flab {

#define DLLexpt __declspec(dllexport)
#define DLLimpt __declspec(dllimport)

#if defined(DLLexport)
#define DLLfrm DLLexpt
#else
#define DLLfrm DLLimpt
#endif

}