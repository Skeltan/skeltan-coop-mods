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

#include "levels/jrb/header.h"
#include "levels/sl/header.h"

extern u8 _jrb_segment_ESegmentRomStart[];
extern u8 _jrb_segment_ESegmentRomEnd[];

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _sl_segment_7SegmentRomStart, _sl_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _slSegmentRomStart, _slSegmentRomEnd),
	LOAD_RAW(0x0E, _jrb_segment_ESegmentRomStart, _jrb_segment_ESegmentRomEnd),
	LOAD_MIO0(        /*seg*/ 0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd),
	LOAD_MIO0(0xA, _ccm_skybox_mio0SegmentRomStart, _ccm_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group7_mio0SegmentRomStart, _group7_mio0SegmentRomEnd),
	LOAD_RAW(12, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd),
	LOAD_MIO0(6, _group16_mio0SegmentRomStart, _group16_mio0SegmentRomEnd),
	LOAD_RAW(13, _group16_geoSegmentRomStart, _group16_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
	// Level Specific Models
	LOAD_MODEL_FROM_GEO(MODEL_SL_SNOW_TRIANGLE,      sl_geo_000390),
	    LOAD_MODEL_FROM_GEO(MODEL_SL_CRACKED_ICE,        sl_geo_000360),
	    LOAD_MODEL_FROM_GEO(MODEL_SL_CRACKED_ICE_CHUNK,  sl_geo_000378),
	    LOAD_MODEL_FROM_GEO(MODEL_SL_SNOW_TREE,          snow_tree_geo),
	// Unspecified Models
	LOAD_MODEL_FROM_GEO(22,  warp_pipe_geo),
	LOAD_MODEL_FROM_GEO(23,  bubbly_tree_geo),
	LOAD_MODEL_FROM_GEO(24,  spiky_tree_geo),
	LOAD_MODEL_FROM_GEO(25,  snow_tree_geo),
	LOAD_MODEL_FROM_GEO(27,  palm_tree_geo),
	LOAD_MODEL_FROM_GEO(29,  haunted_door_geo),
	LOAD_MODEL_FROM_GEO(31,  metal_door_geo),
	LOAD_MODEL_FROM_GEO(32,  hazy_maze_door_geo),
	LOAD_MODEL_FROM_GEO(34,  castle_door_0_star_geo),
	LOAD_MODEL_FROM_GEO(35,  castle_door_1_star_geo),
	LOAD_MODEL_FROM_GEO(36,  castle_door_3_stars_geo),
	LOAD_MODEL_FROM_GEO(37,  key_door_geo),
	LOAD_MODEL_FROM_GEO(38,  castle_door_geo),
	// LOAD_MODEL_FROM_GEO(100, 0x06003754),
	// LOAD_MODEL_FROM_GEO(101, 0x06003874),
	// LOAD_MODEL_FROM_DL(132, 0x08025f08, 4),
	// LOAD_MODEL_FROM_DL(158, 0x0302c8a0, 4),
	// LOAD_MODEL_FROM_DL(159, 0x0302bcd0, 4),
	// LOAD_MODEL_FROM_DL(161, 0x0301cb00, 4),
	// LOAD_MODEL_FROM_DL(164, 0x04032a18, 4),
	// LOAD_MODEL_FROM_DL(201, 0x080048e0, 4),
	// LOAD_MODEL_FROM_DL(218, 0x08024bb8, 4),
	JUMP_LINK(script_func_global_1),
	JUMP_LINK(script_func_global_8),
	JUMP_LINK(script_func_global_17),
	JUMP_LINK(local_area_jrb_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_jrb_1_[] = {
	AREA(1, Geo_jrb_1_0x13f11a0),
	TERRAIN(col_jrb_1_0xe07e960),
	SET_BACKGROUND_MUSIC(0, 37),
	TERRAIN_TYPE(2),
	JUMP_LINK(local_objects_jrb_1_),
	JUMP_LINK(local_warps_jrb_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_jrb_1_[] = {
	OBJECT_WITH_ACTS(0, 3774, 0, 7291, 0, 180, 0, 0x300000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(137, -7977, 270, 5934, 0, 0, 0, 0x10000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(122, 2223, 2532, 1003, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 2775, -720, 8852, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -6259, 3158, -4288, 0, 0, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(101, 5618, 2219, -6052, 0, 0, 0, 0x3000000,  bhvBigChillBully, 31),
	OBJECT_WITH_ACTS(85, 6092, 1744, -5095, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(85, 5409, 1744, -5670, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(85, 7155, 1744, -6113, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(85, 5664, 1744, -7426, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(85, 4575, 1744, -6220, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(85, 4402, 1744, -5334, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(85, 1929, 0, 5209, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(85, -1113, 0, 3479, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(85, -7492, 0, 6915, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(85, 633, 0, 550, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(85, -5936, 0, 1043, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(85, 7991, 0, 467, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(85, 2781, 0, -1706, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(85, -3167, 0, -2960, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(85, -6034, 0, -6443, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(116, 605, -109, -3425, 0, 0, 0, 0x0,  bhvMoneybagHidden, 31),
	OBJECT_WITH_ACTS(116, 624, -109, -4484, 0, 0, 0, 0x0,  bhvMoneybagHidden, 31),
	OBJECT_WITH_ACTS(84, -3923, 120, 2360, 0, 0, 0, 0x0,  bhvSpindrift, 31),
	OBJECT_WITH_ACTS(84, -630, 600, 5998, 0, 0, 0, 0x0,  bhvSpindrift, 31),
	OBJECT_WITH_ACTS(84, -1088, 990, 6938, 0, 0, 0, 0x0,  bhvSpindrift, 31),
	OBJECT_WITH_ACTS(122, 779, 2235, 7889, 0, 0, 0, 0x4000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(140, 1583, 0, -1157, 0, 0, 0, 0x0,  bhvBlueCoinSwitch, 31),
	OBJECT_WITH_ACTS(118, -1573, 0, -1361, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -1163, 0, -1352, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(129, 890, 0, -8084, 0, 0, 0, 0x0,  bhvJumpingBox, 31),
	OBJECT_WITH_ACTS(0, 4357, -109, 1619, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -1643, -109, 1792, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2550, -109, -4982, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -6205, -109, -7755, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 733, 1516, -1326, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -1456, 1170, -4514, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -5131, 0, 1360, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 447, 0, 4233, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -3905, -109, 6557, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 8658, 201, 1254, 0, 0, 0, 0x5000000,  bhvHiddenRedCoinStar, 31),
	OBJECT_WITH_ACTS(215, 6101, -109, -6339, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -9272, 0, -4288, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 732, 1516, -1334, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -1667, 1170, -5163, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 7214, 0, 3078, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -8207, 0, 7933, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -4608, 0, 1164, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 4869, 879, -1856, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(207, -5233, 0, 8580, 0, 0, 0, 0x0,  bhvFloorSwitchHiddenObjects, 31),
	OBJECT_WITH_ACTS(129, 425, 969, 5902, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, 422, 1261, 6604, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(118, -745, 0, -1344, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(0, 6097, -109, -6342, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	RETURN()
};

const LevelScript local_warps_jrb_1_[] = {
	WARP_NODE(48, 16, 1, 48, 0),
	WARP_NODE(240, 16, 1, 53, 0),
	WARP_NODE(241, 16, 1, 103, 0),
	RETURN()
};