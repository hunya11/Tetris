#include "DxLib.h"
#include <string>
#include <list>
#include <math.h>
#include <sstream>
#include <random>
#include <Windows.h>
#include <vector>
#include <iostream>
#include <iomanip>

#pragma warning(disable:4290)
using namespace std;

#define X_SIZE 800
#define Y_SIZE 600

struct FRAME_PAGE {
	enum Type{
		TITLE = 0,
		GAME = 1,
		END
	};
};





#include "RandomNum.h"

#include "BaseComponent.h"
#include "KeyPushed.h"
#include "Fps.h"


#include "DrawableComponent.h"
#include "SelectionMenu.h"

#include "GameObject.h"
#include "Block.h"

#include "Effect.h"
#include "Effect_DelBlock.h"
#include "Effect_FadeString.h"

#include "Page.h"
#include "TitlePage.h"
#include "GamePage.h"

#include "Frame.h"


