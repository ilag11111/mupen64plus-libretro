#ifndef _M64P_LIBRETRO_H
#define _M64P_LIBRETRO_H

extern "C" int retro_return(bool just_flipping);

#define CoreVideo_Init(...)
#define CoreVideo_Quit(...)
#define CoreVideo_ListFullscreenModes(...)
#define CoreVideo_SetVideoMode(...) M64ERR_SUCCESS
#define CoreVideo_SetCaption(...)
#define CoreVideo_ToggleFullScreen(...)
#define CoreVideo_GL_GetProcAddress(...)
#define CoreVideo_GL_SetAttribute(...)
#define CoreVideo_GL_SwapBuffers(...) retro_return(true)

#endif
