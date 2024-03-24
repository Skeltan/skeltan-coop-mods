#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"
#include "game/level_update.h"
#include "levels/scripts.h"
#include "actors/common1.h"
#include "make_const_nonconst.h"

#include "areas/1/custom.model.inc.h"

#include "areas/2/custom.model.inc.h"

#include "areas/3/custom.model.inc.h"

#include "levels/castle_grounds/header.h"
#include "levels/castle_inside/header.h"

extern u8 _castle_grounds_segment_ESegmentRomStart[];
extern u8 _castle_grounds_segment_ESegmentRomEnd[];

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _castle_inside_segment_7SegmentRomStart, _castle_inside_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _castle_insideSegmentRomStart, _castle_insideSegmentRomEnd),
	LOAD_RAW(0x0E, _castle_grounds_segment_ESegmentRomStart, _castle_grounds_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group8_mio0SegmentRomStart, _group8_mio0SegmentRomEnd),
	LOAD_RAW(12, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd),
	LOAD_MIO0(6, _group15_mio0SegmentRomStart, _group15_mio0SegmentRomEnd),
	LOAD_RAW(13, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
	// Level Specific Models
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_BOWSER_TRAP,        castle_geo_000F18),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WATER_LEVEL_PILLAR, castle_geo_001940),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_MINUTE_HAND,  castle_geo_001530),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_HOUR_HAND,    castle_geo_001548),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_PENDULUM,     castle_geo_001518),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR,        castle_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR,        wooden_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_METAL_DOOR,         metal_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR_UNUSED, castle_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR_UNUSED, wooden_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_0_STARS,       castle_door_0_star_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_1_STAR,        castle_door_1_star_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_3_STARS,       castle_door_3_stars_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_KEY_DOOR,           key_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_30_STARS, castle_geo_000F00),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_8_STARS,  castle_geo_000F00),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_50_STARS, castle_geo_000F00),
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_70_STARS, castle_geo_000F00),
	// Unspecified Models
	LOAD_MODEL_FROM_GEO(22,  warp_pipe_geo),
	LOAD_MODEL_FROM_GEO(23,  bubbly_tree_geo),
	LOAD_MODEL_FROM_GEO(24,  spiky_tree_geo),
	LOAD_MODEL_FROM_GEO(25,  snow_tree_geo),
	LOAD_MODEL_FROM_GEO(27,  palm_tree_geo),
	LOAD_MODEL_FROM_GEO(28,  castle_door_geo),
	LOAD_MODEL_FROM_GEO(29,  wooden_door_geo),
	LOAD_MODEL_FROM_GEO(31,  metal_door_geo),
	LOAD_MODEL_FROM_GEO(32,  hazy_maze_door_geo),
	LOAD_MODEL_FROM_GEO(34,  castle_door_0_star_geo),
	LOAD_MODEL_FROM_GEO(35,  castle_door_1_star_geo),
	LOAD_MODEL_FROM_GEO(36,  castle_door_3_stars_geo),
	LOAD_MODEL_FROM_GEO(37,  key_door_geo),
	LOAD_MODEL_FROM_GEO(38,  castle_door_geo),
	LOAD_MODEL_FROM_GEO(39,  wooden_door_geo),
	LOAD_MODEL_FROM_GEO(41,  metal_door_geo),
	// LOAD_MODEL_FROM_DL(84, 0x05002e00, 4),
	// LOAD_MODEL_FROM_DL(86, 0x05003120, 4),
	// LOAD_MODEL_FROM_DL(132, 0x08025f08, 4),
	// LOAD_MODEL_FROM_DL(158, 0x0302c8a0, 4),
	// LOAD_MODEL_FROM_DL(159, 0x0302bcd0, 4),
	// LOAD_MODEL_FROM_DL(161, 0x0301cb00, 4),
	// LOAD_MODEL_FROM_DL(164, 0x04032a18, 4),
	// LOAD_MODEL_FROM_DL(201, 0x080048e0, 4),
	// LOAD_MODEL_FROM_DL(218, 0x08024bb8, 4),
	JUMP_LINK(script_func_global_1),
	JUMP_LINK(script_func_global_9),
	JUMP_LINK(script_func_global_16),
	JUMP_LINK(local_area_castle_grounds_1_),
	JUMP_LINK(local_area_castle_grounds_2_),
	JUMP_LINK(local_area_castle_grounds_3_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 3060, -86, 5129),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_castle_grounds_1_[] = {
	AREA(1, Geo_castle_grounds_1_0x14ac080),
	TERRAIN(col_castle_grounds_1_0xe044640),
	SET_BACKGROUND_MUSIC(0, 4),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_castle_grounds_1_),
	JUMP_LINK(local_warps_castle_grounds_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_castle_grounds_1_[] = {
	OBJECT_WITH_ACTS(0, -3554, -92, 2520, 0, 270, 0, 0x320000,  bhvLaunchStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, -3856, -92, 2519, 0, 0, 0, 0x640000,  bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, -4170, -77, 2211, 0, 0, 0, 0x140000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(22, -3355, -107, -4136, 0, 0, 0, 0x220000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(22, -4755, 1351, 4992, 0, 0, 0, 0x1d0000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(0, -1277, -99, 5750, 0, 0, 0, 0x300000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(34, -1275, -108, 5508, 0, 180, 0, 0xc000000,  bhvDoor, 31),
	OBJECT_WITH_ACTS(34, -524, -89, 501, 0, 19, 0, 0x14000000,  bhvDoor, 31),
	OBJECT_WITH_ACTS(0, -969, -92, 5122, 0, 270, 0, 0x350000,  bhvLaunchStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, -969, -92, 5122, 0, 270, 0, 0x670000,  bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(221, 3208, -80, 5533, 0, 200, 0, 0x85000000,  bhvToadMessage, 31),
	OBJECT_WITH_ACTS(0, -589, 0, 271, 0, 0, 0, 0x420000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, -460, -100, 900, 0, 0, 0, 0x440000,  bhvInstantActiveWarp, 31),
	OBJECT_WITH_ACTS(221, -1440, -125, 7790, 0, 90, 0, 0x87000000,  bhvToadMessage, 31),
	OBJECT_WITH_ACTS(0, -259, -125, 2892, 0, 180, 0, 0x380000,  bhvLaunchStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, -259, -125, 2892, 0, 0, 0, 0x6a0000,  bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, -259, -125, 2892, 0, 0, 0, 0x1a0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(221, 1092, -125, 7898, 0, 180, 0, 0x86000000,  bhvToadMessage, 31),
	OBJECT_WITH_ACTS(0, -259, -125, 2892, 0, 180, 0, 0x3b0000,  bhvLaunchStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, -259, -125, 2892, 0, 0, 0, 0x6d0000,  bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 3060, -86, 5129, 0, 221, 0, 0x400000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, 5, 5, 62, 0, 0, 20, 3,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_castle_grounds_1_[] = {
	WARP_NODE(56, 16, 1, 56, 0),
	WARP_NODE(106, 16, 1, 106, 0),
	WARP_NODE(20, 9, 1, 20, 0),
	WARP_NODE(34, 16, 2, 34, 0),
	WARP_NODE(29, 18, 1, 29, 0),
	WARP_NODE(48, 12, 1, 48, 0),
	WARP_NODE(53, 16, 1, 53, 0),
	WARP_NODE(103, 16, 1, 103, 0),
	WARP_NODE(66, 16, 3, 66, 0),
	WARP_NODE(68, 16, 3, 68, 0),
	WARP_NODE(26, 16, 1, 26, 0),
	WARP_NODE(59, 16, 1, 59, 0),
	WARP_NODE(109, 16, 1, 109, 0),
	WARP_NODE(50, 16, 1, 50, 0),
	WARP_NODE(100, 16, 1, 100, 0),
	WARP_NODE(64, 16, 1, 64, 0),
	WARP_NODE(240, 16, 1, 50, 0),
	WARP_NODE(241, 16, 1, 100, 0),
	RETURN()
};

const LevelScript local_area_castle_grounds_2_[] = {
	AREA(2, Geo_castle_grounds_2_0x14abf70),
	TERRAIN(col_castle_grounds_2_0xe010fd0),
	SET_BACKGROUND_MUSIC(0, 41),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_castle_grounds_2_),
	JUMP_LINK(local_warps_castle_grounds_2_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_castle_grounds_2_[] = {
	OBJECT_WITH_ACTS(22, 645, 0, -1025, 0, 0, 0, 0x220000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(0, -664, 0, 1662, 0, 0, 0, 0x1c0000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(34, -668, 0, 1378, 0, 180, 0, 0x5000000,  bhvDoor, 31),
	OBJECT_WITH_ACTS(0, -645, 0, 533, 0, 0, 0, 0x340000,  bhvLaunchStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, -645, 0, 533, 0, 0, 0, 0x660000,  bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 60, 4, 14, 0, 0, 20, 4,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 100, 4, 272, 0, 0, 20, 5,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_castle_grounds_2_[] = {
	WARP_NODE(34, 16, 1, 34, 0),
	WARP_NODE(28, 24, 1, 28, 0),
	WARP_NODE(52, 16, 2, 52, 0),
	WARP_NODE(102, 16, 2, 102, 0),
	WARP_NODE(240, 6, 1, 50, 0),
	WARP_NODE(241, 6, 1, 100, 0),
	RETURN()
};

const LevelScript local_area_castle_grounds_3_[] = {
	AREA(3, Geo_castle_grounds_3_0x14abe60),
	TERRAIN(col_castle_grounds_3_0xe00d870),
	SET_BACKGROUND_MUSIC(0, 41),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_castle_grounds_3_),
	JUMP_LINK(local_warps_castle_grounds_3_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_castle_grounds_3_[] = {
	OBJECT_WITH_ACTS(0, 590, 66, 5947, 0, 180, 0, 0x420000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, 590, 102, -2934, 0, 0, 0, 0x430000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(0, 590, 102, -1979, 0, 180, 0, 0x380000,  bhvLaunchStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, 589, 102, -2552, 0, 0, 0, 0x6a0000,  bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 589, 66, 8300, 0, 180, 0, 0x440000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, 771, 66, 8292, 0, 180, 0, 0x440000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, 424, 66, 8306, 0, 180, 0, 0x440000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, 60, 4, 191, 0, 0, 20, 6,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 60, 4, 339, 0, 0, 20, 7,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 60, 4, 936, 0, 0, 20, 8,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_castle_grounds_3_[] = {
	WARP_NODE(66, 16, 1, 66, 0),
	WARP_NODE(67, 5, 1, 67, 128),
	WARP_NODE(56, 16, 3, 56, 0),
	WARP_NODE(106, 16, 3, 106, 0),
	WARP_NODE(68, 16, 1, 68, 0),
	WARP_NODE(240, 6, 1, 50, 0),
	WARP_NODE(241, 6, 1, 100, 0),
	RETURN()
};