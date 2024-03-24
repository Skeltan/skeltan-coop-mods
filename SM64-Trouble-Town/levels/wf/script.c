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

#include "levels/wf/header.h"
#include "levels/wdw/header.h"

extern u8 _wf_segment_ESegmentRomStart[];
extern u8 _wf_segment_ESegmentRomEnd[];

const LevelScript level_wf_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _wdw_segment_7SegmentRomStart, _wdw_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _wdwSegmentRomStart, _wdwSegmentRomEnd),
	LOAD_RAW(0x0E, _wf_segment_ESegmentRomStart, _wf_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group1_mio0SegmentRomStart, _group1_mio0SegmentRomEnd),
	LOAD_RAW(12, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd),
	LOAD_MIO0(6, _group13_mio0SegmentRomStart, _group13_mio0SegmentRomEnd),
	LOAD_RAW(13, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
	// Level Specific Models
	LOAD_MODEL_FROM_GEO(MODEL_WDW_BUBBLY_TREE,                   bubbly_tree_geo),
	    LOAD_MODEL_FROM_GEO(MODEL_WDW_SQUARE_FLOATING_PLATFORM,      wdw_geo_000580),
	    LOAD_MODEL_FROM_GEO(MODEL_WDW_ARROW_LIFT,                    wdw_geo_000598),
	    LOAD_MODEL_FROM_GEO(MODEL_WDW_WATER_LEVEL_DIAMOND,           wdw_geo_0005C0),
	    LOAD_MODEL_FROM_GEO(MODEL_WDW_HIDDEN_PLATFORM,               wdw_geo_0005E8),
	    LOAD_MODEL_FROM_GEO(MODEL_WDW_EXPRESS_ELEVATOR,              wdw_geo_000610),
	    LOAD_MODEL_FROM_GEO(MODEL_WDW_RECTANGULAR_FLOATING_PLATFORM, wdw_geo_000628),
	    LOAD_MODEL_FROM_GEO(MODEL_WDW_ROTATING_PLATFORM,             wdw_geo_000640),
	// Unspecified Models
	LOAD_MODEL_FROM_GEO(22,  warp_pipe_geo),
	LOAD_MODEL_FROM_GEO(23,  bubbly_tree_geo),
	LOAD_MODEL_FROM_GEO(24,  spiky_tree_geo),
	LOAD_MODEL_FROM_GEO(25,  snow_tree_geo),
	LOAD_MODEL_FROM_GEO(27,  palm_tree_geo),
	LOAD_MODEL_FROM_GEO(31,  metal_door_geo),
	LOAD_MODEL_FROM_GEO(32,  hazy_maze_door_geo),
	LOAD_MODEL_FROM_GEO(34,  castle_door_0_star_geo),
	LOAD_MODEL_FROM_GEO(35,  castle_door_1_star_geo),
	LOAD_MODEL_FROM_GEO(36,  castle_door_3_stars_geo),
	LOAD_MODEL_FROM_GEO(37,  key_door_geo),
	LOAD_MODEL_FROM_GEO(38,  castle_door_geo),
	// LOAD_MODEL_FROM_DL(132, 0x08025f08, 4),
	// LOAD_MODEL_FROM_DL(158, 0x0302c8a0, 4),
	// LOAD_MODEL_FROM_DL(159, 0x0302bcd0, 4),
	// LOAD_MODEL_FROM_DL(161, 0x0301cb00, 4),
	// LOAD_MODEL_FROM_DL(164, 0x04032a18, 4),
	// LOAD_MODEL_FROM_DL(201, 0x080048e0, 4),
	// LOAD_MODEL_FROM_DL(218, 0x08024bb8, 4),
	JUMP_LINK(script_func_global_1),
	JUMP_LINK(script_func_global_2),
	JUMP_LINK(script_func_global_14),
	JUMP_LINK(local_area_wf_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_wf_1_[] = {
	AREA(1, Geo_wf_1_0x1352200),
	TERRAIN(col_wf_1_0xe074ae0),
	SET_BACKGROUND_MUSIC(0, 35),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_wf_1_),
	JUMP_LINK(local_warps_wf_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_wf_1_[] = {
	OBJECT_WITH_ACTS(0, 3788, 0, -19, 0, -90, 0, 0x1c0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(56, -14168, -3666, -7724, 0, 0, 0, 0x0,  bhvWaterLevelDiamond, 31),
	OBJECT_WITH_ACTS(56, -9634, -2790, -4736, 0, 0, 0, 0x0,  bhvWaterLevelDiamond, 31),
	OBJECT_WITH_ACTS(0, -11404, -4596, -5156, 0, 0, 0, 0x0,  bhvInitializeChangingWaterLevel, 31),
	OBJECT_WITH_ACTS(56, -14414, -936, -4657, 0, 0, 0, 0x0,  bhvWaterLevelDiamond, 31),
	OBJECT_WITH_ACTS(54, -13304, -3515, -6078, 0, 0, 0, 0x0,  bhvWdwSquareFloatingPlatform, 31),
	OBJECT_WITH_ACTS(56, -14287, -2207, -6132, 0, 0, 0, 0x0,  bhvWaterLevelDiamond, 31),
	OBJECT_WITH_ACTS(105, -14044, -3120, -4774, 0, 0, 0, 0x0,  bhvSkeeter, 31),
	OBJECT_WITH_ACTS(105, -11877, -3120, -6589, 0, 0, 0, 0x0,  bhvSkeeter, 31),
	OBJECT_WITH_ACTS(105, -9580, -3120, -7159, 0, 0, 0, 0x0,  bhvSkeeter, 31),
	OBJECT_WITH_ACTS(105, -11129, -3120, -4886, 0, 0, 0, 0x0,  bhvSkeeter, 31),
	OBJECT_WITH_ACTS(122, -8509, -627, -6725, 0, 0, 0, 0x5000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, -2015, 1076, -1276, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(215, 782, 205, 2764, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(0, -6002, 272, -3392, 0, 0, 0, 0x4000000,  bhvHiddenRedCoinStar, 31),
	OBJECT_WITH_ACTS(215, -2009, 1076, -1275, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -6207, 830, 2432, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -6268, 2059, 5, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -3160, 1185, 2505, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -1197, 791, 8646, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -4005, 1791, 7366, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 716, 0, -3842, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(122, -6728, 4118, -1794, 0, 0, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(84, -4062, 980, 3603, 0, 0, 0, 0x0,  bhvBulletBill, 31),
	OBJECT_WITH_ACTS(88, -4558, 3283, -1161, 0, 180, 0, 0x0,  bhvThwomp, 31),
	OBJECT_WITH_ACTS(88, -4020, 3283, -1835, 0, 90, 0, 0x0,  bhvThwomp, 31),
	OBJECT_WITH_ACTS(88, -3428, 3283, -2492, 0, 0, 0, 0x0,  bhvThwomp, 31),
	OBJECT_WITH_ACTS(88, -2336, 3283, -2491, 0, 0, 0, 0x0,  bhvThwomp, 31),
	OBJECT_WITH_ACTS(88, -1781, 3283, -1824, 0, -90, 0, 0x0,  bhvThwomp, 31),
	OBJECT_WITH_ACTS(88, -1252, 3283, -1163, 0, 180, 0, 0x0,  bhvThwomp, 31),
	OBJECT_WITH_ACTS(122, -9862, 3339, 756, 0, 0, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, 0, 0, 0, 0, -90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -649, 0, -3579, 0, -90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -1536, 0, 2778, 0, -90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -2074, 2626, 8666, 0, -90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -4472, 2626, 8644, 0, -90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -1191, 791, 8648, 0, -90, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(88, -4014, 794, 7364, 0, 0, 0, 0x0,  bhvThwomp, 31),
	OBJECT_WITH_ACTS(118, -4043, 798, 5328, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -4047, 791, 6233, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(140, -563, 791, 9891, 0, 0, 0, 0x0,  bhvBlueCoinSwitch, 31),
	OBJECT_WITH_ACTS(0, -10309, 1608, -1162, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -10309, 258, -1162, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(223, -9343, 258, -1143, 0, 0, 0, 0x20000,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(223, -3897, 2626, 8674, 0, 0, 0, 0x20000,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(223, -11774, 2192, 6027, 0, 0, 0, 0x20000,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(0, -6815, 2626, 8667, 0, -90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(116, -11084, 2191, 9165, 0, -90, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(116, -11165, 2219, 7100, 0, -90, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(116, -11372, 2219, 4746, 0, -90, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(116, -12021, 2219, 1086, 0, -90, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(116, -11794, 2219, 3416, 0, -90, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(122, -1600, 3868, 9374, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -3363, 537, -3625, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(118, -4050, 798, 4415, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(84, 205, 980, 8654, 0, -90, 0, 0x0,  bhvBulletBill, 31),
	OBJECT_WITH_ACTS(192, 2029, 0, -16, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(88, 1663, 0, 664, 0, 90, 0, 0x0,  bhvThwomp, 31),
	OBJECT_WITH_ACTS(88, -2463, 0, 262, 0, 0, 0, 0x0,  bhvThwomp, 31),
	OBJECT_WITH_ACTS(188, 587, 3025, -4287, 0, 0, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, -3271, 791, 8601, 0, 0, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, -5721, 791, 8667, 0, 0, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(137, -7351, 536, -759, 0, 0, 0, 0x20000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, -5315, 0, 7, 0, -90, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -6001, 621, 1867, 0, -90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(22, 1724, 0, -2653, 0, 0, 0, 0x3b0000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(0, 1406, 0, -2653, 0, 90, 0, 0x6f0000,  bhvDeathWarp, 31),
	OBJECT_WITH_ACTS(54, -9707, -3515, -7958, 0, 0, 0, 0x0,  bhvWdwSquareFloatingPlatform, 31),
	OBJECT_WITH_ACTS(0, -6686, 721, 4, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -6005, 0, -2504, 0, -90, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -4671, 801, 8610, 0, -90, 0, 0x20000,  bhvCoinFormation, 31),
	//OBJECT_WITH_ACTS(0, 10, 5, 64, 0, 0, 20, 9,  RM_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 100, 5, 272, 0, 0, 20, 10,  RM_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 100, 5, 272, 0, 0, 20, 11,  RM_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 100, 5, 272, 0, 0, 20, 12,  RM_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 100, 5, 272, 0, 0, 20, 13,  RM_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 100, 5, 272, 0, 0, 20, 14,  RM_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 100, 5, 554, 0, 0, 20, 15,  RM_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 100, 5, 554, 0, 0, 20, 16,  RM_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 100, 5, 554, 0, 0, 20, 17,  RM_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 10, 5, 77, 0, 0, 20, 18,  RM_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 10, 5, 8, 0, 0, 20, 19,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_wf_1_[] = {
	WARP_NODE(28, 16, 2, 28, 0),
	WARP_NODE(59, 28, 1, 59, 0),
	WARP_NODE(111, 24, 1, 111, 0),
	WARP_NODE(240, 16, 2, 52, 0),
	WARP_NODE(241, 16, 2, 102, 0),
	RETURN()
};