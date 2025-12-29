#ifndef WINWINDOW_H
#define WINWINDOW_H

#ifdef __cplusplus
extern "C"{
#endif

#if defined(WW_STATIC)
  #define WW_API
#elif defined(_WIN32) || defined(__CYGWIN__)
  #if defined(BUILDING_WINWINDOW)
    #define WW_API __declspec(dllexport)
  #else
    #define WW_API __declspec(dllimport)
  #endif
#elif defined(__GNUC__) && __GNUC__ >= 4
  #define WW_API __attribute__((visibility("default")))
#else
  #define WW_API
#endif

typedef struct Window Window;

WW_API Window* WindowCreate(int w, int h);
WW_API void WindowDestroy(Window* wnd);
WW_API void ClearWindow(Window*, unsigned int color);
WW_API void PutPixel(Window*, int x, int y, unsigned int color);
WW_API int WindowProcessMessage(void);
WW_API void WindowUpdate(Window*);
WW_API void WSleep(int);

#ifdef __cplusplus
}
#endif
#endif