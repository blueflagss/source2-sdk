#ifndef CS2_PROJECT_INCLUDES_HPP
#define CS2_PROJECT_INCLUDES_HPP

#include <windows.h>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <deque>
#include <dxgi.h>
#include <d3d11.h>
#include <string>
#include <spdlog/spdlog.h>
#include <minhook/minhook.h>
#include <xorstr.hpp>
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>
#include <shlobj_core.h>
#include "utilities/padding.hpp"
#include "utilities/console/console.hpp"
#include <imgui/imgui.h>
#include <imgui/imgui_impl_win32.h>
#include <imgui/imgui_impl_dx11.h>
#include <imgui/imgui_internal.h>
#include <imgui/imgui_freetype.h>

#include "utilities/utilities.hpp"
#include "utilities/fnv1a.hpp"
#include "utilities/winapi/undocumented.hpp"
#include "utilities/winapi/winapi.hpp"
#include "utilities/pattern.hpp"
#include "resources/04b03.hpp"
#include "sdk/math/color.hpp"
#include "sdk/math/vector.hpp"
#include "sdk/math/math.hpp"
#include "sdk/tier0.hpp"
#include "sdk/common/CUtlTSHash.h"
#include "sdk/enums.hpp"
#include "sdk/user_cmd.hpp"
#include "sdk/interfaces/client.hpp"
#include "sdk/interfaces/global_vars.hpp"
#include "sdk/interfaces/engine_client.hpp"
#include "sdk/interfaces/csgo_input.hpp"
#include "sdk/interfaces/mem_alloc.hpp"
#include "sdk/interfaces/physics_query.hpp"
#include "sdk/interfaces/schema_system.hpp"
#include "utilities/render/render.hpp"
#include "core/schema.hpp"
#include "sdk/tier0.hpp"
#include "sdk/collision_property.hpp"
#include "sdk/player.hpp"
#include "core/interfaces.hpp"
#include "hooks/detour.hpp"
#include "utilities/globals.hpp"
#include "core/config.hpp"
#include "core/menu.hpp"
#include "features/features.hpp"
#include "hooks/resize_buffers/resize_buffers.hpp"
#include "hooks/present/present.hpp"
#include "hooks/wndproc/wndproc.hpp"
#include "hooks/level_init/level_init.hpp"
#include "hooks/frame_stage_notify/frame_stage_notify.hpp"
#include "hooks/create_move/create_move.hpp"
#include "hooks/hooks.hpp"

#endif //CS2_PROJECT_INCLUDES_HPP