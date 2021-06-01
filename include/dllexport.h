#pragma once

namespace flab {

#define DLLexpt __declspec(dllexport)
#define DLLimpt __declspec(dllimport)

#if defined(DLLexport)
#define DLLfrm DLLexpt
#else
#define DLLfrm DLLimpt
#endif

}