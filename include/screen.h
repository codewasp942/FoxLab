/**
 * @file screen.h
 * @brief Declare class screen.
 * @author codewasp942
 * @email tmz50301@163.com
 * @date 2021-5-22
*/

#pragma once
#define DLLexport
#include "dllexport.h"

namespace FoxLab {

/**
 * @brief Screen class.
 * This class holds a reference to all the data structures that will be displayed.
*/
DLLfrm class screen {
public:
	screen();

	/**
	 * @brief Create window.
	 * @param wide Wide of the window
	 * @param height Height of the window
	 * @return Is init successed
	 *   @retval If successed , return true
	*/
	bool init(int wide, int height);


private:

};

}