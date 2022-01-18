#ifndef __DHUUM_TIMER_H__
#define __DHUUM_TIMER_H__

#include "arcdps_defs.h"
#include <d3d9.h>
#include <string>
#include <vector>
#include "imgui.h"

#define LOGGING_ENABLED 0

#if LOGGING_ENABLED
#include "arc_logging.h"
arc_logging* logging = nullptr;
#endif

LinkedMem *lm = NULL;
MumbleContext *mc = NULL;

/* proto/globals */
uint32_t cbtcount = 0;
arcdps_exports arc_exports;
char* arcvers;
void dll_init(HANDLE hModule);
void dll_exit();
extern "C" __declspec(dllexport) void* get_init_addr(char* arcversion,
    ImGuiContext* imguictx, void* id3dptr, HANDLE arcdll, void* mallocfn,
    void* freefn, uint32_t d3dversion);
extern "C" __declspec(dllexport) void* get_release_addr();
arcdps_exports* mod_init();
uintptr_t mod_release();
uintptr_t mod_wnd(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
uintptr_t mod_combat(cbtevent* ev, ag* src, ag* dst, char* skillname, uint64_t id, uint64_t revision);
uintptr_t mod_imgui();
void mod_reset();
void log_file(char* str);
void log_arc(char* str);

/* arcdps exports */
void* filelog;
void* arclog;

bool in_hoc;
bool dhuum_present;
bool entered_combat;
bool self_dead;
uint64_t encounter_start_time;

uint32_t current_green_circle;
std::vector<uint32_t> green_circle_times;
std::vector<std::string> green_circle_symbols;

#define GREATER_DEATH_MARK_EVENTS 5
uint32_t current_greater_death_mark;
std::vector<uint32_t> greater_death_mark_times;

#endif // __DHUUM_TIMER_H__
