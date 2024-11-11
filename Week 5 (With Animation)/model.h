#ifndef _MODEL_H_
#define _MODEL_H_
#include "space.h"

namespace model{
	class Teapot{
		public:
			void draw();
	};
	
	class World{
		public:
			Teapot teapot;
			void draw();
	};
};
#endif
