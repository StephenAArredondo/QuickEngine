#ifndef _SDL_HELPER_H_
#define _SDL_HELPER_H_

#include <memory>

#include <SDL.h>
// #include "RAIIHelper.h"
// 
// namespace sdl 
// {
// 
// 	struct SDL_Deleter
// 	{
// 		void operator()(SDL_GLContext* ptr) { if(ptr) SDL_GL_DeleteContext(ptr); }
// 		void operator()(SDL_Renderer* ptr) { if(ptr) SDL_DestroyRenderer(ptr); }
// 		void operator()(SDL_RWops* ptr) { if(ptr) SDL_RWclose(ptr); }
// 		void operator()(SDL_Surface* ptr) { if(ptr) SDL_FreeSurface(ptr); }
// 		void operator()(SDL_Texture* ptr) { if(ptr) SDL_DestroyTexture(ptr); }
// 		void operator()(SDL_Window* ptr) { if(ptr) SDL_DestroyWindow(ptr); }
// 	};
// 
// 	typedef GLContextPtr std::unique_ptr<SDL_GLContext, SDL_Deleter>;
// 	typedef RendererPtr std::unique_ptr<SDL_Renderer, SDL_Deleter>;
// 	typedef RWopsPtr std::unique_ptr<SDL_RWops, SDL_Deleter>;
// 	typedef SurfacePtr std::unique_ptr<SDL_Surface, SDL_Deleter>;
// 	typedef TexturePtr std::unique_ptr<SDL_Texture, SDL_Deleter>;
// 	typedef WindowPtr std::unique_ptr<SDL_Window, SDL_Deleter>;
// 
// 	 GLContextShPtr shared_ptr_with_deleter<SDL_GLContext, SDL_Deleter>;
// 	 RendererShPtr shared_ptr_with_deleter<SDL_Renderer, SDL_Deleter>;
// 	 RWopsShPtr shared_ptr_with_deleter<SDL_RWops, SDL_Deleter>;
// 	 SurfaceShPtr shared_ptr_with_deleter<SDL_Surface, SDL_Deleter>;
// 	 TextureShPtr shared_ptr_with_deleter<SDL_Texture, SDL_Deleter>;
// 	 WindowShPtr shared_ptr_with_deleter<SDL_Window, SDL_Deleter>;
// };

#endif//_SDL_HELPER_H_